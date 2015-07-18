#include "stud_info.h"
#include "ui_stud_info.h"
#include "QtSql"
#include "QMessageBox"
#include "QPixmap"
#include "QDebug"
#include "QSql"
QString f;
Stud_info::Stud_info(QWidget *parent,QString s) :
    QDialog(parent),
    ui(new Ui::Stud_info)
{
    MainWindow co;

    f=s;
    ui->setupUi(this);
    QPixmap pix1(":/myimg/1122.jpg");
    ui->img->setPixmap(pix1);
    QPixmap pix11(":/myimg/wap.png");
    ui->img_label->setPixmap(pix11);
    this->setWindowTitle("||_Student_Info_||");
    //----------------------------------------------------
question_view conn;
    co.connopen();
    QSqlQuery qry,qry1,qry2,qry3,qry4,qry5;
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
             ui->label_regnoset->setText(record.value(0).toString());
        }
    qry4.prepare("select username from login where username='"+s+"'");
        qry4.exec();
    while (qry4.next()) {
            QSqlRecord record = qry4.record();
             ui->label_userset->setText(record.value(0).toString());
        }
     co .connclose();
    //------------------------------------------------------

     QSqlQueryModel *mod=new QSqlQueryModel();
         conn.connopen();
       QSqlQuery *qrrry=new QSqlQuery(conn.m1);
       qrrry->prepare("SELECT question FROM bank WHERE usernaam='"+s+"'");
       if(qrrry->exec())

       {

       }


       mod->setQuery(*qrrry);
       ui->tableView->setModel(mod);
     conn.connclose();






    //----------------------------------------------------
}

Stud_info::~Stud_info()
{
    delete ui;
}

void Stud_info::on_pushButton_changepass_clicked()
{
    this->hide();
    changepass *c=new changepass(this,f);
    c->show();

}

void Stud_info::on_pushButton_mainmenu_clicked()
{
    this->hide();
    portal *p=new portal(this,f);
    p->show();
}
