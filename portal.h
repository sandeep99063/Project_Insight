#ifndef PORTAL_H
#define PORTAL_H

#include <QDialog>
#include "mainwindow.h"
#include "quest.h"
#include "QString"
#include"question_view.h"
#include "updates.h"
#include "prof_pre_info.h"
namespace Ui {
class portal;
}

class portal : public QDialog
{
    Q_OBJECT

public:
    explicit portal(QWidget *parent = 0,QString s="sa");
    ~portal();

private slots:
    void on_pushButton_question_clicked();

    void on_pushButton_profileinfo_clicked();

    void on_pushButton_latestnews_clicked();

    void on_pushButton_postedques_clicked();

    void on_pushButton_profinfo_clicked();
    void on_pushButton_clicked();

public slots:



private:
    Ui::portal *ui;
};

#endif // PORTAL_H
