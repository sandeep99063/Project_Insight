#include "prof_info.h"
#include "ui_prof_info.h"
#include "QPixmap"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "QDebug"
Prof_info::Prof_info(QWidget *parent,int s) :
    QDialog(parent),
    ui(new Ui::Prof_info)
{
    ui->setupUi(this);
    this->setWindowTitle("||_Proffessor_Info_||");
    qDebug() <<s;
    if(s==1)
    {
   QFile file("D:/Prof_Pdf/sa.docx");
   if(!file.open(QIODevice::ReadOnly))
       QMessageBox::information(0,"Warning",file.errorString());
QTextStream in(&file);
ui->textBrowser->setText(in.readAll());
    }

}

Prof_info::~Prof_info()
{
    delete ui;
}
