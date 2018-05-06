#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <vector>
#include <cmath>
#include <map>
#include <omp.h>
#include <array>
#include <vector>
#include <thread>
#include <time.h>
#include <fstream>
#include <iostream>
#include <functional>   //ref()


/*
 * #pragma omp parallel for num_threads(2) and #pragma omp parallel sections
 * - It's OpenMP library! It's helping paralellize program.
*/

using namespace std;

static bool okey = Q_NULLPTR;
static bool notEmpty = 0;
static double defaultH = 0.0;
static unsigned int selectZ;
static unsigned long long selectN;
static double stepN;
static map <string, int> Sizes = {{ "windowSizeX", 540 },
                                     { "windowSizeY", 370 },
                                     { "axisX_x1", 0 },
                                     { "axisX_y1", 343 },
                                     { "axisX_x2", 540 },
                                     { "axisX_y2", 343 },
                                     { "axisY_x1", 28 },
                                     { "axisY_y1", 0 },
                                     { "axisY_x2", 28 },
                                     { "axisY_y2", 370 },
                                    };

static double dRC = 1.4;
const double initLayerTV_0 = 160, initLayerTV_1 = 147.99;
const double initLayerTF_0 = 120.37, initLayerTF_1 = 132.39;
const double initLayerCV_0 = 67.94, initLayerCV_1 = 72.04;
const double initLayerCF_0 = 6.5, initLayerCF_1 = 2.78;
static bool state = false;

//----------Petrtubation----------//    Temperature(min:???; maxHeat:???), gas flow or pressure differential?
static double P_TV = 0;
static double P_TF = 0;
static double P_CV = 0;
static double P_CF = 0;

void calculateMM(vector <vector <double> > &TV, vector <vector <double> > &TF);
void calculateMM(vector <vector <double> > &TV, vector <vector <double> > &TF,
                 bool turnOn);
void calculateMM(vector <vector <double> > &TV, vector <vector <double> > &TF,
                 vector <vector <double> > &CV, vector <vector <double> > &CF);

void initialLayerTV(vector <vector <double> > &TV);         // Would be relize as template
void initialLayerTF(vector <vector <double> > &TF);
void initialLayerCV(vector <vector <double> > &CV);
void initialLayerCF(vector <vector <double> > &CF);

void draw_Model(QPixmap *graph, int choiceModel);

void toFileMM(vector <vector <double> > MMM, string nameModel);

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
        clock_t timeMW_0 = clock();
        int msec = 0;

        // To initial array of functions
        MM[0] = &bTV;
        MM[1] = &bTF;
        MM[2] = &bCV;
        MM[3] = &bCF;

        ui->setupUi(this);
        ui->inputLeftX->setReadOnly(true);

        selectZ = static_cast <unsigned int> (ui->CouiceZspinBox->value() + 2);
        selectN = ui->inputRightX->text().toULongLong(&okey, 10);
        defaultH = dRC/(selectZ-2);                                     // dRC = 1.4m

        state = false;

        ui->inputLeftY->clear();
        ui->inputRightY->clear();

        ui->inputLeftY->insert("100");
        ui->inputRightY->insert("180");

        leftY = ui->inputLeftY->text().toDouble();
        rightY = ui->inputRightY->text().toDouble();

        drawGraph();

        clock_t timeDiff = clock() - timeMW_0;
        msec = timeDiff * 1000 / CLOCKS_PER_SEC;
        cout << "General time of program taken " << msec/1000 << " seconds, and " << msec%1000 <<" milliseconds!" << endl;
}


MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::bTV(unsigned long long i, uint j)
{
    return TV[static_cast <size_t> (i)][j];
}

double MainWindow::bTF(unsigned long long i, uint j)
{
    return TF[static_cast <size_t> (i)][j];
}

double MainWindow::bCV(unsigned long long i, uint j)
{
    return CV[static_cast <size_t> (i)][j];
}

double MainWindow::bCF(unsigned long long i, uint j)
{
    return CF[static_cast <size_t> (i)][j];
}


void MainWindow::recountPixels()
{
    onePixelX = (Sizes["windowSizeX"] - Sizes["axisY_x1"]) / (rightX-leftX);
    onePixelY = Sizes["axisX_y1"]  /(rightY - leftY);
    Ox = fabs(leftX + Sizes["axisY_x1"]); Oy = fabs(rightY);                // Nothing!!!
    ui->selectStep->setText(QString::fromStdString(std::to_string(step)));
}

void MainWindow::getData()
{
    leftX = ui->inputLeftX->text().toDouble();
    rightX = ui->inputRightX->text().toDouble();
    leftY = ui->inputLeftY->text().toDouble();
    rightY = ui->inputRightY->text().toDouble();
    selectN = ui->inputRightX->text().toULongLong(&okey, 10);

    step = (ui->selectStep->text().toDouble() <= 0.0)? 0.01 : abs(ui->selectStep->text().toDouble());
}

void MainWindow::drawGraph(bool notEmpty)
{
    clock_t timeMW_1 = clock();
    int msec = 0;

    QPixmap graph(Sizes["windowSizeX"], Sizes["windowSizeY"]);
    QPainter paint;
    paint.begin(&graph);
    paint.eraseRect(0, 0, Sizes["windowSizeX"], Sizes["windowSizeX"]);

    // Draw axises on the map
    paint.setPen(QPen(Qt::black,3));
    paint.drawLine(Sizes["axisX_x1"], Sizes["axisX_y1"], Sizes["axisX_x2"], Sizes["axisX_y2"]);   // Axis X
    paint.drawLine(Sizes["axisY_x1"], Sizes["axisY_y1"], Sizes["axisY_x2"], Sizes["axisY_y2"]);   // Axis Y

    getData();
    recountPixels();

    int scaleX = Sizes["axisX_y1"], scaleY = Sizes["axisY_x1"];
    double stepY = onePixelY;

    //--------------------------------------------------------------------------

    // Draw control of points on the map
    paint.setPen(QPen(Qt::black, 1));

    #pragma omp parallel sections       // parallel's sections
    {
        #pragma omp section
        for(double i = scaleY; i <= Sizes["axisX_x2"]; i += ( (Sizes["windowSizeX"]-Sizes["axisY_x1"]) / 10.0 ))
            paint.drawLine(static_cast <int> (i), (scaleX-6), static_cast <int> (i), (scaleX+6));

        #pragma omp section
        for(double i = scaleX; i >= Sizes["axisY_y1"]; i -= (stepY*4.0))
            paint.drawLine((scaleY-6), static_cast <int> (i), (scaleY+6), static_cast <int> (i));
    }

    //--------------------------------------------------------------------------

    // Draw a grid on the map
    paint.setPen(QPen(Qt::gray, 0.2, Qt::DashLine));

    #pragma omp parallel sections       // parallel's sections
    {
        #pragma omp section
        for(double i = scaleY; i <= Sizes["axisX_x2"]; i += ( (Sizes["windowSizeX"]-Sizes["axisY_x1"]) / 10.0 ))
            paint.drawLine(static_cast <int> (i), Sizes["axisX_y1"], static_cast <int> (i), Sizes["axisY_y1"]);

        #pragma omp section
        for(double i = scaleX; i >= Sizes["axisY_y1"]; i -= (stepY*4.0))
            paint.drawLine(Sizes["axisX_x2"], static_cast <int> (i), Sizes["axisY_x2"], static_cast <int> (i));
    }

    //--------------------------------------------------------------------------

    paint.end();

    if(!notEmpty)
    {
        notEmpty = 1;
        ui->outputGraph->setPixmap(graph);
        return;
    }

    //----------------------------------------------------------------------

    if (ui->LHM->isChecked())
    {
        calculateMM(TV, TF);
        draw_Model(&graph, 0);
    }

    if (ui->NHM->isChecked())
    {
        calculateMM(TV, TF, 1);        // OVERLOADING CALCULATE OF FUNCTION
        draw_Model(&graph, 0);
    }

    if((ui->Hexch->isChecked()) || (ui->Mexch->isChecked()))
    {
        calculateMM(TV, TF, CV, CF);
        if((ui->Hexch->isChecked()))
            draw_Model(&graph, 0);
        else
            draw_Model(&graph, 2);
    }

    //----------------------------------------------------------------------

    // Out to display steady-state value temperature
    if((ui->Hexch->isChecked()) || (ui->LHM->isChecked())) {
        QString str = QString::number(TV[static_cast <size_t> (selectN-1)][1]);
        ui->valV1->setText(str);

        str = QString::number(TV[static_cast <size_t> (selectN-1)][(selectZ-1) / 2]);
        ui->valV2->setText(str);

        str = QString::number(TV[static_cast <size_t> (selectN-1)][selectZ-2]);
        ui->valV3->setText(str);
    //----------------------------------------------------------------------
        str = QString::number(TF[static_cast <size_t> (selectN-1)][1]);
        ui->valF1->setText(str);

        str = QString::number(TF[static_cast <size_t> (selectN-1)][(selectZ-1) / 2]);
        ui->valF2->setText(str);

        str = QString::number(TF[static_cast <size_t> (selectN-1)][selectZ-2]);
        ui->valF3->setText(str);
    }

    // Out to display steady-state concentration of absorbent
    if(ui->Mexch->isChecked()) {
        QString str = QString::number(CV[static_cast <size_t> (selectN-1)][1]);
        ui->valV1->setText(str);

        str = QString::number(CV[static_cast <size_t> (selectN-1)][(selectZ-1) / 2]);
        ui->valV2->setText(str);

        str = QString::number(CV[static_cast <size_t> (selectN-1)][selectZ-2]);
        ui->valV3->setText(str);
    //----------------------------------------------------------------------
        str = QString::number(CF[static_cast <size_t> (selectN-1)][1]);
        ui->valF1->setText(str);

        str = QString::number(CF[static_cast <size_t> (selectN-1)][(selectZ-1) / 2]);
        ui->valF2->setText(str);

        str = QString::number(CF[static_cast <size_t> (selectN-1)][selectZ-2]);
        ui->valF3->setText(str);
    }

    ui->outputGraph->setPixmap(graph);

    clock_t timeDiff = clock() - timeMW_1;
    msec = timeDiff * 1000 / CLOCKS_PER_SEC;
    cout << endl <<"Drawing time of program taken " << msec/1000 << " seconds, and " << msec%1000 <<" milliseconds!" << endl;
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

void MainWindow::draw_Model(QPixmap *graph, int choiceModel)
{
    stepN = rightX/37.0;                                        //----CRUTCHES ----stepN = size of window graph(370) / 37;
    double shift = 17.0;                                        // Offset relative to the edge of the graph
    bool mode = true;

    QPainterPath path, path1;
    QPainter paint;
    paint.begin(graph);

    getData();
    recountPixels();

    // Draw functions
    paint.setRenderHint(QPainter::Antialiasing, true);

    #pragma omp parallel sections                               // parallel's sections
    {
        #pragma omp section
        {
            // Draw Heat's part of model
            for(uint j = 1; j < (selectZ-1); ++j)              // parallel
            {
                switch(j-1)                                     // Move to begin of point
                {
                    case 0: paint.setPen(QPen(Qt::red,1.05,Qt::SolidLine));
                            path.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel])(0, j)))*onePixelY); break;

                    case 1: paint.setPen(QPen(Qt::green,1.05,Qt::SolidLine));
                            path.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel])(0, j)))*onePixelY); break;

                    case 2: paint.setPen(QPen(Qt::blue,1.05,Qt::SolidLine));
                            path.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel])(0, j)))*onePixelY); break;

                    default:{
                            paint.setPen(QPen(Qt::darkCyan,1.05,Qt::SolidLine));
                            path.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel])(0, j)))*onePixelY); break;
                            }
                }

                for(double i = stepN; i <= rightX; i += step)
                {
                    if(!isnan(((this->*MM[choiceModel])(static_cast <unsigned long long> (i), j))))
                    {
                        if(mode)                                // Set begin of point
                        {
                            path.moveTo((i*onePixelX)+shift, (Oy-((this->*MM[choiceModel])(static_cast <unsigned long long> (i), j)))*onePixelY);
                            mode = false;
                        }
                        else
                            path.lineTo((i*onePixelX)+shift,(Oy-((this->*MM[choiceModel])(static_cast <unsigned long long> (i), j)))*onePixelY);
                    }

                    // For endless modeling. As path has maximum size elements type data is INTeger(around 2 147 483 647 * 2)
                    // then we  increase this number to endless.
                    if(path.elementCount() > ((pow((pow(2, 8)), sizeof(int))/1000) - pow(10, 6)) )
                    {
                        double buf_x = path.currentPosition().rx(), buf_y = path.currentPosition().ry();    // to buffer

                        paint.drawPath(path);                   // Drew
                        path = QPainterPath();                  // Clear path

                        path.moveTo(buf_x, buf_y);              // We start drawing from this place
                    }

                }

                paint.drawPath(path);
                path = QPainterPath();                          // Clear path for new curve
            }
        }

        #pragma omp section
        {
            // Draw Fluid's part of model
            mode = true;                                        // serial

            for(uint j = 1; j < (selectZ-1); ++j)              // parallel
            {
                switch(j-1)
                {
                    case 0: paint.setPen(QPen(Qt::red,1.05,Qt::DotLine));
                            path1.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel+1])(0, j)))*onePixelY); break;

                    case 1: paint.setPen(QPen(Qt::green,1.05,Qt::DotLine));
                            path1.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel+1])(0, j)))*onePixelY); break;

                    case 2: paint.setPen(QPen(Qt::blue,1.05,Qt::DotLine));
                            path1.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel+1])(0, j)))*onePixelY); break;

                    default:{
                            paint.setPen(QPen(Qt::darkCyan,1.05,Qt::DotLine));
                            path1.moveTo((stepN*onePixelX)+shift, (Oy-((this->*MM[choiceModel+1])(0, j)))*onePixelY); break;
                            }
                }

                for(double i = stepN; (i <= rightX); i+=step)
                {
                    if(!isnan((this->*MM[choiceModel+1])(static_cast <unsigned long long> (i), j)))
                    {
                        if(mode)
                        {
                            path1.moveTo((i*onePixelX)+shift,(Oy-((this->*MM[choiceModel+1])(static_cast <unsigned long long> (i), j)))*onePixelY);
                            mode = false;
                        }
                        else
                            path1.lineTo((i*onePixelX)+shift,(Oy-((this->*MM[choiceModel+1])(static_cast <unsigned long long> (i), j)))*onePixelY);
                     }

                    if(path1.elementCount() > ((pow((pow(2, 8)), sizeof(int))/1000) - pow(10, 6)) )
                    {
                        double buf_x = path1.currentPosition().rx(), buf_y = path1.currentPosition().ry();

                        paint.drawPath(path1);
                        path1 = QPainterPath();

                        path1.moveTo(buf_x, buf_y);
                    }
                }

                paint.drawPath(path1);
                path1 = QPainterPath();

                path1.moveTo(stepN*onePixelX,(Oy-((this->*MM[choiceModel+1])(0, j+1)))*onePixelY);
            }

        }
    }

    paint.end();

    //----------------------------------------------------------------------

    vector<double> ProcessPoints;

    size_t tmp_var = 0;
    for(tmp_var = 0; tmp_var < (selectZ-2); ++tmp_var)
    {
        ProcessPoints.push_back((this->*MM[choiceModel])(0, tmp_var+1));
    }

    for(tmp_var = 0; tmp_var < (selectZ-2); ++tmp_var)
    {
        ProcessPoints.push_back((this->*MM[choiceModel+1])(0, tmp_var+1));
    }

    vector<double> TimePoints;                                          // 5 - it's number time points display on graph in digital form
    for (uint i = 0; i < 5; ++i)
        TimePoints.push_back( ((2*(i+1)-1)*rightX)/10.0 );           // (2*(i+1)-1) - formula odd numbers; 10.0 - it's number time points on graph

    //----------------------------------------------------------------------

    QPainter painter(graph);
    painter.setPen(QPen(Qt::black, 4, Qt::SolidLine));

    painter.drawText(QPoint(3, 13), "T,'C" );
    painter.drawText(QPoint(35, 360), "0" );
    painter.drawText(QPoint(505, 360), "t,sec" );

    tmp_var = 72;                                                       // tmp_var = 72 it's reference point
    for (size_t i = 0; i < 5; ++i, tmp_var += 102.05)
        painter.drawText(QPoint(static_cast <int> (tmp_var), 360), QString::number(TimePoints[i], 'g', 5));

    // Draw processes points
    QFont serifFont("Times", 7, QFont::Normal);
    painter.setFont(serifFont);
    for (tmp_var = 0; tmp_var < (selectZ-2); ++tmp_var)
        painter.drawText(QPoint(0, static_cast <int> ((Oy-((this->*MM[choiceModel])(0, tmp_var+1)))*onePixelY-2)), QString::number(ProcessPoints[tmp_var], 'g', 5));

    for (size_t i = tmp_var, tmp_var = 0; tmp_var < (selectZ-2); ++tmp_var, ++i)
        painter.drawText(QPoint(0, static_cast <int> ((Oy-((this->*MM[choiceModel+1])(0, tmp_var+1)))*onePixelY-2)), QString::number(ProcessPoints[i], 'g', 5));

}

void MainWindow::on_save_clicked()
{
    if(ui->Hexch->isChecked() || ui->Mexch->isChecked())
    {
        toFileMM(TV, "TV");
        toFileMM(TF, "TF");
        toFileMM(CV, "CV");
        toFileMM(CF, "CF");
    }

    if(ui->LHM->isChecked() || ui->NHM->isChecked())
    {
        toFileMM(TV, "TV");
        toFileMM(TF, "TF");
    }

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

   QMessageBox msgBox;
   msgBox.setStandardButtons(QMessageBox::Ok);

   if(ui->outputGraph->pixmap()->save(&file,"PNG"))
   {
        msgBox.setText("Saved to program folder with name: "+name+".png");
        msgBox.setWindowTitle("Saved!");
    }
    else
   {
        msgBox.setText("Error saving.");
        msgBox.setWindowTitle("Error!");
    }
    msgBox.exec();

}

void MainWindow::on_LHM_clicked()
{
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();

    ui->inputLeftY->clear();
    ui->inputRightY->clear();

    ui->inputLeftY->insert("100");
    ui->inputRightY->insert("170");

    leftY = ui->inputLeftY->text().toDouble();
    rightY = ui->inputRightY->text().toDouble();
}

void MainWindow::on_NHM_clicked()
{
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();

    ui->inputLeftY->clear();
    ui->inputRightY->clear();

    ui->inputLeftY->insert("100");
    ui->inputRightY->insert("170");

    leftY = ui->inputLeftY->text().toDouble();
    rightY = ui->inputRightY->text().toDouble();
}

void MainWindow::on_Hexch_clicked()
{
    ui->inputLeftY->clear();
    ui->inputRightY->clear();

    ui->lineEdit_3->show();
    ui->lineEdit_4->show();

    ui->inputLeftY->insert("100");
    ui->inputRightY->insert("170");

    leftY = ui->inputLeftY->text().toDouble();
    rightY = ui->inputRightY->text().toDouble();
}

void MainWindow::on_Mexch_clicked()
{
    ui->inputLeftY->clear();
    ui->inputRightY->clear();

    ui->lineEdit_3->show();
    ui->lineEdit_4->show();

    ui->inputLeftY->insert("0");
    ui->inputRightY->insert("90");

    leftY = ui->inputLeftY->text().toDouble();
    rightY = ui->inputRightY->text().toDouble();
}

//---------------------------INTERCONNECTED MODEL!!!------------------------------
void calculateMM(vector <vector <double> > &TV, vector <vector <double> > &TF,
                 vector <vector <double> > &CV, vector <vector <double> > &CF)
{
    // -----Model's heat exchenger parameters------
    double RvT = 0.0191806, RfT = 0.0000777, a0 = 0.00016966,
            PTV_L = (a0 * 273.15 * dt) / defaultH, PTV_N = 0, PTF = (0.0002291314 * dt) / defaultH;

    // -----Model's mass exchenger parameters------
    double RvM = 0.004302, RfM = 0.00001222, E = 0.000000001; //RfM = 0.000010734; RvM = 0.0216487318

    vector <double> bmp;
    bmp.assign(selectZ, 0);

    if(!TV.empty())
    {
        #pragma omp parallel for ordered num_threads(4)
        for (unsigned long long i = 0; i < selectN; ++i)
        {
            #pragma omp ordered
            TV.erase(TV.begin(), TV.end());
            TF.erase(TF.begin(), TF.end());
            CV.erase(CV.begin(), CV.end());
            CF.erase(CF.begin(), CF.end());
        }
    }

    #pragma omp parallel for ordered num_threads(4)
    for (unsigned long long i = 0; i < selectN; ++i)
    {
        #pragma omp ordered
        TV.push_back(bmp);
        TF.push_back(bmp);
        CV.push_back(bmp);
        CF.push_back(bmp);
    }

    std::thread threadInitialLayerTV(initialLayerTV, ref(TV));
    std::thread threadInitialLayerTF(initialLayerTF, ref(TF));
    std::thread threadInitialLayerCV(initialLayerCV, ref(CV));
    std::thread threadInitialLayerCF(initialLayerCF, ref(CF));

    threadInitialLayerTV.join();
    threadInitialLayerTF.join();
    threadInitialLayerCV.join();
    threadInitialLayerCF.join();

    // Calculate model
    #pragma omp parallel for ordered num_threads(4)
    for(size_t i = 1; i < selectN; ++i)   // n: t
    {
       for(size_t j = 1; j < (selectZ-1); ++j)  // i: z
       {
           #pragma omp ordered
           // -----Calculate layer heat exchenger model------
           PTV_N = (a0*TV[i-1][j+1] * dt) / defaultH;
           TV[i][j] = -TV[i-1][j] * (PTV_L - 1 - PTV_N + dt*RvT) + (PTV_L * TV[i-1][j-1]) - (PTV_N * TV[i-1][j+1])
                                                                 + (dt * RvT * TF[i-1][(selectZ-1)-j]) + P_TV;  // + perturbation of the temperature, the gas flow, the pressure differential
           TF[i][j] = -TF[i-1][j] * (PTF - 1 + dt*RfT) + (PTF * TF[i-1][j-1]) + (dt * RfT * TV[i-1][(selectZ-1)-j]) + P_TF;

           // -----Calculate layer mass exchenger model------
           CV[i][j] = -CV[i-1][j] * (PTV_L - 1 - PTV_N - dt*RvM) + (PTV_L * CV[i-1][j-1]) - (PTV_N * CV[i-1][j+1])
                                                                 - (dt * RvM * E * CF[i-1][(selectZ-1)-j]) + P_CV;
           CF[i][j] = -CF[i-1][j] * (PTF - 1 - (dt*RfM*E)) + (PTF * CF[i-1][j-1]) - (dt * RfM * CV[i-1][(selectZ-1)-j]) + P_CF;
        }
    }

}


//--------------------------LINER MODEL!!!-----------------------------------
void calculateMM(vector <vector <double> > &TV, vector <vector <double> > &TF)
{
    double  RvT = 0.0191806, RfT = 0.0000777, PTV = (0.05654433 * dt) / defaultH,
            PTF = (0.0002291314 * dt) / defaultH;

    vector <double> bmp;
    bmp.assign(selectZ, 0);

    if(!TV.empty())
    {
        #pragma omp parallel for ordered num_threads(2)
        for (unsigned long long i = 0; i < selectN; ++i)
        {
            #pragma omp ordered
            TV.erase(TV.begin(), TV.end());
            TF.erase(TF.begin(), TF.end());
        }
    }

    #pragma omp parallel for ordered num_threads(4)
    for (unsigned long long i = 0; i < selectN; ++i)
    {
        #pragma omp ordered
        TV.push_back(bmp);
        TF.push_back(bmp);
    }

    std::thread threadInitialLayerTV(initialLayerTV, ref(TV));
    std::thread threadInitialLayerTF(initialLayerTF, ref(TF));

    threadInitialLayerTV.join();
    threadInitialLayerTF.join();


    // Calculate model
    #pragma omp parallel for ordered num_threads(4)
    for(size_t i = 1; i < selectN; ++i)   // n: t
    {
       for(uint j = 1; j < (selectZ-1); ++j)  // i: z
       {
           #pragma omp ordered
           TV[i][j] = TV[i-1][j] * (-PTV + 1 - (dt * RvT)) + (PTV * TV[i-1][j-1]) + (dt * RvT * TF[i-1][(selectZ-1)-j]) + P_TV;
           TF[i][j] = TF[i-1][j] * (-PTF + 1 - (dt * RfT)) + (PTF * TF[i-1][j-1]) + (dt * RfT * TV[i-1][(selectZ-1)-j]) + P_TF;
       }
    }
}

//--------------------------NON-LINER MODEL!!!-----------------------------------
void calculateMM(vector <vector <double> > &TV, vector <vector <double> > &TF, bool turnOn) // turnOn is nonsense
{
    turnOn = ~turnOn;
    //double a0 = 0.0001152735759;  // a0-?????????True or False????

    // -----Model's heat exchenger parameters------
    double RvT = 0.0191806, RfT = 0.0000777, a0 = 0.00016966,
            PTV_L = (a0 * 273.15 * dt) / defaultH,
            PTF = (0.0002291314 * dt) / defaultH,
            PTV_2 = 0;

    vector <double> bmp;
    bmp.assign(selectZ, 0);

    if(!TV.empty())
    {
        #pragma omp parallel for ordered num_threads(2)
        for (unsigned long long i = 0; i < selectN; ++i)
        {
            #pragma omp ordered
            TV.erase(TV.begin(), TV.end());
            TF.erase(TF.begin(), TF.end());
        }
    }

    #pragma omp parallel for ordered num_threads(4)
    for (unsigned long long i = 0; i < selectN; ++i)
    {
        #pragma omp ordered
        TV.push_back(bmp);
        TF.push_back(bmp);
    }

    std::thread threadInitialLayerTV(initialLayerTV, ref(TV));
    std::thread threadInitialLayerTF(initialLayerTF, ref(TF));

    threadInitialLayerTV.join();
    threadInitialLayerTF.join();

    // Calculate model
    #pragma omp parallel for ordered num_threads(4)
    for(size_t i = 1; i < selectN; ++i)   // n: t
    {
       for(uint j = 1; j < (selectZ-1); ++j)  // i: z
       {
           #pragma omp ordered
           PTV_2 = (a0*TV[i-1][j+1] * dt)/defaultH;
           TV[i][j] = (-TV[i-1][j]) * (PTV_L - 1 - PTV_2 + (dt * RvT)) + (PTV_L * TV[i-1][j-1]) - (PTV_2 * TV[i-1][j+1]) + (dt * RvT * TF[i-1][(selectZ-1)-j]) + P_TV;
           TF[i][j] = TF[i-1][j] * ((-PTF * dt) + 1 - (dt * RfT)) + ((PTF * dt) * TF[i-1][j-1]) + (dt * RfT * TV[i-1][(selectZ-1)-j]) + P_TF;
        }
    }

}


void initialLayerTV(vector <vector <double> > &TV)
{
    double *initLayerTV = new double [selectZ];
    double stepInit = 0.0;
    size_t i = 0;

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectN; ++i)
    {
        TV[i][0] = initLayerTV_0;
        TV[i][selectZ-1] = initLayerTV_1;
    }

    stepInit = abs(initLayerTV_0 - initLayerTV_1)/(selectZ-2);

    initLayerTV[0] = initLayerTV_0;
    initLayerTV[1] = initLayerTV_0;
    initLayerTV[selectZ-1] = initLayerTV_1;

    for(i = 2; i < selectZ; ++i)
    {
        initLayerTV[i] = initLayerTV[i-1] - stepInit;
    }

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectZ; ++i)
    {
        TV[0][i] = initLayerTV[i];
        //printf("Thread %d\n", omp_get_thread_num());
    }
}

void initialLayerTF(vector <vector <double> > &TF)
{
    double *initLayerTF = new double [selectZ];
    double stepInit = 0.0;
    size_t i = 0;

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectN; ++i)
    {
        TF[i][0] = initLayerTF_0;
        TF[i][selectZ-1] = initLayerTF_1;
    }

    stepInit = abs(initLayerTF_0 - initLayerTF_1)/(selectZ-2);

    initLayerTF[0] = initLayerTF_0;
    initLayerTF[1] = initLayerTF_0;
    initLayerTF[selectZ-1] = initLayerTF_1;

    for(i = 2; i < selectZ; ++i)
    {
        initLayerTF[i] = initLayerTF[i-1] + stepInit;
    }

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectZ; ++i)
    {
        TF[0][i] = initLayerTF[i];
    }
}

void initialLayerCV(vector <vector <double> > &CV)
{
    double *initLayerCV = new double [selectZ];
    double stepInit = 0.0;
    size_t i = 0;

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectN; ++i)
    {
        CV[i][0] = initLayerCV_0;
        CV[i][selectZ-1] = initLayerCV_1;
    }

    stepInit = abs(initLayerCV_0-initLayerCV_1)/(selectZ-2);

    initLayerCV[0] = initLayerCV_0;
    initLayerCV[1] = initLayerCV_0;
    initLayerCV[selectZ-1] = initLayerCV_1;

    for(i = 2; i < selectZ; ++i)
    {
        initLayerCV[i] = initLayerCV[i-1] + stepInit;
    }

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectZ; ++i)
    {
        CV[0][i] = initLayerCV[i];
        //printf("Thread %d\n", omp_get_thread_num());
    }
}

void initialLayerCF(vector <vector <double> > &CF)
{
    double *initLayerCF = new double [selectZ];
    double stepInit = 0.0;
    size_t i = 0;

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectN; ++i)
    {
        CF[i][0] = initLayerCF_0;
        CF[i][selectZ-1] = initLayerCF_1;
    }

    stepInit = abs(initLayerCF_0-initLayerCF_1)/(selectZ-2);

    initLayerCF[0] = initLayerCF_0;
    initLayerCF[1] = initLayerCF_0;
    initLayerCF[selectZ-1] = initLayerCF_1;

    for(i = 2; i < selectZ; ++i)
    {
        initLayerCF[i] = initLayerCF[i-1] - stepInit;
    }

    #pragma omp parallel for num_threads(2)
    for(i = 0; i < selectZ; ++i)
    {
        CF[0][i] = initLayerCF[i];
    }
}

void MainWindow::toFileMM(vector <vector <double> > MMM, string nameModel)
{
    nameModel = "MM_" + nameModel + ".txt";

    ofstream foutMM(nameModel, ios_base::out | ios_base::trunc);

    for(size_t i = 0; i < selectN; i++)
    {
        for(uint j = 0; j < selectZ; j++)
        {
            foutMM << MMM[i][j] << " | ";
        }
        foutMM << endl;
    }
    foutMM.close();
}

void MainWindow::on_CouiceZspinBox_valueChanged(int valueChanged)
{
    selectZ = static_cast <unsigned int> (valueChanged + 2);
}

void MainWindow::on_lineEdit_editingFinished()
{
    P_TV = ui->lineEdit->text().toDouble();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    P_TF = ui->lineEdit_2->text().toDouble();
}

void MainWindow::on_lineEdit_3_editingFinished()
{
   P_CV = ui->lineEdit_3->text().toDouble();
}

void MainWindow::on_lineEdit_4_editingFinished()
{
    P_CF = ui->lineEdit_4->text().toDouble();
}
