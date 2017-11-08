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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *result;
    QWidget *tab_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_IP;
    QLineEdit *lineEdit_IP;
    QLabel *label_Port;
    QLineEdit *lineEdit_Port;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonConnect;
    QPushButton *pushButton_Disconnect;
    QWidget *widget;
    QLabel *label_SliderEsq;
    QLabel *label_SliderDir;
    QLineEdit *lineEdit;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *webcam;
    QPushButton *pushButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *line_red;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_after_blue;
    QLabel *label_after_red;
    QLineEdit *line_blue;
    QLabel *label_before;
    QLabel *label;
    QLabel *label_2;
    QComboBox *select_blue;
    QComboBox *select_red;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1317, 751);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        result = new QTabWidget(centralWidget);
        result->setObjectName(QStringLiteral("result"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        layoutWidget_2 = new QWidget(tab_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(210, 110, 761, 55));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_IP = new QLabel(layoutWidget_2);
        label_IP->setObjectName(QStringLiteral("label_IP"));

        horizontalLayout->addWidget(label_IP);

        lineEdit_IP = new QLineEdit(layoutWidget_2);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));

        horizontalLayout->addWidget(lineEdit_IP);

        label_Port = new QLabel(layoutWidget_2);
        label_Port->setObjectName(QStringLiteral("label_Port"));

        horizontalLayout->addWidget(label_Port);

        lineEdit_Port = new QLineEdit(layoutWidget_2);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));

        horizontalLayout->addWidget(lineEdit_Port);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonConnect = new QPushButton(layoutWidget_2);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));

        horizontalLayout_3->addWidget(pushButtonConnect);

        pushButton_Disconnect = new QPushButton(layoutWidget_2);
        pushButton_Disconnect->setObjectName(QStringLiteral("pushButton_Disconnect"));

        horizontalLayout_3->addWidget(pushButton_Disconnect);


        verticalLayout_3->addLayout(horizontalLayout_3);

        widget = new QWidget(tab_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 220, 601, 81));
        label_SliderEsq = new QLabel(widget);
        label_SliderEsq->setObjectName(QStringLiteral("label_SliderEsq"));
        label_SliderEsq->setGeometry(QRect(50, 240, 47, 13));
        label_SliderDir = new QLabel(widget);
        label_SliderDir->setObjectName(QStringLiteral("label_SliderDir"));
        label_SliderDir->setGeometry(QRect(320, 240, 47, 13));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 30, 511, 20));
        result->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1251, 571));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        webcam = new QWidget(layoutWidget);
        webcam->setObjectName(QStringLiteral("webcam"));

        verticalLayout->addWidget(webcam);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        result->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        line_red = new QLineEdit(tab_2);
        line_red->setObjectName(QStringLiteral("line_red"));

        gridLayout_3->addWidget(line_red, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_after_blue = new QLabel(tab_2);
        label_after_blue->setObjectName(QStringLiteral("label_after_blue"));

        horizontalLayout_2->addWidget(label_after_blue);

        label_after_red = new QLabel(tab_2);
        label_after_red->setObjectName(QStringLiteral("label_after_red"));

        horizontalLayout_2->addWidget(label_after_red);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        line_blue = new QLineEdit(tab_2);
        line_blue->setObjectName(QStringLiteral("line_blue"));

        gridLayout_3->addWidget(line_blue, 4, 0, 1, 1);

        label_before = new QLabel(tab_2);
        label_before->setObjectName(QStringLiteral("label_before"));

        gridLayout_3->addWidget(label_before, 0, 0, 1, 2);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 5, 0, 1, 1);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 50));

        gridLayout_3->addWidget(label_2, 5, 1, 1, 1);

        select_blue = new QComboBox(tab_2);
        select_blue->setObjectName(QStringLiteral("select_blue"));

        gridLayout_3->addWidget(select_blue, 2, 0, 1, 1);

        select_red = new QComboBox(tab_2);
        select_red->setObjectName(QStringLiteral("select_red"));

        gridLayout_3->addWidget(select_red, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        result->addTab(tab_2, QString());

        verticalLayout_2->addWidget(result);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1317, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        result->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_IP->setText(QApplication::translate("MainWindow", "IP:", Q_NULLPTR));
        label_Port->setText(QApplication::translate("MainWindow", "Porta:", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Conectar", Q_NULLPTR));
        pushButton_Disconnect->setText(QApplication::translate("MainWindow", "Desconectar", Q_NULLPTR));
        label_SliderEsq->setText(QString());
        label_SliderDir->setText(QString());
        result->setTabText(result->indexOf(tab_3), QApplication::translate("MainWindow", "Conex\303\243o", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        result->setTabText(result->indexOf(tab), QApplication::translate("MainWindow", "capture", Q_NULLPTR));
        line_red->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        label_after_blue->setText(QString());
        label_after_red->setText(QString());
        line_blue->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        label_before->setText(QString());
        label->setText(QApplication::translate("MainWindow", "blue", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "red", Q_NULLPTR));
        select_blue->clear();
        select_blue->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escala de cinza", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filtro mediano", Q_NULLPTR)
         << QApplication::translate("MainWindow", "dilata\303\247\303\243o", Q_NULLPTR)
         << QApplication::translate("MainWindow", "erosao", Q_NULLPTR)
        );
        select_red->clear();
        select_red->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escala de cinza", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filtro mediano", Q_NULLPTR)
         << QApplication::translate("MainWindow", "dilata\303\247\303\243o", Q_NULLPTR)
         << QApplication::translate("MainWindow", "erosao", Q_NULLPTR)
        );
        result->setTabText(result->indexOf(tab_2), QApplication::translate("MainWindow", "result", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
