#include "stat.h"
#include "ui_stat.h"
#include "parking.h"
Stat::Stat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stat)
{
    ui->setupUi(this);
    ui->tableDispo->setModel(tableDispo.afficherDispo());
}

Stat::~Stat()
{
    delete ui;
}
