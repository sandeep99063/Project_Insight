#include "question_view.h"
#include "ui_question_view.h"
#include "QDebug"
#include "QtSql"
#include "QMessageBox"
#include "QPixmap"
QString fa;
question_view::question_view(QWidget *parent,QString sa ) :
    QDialog(parent),
    ui(new Ui::question_view)
{
    ui->setupUi(this);
    QPixmap pix1(":/myimg/1122.jpg");
    ui->img->setPixmap(pix1);
    QPixmap pix11(":/myimg/qqq.png");
    ui->img_label->setPixmap(pix11);

    fa=sa;
    this->setWindowTitle("||_Questions_||");
    QSqlQueryModel *mod=new QSqlQueryModel();
connopen();
      QSqlQuery *qry=new QSqlQuery(m1);
      qry->prepare("SELECT * FROM bank");
      if(qry->exec())

      {

      }


      mod->setQuery(*qry);
      ui->tableView->setModel(mod);
     connclose();


}

question_view::~question_view()
{
    delete ui;
}



void question_view::on_pushButton_menu_clicked()
{
    this->hide();
    portal *p=new portal(this,fa);
    p->show();
}

void question_view::on_tableView_pressed(const QModelIndex &index)
{
    qDebug() <<" HEllo "<<index;
    QMessageBox::information(this,"Working","Hurray");
}
