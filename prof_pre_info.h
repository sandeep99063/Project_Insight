#ifndef PROF_PRE_INFO_H
#define PROF_PRE_INFO_H
#include "prof_info.h"
#include <QDialog>
#include "QtSql"
namespace Ui {
class prof_pre_info;
}

class prof_pre_info : public QDialog
{
    Q_OBJECT

public:
    explicit prof_pre_info(QWidget *parent = 0);
    QSqlDatabase my11;
       bool connopen()
       {


       my11=QSqlDatabase::addDatabase("QSQLITE");
       my11.setDatabaseName("C:/Sqlite_1/proff_login.sqlite");
       if(!my11.open())
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
        my11.close();
        my11.removeDatabase(QSqlDatabase::defaultConnection);
       }
    ~prof_pre_info();

private slots:


private:
    Ui::prof_pre_info *ui;
};

#endif // PROF_PRE_INFO_H
