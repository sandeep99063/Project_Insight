#include "quest.h"
#include "ui_quest.h"
#include "QtSql"
#include "QDebug"
#include "QPixmap"

#include "QMessageBox"
QString sa;
Quest::Quest(QWidget *parent,QString s) :
    QDialog(parent),
    ui(new Ui::Quest)
{
    sa=s;
    ui->setupUi(this);
    QPixmap pix1(":/myimg/1122.jpg");
    ui->img->setPixmap(pix1);
    QPixmap pix11(":/myimg/qq.png");
    ui->img_ques->setPixmap(pix11);

    this->setWindowTitle("Question_Zone");
    co1=QSqlDatabase::addDatabase("QSQLITE");
  co1.setDatabaseName("C:/Sqlite_1/question_bank.sqlite");
    if(!co1.open())
  {
      ui->msg2->setText("DataBase Not COnnected....");
  }
  else
  {
      ui->msg2->setText("DataBase COnnected....");
  }

}

Quest::~Quest()
{
    delete ui;
}

void Quest::on_pushButton_submit_clicked()
{

    QString str;
   str=ui->textEdit_ques->toPlainText();
   if(str.isEmpty())
   {
       QMessageBox::information(this,"InValid_Submission","Question Field is Empty ");
   }
   else
   {

    if(!co1.open())
    {
        qDebug()<<"Failed Attempt";
    }

    co1.open();
    QSqlQuery qyy,qryy;


    qyy.prepare("INSERT INTO bank(question,usernaam) VALUES('"+str+"','"+sa+"')");

     if(qyy.exec())
    {

       co1.close();
       QMessageBox::information(this,"Submisssion","||_Addition_|| Successful");
       this->hide();
       portal *p=new portal(this,sa);
       p->show();
    }
    else
    {

      QMessageBox::critical(this,"AttemptError_Info",qyy.lastError().text());
    }
   }
}

void Quest::on_pushButton_clicked()
{
    this->hide();
    portal *p=new portal(this,sa);
    p->show();
}
