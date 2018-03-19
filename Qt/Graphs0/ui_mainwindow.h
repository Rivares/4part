/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_3;
    QWidget *centralWidget;
    QFrame *line;
    QLabel *label;
    QLabel *outputGraph;
    QFrame *line_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *inputLeftY;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *inputRightY;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *inputLeftX;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *inputRightX;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QSpinBox *CouiceZspinBox;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_10;
    QFormLayout *formLayout;
    QLabel *label_18;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_16;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QFrame *line_6;
    QRadioButton *LHM;
    QRadioButton *NHM;
    QRadioButton *Hexch;
    QRadioButton *Mexch;
    QFrame *line_3;
    QVBoxLayout *verticalLayout;
    QPushButton *draw;
    QPushButton *clear;
    QPushButton *save;
    QPushButton *exit;
    QLineEdit *valV1;
    QLineEdit *valV2;
    QLineEdit *valV3;
    QLineEdit *valF2;
    QLineEdit *valF1;
    QLineEdit *valF3;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(849, 532);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(550, 20, 20, 391));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(670, 0, 81, 21));
        outputGraph = new QLabel(centralWidget);
        outputGraph->setObjectName(QStringLiteral("outputGraph"));
        outputGraph->setGeometry(QRect(20, 30, 531, 371));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 400, 551, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 420, 131, 51));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(140, 420, 91, 20));
        label_12->setStyleSheet(QStringLiteral(""));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(140, 450, 111, 20));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(560, 10, 331, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(580, 30, 251, 460));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        inputLeftY = new QLineEdit(verticalLayoutWidget_2);
        inputLeftY->setObjectName(QStringLiteral("inputLeftY"));
        inputLeftY->setEnabled(true);
        inputLeftY->setMaximumSize(QSize(100, 16777215));
        inputLeftY->setReadOnly(false);

        horizontalLayout_6->addWidget(inputLeftY);


        horizontalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        inputRightY = new QLineEdit(verticalLayoutWidget_2);
        inputRightY->setObjectName(QStringLiteral("inputRightY"));
        inputRightY->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(inputRightY);


        horizontalLayout_7->addLayout(horizontalLayout_8);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7, 0, Qt::AlignLeft);


        horizontalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2, 0, Qt::AlignRight);

        inputLeftX = new QLineEdit(verticalLayoutWidget_2);
        inputLeftX->setObjectName(QStringLiteral("inputLeftX"));
        inputLeftX->setMaximumSize(QSize(100, 16777215));
        inputLeftX->setReadOnly(true);

        horizontalLayout->addWidget(inputLeftX);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3, 0, Qt::AlignLeft);

        inputRightX = new QLineEdit(verticalLayoutWidget_2);
        inputRightX->setObjectName(QStringLiteral("inputRightX"));
        inputRightX->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(inputRightX);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4, 0, Qt::AlignLeft);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(1);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetNoConstraint);
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_11->addWidget(label_9);

        CouiceZspinBox = new QSpinBox(verticalLayoutWidget_2);
        CouiceZspinBox->setObjectName(QStringLiteral("CouiceZspinBox"));
        CouiceZspinBox->setMaximumSize(QSize(100, 16777215));
        CouiceZspinBox->setAcceptDrops(false);
        CouiceZspinBox->setValue(3);

        horizontalLayout_11->addWidget(CouiceZspinBox);


        verticalLayout_4->addLayout(horizontalLayout_11);

        line_5 = new QFrame(verticalLayoutWidget_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(105, 16777215));

        verticalLayout_5->addWidget(label_10);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_18 = new QLabel(verticalLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(140, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_18);

        label_15 = new QLabel(verticalLayoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(140, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_15);

        label_17 = new QLabel(verticalLayoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(120, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_17);

        label_16 = new QLabel(verticalLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(140, 16777215));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_16);

        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);


        verticalLayout_5->addLayout(formLayout);


        verticalLayout_2->addLayout(verticalLayout_5);

        line_6 = new QFrame(verticalLayoutWidget_2);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_6);

        LHM = new QRadioButton(verticalLayoutWidget_2);
        LHM->setObjectName(QStringLiteral("LHM"));

        verticalLayout_2->addWidget(LHM);

        NHM = new QRadioButton(verticalLayoutWidget_2);
        NHM->setObjectName(QStringLiteral("NHM"));

        verticalLayout_2->addWidget(NHM);

        Hexch = new QRadioButton(verticalLayoutWidget_2);
        Hexch->setObjectName(QStringLiteral("Hexch"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Hexch->sizePolicy().hasHeightForWidth());
        Hexch->setSizePolicy(sizePolicy);
        Hexch->setMinimumSize(QSize(55, 20));
        Hexch->setMaximumSize(QSize(300, 22));
        QFont font;
        font.setItalic(false);
        font.setUnderline(false);
        font.setKerning(true);
        Hexch->setFont(font);
        Hexch->setChecked(false);
        Hexch->setAutoRepeat(false);

        verticalLayout_2->addWidget(Hexch);

        Mexch = new QRadioButton(verticalLayoutWidget_2);
        Mexch->setObjectName(QStringLiteral("Mexch"));
        Mexch->setMaximumSize(QSize(300, 16777215));

        verticalLayout_2->addWidget(Mexch);


        verticalLayout_4->addLayout(verticalLayout_2);

        line_3 = new QFrame(verticalLayoutWidget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        draw = new QPushButton(verticalLayoutWidget_2);
        draw->setObjectName(QStringLiteral("draw"));

        verticalLayout->addWidget(draw);

        clear = new QPushButton(verticalLayoutWidget_2);
        clear->setObjectName(QStringLiteral("clear"));

        verticalLayout->addWidget(clear);

        save = new QPushButton(verticalLayoutWidget_2);
        save->setObjectName(QStringLiteral("save"));

        verticalLayout->addWidget(save);

        exit = new QPushButton(verticalLayoutWidget_2);
        exit->setObjectName(QStringLiteral("exit"));

        verticalLayout->addWidget(exit);


        verticalLayout_4->addLayout(verticalLayout);

        valV1 = new QLineEdit(centralWidget);
        valV1->setObjectName(QStringLiteral("valV1"));
        valV1->setGeometry(QRect(260, 420, 61, 20));
        valV1->setMaximumSize(QSize(100, 16777215));
        valV1->setReadOnly(true);
        valV2 = new QLineEdit(centralWidget);
        valV2->setObjectName(QStringLiteral("valV2"));
        valV2->setGeometry(QRect(350, 420, 61, 20));
        valV2->setMaximumSize(QSize(100, 16777215));
        valV2->setReadOnly(true);
        valV3 = new QLineEdit(centralWidget);
        valV3->setObjectName(QStringLiteral("valV3"));
        valV3->setGeometry(QRect(440, 420, 61, 20));
        valV3->setMaximumSize(QSize(100, 16777215));
        valV3->setReadOnly(true);
        valF2 = new QLineEdit(centralWidget);
        valF2->setObjectName(QStringLiteral("valF2"));
        valF2->setGeometry(QRect(350, 450, 61, 20));
        valF2->setMaximumSize(QSize(100, 16777215));
        valF2->setReadOnly(true);
        valF1 = new QLineEdit(centralWidget);
        valF1->setObjectName(QStringLiteral("valF1"));
        valF1->setGeometry(QRect(260, 450, 61, 20));
        valF1->setMaximumSize(QSize(100, 16777215));
        valF1->setReadOnly(true);
        valF3 = new QLineEdit(centralWidget);
        valF3->setObjectName(QStringLiteral("valF3"));
        valF3->setGeometry(QRect(440, 450, 61, 20));
        valF3->setMaximumSize(QSize(100, 16777215));
        valF3->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 849, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addSeparator();
        menu->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "The Study Of Technological Processes", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Simulation Program</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        action->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260:</span></p></body></html>", 0));
        outputGraph->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\320\262\321\210\320\270\320\265\321\201\321\217</span></p><p align=\"center\"><span style=\" font-size:9pt; font-weight:600;\">\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217:</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; color:#299d32;\">\320\237\320\260\321\200\320\276\320\262\320\260\321\217 \321\204\320\260\320\267\320\260:</span></p></body></html>", 0));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; color:#2677cd;\">\320\226\320\270\320\264\320\272\320\276\321\201\321\202\320\275\320\260\321\217 \321\204\320\260\320\267\320\260:</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("MainWindow", "T, 'C \320\270\320\273\320\270 \320\241, % = [", 0));
        inputLeftY->setText(QApplication::translate("MainWindow", "100", 0));
        label_6->setText(QApplication::translate("MainWindow", ",", 0));
        inputRightY->setText(QApplication::translate("MainWindow", "180", 0));
        label_7->setText(QApplication::translate("MainWindow", "]", 0));
        label_2->setText(QApplication::translate("MainWindow", "t = [", 0));
        inputLeftX->setText(QApplication::translate("MainWindow", "0", 0));
        label_3->setText(QApplication::translate("MainWindow", ",", 0));
        inputRightX->setText(QApplication::translate("MainWindow", "1000", 0));
        label_4->setText(QApplication::translate("MainWindow", "]", 0));
        label_9->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273. \320\277\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\265\320\275.\320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\321\205: Z   =", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">\320\222\320\276\320\267\320\274\321\203\321\211\320\265\320\275\320\270\320\265 \320\277\320\276:</span></p></body></html>", 0));
        label_18->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\265 \320\277\320\260\321\200\320\260 ->", 0));
        label_15->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\265 \320\266\320\270\320\264\320\272\320\276\321\201\321\202\320\270 ->", 0));
        label_17->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\206\320\265\320\275\321\202\321\200\320\260\321\206\320\270\320\270 \320\277\320\260\321\200\320\260 ->", 0));
        label_16->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\206\320\265\320\275\321\202\321\200\320\260\321\206\320\270\320\270 \320\266\320\270\320\264\320\272\320\276\321\201\321\202\320\270 ->", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "0.0", 0));
        lineEdit_2->setText(QApplication::translate("MainWindow", "0.0", 0));
        lineEdit_3->setText(QApplication::translate("MainWindow", "0.0", 0));
        lineEdit_4->setText(QApplication::translate("MainWindow", "0.0", 0));
        LHM->setText(QApplication::translate("MainWindow", "\320\233\320\270\320\275\320\265\320\271\320\275\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\276\320\261\320\274\320\265\320\275\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
        NHM->setText(QApplication::translate("MainWindow", "\320\235\320\265\320\273\320\270\320\275\320\265\320\271\320\275\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\276\320\261\320\274\320\265\320\275\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
        Hexch->setText(QApplication::translate("MainWindow", "\320\222\320\267\320\260\320\270\320\274\320\276\321\201\320\262\321\217\320\267\320\260\320\275\320\275\320\260\321\217 \321\202\320\265\320\277\320\273\320\276\320\276\320\261\320\274\320\265\320\275\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
        Mexch->setText(QApplication::translate("MainWindow", "\320\222\320\267\320\260\320\270\320\274\320\276\321\201\320\262\321\217\320\267\320\260\320\275\320\275\320\260\321\217 \320\274\320\260\321\201\321\201\320\276\320\276\320\261\320\274\320\265\320\275\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
        draw->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272\320\270", 0));
        clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\274\320\276\320\275\320\270\321\202\320\276\321\200", 0));
        save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", 0));
        valV1->setText(QApplication::translate("MainWindow", "0.0", 0));
        valV2->setText(QApplication::translate("MainWindow", "0.0", 0));
        valV3->setText(QApplication::translate("MainWindow", "0.0", 0));
        valF2->setText(QApplication::translate("MainWindow", "0.0", 0));
        valF1->setText(QApplication::translate("MainWindow", "0.0", 0));
        valF3->setText(QApplication::translate("MainWindow", "0.0", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
