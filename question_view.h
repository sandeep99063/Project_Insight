#ifndef QUESTION_VIEW_H
#define QUESTION_VIEW_H

#include <QDialog>
#include "QtSql"
#include "QDebug"
#include "portal.h"

namespace Ui {
class question_view;
}

class question_view : public QDialog
{
    Q_OBJECT

public:
    explicit question_view(QWidget *parent = 0,QString sa="ssss");
    //------------------------------------------
    QSqlDatabase m1;
       bool connopen()
       {


       m1=QSqlDatabase::addDatabase("QSQLITE");
       m1.setDatabaseName("C:/Sqlite_1/question_bank.sqlite");
       if(!m1.open())
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
        m1.close();
        m1.removeDatabase(QSqlDatabase::defaultConnection);
       }
    //------------------------------------------
    ~question_view();




private slots:
       void on_pushButton_menu_clicked();

       void on_tableView_pressed(const QModelIndex &index);

private:
    Ui::question_view *ui;
};

#endif // QUESTION_VIEW_H
