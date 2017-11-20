#include "result_view.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

//    mainWindow = new MainWindow;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::set_result_view(QImage &img,bool state, bool colors){
    if (state){
        ui->label_before->updatesEnabled();
        ui->label_before->setPixmap(QPixmap::fromImage(img));
        ui->label_before->setScaledContents( true );
        ui->label_before->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_before->update();
        ui->label_before->show();
    }else if (!state && colors){
        ui->label_after_red->updatesEnabled();
        ui->label_after_red->setPixmap(QPixmap::fromImage(img));
        ui->label_after_red->setScaledContents( true );
        ui->label_after_red->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_after_red->update();
        ui->label_after_red->show();
    }else if(!state && !colors){
        ui->label_after_blue->updatesEnabled();
        ui->label_after_blue->setPixmap(QPixmap::fromImage(img));
        ui->label_after_blue->setScaledContents( true );
        ui->label_after_blue->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_after_blue->update();
        ui->label_after_blue->show();
    }
}



