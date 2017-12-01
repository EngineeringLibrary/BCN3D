/********************************************************************************
** Form generated from reading UI file 'result_view.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_VIEW_H
#define UI_RESULT_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *texto_antes;
    QLabel *label_before;
    QVBoxLayout *DEPOIS_GERAL;
    QLabel *texto_depois;
    QHBoxLayout *horizontalLayout_IMG;
    QLabel *label_after_blue;
    QLabel *label_after_red;
    QPushButton *refresh;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(674, 435);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        texto_antes = new QLabel(widget);
        texto_antes->setObjectName(QStringLiteral("texto_antes"));
        texto_antes->setMaximumSize(QSize(16777215, 20));
        texto_antes->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(texto_antes);

        label_before = new QLabel(widget);
        label_before->setObjectName(QStringLiteral("label_before"));
        label_before->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        verticalLayout->addWidget(label_before);

        DEPOIS_GERAL = new QVBoxLayout();
        DEPOIS_GERAL->setObjectName(QStringLiteral("DEPOIS_GERAL"));
        texto_depois = new QLabel(widget);
        texto_depois->setObjectName(QStringLiteral("texto_depois"));
        texto_depois->setMaximumSize(QSize(16777215, 20));
        texto_depois->setAlignment(Qt::AlignCenter);

        DEPOIS_GERAL->addWidget(texto_depois);

        horizontalLayout_IMG = new QHBoxLayout();
        horizontalLayout_IMG->setObjectName(QStringLiteral("horizontalLayout_IMG"));
        label_after_blue = new QLabel(widget);
        label_after_blue->setObjectName(QStringLiteral("label_after_blue"));
        label_after_blue->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        horizontalLayout_IMG->addWidget(label_after_blue);

        label_after_red = new QLabel(widget);
        label_after_red->setObjectName(QStringLiteral("label_after_red"));
        label_after_red->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        horizontalLayout_IMG->addWidget(label_after_red);


        DEPOIS_GERAL->addLayout(horizontalLayout_IMG);


        verticalLayout->addLayout(DEPOIS_GERAL);

        refresh = new QPushButton(widget);
        refresh->setObjectName(QStringLiteral("refresh"));

        verticalLayout->addWidget(refresh);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "result preview", Q_NULLPTR));
        texto_antes->setText(QApplication::translate("Dialog", "ANTES DO PROCESSAMENTO", Q_NULLPTR));
        label_before->setText(QString());
        texto_depois->setText(QApplication::translate("Dialog", "DEPOIS DO PROCESSAMENTO", Q_NULLPTR));
        label_after_blue->setText(QString());
        label_after_red->setText(QString());
        refresh->setText(QApplication::translate("Dialog", "atualizar imagem", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_VIEW_H
