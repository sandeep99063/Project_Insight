#include "updates.h"
#include "ui_updates.h"
#include "QPixmap"
QString da;
updates::updates(QWidget *parent,QString sq) :
    QDialog(parent),
    ui(new Ui::updates)
{
    ui->setupUi(this);
    QPixmap pix1(":/myimg/1122.jpg");
    ui->img->setPixmap(pix1);
    QPixmap pix11(":/myimg/new.png");
    ui->img_news->setPixmap(pix11);

    da=sq;
    this->setWindowTitle("||_Latest_News_||");
    QSqlQueryModel *mod1=new QSqlQueryModel();
      connopen();
      QSqlQuery *qry=new QSqlQuery(my);
      qry->prepare("SELECT * FROM news");
      if(qry->exec())

      {

      }


      mod1->setQuery(*qry);
      ui->tableView->setModel(mod1);
     connclose();

}

updates::~updates()
{
    delete ui;
}

void updates::on_pushButton_clicked()
{
    this->hide();
    portal *p=new portal(this,da);
    p->show();
}
