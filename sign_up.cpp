#include "sign_up.h"
#include "ui_sign_up.h"
#include "QPixmap"
#include "QSqlQuery"
#include "QMessageBox"
#include <QSql>
#include "QSqlError"
Sign_Up::Sign_Up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_Up)
{
    ui->setupUi(this);
    this->setWindowTitle("Join_Us");
    QPixmap pix(":/myimg/background3.jpg");
    ui->img_back->setPixmap(pix);

}

Sign_Up::~Sign_Up()
{
    delete ui;
}

void Sign_Up::on_pushButton_clicked()
{
   MainWindow co;
    QString naam,saal,regnumber,bran,user,pass,repass;
    naam=ui->lineEdit_name->text();
    saal=ui->lineEdit_year->text();
     regnumber=ui->lineEdit_regno->text();
     bran=ui->lineEdit_branch->text();
     user=ui->lineEdit_username->text();
       pass=ui->lineEdit_password->text();
       repass=ui->lineEdit_repassword->text();
       if(pass==repass)
       {
        if(!co.connopen())
        {
            qDebug()<<"Failed Attempt";
        }
        co.connopen();
        QSqlQuery qryy;


        qryy.prepare("INSERT INTO login(name,year,regno,branch,username,password) VALUES('"+naam+"','"+saal+"','"+regnumber+"','"+bran+"','"+user+"','"+pass+"')");

         if(qryy.exec())
        {
           ui->msg->setText("Addition Successful");
           co.connclose();
           QMessageBox::information(this,"Addition Successful","Sign_Up Successful");
           ui->lineEdit_name->clear();
         this->hide();
           MainWindow *m=new MainWindow();
           m->show();

        }
        else
        {

         QMessageBox::critical(this,"AttemptError_Info",qryy.lastError().text());
         ui->msg->setText("Enter Unique Username");
         ui->lineEdit_name->clear();
         ui->lineEdit_branch->clear();
         ui->lineEdit_password->clear();
         ui->lineEdit_regno->clear();
         ui->lineEdit_repassword->clear();
         ui->lineEdit_year->clear();
         ui->lineEdit_username->clear();
        }
       }
       else
       {

        QMessageBox::warning(this,"INVALID_INPUT","Password &Re_Password didnot match");
        ui->lineEdit_name->clear();
        ui->lineEdit_branch->clear();
        ui->lineEdit_password->clear();
        ui->lineEdit_regno->clear();
        ui->lineEdit_repassword->clear();
        ui->lineEdit_year->clear();
        ui->lineEdit_username->clear();
     ui->msg->setText("Addition Unsuccessful");
       }
}

void Sign_Up::on_pushButton_2_clicked()
{
    this->hide();
  MainWindow *m=new MainWindow();
  m->show();
}
