#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
//#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void set_result_view(QImage &img,bool state, bool colors);

private slots:


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
