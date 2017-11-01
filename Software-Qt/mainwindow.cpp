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

    camera->setViewfinder(viewfinder);
//    camera->setProperty("mirrored", false);
//    viewfinder->setProperty("mirrored", true);
    viewfinder->show();
    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);


    // Assuming a QImage has been created from the QVideoFrame that needs to be presented
    QImage videoFrame;
    QCamera myCamera;
    QCameraInfo cameraInfo(*camera);
    videoFrame = img;

//     Get the current display orientation
     QScreen *screen = QGuiApplication::primaryScreen();
     int screenAngle = screen->angleBetween(screen->nativeOrientation(), screen->orientation());

     int rotation;
     if (cameraInfo.position() == QCamera::BackFace) {
         rotation = (cameraInfo.orientation() - screenAngle) % 360;
     } else {
         // Front position, compensate the mirror
         rotation = (360 - cameraInfo.orientation() + screenAngle) % 360;
     }


    // Rotate the frame so it always shows in the correct orientation
    img = img.transformed(QTransform().rotate(rotation));

    QTimer *timer = new QTimer(this);

    connect(timer,
            SIGNAL(timeout()),
                this,
                SLOT(timerClock(1)));
    timer->start(1000);


    camera->start();
    connect(imageCapture,
            SIGNAL(imageCaptured(int,QImage)),
                   this,
                   SLOT(processCaptureImage(int,QImage)));

//    QTimer::singleShot(1,this,  SLOT(timerClock(1)));

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
       std::cout << "save";
    }else{
        img.save(fileName);
        std::cout << "no save";
    }
}
