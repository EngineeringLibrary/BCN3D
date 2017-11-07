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
    void on_pushButton_clicked();

    void timerClock( unsigned clockTime);

    void result_view(QImage &img,bool state = true,bool colors=true);

    void processCaptureImage(int requestId,const QImage &img);

    void on_select_blue_currentIndexChanged(int index);

    void on_select_red_currentIndexChanged(int index);

signals :
    void emit_result();

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QVideoWidget *viewfinder;
    QCameraImageCapture *imageCapture;
    QImage img,Qimg_blue[6],Qimg_red[6],imgB,imgR;
//    QPixmap mypix;
    QPixmap *mypix ;

};

#endif // MAINWINDOW_H
