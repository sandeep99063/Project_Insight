#include "prof_pre_info.h"
#include "ui_prof_pre_info.h"

prof_pre_info::prof_pre_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prof_pre_info)
{
    ui->setupUi(this);
    this->setWindowTitle("Expert Details");
    QSqlQueryModel *mod=new QSqlQueryModel();
      connopen();
      QSqlQuery *qry=new QSqlQuery(my11);
      qry->prepare("SELECT * FROM info");
      if(qry->exec())

      {

      }


      mod->setQuery(*qry);
      ui->tableView->setModel(mod);
     connclose();
}

prof_pre_info::~prof_pre_info()
{
    delete ui;
}


