#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QString>
#include <vector>
#include <fstream>
using namespace std;

static long int selectN;
static unsigned short selectZ;
static bool state = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    initLayerTV{160, 160, 156, 151.99, 147.99},
    initLayerTF{120.37, 120.37, 124.38, 128.38, 132.39},
    initLayerCV{67.94, 67.94, 69.96, 72.04, 72.04},
    initLayerCF{6.5, 6.5, 4.613, 2.78, 2.78}
{

        // -----Model's heat exchenger parameters------
        double RvT = 0.0191806, RfT = 0.0000777, a0 = 0.00016966,
        PTV_L = (a0 * 273.15 * dt) / defaultH, PTV_N = 0, PTF = (0.0002291314 * dt) / defaultH;

        // -----Model's mass exchenger parameters------
        double RvM = 0.004302, RfM = 0.00001222, E = 0.000000001;

        //----------Petrtubation----------
        double petrub = 0; // Temperature(min:-maxHeat:12.5), gas flow or pressure differential?

        bmp.assign(defaultZ,0);

        for (int i = 0; i <defaultN; i++)
        {
            TV.push_back(bmp);
            TF.push_back(bmp);
            CV.push_back(bmp);
            CF.push_back(bmp);
        }

        for(int i = 0; i <defaultN; i++)
        {
            TV[i][0] = 160;
            TV[i][1] = 0; TV[i][2] = 0; TV[i][3] = 0;
            TV[i][defaultZ-1] = 147.99;
        }

        for(short i = 0; i < defaultZ; i++)
        {
            TV[0][i] = initLayerTV[i];
        }

        for(int i = 0; i <defaultN; i++)
        {
            TF[i][0] = 120.37;
            TF[i][1] = 0; TF[i][2] = 0; TF[i][3] = 0;
            TF[i][defaultZ-1] = 132.39;
        }

        for(short i = 0; i < defaultZ; i++)
        {
            TF[0][i] = initLayerTF[i];
        }

        for(int i = 0; i <defaultN; i++)
        {
            CV[i][0] = 67.94;
            CV[i][1] = 0; CV[i][2] = 0; CV[i][3] = 0;
            CV[i][defaultZ-1] = 72.04;
        }

        for(short i = 0; i < defaultZ; i++)
        {
            CV[0][i] = initLayerCV[i];
        }

        for(int i = 0; i <defaultN; i++)
        {
            CF[i][0] = 6.5;
            CF[i][1] = 0; CF[i][2] = 0; CF[i][3] = 0;
            CF[i][defaultZ-1] = 2.78;
        }

        for(short i = 0; i < defaultZ; i++)
        {
            CF[0][i] = initLayerCF[i];
        }


        // Calculate model
        for(unsigned int i = 1; i <defaultN; i++)   // n: t
        {
           for(short j = 1; j < (defaultZ-1); j++)  //  i: defaultZ
           {
                // -----Calculate layer heat exchenger model------
                PTV_N = (a0*TV[i-1][j+1] * dt) / defaultH;
                TV[i][j] = -TV[i-1][j] * (PTV_L - 1 - PTV_N + dt*RvT) + (PTV_L * TV[i-1][j-1]) - (PTV_N * TV[i-1][j+1]) + (dt * RvT * TF[i-1][(defaultZ-1)-j]) + petrub;  // + perturbation of the temperature, the gas flow, the pressure differential
                TF[i][j] = -TF[i-1][j] * (PTF - 1 + dt*RfT) + (PTF * TF[i-1][j-1]) + (dt * RfT * TV[i-1][(defaultZ-1)-j]);

                // -----Calculate layer mass exchenger model------
                CV[i][j] = -CV[i-1][j] * (PTV_L - 1 - PTV_N - dt*RvM) + (PTV_L * CV[i-1][j-1]) -(PTV_N * CV[i-1][j+1]) - (dt * RvM * E * CF[i-1][(defaultZ-1)-j]);
                CF[i][j] = -CF[i-1][j] * (PTF - 1 - (dt*RfM*E)) + (PTF * CF[i-1][j-1]) - (dt * RfM * CV[i-1][(defaultZ-1)-j]);
           }
        }


        ofstream foutTV("Tpar.txt"); // 4(1)
        for(int i = 0; i < defaultN; i++)
        {
           for(int j = 0; j < 5; j++)
           {
               foutTV << TV[i][j] << " | ";
           }
           foutTV << endl;
        }
        foutTV.close();


        ofstream foutTF("Tjyd.txt");  // 4(2)
        for(int i = 0; i < defaultN; i++)
        {
           for(int j = 0; j < 5; j++)
           {
               foutTF << TF[i][j] << " | ";
           }
           foutTF << endl;
        }
        foutTF.close();

        ofstream foutCV("Cpar.txt"); // 4(1)
        for(int i = 0; i < defaultN; i++)
        {
           for(int j = 0; j < 5; j++)
           {
               foutCV << CV[i][j] << " | ";
           }
           foutCV << endl;
        }
        foutCV.close();


        ofstream foutCF("Cjyd.txt");  // 4(2)
        for(int i = 0; i < defaultN; i++)
        {
           for(int j = 0; j < 5; j++)
           {
               foutCF << CF[i][j] << " | ";
           }
           foutCF << endl;
        }
        foutCF.close();

    //----------------------------------

    ui->setupUi(this);
    ui->inputLeftX->setReadOnly(true);

    pictHeight = 370;
    pictWidth = 540;
    leftX = -1; rightX = 1;
    leftY = -1; rightY = 1;
    state = false;
    drawGraph();

    ui->inputLeftY->clear();
    ui->inputRightY->clear();
    ui->CouiceZspinBox->clear();
    ui->CouiceNLineEdit->clear();

    ui->CouiceZspinBox->setValue(3);
    ui->CouiceNLineEdit->insert("10000");
    ui->inputLeftY->insert("100");
    ui->inputRightY->insert("180");


    selectZ = ui->CouiceZspinBox->value();
    selectN = ui->CouiceNLineEdit->text().toDouble();

    leftY = ui->inputLeftY->text().toDouble();
    rightY = ui->inputRightY->text().toDouble();

}



MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::bTV(double i, short j)
{
    return TV[int(i)][j];
}

double MainWindow::bTF(double i, short j)
{
    return TF[int(i)][j];
}

double MainWindow::bCV(double i, short j)
{
    return CV[int(i)][j];
}

double MainWindow::bCF(double i, short j)
{
    return CF[int(i)][j];
}

void MainWindow::recountPixels()
{
    onePixelX = 540.0/(rightX-leftX);
    onePixelY = 370.0/(rightY-leftY);
    Ox = fabs(leftX); Oy = rightY;
}

void MainWindow::getData()
{
    leftX = ui->inputLeftX->text().toDouble();
    rightX = ui->inputRightX->text().toDouble();
    leftY = ui->inputLeftY->text().toDouble();
    rightY = ui->inputRightY->text().toDouble();
    step = 0.01;
}

void MainWindow::drawGraph(bool notEmpty)
{

//??????????????????????????????????????????????????????????

    QPixmap graph(540,370);
    QPainter paint;
    paint.begin(&graph);
    paint.eraseRect(0,0,540,370);

    paint.setPen(QPen(Qt::black,3));
    paint.drawLine(0, 365, 540, 365);   // Axis X
    paint.drawLine(5, 0, 5, 370);       // Axis Y

    getData();
    recountPixels();

    // Draw axises on the map
    paint.setPen(QPen(Qt::black,1));
    short scaleX = 102*onePixelX, scaleY = 20*onePixelY;//??????????????????????????????????????????????????????????

    for(double i = leftX+20; i <= rightX; i+=20.0)
        paint.drawLine((i+Ox)*onePixelX, Oy*onePixelY, (i+Ox)*onePixelX, (Oy-scaleX)*onePixelY);    // Axis X

    for(double i = leftY; i<= rightY; i+=10.0)
       paint.drawLine(Ox*onePixelX, (Oy-i)*onePixelY, (Ox+scaleY)*onePixelX, (Oy-i)*onePixelY);    // Axis Y

    // Draw a grid on the map
    paint.setPen(QPen(Qt::gray, 0.4, Qt::DashLine));
    scaleX = 180, scaleY = 1000;//??????????????????????????????????????????????????????????

    for(double i = leftX+20; i <= rightX; i+=20.0)
        paint.drawLine((i+Ox)*onePixelX, Oy*onePixelY, (i+Ox)*onePixelX, (Oy-scaleX)*onePixelY);    // Axis X

    for(double i = leftY; i<= rightY; i+=10.0)
        paint.drawLine(Ox*onePixelX, (Oy-i)*onePixelY, (Ox+scaleY)*onePixelX, (Oy-i)*onePixelY);    // Axis Y

/*
    // Draw points on the map
    paint.setPen(QPen(Qt::black,2));

    for(double i = leftX;i<=rightX;i+=10.0)
        paint.drawPoint((i+Ox)*onePixelX,Oy*onePixelY); // Axis X
    for(double i = leftY;i<=rightY;i+=10.0)
        paint.drawPoint(Ox*onePixelX,(Oy-i)*onePixelY); // Axis Y

    //  + Grid!

*/


    if(!notEmpty) {
        paint.end();
        ui->outputGraph->setPixmap(graph);
        return;
    }

    // Draw functions
    paint.setPen(QPen(Qt::green,1,Qt::SolidLine));
    paint.setRenderHint(QPainter::Antialiasing, true);
    QPainterPath path,p[3];
    bool first[2] = {1,1};
    double buff = step;

    if(ui->Hexch->isChecked()) {

        for(short j = 1; j < (defaultZ-1); ++j)
        {
            for(double i = (double)leftX+step; (i <= (double)rightX); i+=step)
            {   if(!isnan(bTV(i, j))) {
                    if(first[0]) {
                        path.moveTo((i+Ox)*onePixelX,(Oy-bTV(i, j))*onePixelY);
                        first[0] = false;
                    }
                    else
                        path.lineTo((i+Ox)*onePixelX,(Oy-bTV(i, j))*onePixelY);
                }

                if(!isnan(bTF(i, j))) {
                    if(first[1]) {
                        p[0].moveTo((i+Ox)*onePixelX,(Oy-bTF(i, j))*onePixelY);
                        first[1] = false;
                    }
                    else
                        p[0].lineTo((i+Ox)*onePixelX,(Oy-bTF(i, j))*onePixelY);
                 }
            }

            path.moveTo(Ox,(Oy-bTV(0, j+1))*onePixelY);
            p[0].moveTo(Ox,(Oy-bTF(0, j+1))*onePixelY);
            step = buff;
        }


        paint.setPen(QPen(Qt::blue,1,Qt::SolidLine));
        paint.drawPath(p[0]);

        paint.setPen(QPen(Qt::green,1,Qt::SolidLine));
        paint.drawPath(path);
    }
    if(ui->Mexch->isChecked())
    {
        first[0] = 1;   first[1] = 1;
        for(short j = 1; j < (defaultZ-1); ++j)
        {
            for(double i = (double)leftX+step; (i <= (double)rightX); i+=step)
            {   if(!isnan(bCV(i, j))) {
                    if(first[0]) {
                        path.moveTo((i+Ox)*onePixelX,(Oy-bCV(i, j))*onePixelY);
                        first[0] = false;
                    }
                    else
                        path.lineTo((i+Ox)*onePixelX,(Oy-bCV(i, j))*onePixelY);
                }

                if(!isnan(bCF(i, j))) {
                    if(first[1]) {
                        p[0].moveTo((i+Ox)*onePixelX,(Oy-bCF(i, j))*onePixelY);
                        first[1] = false;
                    }
                    else
                        p[0].lineTo((i+Ox)*onePixelX,(Oy-bCF(i, j))*onePixelY);
                    }
            }

            path.moveTo(Ox,(Oy-bCV(0, j+1))*onePixelY);
            p[0].moveTo(Ox,(Oy-bCF(0, j+1))*onePixelY);
            step = buff;
        }

        paint.setPen(QPen(Qt::blue,1,Qt::DashLine));
        paint.drawPath(p[0]);

        paint.setPen(QPen(Qt::green,1,Qt::DashLine));
        paint.drawPath(path);
    }


//--------------------------------------------------------------------------


    if(ui->Hexch->isChecked()) {
        QString str = QString::number(TV[defaultN-1][1]);
        ui->valV1->setText(str);

        str = QString::number(TV[defaultN-1][2]);
        ui->valV2->setText(str);

        str = QString::number(TV[defaultN-1][3]);
        ui->valV3->setText(str);
//----------------------------------------
        str = QString::number(TF[defaultN-1][1]);
        ui->valF1->setText(str);

        str = QString::number(TF[defaultN-1][2]);
        ui->valF2->setText(str);

        str = QString::number(TF[defaultN-1][3]);
        ui->valF3->setText(str);
    }

    if(ui->Mexch->isChecked()) {
        QString str = QString::number(CV[defaultN-1][1]);
        ui->valV1->setText(str);

        str = QString::number(CV[defaultN-1][2]);
        ui->valV2->setText(str);

        str = QString::number(CV[defaultN-1][3]);
        ui->valV3->setText(str);
//----------------------------------------
        str = QString::number(CF[defaultN-1][1]);
        ui->valF1->setText(str);

        str = QString::number(CF[defaultN-1][2]);
        ui->valF2->setText(str);

        str = QString::number(CF[defaultN-1][3]);
        ui->valF3->setText(str);
    }



    paint.end();
    ui->outputGraph->setPixmap(graph);
    return;
}

void MainWindow::on_exit_clicked()
{
    this->close();
}

void MainWindow::on_clear_clicked()
{
    recountPixels();
    drawGraph();
}

void MainWindow::on_draw_clicked()
{
    getData();
    recountPixels();
    drawGraph(1);
}

void MainWindow::on_save_clicked()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString name;
   if(date.day()<10)
        name += "0";
    name += QString::number(date.day())+".";
    if(date.month()<10)
        name += "0";
    name += QString::number(date.month())+".";
    name += QString::number(date.year())+"_";
    if(time.hour()<10)
        name += "0";
    name += QString::number(time.hour())+"-";
    if(time.minute()<10)
        name += "0";
    name += QString::number(time.minute())+"-";
    if(time.second()<10)
        name += "0";
    name += QString::number(time.second());
    QFile file(name+".png");
    qDebug() << name;
    file.open(QIODevice::WriteOnly);
/*    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Ok);
    if(ui->outputGraph->pixmap()->save(&file,"PNG")) {
        msgBox.setText("Saved to program folder with name: "+name+".png");
        msgBox.setWindowTitle("Saved!");
    }
    else {
        msgBox.setText("Error saving.");
        msgBox.setWindowTitle("Error!");
    }
    msgBox.exec(); */
}


void MainWindow::on_Mexch_clicked()
{
        ui->inputLeftY->clear();
        ui->inputRightY->clear();

        ui->inputLeftY->insert("0");
        ui->inputRightY->insert("90");

        leftY = ui->inputLeftY->text().toDouble();
        rightY = ui->inputRightY->text().toDouble();
}

void MainWindow::on_Hexch_clicked()
{
        ui->inputLeftY->clear();
        ui->inputRightY->clear();

        ui->inputLeftY->insert("100");
        ui->inputRightY->insert("180");

        leftY = ui->inputLeftY->text().toDouble();
        rightY = ui->inputRightY->text().toDouble();
}
