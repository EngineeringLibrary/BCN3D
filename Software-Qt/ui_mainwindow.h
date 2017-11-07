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
    QWidget *tab;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *webcam;
    QPushButton *pushButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_after_blue;
    QLabel *label_after_red;
    QLineEdit *lineEdit_5;
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
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 1251, 571));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        webcam = new QWidget(widget);
        webcam->setObjectName(QStringLiteral("webcam"));

        verticalLayout->addWidget(webcam);

        pushButton = new QPushButton(widget);
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
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 4, 1, 1, 1);

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

        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_3->addWidget(lineEdit_5, 4, 0, 1, 1);

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
        menuBar->setGeometry(QRect(0, 0, 1317, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButton, result);

        retranslateUi(MainWindow);

        result->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        result->setTabText(result->indexOf(tab), QApplication::translate("MainWindow", "capture", Q_NULLPTR));
        label_after_blue->setText(QString());
        label_after_red->setText(QString());
        label_before->setText(QString());
        label->setText(QApplication::translate("MainWindow", "blue", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "red", Q_NULLPTR));
        select_blue->clear();
        select_blue->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escala de cinza", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filtro mediano", Q_NULLPTR)
        );
        select_red->clear();
        select_red->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "escala de cinza", Q_NULLPTR)
         << QApplication::translate("MainWindow", "filtro mediano", Q_NULLPTR)
        );
        result->setTabText(result->indexOf(tab_2), QApplication::translate("MainWindow", "result", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
