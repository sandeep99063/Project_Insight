#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql"
#include "QPixmap"
#include "sign_up.h"
#include "portal.h"
#include "QString"
#include "QDesktopServices"
#include "QUrl"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Portal");
    QPixmap pix1(":/myimg/1122.jpg");
    ui->img_background->setPixmap(pix1);
    QPixmap pix(":/myimg/12.png");
    ui->image_login->setPixmap(pix);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Sqlite_1/Login_Stud.sqlite");
    if(!mydb.open())
  {
      ui->label_conn->setText("DataBase Not Connected....");
  }
  else
  {
      ui->label_conn->setText("DataBase Connected....");
  }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_signup_clicked()
{
    this->hide();
    Sign_Up *si=new Sign_Up();
    si->show();
}

void MainWindow::on_pushButton_submit_clicked()
{

    QString user,pass;
    user=ui->lineEdit->text();
    pass=ui->lineEdit_2->text();
    if(!mydb.open())
    {
       ui->label_conn->setText("DataBase Not COnnected....");
    }

    QSqlQuery qry;
    qry.prepare("select * from login WHERE username='"+user+"' and password='"+pass+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {

           ui->label_conn->setText("Username And Password Is Correct..");
            mydb.close();
            if(ui->radioButton_stud->isChecked())
            {
                if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty())

                {this->hide();
                     portal *p=new portal(this,user);
                     p->show();
                }else
                    QMessageBox::information(this,"Unauthorised Access","Username And Password Field Empty");
            }
            else
                QMessageBox::information(this,"WElcoem","Proffesor Info need WOrkout");

        }

        if(count>1)
            ui->label_conn->setText("Duplicate Username And Passsword..");
        if(count<1)
            ui->label_conn->setText("Username And Password Is InCorrect..");

    }

}
/*
 * this->hide();
portal *p=new portal();
p->show();
*/

void MainWindow::on_fb_clicked()
{
    QString link="https://www.facebook.com/sandy201194";
    QDesktopServices::openUrl(QUrl(link));
}
