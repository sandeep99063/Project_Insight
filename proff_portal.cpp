#include "proff_portal.h"
#include "ui_proff_portal.h"

Proff_portal::Proff_portal(QWidget *parent,QString s) :
    QDialog(parent),
    ui(new Ui::Proff_portal)
{
    prof_pre_info co1;
    ui->setupUi(this);
    co1.connopen();
    QSqlQuery qry,qry1,qry2;
    qry.prepare("select name from info where username='"+s+"'");
     qry.exec();
    while (qry.next()) {
            QSqlRecord record = qry.record();
             ui->label_name->setText(record.value(0).toString());
        }
    qry1.prepare("select dept from info where username='"+s+"'");
    qry1.exec();
    while (qry1.next()) {
            QSqlRecord record = qry1.record();
             ui->label_dept->setText(record.value(0).toString());
        }
    qry2.prepare("select email id from info where username='"+s+"'");
    qry2.exec();
    while (qry2.next()) {
            QSqlRecord record = qry2.record();
             ui->label_email->setText(record.value(0).toString());
        }
    co1.connclose();
}

Proff_portal::~Proff_portal()
{
    delete ui;
}
