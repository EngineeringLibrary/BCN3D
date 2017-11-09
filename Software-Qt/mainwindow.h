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

    void filtro(const ImageProcessing::GrayImage<unsigned> &gray_img,const unsigned filter_value,const bool color,const unsigned scale = 3);

    void dilation(const ImageProcessing::BinaryImage &bin_blue,const ImageProcessing::BinaryImage &bin_red);

    void erosion(const ImageProcessing::BinaryImage &bin_blue,const ImageProcessing::BinaryImage &bin_red);

    void linearizar(const ImageProcessing::GrayImage<unsigned> &gray_blu,const ImageProcessing::GrayImage<unsigned> &gray_re,const unsigned scale_blue,const unsigned scale_red);

    void bound(const ImageProcessing::GrayImage<unsigned> &grayImgs,const ImageProcessing::BinaryImage &imgs,const bool color);

    void on_pushButtonConnect_clicked();

    void on_pushButton_Disconnect_clicked();

signals :
    void emit_result();

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QVideoWidget *viewfinder;
    QCameraImageCapture *imageCapture;
    QImage img,Qimg_blue[6],Qimg_red[6];

    ImageProcessing::RGBImage<unsigned>mat_complete,rgb_blue,rgb_red;
    ImageProcessing::GrayImage<unsigned>gray_blue,gray_red;
    ImageProcessing::BinaryImage bina_blue,bina_red;
//    QPixmap mypix;
    QPixmap *mypix ;
    Client *wifi;
    QString dataToSend;

};

#endif // MAINWINDOW_H
