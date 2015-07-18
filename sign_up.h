#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Sign_Up;
}

class Sign_Up : public QDialog
{
    Q_OBJECT

public:
    explicit Sign_Up(QWidget *parent = 0);

    ~Sign_Up();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Sign_Up *ui;
};

#endif // SIGN_UP_H
