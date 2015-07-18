#include "proff_info_view.h"
#include "ui_proff_info_view.h"

Proff_info_view::Proff_info_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Proff_info_view)
{
    ui->setupUi(this);
}

Proff_info_view::~Proff_info_view()
{
    delete ui;
}
