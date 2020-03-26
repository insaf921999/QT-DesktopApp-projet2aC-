#include "dialog.h"
#include "ui_dialog.h"
#include "connection.h"
#include <QMessageBox>
#include<QSqlQueryModel>
#include "agent.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    ui->tableWidget->setModel(a.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}






void Dialog::on_pushButton_clicked()
{

    int id = ui->ID->text().toInt();
    int heuree= ui->HEUREE->text().toInt();
    int heures= ui->HEURES->text().toInt();
    QString role=ui->ROLE->text();
    QString email=ui->EMAIL->text();


  Agent a(id,heuree,heures,role,email);
  bool test=a.ajouter();
  if(test)
{

      ui->tableWidget->setModel(a.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un agent"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un agent"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }



void Dialog::on_pushButton_4_clicked()
{
    int id = ui->pushButton_4->text().toInt();
    bool test=a.supprimer(id);
    if(test)
    {ui->tableWidget->setModel(a.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


