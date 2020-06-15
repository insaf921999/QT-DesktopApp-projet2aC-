#include "parkinng.h"
#include "ui_parkinng.h"
#include "choisir.h"
#include <QApplication>
#include <QMessageBox>
#include <QPixmap>
#include "stat_no.h"
parkinng::parkinng(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parkinng)
{
    ui->setupUi(this);
     ui->tab_afficher_client->setModel(tmpparking.afficher());
    ui->comboBox_3->addItem("1");

    ui->comboBox_3->addItem("2");
    ui->comboBox_3->addItem("3");

    ui->comboBox_3->addItem("4");
     ui->lineEditcin->setStyleSheet("color: red;");
     ui->lineEditprenom->setStyleSheet("color: red;");

}

parkinng::~parkinng()
{
    delete ui;
}

void parkinng::on_pushButton_4_clicked()
{
    choisir c;
    c.exec();

}

void parkinng::on_pushButton_clicked()
{
    int id = ui->lineEditcin->text().toInt();
        QString prenom= ui->lineEditnumtel->text();
        int nbrplace= ui->lineEditprenom->text().toInt();
        int nbretage= ui->comboBox_3->currentText().toInt();
      parkingCode r(id,prenom,nbrplace,nbretage);
      bool test=r.ajouter();
      if(test)
    {ui->tab_afficher_client->setModel(tmpparking.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un parking"),
                      QObject::tr("parking ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un parking"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}

void parkinng::on_pushButton_2_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool test= tmpparking.supprimer(id);
    if(test)
    {ui->tab_afficher_client->setModel( tmpparking.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("parking supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void parkinng::on_pushButton_3_clicked()
{
    int num = ui->lineEdit_2->text().toInt();
    int qt_produit = ui->lineEdit_3->text().toInt();

     bool test= tmpparking.modifier(num,qt_produit);
    if(test)
    {ui->tab_afficher_client->setModel( tmpparking.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr(" parking modifié"),
                    QObject::tr("PARKING modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void parkinng::on_pushButton_RP_clicked()
{
    int id = ui->lineEdit_RP->text().toInt();
       bool test=tmpparking.testerPark(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("parking existe"),
                        QObject::tr("parking existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_afficher_RP->setModel( tmpparking.afficherid(id));//refresh

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("abonnement n'existe pas"),
                        QObject::tr("abonnement n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void parkinng::on_pushButton_NBE_clicked()
{
    parkingCode park;
        QSqlQueryModel* p=park.Tri2();


          ui->tab_afficher_triNBE->setModel(p);
}

void parkinng::on_pushButton_NBP_clicked()
{
    parkingCode park;
        QSqlQueryModel* p=park.Tri();


          ui->tab_afficher_triNBP->setModel(p);
}

void parkinng::on_pushButton_S_clicked()
{
    stat_no afficher;
    afficher.setModal(true);
    afficher.exec();
}
