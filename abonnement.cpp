#include "abonnement.h"
#include "ui_abonnement.h"
#include "choisir.h"
#include "abonnementcode.h"
#include <QApplication>
#include <QMessageBox>
#include <QPixmap>


abonnement::abonnement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::abonnement)
{
    ui->setupUi(this);
    ui->tab_afficher_client->setModel(tmpabonnement.afficher());
}

abonnement::~abonnement()
{
    delete ui;
}


void abonnement::on_ajouter_abon_clicked()
{
    int id = ui->lineEditid_abon->text().toInt();
        QString nom= ui->lineEditnom_abon->text();
        QString prenom= ui->lineEditprenom_abon->text();
         int numplace = ui->lineEditprenom_2_abon->text().toInt();
        QDate datenaiss = ui->dateEdit_2_abon->date();
       QDate datedeb=ui->dateEdit_3_abon->date();
        QDate datefin=ui->dateEdit_4_abon->date();

      abonnementCode c(id,nom,prenom,numplace,datenaiss,datedeb,datefin);
      bool test=c.ajouter();
      if((test)&&(id))
    {ui->tab_afficher_client->setModel(tmpabonnement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("client ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void abonnement::on_supp_abon_clicked()
{    int id = ui->lineEditid_2_abon->text().toInt();
     bool test= tmpabonnement.supprimer(id);
     if(test)
     {ui->tab_afficher_client->setModel( tmpabonnement.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnement"),
                     QObject::tr("abonnement supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


}

void abonnement::on_midifer_abon_clicked()
{  int num = ui->lineEditprenom_3_abon->text().toInt();
    int qt_produit = ui->lineEditid_6_abon->text().toInt();

     bool test= tmpabonnement.modifier(num,qt_produit);
    if(test)
    {ui->tab_afficher_client->setModel( tmpabonnement.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr(" abonnement modifié"),
                    QObject::tr("abonnement modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification abonnement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void abonnement::on_pushButton_4_retour_clicked()
{choisir c;
    c.exec();

}






void abonnement::on_pushButton_R_clicked()
{
    int id = ui->lineEdit_r_abon->text().toInt();
       bool test=tmpabonnement.tester(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("abonnement existe"),
                        QObject::tr("abonnement existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_rechercher_abonnement->setModel( tmpabonnement.afficherID(id));//refresh

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("abonnement n'existe pas"),
                        QObject::tr("abonnement n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void abonnement::sendMail_abon()
{
    Smtp* smtp = new Smtp("dombe.airline@gmail.com","dombedombe2020","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


     smtp->sendMail("dombe.airline@gmail.com", ui->rcpt_abon->text() , ui->subject_abon->text(),ui->msg_abon->toPlainText());

}

void abonnement::mailSent(QString status)
{
    if (status=="message")
    {QMessageBox::information( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );}
}
