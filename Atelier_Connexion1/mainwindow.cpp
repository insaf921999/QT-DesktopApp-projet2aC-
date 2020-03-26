#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "dialog.h"
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include "connection.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_8_clicked()
{


    QString username=ui->lineUsername->text();
    QString password=ui->Password->text();
    if (username=="test" &&  password=="test"){
        QMessageBox::information(this,"Login","Username  and password are correct");
        Dialog a;
        a.setModal(true);
        a.exec();
    }


}





