#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera = new QCamera;
    viewfinder = new QVideoWidget(ui->webcam);
    viewfinder->setMinimumSize(
        (ui->webcam->geometry().width()*10),
        (ui->webcam->geometry().height()*17)
    );
    viewfinder->setMaximumSize(
        ui->webcam->maximumWidth(),
        ui->webcam->maximumHeight()
    );
    viewfinder->show();
    camera->setViewfinder(viewfinder);

    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();

    connect(imageCapture,
            SIGNAL(imageCaptured(int,QImage)),
                   this,
                   SLOT(processCaptureImage(int,QImage)));

    QTimer::singleShot(1,this,  SLOT(timerClock(1)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    camera->searchAndLock();
    imageCapture->capture();
    std::cout << "time2: "<< QDate::currentDate().toString().toUtf8().toStdString() << std::endl;
}

void MainWindow::timerClock( unsigned clockTime){

    std::cout << "time: "<< QDate::currentDate().toString().toUtf8().toStdString() << std::endl;
}

void MainWindow::processCaptureImage(int requestId,const QImage& img){

    QString fileName =  QDir::currentPath()+"/imageCaptured.jpg";

    if(!fileName.isEmpty()){
       img.save(fileName);
    }
}
