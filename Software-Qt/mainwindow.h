#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QCamera>
#include <QTimer>
#include <QDate>
#include <QVideoWidget>
#include <QCameraImageCapture>
#include <QScreen>
#include <QCameraInfo>
#include "imageconversion.h"


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

    void processCaptureImage(int requestId,const QImage &img);

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QVideoWidget *viewfinder;
    QCameraImageCapture *imageCapture;
    QImage img;

};

#endif // MAINWINDOW_H
