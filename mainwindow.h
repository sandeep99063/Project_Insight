#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include "sign_up.h"
#include "prof_pre_info.h"
#include "proff_portal.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QSqlDatabase mydb,db;
       bool connopen()
       {


       db=QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName("C:/Sqlite_1/Login_Stud.sqlite");
       if(!db.open())
       {
           qDebug()<<"DataBase Not COnnected....";
           return false;
       }
       else
       {
        qDebug()<<"DataBase COnnected....";
        return true;
       }
   }
       void connclose()
       {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
       }
    ~MainWindow();

private slots:
    void on_pushButton_signup_clicked();

    void on_pushButton_submit_clicked();

    void on_fb_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
