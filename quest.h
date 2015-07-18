#ifndef QUEST_H
#define QUEST_H

#include <QDialog>
#include "QDebug"
#include "QtSql"
#include "QSqlDatabase"
#include "portal.h"

namespace Ui {
class Quest;
}

class Quest : public QDialog
{
    Q_OBJECT

public:
    explicit Quest(QWidget *parent = 0,QString sa="ssss");
    QSqlDatabase co1;
        ~Quest();

private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_clicked();

private:
    Ui::Quest *ui;
};

#endif // QUEST_H
