#include "changepass.h"
#include "ui_changepass.h"
#include "QtSql"
#include "QMessageBox"
#include "QDebug"
QString d;
changepass::changepass(QWidget *parent,QString s) :
    QDialog(parent),
    ui(new Ui::changepass)
{
    ui->setupUi(this);
    QPixmap pix1(":/myimg/1122.jpg");
    ui->img->setPixmap(pix1);
    QPixmap pix11(":/myimg/pass.png");
    ui->img_label->setPixmap(pix11);
    d=s;
    this->setWindowTitle("||_Password_Change_||");

}

changepass::~changepass()
{
    delete ui;
}

void changepass::on_pushButton_clicked()
{ MainWindow co;
    portal po;
    QString passw,passwold,repass;
    passw=ui->lineEdit_new->text();
      passwold=ui->lineEdit_old->text();
        repass=ui->lineEdit_renew->text();
        if(!repass.isEmpty()&& !passw.isEmpty() && !passwold.isEmpty())
        {
        if(passw==passwold)
        {
          QMessageBox::information(this,"||_Attempt Failed_||","New Password is Same as Old Password");
          ui->lineEdit_new->clear();
          ui->lineEdit_old->clear();
          ui->lineEdit_renew->clear();
        }
        else
        {
            if(repass==passw)
            {
    if(!co.connopen())
    {
        qDebug()<<"Failed Attempt";
    }
    co.connopen();
    QSqlQuery qyy;


    qyy.prepare("UPDATE login SET password='"+passw+"' WHERE username='"+d+"'");


     if(qyy.exec())
    {

       co.connclose();
       QMessageBox::information(this,"||_Successfull_||","Updation Successfull");
       this->hide();
       Stud_info *sw=new Stud_info(this,d);
       sw->show();


    }
    else
    {

      QMessageBox::critical(this,"AttemptError_Info",qyy.lastError().text());
    }
            }
            else
            {
                QMessageBox::information(this,"||_Password Mismatch_||","New Password and Re-new Password Mismatch");
                ui->lineEdit_new->clear();
                ui->lineEdit_old->clear();
                ui->lineEdit_renew->clear();
            }
        }
        }
        else
        {
            QMessageBox::information(this,"||_empty box_||","Some Password field is empty");
        }
}
