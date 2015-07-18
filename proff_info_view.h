#ifndef PROFF_INFO_VIEW_H
#define PROFF_INFO_VIEW_H

#include <QDialog>

namespace Ui {
class Proff_info_view;
}

class Proff_info_view : public QDialog
{
    Q_OBJECT

public:
    explicit Proff_info_view(QWidget *parent = 0);
    ~Proff_info_view();

private:
    Ui::Proff_info_view *ui;
};

#endif // PROFF_INFO_VIEW_H
