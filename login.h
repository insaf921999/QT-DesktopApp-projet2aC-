#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_button_login_clicked();

  //  void on_pushButton_2_clicked();

  //  void on_pushButton_3_clicked();

   // void on_pushButton_3_clicked();

private:
    Ui::login *ui;

};
#endif // LOGIN_H
