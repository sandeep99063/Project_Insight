#ifndef STUD_INFO_H
#define STUD_INFO_H

#include <QDialog>
#include "mainwindow.h"
#include "changepass.h"
#include "question_view.h"
namespace Ui {
class Stud_info;
}

class Stud_info : public QDialog
{
    Q_OBJECT

public:
    explicit Stud_info(QWidget *parent = 0,QString s="sss");
    ~Stud_info();

private slots:
    void on_pushButton_changepass_clicked();

    void on_pushButton_mainmenu_clicked();

private:
    Ui::Stud_info *ui;
};

#endif // STUD_INFO_H
