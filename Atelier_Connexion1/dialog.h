#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include<QSqlQueryModel>
#include "agent.h"





namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_pushButton_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog *ui;
    Agent a;


};
#endif // DIALOG_H
