#include "parking.h"
#include "ui_parking.h"

parking::parking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parking)
{
    ui->setupUi(this);
}

parking::~parking()
{
    delete ui;
}
