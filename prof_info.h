#ifndef PROF_INFO_H
#define PROF_INFO_H

#include <QDialog>
#include "QtSql"
namespace Ui {
class Prof_info;
}

class Prof_info : public QDialog
{
    Q_OBJECT

public:
    explicit Prof_info(QWidget *parent = 0,int s=0);
   /* //-------------------------------------
    QSqlDatabase my1;
       bool connopen()
       {


       my1=QSqlDatabase::addDatabase("QSQLITE");
       my1.setDatabaseName("C:/Sqlite_1/prof.sqlite");
       if(!my1.open())
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
        my1.close();
        my1.removeDatabase(QSqlDatabase::defaultConnection);
       }
    //--------------------------------------*/
    ~Prof_info();

private:
    Ui::Prof_info *ui;
};

#endif // PROF_INFO_H
