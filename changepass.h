#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QDialog>
#include "mainwindow.h"
#include "stud_info.h"
#include "portal.h"
namespace Ui {
class changepass;
}

class changepass : public QDialog
{
    Q_OBJECT

public:
    explicit changepass(QWidget *parent = 0,QString s="sss");
    ~changepass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::changepass *ui;
};

#endif // CHANGEPASS_H
