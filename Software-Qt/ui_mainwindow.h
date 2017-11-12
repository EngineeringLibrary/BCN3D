/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_4;
    QTabWidget *result;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_IP;
    QLineEdit *lineEdit_IP;
    QLabel *label_Port;
    QLineEdit *lineEdit_Port;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonConnect;
    QPushButton *pushButton_Disconnect;
    QLineEdit *lineEdit;
    QWidget *widget;
    QLabel *label_SliderEsq;
    QLabel *label_SliderDir;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *webcam;
    QCheckBox *check_saved_img;
    QPushButton *pushButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *ANTES_GERAL;
    QLabel *texto_antes;
    QLabel *label_before;
    QVBoxLayout *DEPOIS_GERAL;
    QLabel *texto_depois;
    QHBoxLayout *horizontalLayout_IMG;
    QLabel *label_after_blue;
    QLabel *label_after_red;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_blueGeral;
    QLabel *texto_depoisBlue;
    QComboBox *select_blue;
    QHBoxLayout *horizontalLayout_BLUE_0;
    QLineEdit *filter_blue;
    QLabel *label_blue_filter;
    QHBoxLayout *horizontalLayout_BLUE;
    QLineEdit *line_blue;
    QLabel *label_blue_linear;
    QVBoxLayout *verticalLayout_redGeral;
    QLabel *texto_depoisRED;
    QComboBox *select_red;
    QHBoxLayout *horizontalLayout_RED;
    QLineEdit *filter_red;
    QLabel *label_red_filter;
    QHBoxLayout *horizontalLayout_RED_0;
    QLineEdit *line_red;
    QLabel *label_red_linear;
    QWidget *buttons;
    QGridLayout *gridLayout_5;
    QVBoxLayout *coluna_Red;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_red_filter_0;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *filter_red_0;
    QComboBox *select_red_0;
    QPushButton *button_red_0;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_red_filter_1;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *filter_red_1;
    QComboBox *select_red_1;
    QPushButton *button_red_1;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_red_filter_2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *filter_red_2;
    QComboBox *select_red_2;
    QPushButton *button_red_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_red_filter_3;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *filter_red_3;
    QComboBox *select_red_3;
    QPushButton *button_red_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_red_filter_4;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *filter_red_4;
    QComboBox *select_red_4;
    QPushButton *button_red_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_red_filter_5;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *filter_red_5;
    QComboBox *select_red_5;
    QPushButton *button_red_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QVBoxLayout *coluna_Blue;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_blue_filter_0;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *filter_blue_0;
    QComboBox *select_blue_0;
    QPushButton *button_blue_0;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_blue_filter_1;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *filter_blue_1;
    QComboBox *select_blue_1;
    QPushButton *button_blue_1;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_blue_filter_2;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *filter_blue_2;
    QComboBox *select_blue_2;
    QPushButton *button_blue_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_blue_filter_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *filter_blue_3;
    QComboBox *select_blue_3;
    QPushButton *button_blue_3;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_blue_filter_4;
    QHBoxLayout *horizontalLayout_15;
    QLineEdit *filter_blue_4;
    QComboBox *select_blue_4;
    QPushButton *button_blue_4;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_blue_filter_5;
    QHBoxLayout *horizontalLayout_16;
    QLineEdit *filter_blue_5;
    QComboBox *select_blue_5;
    QPushButton *button_blue_5;
    QPushButton *refresh;
    QPushButton *set_saved_img_0;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1258, 653);
        MainWindow->setToolTipDuration(1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_7 = new QGridLayout(centralWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1224, 750));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(10);
        gridLayout_8->setContentsMargins(5, 5, 5, 5);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        result = new QTabWidget(scrollAreaWidgetContents);
        result->setObjectName(QStringLiteral("result"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(result->sizePolicy().hasHeightForWidth());
        result->setSizePolicy(sizePolicy);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_IP = new QLabel(tab_3);
        label_IP->setObjectName(QStringLiteral("label_IP"));

        horizontalLayout->addWidget(label_IP);

        lineEdit_IP = new QLineEdit(tab_3);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));

        horizontalLayout->addWidget(lineEdit_IP);

        label_Port = new QLabel(tab_3);
        label_Port->setObjectName(QStringLiteral("label_Port"));

        horizontalLayout->addWidget(label_Port);

        lineEdit_Port = new QLineEdit(tab_3);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));

        horizontalLayout->addWidget(lineEdit_Port);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonConnect = new QPushButton(tab_3);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));

        horizontalLayout_3->addWidget(pushButtonConnect);

        pushButton_Disconnect = new QPushButton(tab_3);
        pushButton_Disconnect->setObjectName(QStringLiteral("pushButton_Disconnect"));

        horizontalLayout_3->addWidget(pushButton_Disconnect);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout_6->addLayout(verticalLayout_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_6->addWidget(lineEdit, 1, 0, 1, 1);

        widget = new QWidget(tab_3);
        widget->setObjectName(QStringLiteral("widget"));
        label_SliderEsq = new QLabel(widget);
        label_SliderEsq->setObjectName(QStringLiteral("label_SliderEsq"));
        label_SliderEsq->setGeometry(QRect(50, 240, 47, 13));
        label_SliderDir = new QLabel(widget);
        label_SliderDir->setObjectName(QStringLiteral("label_SliderDir"));
        label_SliderDir->setGeometry(QRect(320, 240, 47, 13));

        gridLayout_6->addWidget(widget, 2, 0, 1, 1);

        result->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        webcam = new QWidget(tab);
        webcam->setObjectName(QStringLiteral("webcam"));
        sizePolicy1.setHeightForWidth(webcam->sizePolicy().hasHeightForWidth());
        webcam->setSizePolicy(sizePolicy1);
        webcam->setMaximumSize(QSize(1280, 720));
        QFont font;
        font.setKerning(true);
        webcam->setFont(font);
        webcam->setMouseTracking(false);
        webcam->setLayoutDirection(Qt::LeftToRight);
        webcam->setStyleSheet(QStringLiteral("background-color: rgb(186, 189, 182);"));

        verticalLayout->addWidget(webcam);

        check_saved_img = new QCheckBox(tab);
        check_saved_img->setObjectName(QStringLiteral("check_saved_img"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(check_saved_img->sizePolicy().hasHeightForWidth());
        check_saved_img->setSizePolicy(sizePolicy2);
        check_saved_img->setSizeIncrement(QSize(0, 0));
        check_saved_img->setFocusPolicy(Qt::WheelFocus);
        check_saved_img->setLayoutDirection(Qt::LeftToRight);
        check_saved_img->setAutoFillBackground(false);
        check_saved_img->setText(QStringLiteral("USAR  IMAGEM SALVA"));
        check_saved_img->setTristate(false);

        verticalLayout->addWidget(check_saved_img);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        result->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        ANTES_GERAL = new QVBoxLayout();
        ANTES_GERAL->setSpacing(6);
        ANTES_GERAL->setObjectName(QStringLiteral("ANTES_GERAL"));
        texto_antes = new QLabel(tab_2);
        texto_antes->setObjectName(QStringLiteral("texto_antes"));
        texto_antes->setMaximumSize(QSize(16777215, 20));
        texto_antes->setAlignment(Qt::AlignCenter);

        ANTES_GERAL->addWidget(texto_antes);

        label_before = new QLabel(tab_2);
        label_before->setObjectName(QStringLiteral("label_before"));
        label_before->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        ANTES_GERAL->addWidget(label_before);


        verticalLayout_16->addLayout(ANTES_GERAL);

        DEPOIS_GERAL = new QVBoxLayout();
        DEPOIS_GERAL->setSpacing(6);
        DEPOIS_GERAL->setObjectName(QStringLiteral("DEPOIS_GERAL"));
        texto_depois = new QLabel(tab_2);
        texto_depois->setObjectName(QStringLiteral("texto_depois"));
        texto_depois->setMaximumSize(QSize(16777215, 20));
        texto_depois->setAlignment(Qt::AlignCenter);

        DEPOIS_GERAL->addWidget(texto_depois);

        horizontalLayout_IMG = new QHBoxLayout();
        horizontalLayout_IMG->setSpacing(6);
        horizontalLayout_IMG->setObjectName(QStringLiteral("horizontalLayout_IMG"));
        label_after_blue = new QLabel(tab_2);
        label_after_blue->setObjectName(QStringLiteral("label_after_blue"));
        label_after_blue->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        horizontalLayout_IMG->addWidget(label_after_blue);

        label_after_red = new QLabel(tab_2);
        label_after_red->setObjectName(QStringLiteral("label_after_red"));
        label_after_red->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        horizontalLayout_IMG->addWidget(label_after_red);


        DEPOIS_GERAL->addLayout(horizontalLayout_IMG);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_blueGeral = new QVBoxLayout();
        verticalLayout_blueGeral->setSpacing(6);
        verticalLayout_blueGeral->setObjectName(QStringLiteral("verticalLayout_blueGeral"));
        texto_depoisBlue = new QLabel(tab_2);
        texto_depoisBlue->setObjectName(QStringLiteral("texto_depoisBlue"));
        texto_depoisBlue->setMaximumSize(QSize(16777215, 20));
        texto_depoisBlue->setAlignment(Qt::AlignCenter);

        verticalLayout_blueGeral->addWidget(texto_depoisBlue);

        select_blue = new QComboBox(tab_2);
        select_blue->setObjectName(QStringLiteral("select_blue"));

        verticalLayout_blueGeral->addWidget(select_blue);

        horizontalLayout_BLUE_0 = new QHBoxLayout();
        horizontalLayout_BLUE_0->setSpacing(6);
        horizontalLayout_BLUE_0->setObjectName(QStringLiteral("horizontalLayout_BLUE_0"));
        filter_blue = new QLineEdit(tab_2);
        filter_blue->setObjectName(QStringLiteral("filter_blue"));

        horizontalLayout_BLUE_0->addWidget(filter_blue);

        label_blue_filter = new QLabel(tab_2);
        label_blue_filter->setObjectName(QStringLiteral("label_blue_filter"));
        label_blue_filter->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_BLUE_0->addWidget(label_blue_filter);


        verticalLayout_blueGeral->addLayout(horizontalLayout_BLUE_0);

        horizontalLayout_BLUE = new QHBoxLayout();
        horizontalLayout_BLUE->setSpacing(6);
        horizontalLayout_BLUE->setObjectName(QStringLiteral("horizontalLayout_BLUE"));
        line_blue = new QLineEdit(tab_2);
        line_blue->setObjectName(QStringLiteral("line_blue"));

        horizontalLayout_BLUE->addWidget(line_blue);

        label_blue_linear = new QLabel(tab_2);
        label_blue_linear->setObjectName(QStringLiteral("label_blue_linear"));
        label_blue_linear->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_BLUE->addWidget(label_blue_linear);


        verticalLayout_blueGeral->addLayout(horizontalLayout_BLUE);


        horizontalLayout_2->addLayout(verticalLayout_blueGeral);

        verticalLayout_redGeral = new QVBoxLayout();
        verticalLayout_redGeral->setSpacing(6);
        verticalLayout_redGeral->setObjectName(QStringLiteral("verticalLayout_redGeral"));
        texto_depoisRED = new QLabel(tab_2);
        texto_depoisRED->setObjectName(QStringLiteral("texto_depoisRED"));
        texto_depoisRED->setMaximumSize(QSize(16777215, 20));
        texto_depoisRED->setAlignment(Qt::AlignCenter);

        verticalLayout_redGeral->addWidget(texto_depoisRED);

        select_red = new QComboBox(tab_2);
        select_red->setObjectName(QStringLiteral("select_red"));

        verticalLayout_redGeral->addWidget(select_red);

        horizontalLayout_RED = new QHBoxLayout();
        horizontalLayout_RED->setSpacing(6);
        horizontalLayout_RED->setObjectName(QStringLiteral("horizontalLayout_RED"));
        filter_red = new QLineEdit(tab_2);
        filter_red->setObjectName(QStringLiteral("filter_red"));

        horizontalLayout_RED->addWidget(filter_red);

        label_red_filter = new QLabel(tab_2);
        label_red_filter->setObjectName(QStringLiteral("label_red_filter"));

        horizontalLayout_RED->addWidget(label_red_filter);


        verticalLayout_redGeral->addLayout(horizontalLayout_RED);

        horizontalLayout_RED_0 = new QHBoxLayout();
        horizontalLayout_RED_0->setSpacing(6);
        horizontalLayout_RED_0->setObjectName(QStringLiteral("horizontalLayout_RED_0"));
        line_red = new QLineEdit(tab_2);
        line_red->setObjectName(QStringLiteral("line_red"));

        horizontalLayout_RED_0->addWidget(line_red);

        label_red_linear = new QLabel(tab_2);
        label_red_linear->setObjectName(QStringLiteral("label_red_linear"));

        horizontalLayout_RED_0->addWidget(label_red_linear);


        verticalLayout_redGeral->addLayout(horizontalLayout_RED_0);


        horizontalLayout_2->addLayout(verticalLayout_redGeral);


        DEPOIS_GERAL->addLayout(horizontalLayout_2);


        verticalLayout_16->addLayout(DEPOIS_GERAL);


        gridLayout_3->addLayout(verticalLayout_16, 0, 0, 1, 1);

        result->addTab(tab_2, QString());
        buttons = new QWidget();
        buttons->setObjectName(QStringLiteral("buttons"));
        gridLayout_5 = new QGridLayout(buttons);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        coluna_Red = new QVBoxLayout();
        coluna_Red->setSpacing(6);
        coluna_Red->setObjectName(QStringLiteral("coluna_Red"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_red_filter_0 = new QLabel(buttons);
        label_red_filter_0->setObjectName(QStringLiteral("label_red_filter_0"));
        label_red_filter_0->setMaximumSize(QSize(16777215, 30));

        verticalLayout_4->addWidget(label_red_filter_0);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        filter_red_0 = new QLineEdit(buttons);
        filter_red_0->setObjectName(QStringLiteral("filter_red_0"));
        filter_red_0->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(filter_red_0);

        select_red_0 = new QComboBox(buttons);
        select_red_0->setObjectName(QStringLiteral("select_red_0"));

        horizontalLayout_5->addWidget(select_red_0);


        verticalLayout_4->addLayout(horizontalLayout_5);

        button_red_0 = new QPushButton(buttons);
        button_red_0->setObjectName(QStringLiteral("button_red_0"));

        verticalLayout_4->addWidget(button_red_0);


        coluna_Red->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_red_filter_1 = new QLabel(buttons);
        label_red_filter_1->setObjectName(QStringLiteral("label_red_filter_1"));
        label_red_filter_1->setMaximumSize(QSize(16777215, 30));

        verticalLayout_6->addWidget(label_red_filter_1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        filter_red_1 = new QLineEdit(buttons);
        filter_red_1->setObjectName(QStringLiteral("filter_red_1"));
        filter_red_1->setMinimumSize(QSize(0, 0));
        filter_red_1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(filter_red_1);

        select_red_1 = new QComboBox(buttons);
        select_red_1->setObjectName(QStringLiteral("select_red_1"));

        horizontalLayout_7->addWidget(select_red_1);


        verticalLayout_6->addLayout(horizontalLayout_7);

        button_red_1 = new QPushButton(buttons);
        button_red_1->setObjectName(QStringLiteral("button_red_1"));

        verticalLayout_6->addWidget(button_red_1);


        coluna_Red->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_red_filter_2 = new QLabel(buttons);
        label_red_filter_2->setObjectName(QStringLiteral("label_red_filter_2"));
        label_red_filter_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout_7->addWidget(label_red_filter_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        filter_red_2 = new QLineEdit(buttons);
        filter_red_2->setObjectName(QStringLiteral("filter_red_2"));

        horizontalLayout_8->addWidget(filter_red_2);

        select_red_2 = new QComboBox(buttons);
        select_red_2->setObjectName(QStringLiteral("select_red_2"));

        horizontalLayout_8->addWidget(select_red_2);


        verticalLayout_7->addLayout(horizontalLayout_8);

        button_red_2 = new QPushButton(buttons);
        button_red_2->setObjectName(QStringLiteral("button_red_2"));

        verticalLayout_7->addWidget(button_red_2);


        coluna_Red->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_red_filter_3 = new QLabel(buttons);
        label_red_filter_3->setObjectName(QStringLiteral("label_red_filter_3"));
        label_red_filter_3->setMaximumSize(QSize(16777215, 30));

        verticalLayout_8->addWidget(label_red_filter_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        filter_red_3 = new QLineEdit(buttons);
        filter_red_3->setObjectName(QStringLiteral("filter_red_3"));

        horizontalLayout_9->addWidget(filter_red_3);

        select_red_3 = new QComboBox(buttons);
        select_red_3->setObjectName(QStringLiteral("select_red_3"));

        horizontalLayout_9->addWidget(select_red_3);


        verticalLayout_8->addLayout(horizontalLayout_9);

        button_red_3 = new QPushButton(buttons);
        button_red_3->setObjectName(QStringLiteral("button_red_3"));

        verticalLayout_8->addWidget(button_red_3);


        coluna_Red->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_red_filter_4 = new QLabel(buttons);
        label_red_filter_4->setObjectName(QStringLiteral("label_red_filter_4"));
        label_red_filter_4->setMaximumSize(QSize(16777215, 30));

        verticalLayout_9->addWidget(label_red_filter_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        filter_red_4 = new QLineEdit(buttons);
        filter_red_4->setObjectName(QStringLiteral("filter_red_4"));

        horizontalLayout_10->addWidget(filter_red_4);

        select_red_4 = new QComboBox(buttons);
        select_red_4->setObjectName(QStringLiteral("select_red_4"));

        horizontalLayout_10->addWidget(select_red_4);


        verticalLayout_9->addLayout(horizontalLayout_10);

        button_red_4 = new QPushButton(buttons);
        button_red_4->setObjectName(QStringLiteral("button_red_4"));

        verticalLayout_9->addWidget(button_red_4);


        coluna_Red->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_red_filter_5 = new QLabel(buttons);
        label_red_filter_5->setObjectName(QStringLiteral("label_red_filter_5"));
        label_red_filter_5->setMaximumSize(QSize(16777215, 30));

        verticalLayout_10->addWidget(label_red_filter_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        filter_red_5 = new QLineEdit(buttons);
        filter_red_5->setObjectName(QStringLiteral("filter_red_5"));

        horizontalLayout_11->addWidget(filter_red_5);

        select_red_5 = new QComboBox(buttons);
        select_red_5->setObjectName(QStringLiteral("select_red_5"));

        horizontalLayout_11->addWidget(select_red_5);


        verticalLayout_10->addLayout(horizontalLayout_11);

        button_red_5 = new QPushButton(buttons);
        button_red_5->setObjectName(QStringLiteral("button_red_5"));

        verticalLayout_10->addWidget(button_red_5);


        coluna_Red->addLayout(verticalLayout_10);


        gridLayout_5->addLayout(coluna_Red, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(buttons);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 20));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        label_3 = new QLabel(buttons);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);


        gridLayout_5->addLayout(horizontalLayout_4, 0, 0, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        coluna_Blue = new QVBoxLayout();
        coluna_Blue->setSpacing(6);
        coluna_Blue->setObjectName(QStringLiteral("coluna_Blue"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_blue_filter_0 = new QLabel(buttons);
        label_blue_filter_0->setObjectName(QStringLiteral("label_blue_filter_0"));
        label_blue_filter_0->setMaximumSize(QSize(16777215, 30));

        verticalLayout_11->addWidget(label_blue_filter_0);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        filter_blue_0 = new QLineEdit(buttons);
        filter_blue_0->setObjectName(QStringLiteral("filter_blue_0"));
        filter_blue_0->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_12->addWidget(filter_blue_0);

        select_blue_0 = new QComboBox(buttons);
        select_blue_0->setObjectName(QStringLiteral("select_blue_0"));

        horizontalLayout_12->addWidget(select_blue_0);


        verticalLayout_11->addLayout(horizontalLayout_12);

        button_blue_0 = new QPushButton(buttons);
        button_blue_0->setObjectName(QStringLiteral("button_blue_0"));

        verticalLayout_11->addWidget(button_blue_0);


        coluna_Blue->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_blue_filter_1 = new QLabel(buttons);
        label_blue_filter_1->setObjectName(QStringLiteral("label_blue_filter_1"));
        label_blue_filter_1->setMaximumSize(QSize(16777215, 30));

        verticalLayout_12->addWidget(label_blue_filter_1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        filter_blue_1 = new QLineEdit(buttons);
        filter_blue_1->setObjectName(QStringLiteral("filter_blue_1"));
        filter_blue_1->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(filter_blue_1);

        select_blue_1 = new QComboBox(buttons);
        select_blue_1->setObjectName(QStringLiteral("select_blue_1"));

        horizontalLayout_13->addWidget(select_blue_1);


        verticalLayout_12->addLayout(horizontalLayout_13);

        button_blue_1 = new QPushButton(buttons);
        button_blue_1->setObjectName(QStringLiteral("button_blue_1"));

        verticalLayout_12->addWidget(button_blue_1);


        coluna_Blue->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_blue_filter_2 = new QLabel(buttons);
        label_blue_filter_2->setObjectName(QStringLiteral("label_blue_filter_2"));
        label_blue_filter_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout_13->addWidget(label_blue_filter_2);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        filter_blue_2 = new QLineEdit(buttons);
        filter_blue_2->setObjectName(QStringLiteral("filter_blue_2"));

        horizontalLayout_14->addWidget(filter_blue_2);

        select_blue_2 = new QComboBox(buttons);
        select_blue_2->setObjectName(QStringLiteral("select_blue_2"));

        horizontalLayout_14->addWidget(select_blue_2);


        verticalLayout_13->addLayout(horizontalLayout_14);

        button_blue_2 = new QPushButton(buttons);
        button_blue_2->setObjectName(QStringLiteral("button_blue_2"));

        verticalLayout_13->addWidget(button_blue_2);


        coluna_Blue->addLayout(verticalLayout_13);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_blue_filter_3 = new QLabel(buttons);
        label_blue_filter_3->setObjectName(QStringLiteral("label_blue_filter_3"));

        verticalLayout_5->addWidget(label_blue_filter_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        filter_blue_3 = new QLineEdit(buttons);
        filter_blue_3->setObjectName(QStringLiteral("filter_blue_3"));

        horizontalLayout_6->addWidget(filter_blue_3);

        select_blue_3 = new QComboBox(buttons);
        select_blue_3->setObjectName(QStringLiteral("select_blue_3"));

        horizontalLayout_6->addWidget(select_blue_3);


        verticalLayout_5->addLayout(horizontalLayout_6);

        button_blue_3 = new QPushButton(buttons);
        button_blue_3->setObjectName(QStringLiteral("button_blue_3"));

        verticalLayout_5->addWidget(button_blue_3);


        coluna_Blue->addLayout(verticalLayout_5);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_blue_filter_4 = new QLabel(buttons);
        label_blue_filter_4->setObjectName(QStringLiteral("label_blue_filter_4"));
        label_blue_filter_4->setMaximumSize(QSize(16777215, 30));

        verticalLayout_14->addWidget(label_blue_filter_4);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        filter_blue_4 = new QLineEdit(buttons);
        filter_blue_4->setObjectName(QStringLiteral("filter_blue_4"));

        horizontalLayout_15->addWidget(filter_blue_4);

        select_blue_4 = new QComboBox(buttons);
        select_blue_4->setObjectName(QStringLiteral("select_blue_4"));

        horizontalLayout_15->addWidget(select_blue_4);


        verticalLayout_14->addLayout(horizontalLayout_15);

        button_blue_4 = new QPushButton(buttons);
        button_blue_4->setObjectName(QStringLiteral("button_blue_4"));

        verticalLayout_14->addWidget(button_blue_4);


        coluna_Blue->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_blue_filter_5 = new QLabel(buttons);
        label_blue_filter_5->setObjectName(QStringLiteral("label_blue_filter_5"));
        label_blue_filter_5->setMaximumSize(QSize(16777215, 30));

        verticalLayout_15->addWidget(label_blue_filter_5);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        filter_blue_5 = new QLineEdit(buttons);
        filter_blue_5->setObjectName(QStringLiteral("filter_blue_5"));

        horizontalLayout_16->addWidget(filter_blue_5);

        select_blue_5 = new QComboBox(buttons);
        select_blue_5->setObjectName(QStringLiteral("select_blue_5"));

        horizontalLayout_16->addWidget(select_blue_5);


        verticalLayout_15->addLayout(horizontalLayout_16);

        button_blue_5 = new QPushButton(buttons);
        button_blue_5->setObjectName(QStringLiteral("button_blue_5"));

        verticalLayout_15->addWidget(button_blue_5);


        coluna_Blue->addLayout(verticalLayout_15);


        gridLayout->addLayout(coluna_Blue, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 1, 0, 1, 1);

        result->addTab(buttons, QString());

        gridLayout_4->addWidget(result, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 0, 0, 1, 1);

        refresh = new QPushButton(scrollAreaWidgetContents);
        refresh->setObjectName(QStringLiteral("refresh"));
        sizePolicy1.setHeightForWidth(refresh->sizePolicy().hasHeightForWidth());
        refresh->setSizePolicy(sizePolicy1);
        refresh->setMinimumSize(QSize(0, 30));
        refresh->setMaximumSize(QSize(16777215, 60));
        refresh->setAutoDefault(false);
        refresh->setFlat(false);

        gridLayout_8->addWidget(refresh, 2, 0, 1, 1);

        set_saved_img_0 = new QPushButton(scrollAreaWidgetContents);
        set_saved_img_0->setObjectName(QStringLiteral("set_saved_img_0"));

        gridLayout_8->addWidget(set_saved_img_0, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_7->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        result->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BCN3D v1.0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_IP->setText(QApplication::translate("MainWindow", "IP:", Q_NULLPTR));
        label_Port->setText(QApplication::translate("MainWindow", "Porta:", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Conectar", Q_NULLPTR));
        pushButton_Disconnect->setText(QApplication::translate("MainWindow", "Desconectar", Q_NULLPTR));
        label_SliderEsq->setText(QString());
        label_SliderDir->setText(QString());
        result->setTabText(result->indexOf(tab_3), QApplication::translate("MainWindow", "Conex\303\243o", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "TIRAR FOTO", Q_NULLPTR));
        result->setTabText(result->indexOf(tab), QApplication::translate("MainWindow", "capture", Q_NULLPTR));
        texto_antes->setText(QApplication::translate("MainWindow", "ANTES DO PROCESSAMENTO", Q_NULLPTR));
        label_before->setText(QString());
        texto_depois->setText(QApplication::translate("MainWindow", "DEPOIS DO PROCESSAMENTO", Q_NULLPTR));
        label_after_blue->setText(QString());
        label_after_red->setText(QString());
        texto_depoisBlue->setText(QApplication::translate("MainWindow", "BLUE", Q_NULLPTR));
        select_blue->clear();
        select_blue->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escala de cinza", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filtro mediano", Q_NULLPTR)
         << QApplication::translate("MainWindow", "dilata\303\247\303\243o", Q_NULLPTR)
         << QApplication::translate("MainWindow", "erosao", Q_NULLPTR)
         << QApplication::translate("MainWindow", "bound", Q_NULLPTR)
        );
        filter_blue->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        label_blue_filter->setText(QApplication::translate("MainWindow", "filter value", Q_NULLPTR));
        line_blue->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        label_blue_linear->setText(QApplication::translate("MainWindow", "linear value", Q_NULLPTR));
        texto_depoisRED->setText(QApplication::translate("MainWindow", "RED", Q_NULLPTR));
        select_red->clear();
        select_red->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escala de cinza", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filtro mediano", Q_NULLPTR)
         << QApplication::translate("MainWindow", "dilata\303\247\303\243o", Q_NULLPTR)
         << QApplication::translate("MainWindow", "erosao", Q_NULLPTR)
         << QApplication::translate("MainWindow", "bound", Q_NULLPTR)
        );
        filter_red->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        label_red_filter->setText(QApplication::translate("MainWindow", "filter value", Q_NULLPTR));
        line_red->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        label_red_linear->setText(QApplication::translate("MainWindow", "linear value", Q_NULLPTR));
        result->setTabText(result->indexOf(tab_2), QApplication::translate("MainWindow", "result", Q_NULLPTR));
        label_red_filter_0->setText(QApplication::translate("MainWindow", "value                  filter ", Q_NULLPTR));
        filter_red_0->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        select_red_0->clear();
        select_red_0->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "selecione o seu filtro", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterPrewittHorizontal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterPrewittVertical", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterRobertsHorizontal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterRobertsVertical", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterSobelHorizontal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterSobelVertical", Q_NULLPTR)
         << QApplication::translate("MainWindow", "averageFilter", Q_NULLPTR)
         << QApplication::translate("MainWindow", "medianFilter", Q_NULLPTR)
         << QApplication::translate("MainWindow", "selfreinforceFilter", Q_NULLPTR)
        );
        button_red_0->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_red_filter_1->setText(QApplication::translate("MainWindow", "value                  operador ", Q_NULLPTR));
        filter_red_1->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        select_red_1->clear();
        select_red_1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escolha um operador", Q_NULLPTR)
         << QApplication::translate("MainWindow", "==", Q_NULLPTR)
         << QApplication::translate("MainWindow", "!=", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">=", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<=", Q_NULLPTR)
        );
        button_red_1->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_red_filter_2->setText(QApplication::translate("MainWindow", "dilation", Q_NULLPTR));
        filter_red_2->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_red_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_red_filter_3->setText(QApplication::translate("MainWindow", "erosion", Q_NULLPTR));
        filter_red_3->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_red_3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_red_filter_4->setText(QApplication::translate("MainWindow", "histograma", Q_NULLPTR));
        filter_red_4->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_red_4->setText(QApplication::translate("MainWindow", "histograma", Q_NULLPTR));
        label_red_filter_5->setText(QApplication::translate("MainWindow", "centroid provisorio", Q_NULLPTR));
        filter_red_5->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_red_5->setText(QApplication::translate("MainWindow", "centroid provisorio", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "BLUE", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "RED", Q_NULLPTR));
        label_blue_filter_0->setText(QApplication::translate("MainWindow", "value                  filter ", Q_NULLPTR));
        filter_blue_0->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        select_blue_0->clear();
        select_blue_0->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "selecione o seu filtro", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterPrewittHorizontal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterPrewittVertical", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterRobertsHorizontal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterRobertsVertical", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterSobelHorizontal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filterSobelVertical", Q_NULLPTR)
         << QApplication::translate("MainWindow", "averageFilter", Q_NULLPTR)
         << QApplication::translate("MainWindow", "medianFilter", Q_NULLPTR)
         << QApplication::translate("MainWindow", "selfreinforceFilter", Q_NULLPTR)
        );
        button_blue_0->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_blue_filter_1->setText(QApplication::translate("MainWindow", "value                  operador ", Q_NULLPTR));
        filter_blue_1->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        select_blue_1->clear();
        select_blue_1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escolha um operador", Q_NULLPTR)
         << QApplication::translate("MainWindow", "==", Q_NULLPTR)
         << QApplication::translate("MainWindow", "!=", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">=", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<=", Q_NULLPTR)
        );
        button_blue_1->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_blue_filter_2->setText(QApplication::translate("MainWindow", "dilation", Q_NULLPTR));
        filter_blue_2->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_blue_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_blue_filter_3->setText(QApplication::translate("MainWindow", "erosion", Q_NULLPTR));
        filter_blue_3->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_blue_3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label_blue_filter_4->setText(QApplication::translate("MainWindow", "histograma", Q_NULLPTR));
        filter_blue_4->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_blue_4->setText(QApplication::translate("MainWindow", "histograma", Q_NULLPTR));
        label_blue_filter_5->setText(QApplication::translate("MainWindow", "centroid provisorio", Q_NULLPTR));
        filter_blue_5->setText(QApplication::translate("MainWindow", "2.5", Q_NULLPTR));
        button_blue_5->setText(QApplication::translate("MainWindow", "centroid provisorio", Q_NULLPTR));
        result->setTabText(result->indexOf(buttons), QApplication::translate("MainWindow", "Buttons", Q_NULLPTR));
        refresh->setText(QApplication::translate("MainWindow", "ATUALIZAR IMAGENS", Q_NULLPTR));
        set_saved_img_0->setText(QApplication::translate("MainWindow", "USAR  IMAGEM SALVA", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
