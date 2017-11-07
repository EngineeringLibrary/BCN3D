#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//     mypix = (QDir::currentPath()+"/imageCaptured.jpg");
//     ui->label_before->setPixmap(mypix);


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

    camera->setViewfinder(viewfinder);
    viewfinder->show();
    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();

    connect(imageCapture,
            SIGNAL(imageCaptured(int,QImage)),
                   this,
                   SLOT(processCaptureImage(int,QImage)));

//    connect(imageCapture,
//            SIGNAL(processCaptureImage(int.QImage)),
//                   this,
//                   SLOT(result_update));
//client_tcp dentro da pasta robotica/rfc
//    img = ui->label_before->pixmap()->toImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    camera->searchAndLock();
    imageCapture->capture();
    QThread::sleep(2);

    qDebug() <<"img:" << img.isNull() ;

//    result_before(img);

}

void MainWindow::timerClock( unsigned clockTime){

    std::cout << "time: " << QDate::currentDate().toString().toUtf8().toStdString() << std::endl;
}

void emit_result(){
    return emit;
}

void MainWindow::result_view(QImage &img,bool state){
    if (state){
        ui->label_before->updatesEnabled();
        ui->label_before->setPixmap(QPixmap::fromImage(img));
        ui->label_before->setScaledContents( true );
        ui->label_before->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_before->update();
        ui->label_before->show();
    }else{
        ui->label_after->updatesEnabled();
        ui->label_after->setPixmap(QPixmap::fromImage(img));
        ui->label_after->setScaledContents( true );
        ui->label_after->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_after->update();
        ui->label_after->show();
    }
}

void MainWindow::processCaptureImage(int requestId,const QImage& imgs){
    img = imgs;
    QString fileName =  QDir::currentPath()+"/imageCaptured.jpg";
    if(!fileName.isEmpty()){
       imgs.save(fileName);
       std::cout << "save";
    }else{
        std::cout << "no save";
    }
    result_view(img);

}
