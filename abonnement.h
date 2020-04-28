#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include "abonnementcode.h"
#include <QDialog>
#include "smtp.h"

namespace Ui {
class abonnement;
}

class abonnement : public QDialog
{
    Q_OBJECT

public:
    explicit abonnement(QWidget *parent = nullptr);
    ~abonnement();

private slots:
    void on_pushButton_R_clicked();
 void sendMail_abon();
 void mailSent(QString );




    void on_ajouter_abon_clicked();

    void on_supp_abon_clicked();

    void on_midifer_abon_clicked();

    void on_pushButton_4_retour_clicked();

private:
    Ui::abonnement *ui;
  abonnementCode  tmpabonnement;
};

#endif // ABONNEMENT_H
