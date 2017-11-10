#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QCamera>
#include <QTimer>
#include <QDate>
#include <QThread>
#include <QVideoWidget>
#include <QCameraImageCapture>
#include <QScreen>
#include <QCameraInfo>
#include "imageconversion.h"
#include "grayimage.h"
#include "binaryimage.h"
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update();

    void Conectado();

    void dataHandler();

    void on_pushButton_clicked();

    void timerClock( unsigned clockTime);

    void result_view(QImage &img,bool state = true,bool colors=true);

    void processCaptureImage(int requestId,const QImage &img);

    void on_select_blue_currentIndexChanged(int index);

    void on_select_red_currentIndexChanged(int index);

    void filtro(const ImageProcessing::GrayImage<unsigned> &gray_img,const double    filter_value,const bool color,const unsigned scale = 3);

    void dilation(const ImageProcessing::BinaryImage &bin,const bool color);

    void erosion(const ImageProcessing::BinaryImage &bin, const bool color);

    void linearizar(const ImageProcessing::GrayImage<unsigned> &gray_img,const unsigned scale,const bool color,const unsigned index);

    void bound(const ImageProcessing::GrayImage<unsigned> &grayImgs,const ImageProcessing::BinaryImage &imgs,const bool color);

    void on_pushButtonConnect_clicked();

    void on_pushButton_Disconnect_clicked();

    void on_select_blue_0_currentIndexChanged(int index);

    void on_button_blue_0_clicked();

    void on_refresh_clicked();

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

signals :
    void emit_result();

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QVideoWidget *viewfinder;
    QCameraImageCapture *imageCapture;
//    ----
    QImage img,Qimg_blue[6],Qimg_red[6];
    QImage Qimg_blue_,Qimg_red_;

    ImageProcessing::RGBImage<unsigned>mat_complete,rgb_blue,rgb_red;
    ImageProcessing::GrayImage<unsigned>gray_blue,gray_red;
    ImageProcessing::BinaryImage bina_blue,bina_red;
    int select_blue_0_index,select_red_0_index;
    int select_blue_1_index,select_red_1_index;

//   VARIAVEIS WIFI
    QPixmap *mypix ;
    Client *wifi;
    QString dataToSend;

};

#endif // MAINWINDOW_H
