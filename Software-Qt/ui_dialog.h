/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *ANTES_GERAL;
    QLabel *texto_antes;
    QLabel *label_before;
    QVBoxLayout *DEPOIS_GERAL;
    QLabel *texto_depois;
    QHBoxLayout *horizontalLayout_IMG;
    QLabel *label_after_blue;
    QLabel *label_after_red;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(674, 435);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ANTES_GERAL = new QVBoxLayout();
        ANTES_GERAL->setObjectName(QStringLiteral("ANTES_GERAL"));
        texto_antes = new QLabel(Dialog);
        texto_antes->setObjectName(QStringLiteral("texto_antes"));
        texto_antes->setMaximumSize(QSize(16777215, 20));
        texto_antes->setAlignment(Qt::AlignCenter);

        ANTES_GERAL->addWidget(texto_antes);

        label_before = new QLabel(Dialog);
        label_before->setObjectName(QStringLiteral("label_before"));
        label_before->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        ANTES_GERAL->addWidget(label_before);


        gridLayout->addLayout(ANTES_GERAL, 0, 0, 1, 1);

        DEPOIS_GERAL = new QVBoxLayout();
        DEPOIS_GERAL->setObjectName(QStringLiteral("DEPOIS_GERAL"));
        texto_depois = new QLabel(Dialog);
        texto_depois->setObjectName(QStringLiteral("texto_depois"));
        texto_depois->setMaximumSize(QSize(16777215, 20));
        texto_depois->setAlignment(Qt::AlignCenter);

        DEPOIS_GERAL->addWidget(texto_depois);

        horizontalLayout_IMG = new QHBoxLayout();
        horizontalLayout_IMG->setObjectName(QStringLiteral("horizontalLayout_IMG"));
        label_after_blue = new QLabel(Dialog);
        label_after_blue->setObjectName(QStringLiteral("label_after_blue"));
        label_after_blue->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        horizontalLayout_IMG->addWidget(label_after_blue);

        label_after_red = new QLabel(Dialog);
        label_after_red->setObjectName(QStringLiteral("label_after_red"));
        label_after_red->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));

        horizontalLayout_IMG->addWidget(label_after_red);


        DEPOIS_GERAL->addLayout(horizontalLayout_IMG);


        gridLayout->addLayout(DEPOIS_GERAL, 1, 0, 1, 1);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        texto_antes->setText(QApplication::translate("Dialog", "ANTES DO PROCESSAMENTO", Q_NULLPTR));
        label_before->setText(QString());
        texto_depois->setText(QApplication::translate("Dialog", "DEPOIS DO PROCESSAMENTO", Q_NULLPTR));
        label_after_blue->setText(QString());
        label_after_red->setText(QString());
        pushButton->setText(QApplication::translate("Dialog", "atualizar imagem", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
