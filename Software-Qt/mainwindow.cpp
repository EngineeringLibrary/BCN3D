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

//    qDebug() <<"img:" << img.isNull() ;

//    result_before(img);

}

void MainWindow::timerClock( unsigned clockTime){

    std::cout << "time: " << QDate::currentDate().toString().toUtf8().toStdString() << std::endl;
}

void emit_result(){
    return emit;
}

void MainWindow::result_view(QImage &img,bool state, bool colors){
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

void MainWindow::processCaptureImage(int requestId,const QImage& imgs){
    img = imgs;
    QString fileName =  QDir::currentPath()+"/imageCaptured.jpg";
    if(!fileName.isEmpty()){
       imgs.save(fileName);
       std::cout << "save";
    }else{
        std::cout << "no save";
    }
//   mostrando imagem antes do processamento
    result_view(img,true,true);
//    separando a image por cor
    ImageProcessing::RGBImage<double>mat_complete;
    ImageProcessing::GrayImage<double>mat_blue,mat_red;

    //convertendo de qimage para rgbimage
    mat_complete = ImageProcessing::QImage2RGBImage<double>(img);

    mat_blue.setGray(mat_complete.getBlue());

    mat_red.setGray(mat_complete.getRed());

    Qimg_blue = ImageProcessing::GrayImage2QImage<double>(mat_blue);
    Qimg_red = ImageProcessing::GrayImage2QImage<double>(mat_red);

//mostrando imagem azul
    result_view(Qimg_blue,false,false);
//mostrando imagem vermelha
    result_view(Qimg_red,false,true);

//    filtros


}
