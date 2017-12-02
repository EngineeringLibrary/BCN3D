#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QCamera>
#include <QtGui>
#include <QtWidgets>
#include <QTimer>
#include <QDate>
#include <QThread>
#include <QVideoWidget>
#include <QCameraImageCapture>
#include <QScreen>
#include <QCameraInfo>
#include "result_view.h"
#include "imageconversion.h"
#include "grayimage.h"
#include "binaryimage.h"
#include "client.h"
#include "SistemasdeControle/headers/optimizationLibs/pso.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void set_saved_img(const bool use);

    void on_refresh_clicked();

    void processamentoImagem();

    void calcularAngulos(LinAlg::Matrix<double> posicoes);
    void calcularTrajetoria();
    LinAlg::Matrix<double> MoveX(LinAlg::Matrix<double> posicao, double p);
    LinAlg::Matrix<double> MoveY(LinAlg::Matrix<double> posicao, double p);
    LinAlg::Matrix<double> MoveZ(LinAlg::Matrix<double> posicao, double p);


public slots:


private slots:

    bool checkCameras(void);

    void Conectado();

    void dataHandler();

    void on_pushButton_clicked();

    void result_view(QImage &img,bool state = true,bool colors=true);

    void enableTab(int except);

    void disableTab(int except);




// funcoes matematicas
    void filtro(const ImageProcessing::GrayImage<unsigned> &gray_img,const double    filter_value,const bool color,const unsigned scale = 3);

    void dilation(const ImageProcessing::BinaryImage &bin,const bool color);

    void erosion(const ImageProcessing::BinaryImage &bin, const bool color);

    void linearizar(const ImageProcessing::GrayImage<unsigned> &gray_img,const unsigned scale,const unsigned scale2,const bool color,const unsigned index);

    void bound(const ImageProcessing::BinaryImage &imgs,const bool color);

    void histrograma(const ImageProcessing::GrayImage<unsigned> &grayImg);

    void centroid( ImageProcessing::BinaryImage &bin_img,const unsigned color);


    // eventos

    void processCaptureImage(int requestId,const QImage &img);

    void on_pushButtonConnect_clicked();

    void on_pushButton_Disconnect_clicked();

    void on_select_blue_0_currentIndexChanged(int index);

    void on_button_blue_0_clicked();

    void on_select_red_0_currentIndexChanged(int index);

    void on_button_red_0_clicked();

    void on_select_red_1_currentIndexChanged(int index);

    void on_button_red_1_clicked();

    void on_select_blue_1_currentIndexChanged(int index);

    void on_button_blue_1_clicked();

    void on_select_blue_2_currentIndexChanged(int index);

    void on_button_blue_2_clicked();

    void on_select_red_2_currentIndexChanged(int index);

    void on_button_red_2_clicked();

    void on_select_blue_3_currentIndexChanged(int index);

    void on_button_blue_3_clicked();

    void on_select_red_3_currentIndexChanged(int index);

    void on_button_red_3_clicked();

    void on_button_blue_5_clicked();

    void on_check_saved_img_clicked(bool checked);

    void on_button_blue_4_clicked();

    void on_button_red_4_clicked();

    void on_set_saved_img_0_clicked(bool checked);

    void on_button_red_5_clicked();

    void on_actionExit_triggered();

    void on_actionPreview_triggered();

    void on_actionWebcam_triggered();

    void on_actionButtons_triggered();

    void on_actionConnect_triggered();

    void on_actionAlualizar_Imagem_triggered();

    void on_actionusar_imagem_salva_triggered();

    void on_pushButton_GetPositions_clicked();

    void on_pushButton_GetTrack_clicked();

    void on_pushButton_Enviar_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_GenSteps_clicked();

    void on_ImageProcess_clicked();

    void on_resizeImg_valueChanged(int value);

    void on_actionProcessar_triggered();

signals :

private:
    Dialog *result_img;
    Ui::MainWindow *ui;
    QCamera *camera;
    QVideoWidget *viewfinder;
    QCameraImageCapture *imageCapture;
//    ----
    QImage *img,Qimg_blue[6],Qimg_red[6];
    QImage *Qimg_blue_,*Qimg_red_;

    ImageProcessing::RGBImage<unsigned>*mat_complete,*rgb_blue,*rgb_red;
    ImageProcessing::GrayImage<unsigned>*gray_blue,*gray_red;
    LinAlg::Matrix<unsigned> *histogramMatrix;
    LinAlg::Matrix<unsigned> qdt, segmentedMatrix;
    LinAlg::Matrix<unsigned> centroids;

    LinAlg::Matrix<unsigned> posicao;
    LinAlg::Matrix<double> angulos;
    LinAlg::Matrix<double> trajetoria;
    LinAlg::Matrix<double> steps;
    LinAlg::Matrix<int> stepstrack;


//    LinAlg::Matrix<unsigned> *centroid;
    unsigned camCount;
    ImageProcessing::BinaryImage *bina_blue,*bina_red;
    int select_blue_0_index,select_red_0_index;
    int select_blue_1_index,select_red_1_index;
    unsigned area_blue[2],area_red[2];

//   VARIAVEIS WIFI
    QPixmap mypix = (QDir::currentPath()+"/imageCaptured.jpg");
    Client *wifi;
    QString dataToSend;

};

#endif // MAINWINDOW_H
