#ifndef GESTION_CARTESOLDE_H
#define GESTION_CARTESOLDE_H
#include <QMessageBox>
#include <QDialog>
#include "gestionclient.h"
#include "cartesolde.h"


namespace Ui {
class gestion_cartesolde ;

}
class gestion_cartesolde : public QDialog
{
    Q_OBJECT


public:
    explicit gestion_cartesolde (QWidget *parent = nullptr);
    ~gestion_cartesolde();



private:
    Ui::gestion_cartesolde *ui;
    cartesolde tmpcartesolde;
};

#endif // GESTION_CARTESOLDE_H
