#include "portal.h"
#include "ui_portal.h"
#include "question_view.h"
#include "QPixmap"
#include "mainwindow.h"
#include "QtSql"
#include "QMessageBox"
#include "QDebug"
#include "prof_info.h"
#include "stud_info.h"
QString g;
portal::portal(QWidget *parent,QString s) :
    QDialog(parent),
    ui(new Ui::portal)
{

    MainWindow co;
    g=s;
    ui->setupUi(this);
    this->setWindowTitle("||_Student_Portal_||");
    QPixmap pix(":/myimg/1126.jpg");
    ui->img_background->setPixmap(pix);

    //----------------------------------------------------

    co.connopen();
    QSqlQuery qry,qry1,qry2,qry3;
    qry.prepare("select name from login where username='"+s+"'");



    qry.exec();



   // QSqlQuery query;
       // QString queryString = "SELECT date FROM TABLE";
       // query.exec(queryString);

    while (qry.next()) {
            QSqlRecord record = qry.record();
             ui->label_nameset->setText(record.value(0).toString());
        }
    qry1.prepare("select year from login where username='"+s+"'");
    qry1.exec();
    while (qry1.next()) {
            QSqlRecord record = qry1.record();
             ui->label_yearset->setText(record.value(0).toString());
        }

     qry2.prepare("select branch from login where username='"+s+"'");
     qry2.exec();
    while (qry2.next()) {
            QSqlRecord record = qry2.record();
             ui->label_branchset->setText(record.value(0).toString());
        }
    qry3.prepare("select regno from login where username='"+s+"'");
        qry3.exec();
    while (qry3.next()) {
            QSqlRecord record = qry3.record();
             ui->label_regno_set->setText(record.value(0).toString());
        }

    co .connclose();
    //----------------------------------------------------
}

portal::~portal()
{
    delete ui;
}

void portal::on_pushButton_question_clicked()
{
this->hide();
Quest *q=new Quest(this,g);
q->show();

}

void portal::on_pushButton_profileinfo_clicked()
{
this->hide();
Stud_info *s=new Stud_info(this,g);
s->show();
}

void portal::on_pushButton_latestnews_clicked()
{
    this->hide();
  updates *u=new updates(this,g);
  u->show();
}

void portal::on_pushButton_postedques_clicked()
{
  this->hide();
question_view *q=new question_view(this,g);
q->show();

}

void portal::on_pushButton_profinfo_clicked()
{
this->hide();
    prof_pre_info *p=new prof_pre_info();
    p->show();
}

void portal::on_pushButton_clicked()
{
    this->hide();
  MainWindow *m=new MainWindow();
  m->show();
}
