#include "gestion_cartesolde.h"
#include "ui_gestion_cartesolde"

#include <iostream>

using namespace std;
gestion_cartesolde::gestion_cartesolde(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_cartesolde)
{
    ui->setupUi(this);


}
