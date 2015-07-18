#ifndef UPDATES_H
#define UPDATES_H

#include <QDialog>
#include <QtSql>
#include "portal.h"
#include <QString>
namespace Ui {
class updates;
}

class updates : public QDialog
{
    Q_OBJECT

public:
    explicit updates(QWidget *parent = 0,QString sq="sss");
    //------------------------------------------
    QSqlDatabase my;
       bool connopen()
       {


       my=QSqlDatabase::addDatabase("QSQLITE");
       my.setDatabaseName("C:/Sqlite_1/latestnews.sqlite");
       if(!my.open())
       {
           qDebug()<<"DataBase Not COnnected....";
           return false;
       }
       else
       {
        qDebug()<<"DataBase Connected....";
        return true;
       }
   }
       void connclose()
       {
        my.close();
        my.removeDatabase(QSqlDatabase::defaultConnection);
       }
    //------------------------------------------
    ~updates();

private slots:
       void on_pushButton_clicked();

private:
    Ui::updates *ui;
};

#endif // UPDATES_H
