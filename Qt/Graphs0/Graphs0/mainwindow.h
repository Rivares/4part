#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <vector>

using namespace std;

#define defaultN 100000     // five zeros
#define defaultZ 5
#define defaultH 0.5
#define dt 1    // dt = 3;  //dt = 1; - it's perfect!

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawGraph(bool notEmpty = 0);
    void recountPixels();
    void getData();

    double bTV(double i, short j);
    double bTF(double i, short j);
    double bCV(double i, short j);
    double bCF(double i, short j);
    
private slots:
    void on_exit_clicked();

    void on_clear_clicked();

    void on_draw_clicked();

    void on_save_clicked();

    void on_Mexch_clicked();

    void on_Hexch_clicked();

private:
    Ui::MainWindow *ui;


    // -----Model's heat exchenger parameters------
    double RvT, RfT, a0, PTV_L, PTV_N, PTF, initLayerTV[defaultZ], initLayerTF[defaultZ];

    // -----Model's mass exchenger parameters------
    double RvM, RfM, E, PCV, PCF, initLayerCV[defaultZ], initLayerCF[defaultZ];

    vector <double> bmp;
    vector <vector <double> > TV;
    vector <vector <double> > TF;
    vector <vector <double> > CV;
    vector <vector <double> > CF;

    double leftX,rightX;
    double leftY,rightY;
    int pictWidth,pictHeight;
    double step;
    double onePixelX,onePixelY;
    double Ox,Oy;
};

#endif // MAINWINDOW_H
