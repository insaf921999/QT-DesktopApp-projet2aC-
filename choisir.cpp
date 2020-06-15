#include "choisir.h"
#include "ui_choisir.h"
#include "parkinng.h"
#include "abonnement.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
choisir::choisir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choisir)
{
    ui->setupUi(this);
}

choisir::~choisir()
{
    delete ui;
}

void choisir::on_pushButton_clicked()
{
parkinng p;
p.exec();

}

void choisir::on_pushButton_2_clicked()
{
    abonnement a;
    a.exec();
}

void choisir::on_pushButton_3_clicked()
{
}
