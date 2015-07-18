#ifndef PROFF_PORTAL_H
#define PROFF_PORTAL_H

#include <QDialog>
#include "prof_pre_info.h"
namespace Ui {
class Proff_portal;
}

class Proff_portal : public QDialog
{
    Q_OBJECT

public:
    explicit Proff_portal(QWidget *parent = 0,QString s="sss");
    ~Proff_portal();

private:
    Ui::Proff_portal *ui;
};

#endif // PROFF_PORTAL_H
