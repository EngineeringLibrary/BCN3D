#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* INICIO MODULO WIFI */

    dataToSend = "0000000000000";
    this->wifi = nullptr;

    /* FIM MODULO WIFI */

    //     mypix = (QDir::currentPath()+"/imageCaptured.jpg");
    //     ui->label_before->setPixmap(mypix);
//    if(checkCameras()){
//        QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

//        foreach (const QCameraInfo &cameraInfo, cameras) {
//            qDebug() << "Device Name  : " << cameraInfo.deviceName() << endl;
//            qDebug() << "Description  : " << cameraInfo.description() << endl;
//            qDebug() << "Position     : " << cameraInfo.position() << endl;
//            qDebug() << "Cam Default  : " << cameraInfo.defaultCamera() << endl;
//            qDebug() << "Orientation  : " << cameraInfo.orientation() << endl;
//        }
//    }

    result_img = new Dialog(this);
    if(camCount > 1){
       camera = new QCamera("/dev/video1");
    }else{
         camera = new QCamera;
    }

    viewfinder = new QVideoWidget(ui->webcam);


    mat_complete = new ImageProcessing::RGBImage<unsigned>;
    gray_blue = new ImageProcessing::GrayImage<unsigned>;
    gray_red = new ImageProcessing::GrayImage<unsigned>;
    bina_blue = new ImageProcessing::BinaryImage;
    bina_red = new ImageProcessing::BinaryImage;

    histogramMatrix = new LinAlg::Matrix<unsigned>;

    Qimg_blue_ = new QImage;
    Qimg_red_ = new QImage;
    img = new QImage;

//        ui->webcam->setScaledContents( true );
        ui->webcam->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        viewfinder->setMinimumSize(
            (ui->webcam->geometry().width()*13),
            (ui->webcam->geometry().height()*17)
        );


//    viewfinder->setMinimumSize(
//                (ui->webcam->geometry().width()*1.5),
//                (ui->webcam->geometry().height()*1.3)
//                );

    viewfinder->setMaximumSize(
                ui->webcam->maximumWidth(),
                ui->webcam->maximumHeight()
                );

    camera->setViewfinder(viewfinder);
    viewfinder->show();
    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();

    QImageEncoderSettings imageSettings;
    imageSettings.setCodec("image/jpeg");
    imageSettings.setResolution(1280, 720);
    imageCapture->setEncodingSettings(imageSettings);

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


//------------------------- PROCESSAMENTO DE IMAGENS--------------------------------

bool MainWindow::checkCameras()
{
     camCount = QCameraInfo::availableCameras().count();
    if ( camCount > 0) {
        qDebug() << "Cameras encontradas: " << camCount << endl;
        return true;
    }
    else {
        qDebug() << "Nenhuma camera foi detectada!" << endl;
        return false;
    }
}

void MainWindow::on_ImageProcess_clicked()
{
    processamentoImagem();//faz todo o processamento da imagem encontra as posicoes reais dos objetos
}


void MainWindow::on_pushButton_clicked()
{
    camera->searchAndLock();
    imageCapture->capture();
    //    QThread::sleep(2);
}

void MainWindow::result_view(QImage &img,bool state, bool colors){
    //    coloca as mesmas img no result_view.ui
    if(!result_img->isHidden()){
        result_img->set_result_view(img,state,colors);
    }

    if (state){
        ui->label_before->updatesEnabled();
        ui->label_before->setPixmap(QPixmap::fromImage(img));
        ui->label_before->setScaledContents( true );
        ui->label_before->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_before->update();
        ui->label_before->show();
    }else if (!state && colors){
        *Qimg_red_ = img;
        ui->label_after_red->updatesEnabled();
        ui->label_after_red->setPixmap(QPixmap::fromImage(img));
        ui->label_after_red->setScaledContents( true );
        ui->label_after_red->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_after_red->update();
        ui->label_after_red->show();
    }else if(!state && !colors){
        *Qimg_blue_ = img;
        ui->label_after_blue->updatesEnabled();
        ui->label_after_blue->setPixmap(QPixmap::fromImage(img));
        ui->label_after_blue->setScaledContents( true );
        ui->label_after_blue->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        ui->label_after_blue->update();
        ui->label_after_blue->show();
    }
}

void MainWindow::enableTab(int except){
    for(int i= 0;i < ui->result->count();i++){
        if(i!=except)
            ui->result->setTabEnabled(i,true);
    }
}

void MainWindow::disableTab(int except){
    for(int i= 0;i < ui->result->count();i++){
        if(i!=except)
            ui->result->setTabEnabled(i,false);
    }
}

void MainWindow::processamentoImagem(){



    //    PARTE AZUL
//    histrograma(*gray_blue);
    *gray_blue = ImageProcessing::selfreinforceFilter(*gray_blue,3,2.5);
    *bina_blue = (*gray_blue > 43) && (*gray_blue < 215);
    //pego a matriz binaria inverto e retorno invertida
    *bina_blue = ImageProcessing::BinaryImage((!bina_blue[0]).getBinaryImageMatrix());
    dilation(*bina_blue,false);
    dilation(*bina_blue,false);
    dilation(*bina_blue,false);
    erosion(*bina_blue,false);
    erosion(*bina_blue,false);
    erosion(*bina_blue,false);
    erosion(*bina_blue,false);
    erosion(*bina_blue,false);
    erosion(*bina_blue,false);



    bound(*bina_blue,false);
    std::cout <<"blue: "<< qdt << std::endl;
    centroid(*bina_blue,false);


//    if(area_blue[0] > area_blue[1]){
//        std::cout << "quadrado blue p:0->" << area_blue[0] << std::endl;
//    }else{
//        std::cout << "quadrado blue p:1->" << area_blue[1] << std::endl;
//    }

    //    PARTE VERMELHA

//    histrograma(*gray_red);
    *gray_red = ImageProcessing::selfreinforceFilter(*gray_red,3,2.5);
    *bina_red = (*gray_red > 43) && (*gray_red < 215);
    //pego a matriz binaria inverto e retorno invertida
    *bina_red = ImageProcessing::BinaryImage((!bina_red[0]).getBinaryImageMatrix());

    dilation(*bina_red,true);
    dilation(*bina_red,true);
    dilation(*bina_red,true);
    erosion(*bina_red,true);
    erosion(*bina_red,true);
    erosion(*bina_red,true);
    erosion(*bina_red,true);
    erosion(*bina_red,true);
    erosion(*bina_red,true);
//    erosion(*bina_red,true);



    bound(*bina_red,true);
    centroid(*bina_red,true);

//    if(area_red[0] > area_red[1]){
//        std::cout << "quadrado red p:0->" << area_red[0] << std::endl;
//    }else{
//        std::cout << "quadrado red p:1->" << area_red[1] << std::endl;
//    }
    std::cout << "posicao: " << std::endl << posicao << std::endl;

    //    FIM

    Qimg_blue[0] = ImageProcessing::BinaryImage2QImage<unsigned>(*bina_blue);
    Qimg_red[0] = ImageProcessing::BinaryImage2QImage<unsigned>(*bina_red);
    //        mostra imagem em escala de cinza
    result_view(Qimg_blue[0],false,false);
    result_view(Qimg_red[0],false,true);
}

void MainWindow::set_saved_img(const bool use)
{
    QImage temp;
    if(use){

        *mat_complete = ImageProcessing::QImage2RGBImage<unsigned>(mypix.toImage());
        *img = ImageProcessing::RGBImage2QImage<unsigned>(*mat_complete);
        result_view(*img,true,true);

        gray_blue->setGray(255-mat_complete->getRed());//pode parecer errado mais esta certo
        gray_red->setGray(255-mat_complete->getBlue());//pode parecer errado mais esta certo
        //        passa de rgb para  escala de cinza invertendo as cores
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage<unsigned>(*gray_blue);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage<unsigned>(*gray_red);
        //        mostra imagem em escala de cinza
        result_view(*Qimg_blue_,false,false);
        result_view(*Qimg_red_,false,true);

    }
}

void MainWindow::processCaptureImage(int requestId,const QImage& imgs){
    *img = imgs;

    QString fileName =  QDir::currentPath()+"/imageCaptured.jpg";
    if(!fileName.isEmpty()){
               imgs.save(fileName);
        std::cout << "save";
    }else{
        std::cout << "no save";
    }
    //   mostrando imagem antes do processamento
    result_view(*img,true,true);
    *mat_complete = ImageProcessing::QImage2RGBImage<unsigned>(*img);
    on_resizeImg_valueChanged(995);

    gray_blue->setGray(255-mat_complete->getRed());//pode parecer errado mais esta certo
    gray_red->setGray(255-mat_complete->getBlue());//pode parecer errado mais esta certo
    //        passa de rgb para  escala de cinza invertendo as cores
    *Qimg_blue_ = ImageProcessing::GrayImage2QImage<unsigned>(*gray_blue);
    *Qimg_red_ = ImageProcessing::GrayImage2QImage<unsigned>(*gray_red);
    //        mostra imagem em escala de cinza
    result_view(*Qimg_blue_,false,false);
    result_view(*Qimg_red_,false,true);

}

void MainWindow::filtro(const ImageProcessing::GrayImage<unsigned> &gray_img,const double filter_value,const bool color,const unsigned scale){
    //esta recebendo inteiro so
    if(!color){
        qDebug() <<"filtro :" <<filter_value<<": ";
        *gray_blue = ImageProcessing::medianFilter(gray_img,scale);
        *gray_blue = ImageProcessing::selfreinforceFilter(*gray_blue,scale,filter_value);
        Qimg_blue[1] = ImageProcessing::GrayImage2QImage<unsigned>(*gray_blue);
    }else{
        qDebug() <<"filtro :" <<filter_value<<": ";
        *gray_red = ImageProcessing::medianFilter<unsigned>(gray_img,scale);
        *gray_red  = ImageProcessing::selfreinforceFilter(*gray_red,scale,filter_value);
        Qimg_red [1]  = ImageProcessing::GrayImage2QImage<unsigned>(*gray_red);
    }
}

void MainWindow::linearizar(const ImageProcessing::GrayImage<unsigned> &gray_img,const unsigned scale,const unsigned scale2,const bool color,const unsigned index){
    // linearizar pelo que entendi e passar pela dilataçao blue
    if(!color){
        switch (index) {
        case 0:
            qDebug() <<"escolha um tipo  :"<<": ";
            break;
        case 1:
            *bina_blue = gray_img == scale;
            break;
        case 2:
            *bina_blue = gray_img != scale;
            break;
        case 3:
            *bina_blue = gray_img > scale;
            break;
        case 4:
            *bina_blue = gray_img >= scale;
            break;
        case 5:
            *bina_blue = gray_img < scale;
            break;
        case 6:
            *bina_blue = gray_img <= scale;
            break;
        case 7:
            *bina_blue = (gray_img > scale) && (gray_img < scale2);
            break;
        case 8:
            *bina_blue = (gray_img >= scale) && (gray_img <= scale2);
            break;
        default:
            *bina_blue = gray_img > scale;
        }

    }else{
        switch (index) {
        case 0:
            qDebug() <<"escolha um tipo  :"<<": ";
            break;
        case 1:
            *bina_red = gray_img == scale;
            break;
        case 2:
            *bina_red = gray_img != scale;
            break;
        case 3:
            *bina_red = gray_img > scale;
            break;
        case 4:
            *bina_red = gray_img >= scale;
            break;
        case 5:
            *bina_red = gray_img < scale;
            break;
        case 6:
            *bina_red = gray_img <= scale;
            break;
        case 7:
            *bina_blue = (gray_img > scale) && (gray_img < scale2);
            break;
        case 8:
            *bina_blue = (gray_img >= scale) && (gray_img <= scale2);
            break;
        default:
            qDebug() <<"escolha um tipo  :"<<": ";
            break;
        }
    }
}

void MainWindow::dilation(const ImageProcessing::BinaryImage &bin,const bool color){
    if(!color){    // dilataçao blue
        *bina_blue = ImageProcessing::dilation(bin);
        Qimg_blue[2] = *Qimg_blue_ = ImageProcessing::BinaryImage2QImage<bool>(*bina_blue);
    }else{   // dilataçao red
        *bina_red = ImageProcessing::dilation(bin);
        Qimg_red[2] =*Qimg_red_= ImageProcessing::BinaryImage2QImage<bool>(*bina_red);
    }
}

void MainWindow::erosion(const ImageProcessing::BinaryImage &bin,const bool color){

    if(!color){    // erosion blue
        *bina_blue = ImageProcessing::erosion(bin);
        Qimg_blue[3] =*Qimg_blue_=ImageProcessing::BinaryImage2QImage<bool>(*bina_blue);
    }else{     // erosion red
        *bina_red = ImageProcessing::erosion(bin);
        Qimg_red[3] =*Qimg_red_=ImageProcessing::BinaryImage2QImage<bool>(*bina_red);
    }
}

void MainWindow::bound(const ImageProcessing::BinaryImage &imgs,const bool color){

    if(!color){
        *(qdt, segmentedMatrix) = ImageProcessing::bound(imgs);
    }else{
        *(qdt, segmentedMatrix) = ImageProcessing::bound(imgs);
    }
}

void MainWindow::histrograma(const ImageProcessing::GrayImage<unsigned> &grayImg){

    *histogramMatrix = ImageProcessing::Histogram<unsigned>(grayImg);
    std::cout << (~(*histogramMatrix || LinAlg::LineVector<unsigned>(0,255,1))) << std::endl;
}

void MainWindow::centroid( ImageProcessing::BinaryImage &bin_img,const unsigned color)
{

    //    ja devemos ter valores em qdt,segmentoMatrix
    if(!qdt.isNull() && !segmentedMatrix.isNull()){

        centroids = ImageProcessing::centroid(bin_img);
        if(!color){
            //          pegando a area do objeto

            for(unsigned i =1;i<=qdt(1,1);++i){
                centroids = ImageProcessing::centroid(segmentedMatrix==(i+1));
                //              pegando posicoes dos objetos
                posicao = posicao || ImageProcessing::pixelToWorldMetric(segmentedMatrix,24,50  ,centroids);
                this->area_blue[(i-1)] = ImageProcessing::area(segmentedMatrix==(i+2));
                //              colocar um ponto no centro da imagem
                //              bina_blue[0] ->   coloco como ponto zero para pegar posição da memoria do ponteiro
                bina_blue[0](centroids(1,1)-1,centroids(1,2)-1) = 0;
                bina_blue[0](centroids(1,1)-1,centroids(1,2))   = 0;
                bina_blue[0](centroids(1,1),  centroids(1,2)-1) = 0;
                bina_blue[0](centroids(1,1),  centroids(1,2))   = 0;
                bina_blue[0](centroids(1,1)+1,centroids(1,2))   = 0;
                bina_blue[0](centroids(1,1),  centroids(1,2)+1) = 0;
                bina_blue[0](centroids(1,1)+1,centroids(1,2)+1) = 0;
            }

            //    de binario para escala de cinza
            gray_blue->setGray(this->bina_blue->getBinaryImageMatrix());
            //    expandindo de binario para escala de cinza
            gray_blue->setGray(gray_blue->getGray()*100);
            *Qimg_blue_ = ImageProcessing::GrayImage2QImage<unsigned>(*gray_blue);
        }else{
            //        pegando a area do objeto

            for(unsigned i =1;i<=qdt(1,1);++i){
                centroids = ImageProcessing::centroid(segmentedMatrix==(i+1));
                //              pegando posicoes dos objetos
                posicao = posicao || ImageProcessing::pixelToWorldMetric(segmentedMatrix,24,50,centroids);
                this->area_red[(i-1)]  = ImageProcessing::area(segmentedMatrix==(i+2));
                //               colocar um ponto no centro da imagem
                //               bina_blue[0] ->   coloco como ponto zero para pegar posição da memoria do ponteiro
                bina_red[0](centroids(1,1)-1,centroids(1,2)-1) = 0;
                bina_red[0](centroids(1,1)-1,centroids(1,2))   = 0;
                bina_red[0](centroids(1,1),  centroids(1,2)-1) = 0;
                bina_red[0](centroids(1,1),  centroids(1,2))   = 0;
                bina_red[0](centroids(1,1)+1,centroids(1,2))   = 0;
                bina_red[0](centroids(1,1),  centroids(1,2)+1) = 0;
                bina_red[0](centroids(1,1)+1,centroids(1,2)+1) = 0;
            }

            //    de binario para escala de cinza
            gray_red->setGray(this->bina_red->getBinaryImageMatrix());
            //    expandindo de binario para escala de cinza
            gray_red->setGray(gray_red->getGray()*100);
            *Qimg_red_ = ImageProcessing::GrayImage2QImage<unsigned>(*gray_red);
        }
    }else{
        qDebug() <<"voce deve calcular bound primeiro ";
    }
}

//-------------------------------EVENTS: PROCESSAMENTO DE IMAGENS----------------------------------------------------------

void MainWindow::on_resizeImg_valueChanged(int value)
{
    *mat_complete = ImageProcessing::reScale(*mat_complete,value/1000.0);
    ui->resultRescale->setText(QString::number(value/1000.0));
//    ui->label_after_red->setPixmap(QPixmap::fromImage(ImageProcessing::RGBImage2QImage(*mat_complete)));
    QImage temp = ImageProcessing::RGBImage2QImage(*mat_complete);
    QString fileName =  QDir::currentPath()+"/imageCapturedResize.jpg";
    if(!fileName.isEmpty()){
        temp.save(fileName);
    }
}

void MainWindow::on_check_saved_img_clicked(bool checked)
{
    set_saved_img(checked);
}

void MainWindow::on_set_saved_img_0_clicked(bool checked)
{
    set_saved_img(!checked);
}

void MainWindow::on_actionProcessar_triggered()
{
    processamentoImagem();
}


void MainWindow::on_select_blue_0_currentIndexChanged(int index)
{
    select_blue_0_index = index;
    switch (index) {
    case 1:
        *gray_blue = ImageProcessing::filterPrewittHorizontal(*gray_blue);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 2:
        *gray_blue = ImageProcessing::filterPrewittVertical(*gray_blue);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 3:
        *gray_blue = ImageProcessing::filterRobertsHorizontal(*gray_blue);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 4:
        *gray_blue = ImageProcessing::filterRobertsVertical(*gray_blue);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 5:
        *gray_blue = ImageProcessing::filterSobelHorizontal(*gray_blue);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 6:
        *gray_blue = ImageProcessing::filterSobelVertical(*gray_blue);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 7:
        *gray_blue = ImageProcessing::averageFilter(*gray_blue,3);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 8:
        *gray_blue = ImageProcessing::medianFilter(*gray_blue,3);
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    case 9:
        *gray_blue = ImageProcessing::selfreinforceFilter(*gray_blue,3,ui->filter_blue_0->text().toDouble());
        *Qimg_blue_ = ImageProcessing::GrayImage2QImage(*gray_blue);
        break;
    default:
        break;
    }
}

void MainWindow::on_button_blue_0_clicked()
{
    switch (select_blue_0_index) {
    case 1:
        *gray_blue = ImageProcessing::filterPrewittHorizontal(*gray_blue);

        break;
    case 2:
        *gray_blue = ImageProcessing::filterPrewittVertical(*gray_blue);
        break;
    case 3:
        *gray_blue = ImageProcessing::filterRobertsHorizontal(*gray_blue);

        break;
    case 4:
        *gray_blue = ImageProcessing::filterRobertsVertical(*gray_blue);

        break;
    case 5:
        *gray_blue = ImageProcessing::filterSobelHorizontal(*gray_blue);

        break;
    case 6:
        *gray_blue = ImageProcessing::filterSobelVertical(*gray_blue);

        break;
    case 7:
        *gray_blue = ImageProcessing::averageFilter(*gray_blue,3);

        break;
    case 8:
        *gray_blue = ImageProcessing::medianFilter(*gray_blue,3);

        break;
    case 9:
        *gray_blue = ImageProcessing::selfreinforceFilter(*gray_blue,3,ui->filter_blue_0->text().toDouble());
        break;
    default:
        break;
    }
}

void MainWindow::on_select_red_0_currentIndexChanged(int index)
{
    select_red_0_index =  index;
    switch (select_red_0_index) {
    case 1:
        *gray_red = ImageProcessing::filterPrewittHorizontal(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 2:
        *gray_red = ImageProcessing::filterPrewittVertical(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 3:
        *gray_red = ImageProcessing::filterRobertsHorizontal(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 4:
        *gray_red = ImageProcessing::filterRobertsVertical(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 5:
        *gray_red = ImageProcessing::filterSobelHorizontal(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 6:
        *gray_red = ImageProcessing::filterSobelVertical(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 7:
        *gray_red = ImageProcessing::averageFilter(*gray_red,3);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 8:
        *gray_red = ImageProcessing::medianFilter(*gray_red,3);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 9:
        *gray_red = ImageProcessing::selfreinforceFilter(*gray_red,3,ui->filter_red_0->text().toDouble());
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    default:
        break;
    }
}

void MainWindow::on_button_red_0_clicked()
{
    switch (select_red_0_index) {
    case 1:
        *gray_red = ImageProcessing::filterPrewittHorizontal(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 2:
        *gray_red = ImageProcessing::filterPrewittVertical(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 3:
        *gray_red = ImageProcessing::filterRobertsHorizontal(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 4:
        *gray_red = ImageProcessing::filterRobertsVertical(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 5:
        *gray_red = ImageProcessing::filterSobelHorizontal(*gray_red);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 6:
        *gray_red = ImageProcessing::filterSobelVertical(*gray_red);

        break;
    case 7:
        *gray_red = ImageProcessing::averageFilter(*gray_red,3);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 8:
        *gray_red = ImageProcessing::medianFilter(*gray_red,3);
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    case 9:
        *gray_red = ImageProcessing::selfreinforceFilter(*gray_red,3,ui->filter_red_0->text().toDouble());
        *Qimg_red_ = ImageProcessing::GrayImage2QImage(*gray_red);
        break;
    default:
        break;
    }
}

//BLUE 1
void MainWindow::on_select_blue_1_currentIndexChanged(int index)
{
    select_blue_0_index = index;
}

void MainWindow::on_button_blue_1_clicked()
{
    linearizar(*gray_blue,ui->filter_blue_1->text().toInt(),ui->filter_blue_1_0->text().toInt(),false,select_blue_1_index);
}

//RED 1
void MainWindow::on_select_red_1_currentIndexChanged(int index)
{
    select_red_1_index = index;
}

void MainWindow::on_button_red_1_clicked()
{
    linearizar(*gray_red,ui->filter_red_1->text().toInt(),ui->filter_red_1_0->text().toInt(),true,select_red_1_index);
}

//BLUE 2
void MainWindow::on_select_blue_2_currentIndexChanged(int index)
{

}

void MainWindow::on_button_blue_2_clicked()
{
    MainWindow::dilation(*bina_blue,false);
}

//RED 2
void MainWindow::on_select_red_2_currentIndexChanged(int index)
{

}

void MainWindow::on_button_red_2_clicked()
{
    MainWindow::dilation(*bina_red,true);
}

//BLUE 3
void MainWindow::on_select_blue_3_currentIndexChanged(int index)
{

}

void MainWindow::on_button_blue_3_clicked()
{
    MainWindow::erosion(*bina_blue,false);
}

//RED 3
void MainWindow::on_select_red_3_currentIndexChanged(int index)
{

}

void MainWindow::on_button_red_3_clicked()
{
    MainWindow::erosion(*bina_red,true);
}

void MainWindow::on_button_blue_4_clicked()
{
    //    histrograma(*gray_blue);
    bound(*bina_blue,false);
}

void MainWindow::on_button_red_4_clicked()
{
    //    histrograma(*gray_red);
    bound(*bina_red,true);
}

void MainWindow::on_button_blue_5_clicked()
{
    centroid(*bina_blue,false);
}

void MainWindow::on_button_red_5_clicked()
{
    centroid(*bina_red,true);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionPreview_triggered()
{
    result_img->show();
}

void MainWindow::on_refresh_clicked()
{
    QImage temp = ImageProcessing::RGBImage2QImage(*mat_complete);
    result_view(temp,false,false);
    result_view(*Qimg_blue_,false,false);
    result_view(*Qimg_red_,false,true);
}

void MainWindow::on_actionWebcam_triggered()
{
    //    disableTab(ui->result->currentIndex());
    //    enableTab(1);
    ui->result->currentWidget()->close();
    //    ui->result->
    //    ui->result->c(ui->gridLayout_4);
    //    ui->result->setLayout(ui->gridLayout_2);
    ui->camera->show();
}

void MainWindow::on_actionButtons_triggered()
{
    ui->result->currentWidget()->close();
    ui->buttons->show();
}

void MainWindow::on_actionConnect_triggered()
{
    ui->result->currentWidget()->close();
    ui->connect->show();
}

void MainWindow::on_actionAlualizar_Imagem_triggered()
{
    result_view(*img,true,true);
    result_view(*Qimg_blue_,false,false);
    result_view(*Qimg_red_,false,true);
}

void MainWindow::on_actionusar_imagem_salva_triggered()
{
    set_saved_img(true);
}

// END -------------------------------EVENTS:  DE IMAGENS----------------------------------------------------------

//------------------------- WIFI--------------------------------

void MainWindow::Conectado(){
    QMessageBox msgBox;
    msgBox.setText("Conexão Realizada com Sucesso!");
    msgBox.exec();
}

void MainWindow::dataHandler(){
    std::string dadosWifi = this->wifi->dataReceived().toStdString();
    ui->textEdit_Console->setText(ui->textEdit_Console->toPlainText()+QString::fromStdString(dadosWifi)+"\n");
    ui->textEdit_Console->verticalScrollBar()->setSliderPosition(ui->textEdit_Console->verticalScrollBar()->maximum());
}

//--------------------------EVENTS: WIFI------------------------

void MainWindow::on_pushButtonConnect_clicked()
{
    QString ip = ui->lineEdit_IP->text();
    quint16 port = ui->lineEdit_Port->text().toShort();

    this->wifi = new Client(ip,port);
    connect(wifi, SIGNAL(connectionSuccessful()),this,SLOT(Conectado()));
    connect(wifi, SIGNAL(hasReadData()),this,SLOT(dataHandler()));
}

void MainWindow::on_pushButton_Disconnect_clicked()
{
    if(this->wifi){
        disconnect(wifi, SIGNAL(hasReadData()),this,SLOT(dataHandler()));
        delete this->wifi;
        this->wifi = nullptr;

        QMessageBox msgBox;
        msgBox.setText("Dispositivo Desconectado!");
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_Enviar_clicked()
{
    if(this->wifi){
        this->wifi->writeData(ui->lineEdit->text());
    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    this->on_pushButton_Enviar_clicked();
}

// END --------------------------EVENTS: WIFI------------------------



//------------------------- CINEMÁTICA INVERSA--------------------------------


void MainWindow::calcularAngulos(LinAlg::Matrix<double> posicoes){

    LinAlg::Matrix<double> target;
    PSO<double> p;

    for (unsigned i =1;i<=posicoes.getNumberOfRows();++i){
        target = posicoes.getRow(i);

        LinAlg::Matrix<double> resultado = p.Optimize(target);

        double O1 = resultado(1,1), O2 = resultado(1,2), O3 = resultado(1,3), O4 = resultado(1,4), O5 = resultado(1,5);

        double x = 10*cos(O5)*(cos(O1)*cos(O2)*sin(O3) + cos(O1)*cos(O3)*sin(O2)) + 24*cos(O1)*cos(O2) + 10*sin(O5)*(cos(O4)*(cos(O1)*cos(O2)*cos(O3) - cos(O1)*sin(O2)*sin(O3)) + sin(O1)*sin(O4)) + 14*cos(O1)*cos(O2)*sin(O3) + 14*cos(O1)*cos(O3)*sin(O2);
        double y = 10*cos(O5)*(cos(O2)*sin(O1)*sin(O3) + cos(O3)*sin(O1)*sin(O2)) + 24*cos(O2)*sin(O1) + 10*sin(O5)*(cos(O4)*(cos(O2)*cos(O3)*sin(O1) - sin(O1)*sin(O2)*sin(O3)) - cos(O1)*sin(O4)) + 14*cos(O2)*sin(O1)*sin(O3) + 14*cos(O3)*sin(O1)*sin(O2);
        double z = 24*sin(O2) - 14*cos(O2 + O3) + 5*sin(O2 + O3)*sin(O4 + O5) - 10*cos(O2 + O3)*cos(O5) - 5*sin(O2 + O3)*sin(O4 - O5) + 8;

        angulos = angulos || resultado;

    }

    std::string qposicao ; qposicao << posicoes;
    ui->textEdit_Deslocamentos->setText(QString::fromStdString(qposicao));

    std::string qangulos; qangulos << angulos;
    ui->textEdit_Angulos->setText(QString::fromStdString(qangulos));

    std::cout << posicao << std::endl;
    std::cout << angulos << std::endl;

}

void MainWindow::calcularTrajetoria(){

    LinAlg::Matrix<double> new_posicao, track, destino;

    new_posicao = posicao | LinAlg::Matrix<double>(3,1);

    destino = ui->lineEdit_Destino->text().toStdString().c_str();

    for (unsigned i =1;i<=new_posicao.getNumberOfRows();++i){
        track = track || new_posicao.getRow(i);
        track = track || MoveZ(new_posicao.getRow(i),10);
        track = track || MoveZ(destino,10);
        track = track || destino;
    }

    std::cout << track << std::endl;

    calcularAngulos(track);

}

LinAlg::Matrix<double> MainWindow::MoveX(LinAlg::Matrix<double> posicao, double p){
    LinAlg::Matrix<double> temp = posicao;

    temp(1,1) = temp(1,1)+p;

    return temp;

}

LinAlg::Matrix<double> MainWindow::MoveY(LinAlg::Matrix<double> posicao, double p){
    LinAlg::Matrix<double> temp = posicao;

    temp(1,2) = temp(1,2)+p;

    return temp;

}

LinAlg::Matrix<double> MainWindow::MoveZ(LinAlg::Matrix<double> posicao, double p){
    LinAlg::Matrix<double> temp = posicao;

    temp(1,3) = temp(1,3)+p;

    return temp;

}

//--------------------------EVENTS: CINEMÁTICA INVERSA------------------------

void MainWindow::on_pushButton_GetPositions_clicked()
{
    if (!qdt.isNull()){
        std::string qposicao ; qposicao << posicao;
        ui->textEdit_PosObj->setText(QString::fromStdString(qposicao));
        ui->label_QtdObj->setText(QString::fromStdString(std::to_string(posicao.getNumberOfRows())));
    }
}

void MainWindow::on_pushButton_GetTrack_clicked()
{
    if (!qdt.isNull()){
        calcularTrajetoria();
    }
}

void MainWindow::on_pushButton_GenSteps_clicked()
{
    steps = angulos;
    for (unsigned int i = 1; i<=steps.getNumberOfRows();++i){
        for (unsigned int j = 1; j<=steps.getNumberOfColumns();++j){
            steps(i,j) = steps(i,j)/0.1125;
        }
    }
//    std::cout << steps << std::endl;

    stepstrack = steps;
    for (unsigned int i = 2; i<=steps.getNumberOfRows();++i){
        for (unsigned int j = 1; j<=steps.getNumberOfColumns();++j){
            stepstrack(i,j) = stepstrack(i,j)-steps(i-1,j);
        }
    }
//    std::cout << stepstrack << std::endl;
    string str; str << stepstrack;
    ui->textEdit_StepTrack->setText(QString::fromStdString(str));

    string stepstrack_str; stepstrack_str <<= stepstrack;
    ui->lineEdit->setText(QString::fromStdString(stepstrack_str));
}

// END --------------------------EVENTS: CINEMÁTICA INVERSA------------------------




