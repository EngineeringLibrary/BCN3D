#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->hide();
    dataToSend = "0000000000000";
    arma = 0;
    this->wifi = nullptr;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(300);

//     mypix = (QDir::currentPath()+"/imageCaptured.jpg");
//     ui->label_before->setPixmap(mypix);


    camera = new QCamera;
//    ui->webcam->setScaledContents( true );
    ui->webcam->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    viewfinder = new QVideoWidget(ui->webcam);
    viewfinder->setMinimumSize(
        (ui->webcam->geometry().width()*13),
        (ui->webcam->geometry().height()*17)
    );
    viewfinder->setMaximumSize(
        ui->webcam->geometry().x(),
        ui->webcam->geometry().y()
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
    if(this->wifi)
        delete this->wifi;
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
    this->img = imgs;
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

    //convertendo de qimage para rgbimage
    mat_complete = ImageProcessing::QImage2RGBImage<unsigned>(img);
    gray_blue.setGray(mat_complete.getBlue());
    gray_red.setGray(mat_complete.getRed());

    Qimg_blue[0] = ImageProcessing::GrayImage2QImage<unsigned>(gray_blue);
    Qimg_red[0] = ImageProcessing::GrayImage2QImage<unsigned>(gray_red);

//    filtro(gray_blue,gray_red);

//// linearizar pelo que entendi e passar pela dilataçao blue
//    linearizar(gray_blue,gray_red,ui->line_blue->text().toULong(),ui->line_red->text().toULong());

//    dilation(bina_blue,bina_red);

//    erosion(bina_blue,bina_red);

}

void MainWindow::linearizar(const ImageProcessing::GrayImage<unsigned> &gray_blu,const ImageProcessing::GrayImage<unsigned> &gray_re,const unsigned scale_blue,const unsigned scale_red){
// linearizar pelo que entendi e passar pela dilataçao blue
    bina_blue = gray_blu > scale_blue;
    bina_red  = gray_re > scale_red;

}

void MainWindow::filtro(const ImageProcessing::GrayImage<unsigned> &gray_blu,const ImageProcessing::GrayImage<unsigned> &gray_re,const unsigned scale){

    gray_blue = ImageProcessing::medianFilter(gray_blu,scale);
    gray_red  = ImageProcessing::medianFilter(gray_re,scale);

    Qimg_blue[1] = ImageProcessing::GrayImage2QImage<unsigned>(gray_blue);
    Qimg_red [1]  = ImageProcessing::GrayImage2QImage<unsigned>(gray_red);

}

void MainWindow::dilation(const ImageProcessing::BinaryImage &bin_blue,const ImageProcessing::BinaryImage &bin_red){

    bina_blue = ImageProcessing::dilation(bin_blue);
    Qimg_blue[2] = ImageProcessing::BinaryImage2QImage<bool>(bina_blue);
    // dilataçao red
    bina_red = ImageProcessing::dilation(bin_red);
    Qimg_red[2] = ImageProcessing::BinaryImage2QImage<bool>(bina_red);

}

void MainWindow::erosion(const ImageProcessing::BinaryImage &bin_blue,const ImageProcessing::BinaryImage &bin_red){

    // erosion blue
    bina_blue = ImageProcessing::erosion(bin_blue);
    Qimg_blue[3] =ImageProcessing::BinaryImage2QImage<bool>(bina_blue);
    // erosion blue
    bina_red = ImageProcessing::erosion(bin_red);
    Qimg_red[3] =ImageProcessing::BinaryImage2QImage<bool>(bina_red);

}

void MainWindow::on_select_blue_currentIndexChanged(int index)
{
    switch (index) {
       case 0:
//        if(!this->Qimg_blue[index].isNull()){
            qDebug() <<"case 0:" <<index<<" blue:" << !this->Qimg_blue[index].isNull() ;
            result_view(this->Qimg_blue[index],false,false);
            break;
//        }
       case 1:
//        if(!this->Qimg_blue[index].isNull()){
            qDebug() <<"case 1:" <<index<<" blue:" << !this->Qimg_blue[index].isNull() ;
            filtro(gray_blue,gray_red);
            result_view(this->Qimg_blue[index],false,false);
            break;
//        }
        case 2:
//         if(!this->Qimg_blue[index].isNull()){
             qDebug() <<"case 2:" <<index<<" blue:" << !this->Qimg_blue[index].isNull() ;
             linearizar(gray_blue,gray_red,ui->line_blue->text().toULong(),ui->line_red->text().toULong());
             dilation(bina_blue,bina_red);
             result_view(this->Qimg_blue[index],false,false);
             break;
//         }
        case 3:
//         if(!this->Qimg_blue[index].isNull()){
             qDebug() <<"case 2:" <<index<<" blue:" << !this->Qimg_blue[index].isNull() ;
             linearizar(gray_blue,gray_red,ui->line_blue->text().toULong(),ui->line_red->text().toULong());
              erosion(bina_blue,bina_red);
             result_view(this->Qimg_blue[index],false,false);
             break;
//         }
       default:
        qDebug() <<"case default" <<index<<" blue:" << !this->Qimg_blue[0].isNull() ;
        qDebug() <<"case default" <<index<<" blue:" << !this->Qimg_blue[1].isNull() ;
         qDebug() <<"default blue";

       }
}

void MainWindow::on_select_red_currentIndexChanged(int index)
{
    switch (index) {
       case 0:
//        if(!this->Qimg_red[index].isNull()){
            qDebug() <<"case 0 red:" << this->Qimg_red[index].isNull() ;
            result_view(this->Qimg_red[index],false,true);
            break;
//        }

       case 1:
//        if(!this->Qimg_red[index].isNull()){
            qDebug() <<"case 1 red:" << this->Qimg_red[index].isNull() ;
            filtro(gray_blue,gray_red);
            result_view(this->Qimg_red[index],false,true);
            break;
//        }
        case 2:
//         if(!this->Qimg_red[index].isNull()){
             qDebug() <<"case 2 red:" << this->Qimg_red[index].isNull() ;
             linearizar(gray_blue,gray_red,ui->line_blue->text().toULong(),ui->line_red->text().toULong());
             dilation(bina_blue,bina_red);
             result_view(this->Qimg_red[index],false,true);
             break;
//         }
        case 3:
//         if(!this->Qimg_red[index].isNull()){
             qDebug() <<"case 2 red:" << this->Qimg_red[index].isNull() ;
             linearizar(gray_blue,gray_red,ui->line_blue->text().toULong(),ui->line_red->text().toULong());
              erosion(bina_blue,bina_red);
             result_view(this->Qimg_red[index],false,true);
             break;
//         }
       default:
        qDebug() <<"case default red:" << this->Qimg_red[0].isNull() ;
        qDebug() <<"case default red:" << this->Qimg_red[1].isNull() ;
          qDebug() <<"default red";
       }
}

void MainWindow::update()
{
    if(this->wifi)
        this->wifi->writeData(this->dataToSend);
    ui->lineEdit->setText(this->dataToSend);
}

void MainWindow::Conectado(){
    QMessageBox msgBox;
    msgBox.setText("Conexão Realizada com Sucesso!");
    msgBox.exec();
    ui->widget->show();
}

void MainWindow::dataHandler(){
    std::string dadosWifi = this->wifi->dataReceived().toStdString();
}

void MainWindow::on_pushButtonConnect_clicked()
{
    QString ip = ui->lineEdit_IP->text();
    quint16 port = ui->lineEdit_Port->text().toShort();

    this->wifi = new Client("192.168.4.1",4000);
    connect(wifi, SIGNAL(connectionSuccessful()),this,SLOT(Conectado()));
    connect(wifi, SIGNAL(hasReadData()),this,SLOT(dataHandler()));
}

void MainWindow::on_pushButton_Disconnect_clicked()
{
    if(this->wifi){
       disconnect(wifi, SIGNAL(hasReadData()),this,SLOT(dataHandler()));
       delete this->wifi;
       this->wifi = nullptr;
    }
    ui->widget->hide();
}
