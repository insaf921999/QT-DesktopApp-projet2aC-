#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coli.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlError>
#include <connexion.h>
#include <QSpinBox>
#include "qcustomplot.cpp"
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
#include <QFileDialog>
#include <QDesktopWidget>
#include <QDebug>
#include "smtp.h"
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include "mailing.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    ui->setupUi(this);

ui->tablecoli->setModel(tcmp.affichercoli());
ui->tablecourrier->setModel(tccmp.affichercourrier());




}

  //ui->checkBox_2->setChecked(true);
  //   ui->checkBox->setChecked(true);
   /* ui->comboBox->addItem("en cours");*/

MainWindow::~MainWindow(){
   delete ui
            ;}

void MainWindow::on_ajoutercoli_clicked()
{//      ui->le_poids->setText(ui->spinBox->cleanText());
         int reference=ui->le_idcoli->text().toInt();
        // QString nom=ui->le_nom->text();
         QString nom=ui->comboBox_3->currentText();
         QString idclientdest=ui->le_nom_2->text();
         QString poids=ui->spinBox->cleanText();
         QString nbpiece=ui->le_nbpiece->text();
         QString etat=ui->comboBox->currentText();
         QString paiement=ui->comboBox_2->currentText();
         QString montant=ui->le_montant->text();
         QString adresseexp=ui->le_adresse_exp_2->text();
         QString adressedest=ui->le_adresse_dest_2->text();
         coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);

         qDebug() << idclientdest ;
           QMessageBox msg;
          if(c.ajoutercoli())
           {    ui->tablecoli->setModel(tcmp.affichercoli());
               msg.setText("Ajout avec succès");
               msg.exec();}
          if(ui->checkBox_2->isChecked())
           {
               QMessageBox::information(this,"Agent","Vous êtes un agent respensable sur les colis");
           }
           else
           {
               QMessageBox::information(this,"Agent","Vous n'êtes pas un agent respensable sur les colis");
           }
}

void MainWindow::on_lirecoli_clicked()
{  //  ui->le_poids->setText(ui->spinBox->cleanText());
   int reference=ui->le_idcoli->text().toInt();
     QString nom=ui->comboBox_3->currentText();
   // QString nom=ui->le_nom->text();
    QString idclientdest=ui->le_nom_2->text();
    QString poids=ui->spinBox->text();
    QString nbpiece=ui->le_nbpiece->text();
    QString etat=ui->comboBox->currentText();
    QString paiement=ui->comboBox_2->currentText();
    QString montant=ui->le_montant->text();
    QString adresseexp=ui->le_adresse_exp_2->text();
    QString adressedest=ui->le_adresse_dest_2->text();

      coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        if(c.affichercoli())
        {   ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("Voilà la liste des colis");
            msg.exec(); }}

void MainWindow::on_modifiercoli_clicked()
{  //  ui->le_poids->setText(ui->spinBox->cleanText());
    int reference=ui->le_idcoli->text().toInt();
      QString nom=ui->comboBox_3->currentText();
   // QString nom=ui->le_nom->text();
    QString idclientdest=ui->le_nom_2->text();
    QString poids=ui->spinBox->text();
    QString nbpiece=ui->le_nbpiece->text();
    QString etat=ui->comboBox->currentText();
    QString paiement=ui->comboBox_2->currentText();
    QString montant=ui->le_montant->text();
    QString adresseexp=ui->le_adresse_exp_2->text();
    QString adressedest=ui->le_adresse_dest_2->text();
      coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        if(c.modifiercoli(reference))
        {
            ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("Modification avec succès");
            msg.exec(); }}

void MainWindow::on_suppcoli_clicked()
{
   int verifsupp=0;
    //ui->le_poids->setText(ui->spinBox->cleanText());
   int reference=ui->le_idcoli->text().toInt();
   // QString nom=ui->le_nom->text();
    QString nom=ui->comboBox_3->currentText();
    QString idclientdest=ui->le_nom_2->text();
    QString poids=ui->spinBox->text();
    QString nbpiece=ui->le_nbpiece->text();
    QString etat=ui->comboBox->currentText();
    QString paiement=ui->comboBox_2->currentText();
    QString montant=ui->le_montant->text();
    QString adresseexp=ui->le_adresse_exp_2->text();
    QString adressedest=ui->le_adresse_dest_2->text();
      coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        qDebug()<<reference;

        if(reference!=0)
        {
        verifsupp= QMessageBox::question( this, "Confimation De la Suppression", "Voulez Vous Supprmier Cette Coli ?", QMessageBox::No | QMessageBox::Yes  );
        if(verifsupp==16384)
        {
            c.supprimercoli(reference);
            ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("suppression avec succès");
            msg.exec();
            QMessageBox::information(this,"Information","Coli qui a la reference "+QString::number(reference)+" a ete Supprimer");
        }
        if(verifsupp==65536)
        {
        QMessageBox::information(this,"Information","La Suppression du Coli qui a la reference "+QString::number(reference)+" a ete annulee  ");
        }
        }
        if(reference==0)
        {
        QMessageBox::warning(this,"Information","Il faut double click sur tableau Pour Supprimer du Coli");
        }


}

void MainWindow::on_tricroisscoli_clicked()
{// ui->le_poids->setText(ui->spinBox->cleanText());
    int reference=ui->le_idcoli->text().toInt();
    // QString nom=ui->le_nom->text();
      QString nom=ui->comboBox_3->currentText();
     QString idclientdest=ui->le_nom_2->text();
     QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
       coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
         QMessageBox msg;
        if(c.affichertriccoli())
        {
            ui->tablecoli->setModel(tcmp.affichertriccoli());
           // ui->tablelivraisontric->setModel(tmp.affichertric());
            msg.setText("Voilà la liste des coli avec tri croissant selon l'id");
            msg.exec(); }
}
void MainWindow::on_tridecroissantcoli_clicked()
{// ui->le_poids->setText(ui->spinBox->cleanText());
    int reference=ui->le_idcoli->text().toInt();
    // QString nom=ui->le_nom->text();
      QString nom=ui->comboBox_3->currentText();
     QString idclientdest=ui->le_nom_2->text();
   QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
       coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
         QMessageBox msg;
         if(c.affichertridcoli())
         {
             ui->tablecoli->setModel(tcmp.affichertridcoli());
            // ui->tablelivraisontric->setModel(tmp.affichertric());
             msg.setText("Voilà la liste des coli avec tri decroissant selon l'id");
             msg.exec(); }}
void MainWindow::on_rechcoli_clicked()
{
    QString input =ui->le_idcolirech->text();
    qDebug()<< input;


            if(ui->comboBox_rechercheColi->currentText()=="reference")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_ref(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="nom")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_nom(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="id_client_dest")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_idclientdest(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="poids")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_poid(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="nbpieces")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_nbpiece(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="etat")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_etat(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="paiment")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_paiment(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="montant")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_montant(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="adresse_exp")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_adresseed(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="adresse_dest")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_adressee(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }













    /*
    int numserieRech = model->data(model->index(0, 0)).toInt();
    if(reference == numserieRech)
    {
        ui->recherchecoliview->show();
        ui->recherchecoliview->setModel(model);
    }
     else
    {
        QMessageBox::critical(0, qApp->tr("Recherche"),
            qApp->tr("Client non trouvé"), QMessageBox::Ok);
         ui->recherchecoliview->hide();
    }*/

}



/*void MainWindow::on_tablecoli_activated(const QModelIndex &index)
{    QString val=ui->tablecoli->model()->data(index).toString();
    QSqlQuery qry;
qry.prepare("select * from coli where reference='"+val+"' or poids='"+val+" nbpiece='"+val+"' or etat='"+val+"' or paiement='"+val+"' '");
        ui->comboBox_3->setCurrentText(qry.value(0).toString());
        ui->spinBox->setSuffix(qry.value(1).toString());
        ui->le_nbpiece->setText(qry.value(2).toString());
        ui->comboBox->setCurrentText(qry.value(3).toString());
        ui->comboBox_2->setCurrentText(qry.value(4).toString());
      //  {    QMessageBox::critical(this,tr("error::"),qry.lastError().text()); }
}*/

/*void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{*/
    /*int reference=ui->le_idcoli->text().toInt();

     QString nom=ui->le_nom->text();
     QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
     coli c(reference,nom,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);*/
      /* QMessageBox msg;
       if(c.ajoutercoli())
       {   ui->tablecoli->setModel(tcmp.affichercoli());
           msg.setText("Ajout avec succès");
           msg.exec(); }*/
 /*   QString nom=ui->comboBox_3->currentText();
    QSqlQuery qry;*/

   // qry.prepare("insert into coli(reference,nom,poids,nbpiece,etat,paiement,montant,adressexp,adressedest") values ('"+reference+"','"+nom+"','"+poids+"','"+nbpiece+"','"+etat+"','"+paiement+"','"+montant+"','"+adressexp+"','"+adressedest+"'');
/* qry.prepare("select * from coli where name='"+nom+"'");

 if(qry.exec()){
         ui->le_idcoli->setText(qry.value(0).toString());
         ui->le_nom->setText(qry.value(1).toString());
         ui->spinBox->setSuffix(qry.value(2).toString());
         ui->le_nbpiece->setText(qry.value(3).toString());
         ui->comboBox->setCurrentText(qry.value(4).toString());
         ui->comboBox_2->setCurrentText(qry.value(5).toString());
         ui->le_montant->setText(qry.value(6).toString());
         ui->le_adresse_exp_2->setText(qry.value(7).toString());
         ui->le_adresse_dest_2->setText(qry.value(8).toString());

     }else
 {
     QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }

}*/

/*void MainWindow::on_label_linkActivated(const QString &link)
{
    int ref3=ui->le_idcoli->text().toInt();
   // QString nomc=ui->comboBox_3->currentText();
     QString nom=ui->le_nom->text();
     QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
     coli c(ref3,nom,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        if(c.supprimercoli(ref3))
        {

            ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("suppression avec succès");
            msg.exec(); }
}
*/
void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{QMessageBox msg;
    QString val=ui->comboBox_3->currentText();
    QSqlQuery qry;
    qry.prepare("select * from coli where nom='"+val+"'");
    if(qry.exec())
    {while(qry.next())
       {  ui->le_idcoli->setText(qry.value(0).toString());
          //  ui->le_nom->setText(qry.value(1).toString());
            ui->comboBox_3->setCurrentText(qry.value(1).toString());
            ui->le_nom_2->setText(qry.value(2).toString());
            ui->spinBox->setPrefix(qry.value(3).toString());
            ui->le_nbpiece->setPrefix(qry.value(4).toString());
            ui->comboBox->setCurrentText(qry.value(5).toString());
            ui->comboBox_2->setCurrentText(qry.value(6).toString());
            ui->le_montant->setText(qry.value(7).toString());
            ui->le_adresse_exp_2->setText(qry.value(8).toString());
            ui->le_adresse_dest_2->setText(qry.value(9).toString());}
            msg.setText("");
  }
}
void MainWindow::on_tablecoli_activated(const QModelIndex &index)
{QMessageBox msg;
    QString val=ui->tablecoli->model()->data(index).toString(); //take the selected index in tablecoli in transform it to val
    qDebug()<< val;
    QSqlQuery qry;
    qry.prepare("select * from coli where reference='"+val+"' or nom='"+val+"' or poids='"+val+"' or nbpiece='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
           { ui->le_idcoli->setText(qry.value(0).toString());
            ui->comboBox_3->setCurrentText(qry.value(1).toString());
             ui->le_nom_2->setText(qry.value(2).toString());
            ui->spinBox->setPrefix(qry.value(3).toString());
            ui->le_nbpiece->setPrefix(qry.value(4).toString());
            ui->comboBox->setCurrentText(qry.value(5).toString());
            ui->comboBox_2->setCurrentText(qry.value(6).toString());
            ui->le_montant->setText(qry.value(7).toString());
            ui->le_adresse_exp_2->setText(qry.value(8).toString());
            ui->le_adresse_dest_2->setText(qry.value(9).toString());}
            msg.setText("");
        }else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}
/**************************************************************************courrier********************************************************************/
void MainWindow::on_pushButton_aj_courrier_clicked()
{
    //ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
    int ref3=ui->le_ref3->text().toInt();
    QString nbpiecej=ui->spinBox_2->text();
     QString nom3=ui->comboBox_6->currentText();
     QString idclientdest3=ui->le_nom3_2->text();
     QString etat3=ui->comboBox_4->currentText();
     QString paiement3=ui->comboBox_5->currentText();
     QString montant3=ui->le_montant3->text();
     QString adressee=ui->le_adressee->text();
     QString adressed=ui->le_adressed->text();
       courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
        QMessageBox msg;
      if(co.ajoutercourrier())
      {
          ui->tablecourrier->setModel(tccmp.affichercourrier());
          msg.setText("Ajout avec succès");
          msg.exec(); }
   /*   if(ui->checkBox->isChecked())
      {
          QMessageBox::information(this,"Agent","Vous êtes un agent respensable sur les courriers");
      }
      else
      {
          QMessageBox::information(this,"Agent","Vous n'êtes pas un agent respensable sur les courriers");
      }*/}


void MainWindow::on_pushButton_affich_courrier_clicked()
{
  //  ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
        int ref3=ui->le_ref3->text().toInt();
        QString nbpiecej=ui->spinBox_2->cleanText();
         QString nom3=ui->le_nom3->text();
          QString idclientdest3=ui->le_nom3_2->text();
         QString etat3=ui->comboBox_4->currentText();
         QString paiement3=ui->comboBox_5->currentText();
         QString montant3=ui->le_montant3->text();
         QString adressee=ui->le_adressed->text();
         QString adressed=ui->le_adressed->text();
           courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
            QMessageBox msg;
           if(co.affichercourrier())
           {   ui->tablecourrier->setModel(tccmp.affichercourrier());
               msg.setText("Voilà la liste des courriers");
               msg.exec(); }
}

void MainWindow::on_pbmodifiercourrier_clicked()
{

   // ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
        int ref3=ui->le_ref3->text().toInt();
        QString nbpiecej=ui->spinBox_2->text();
        QString nom3=ui->comboBox_6->currentText();
          QString idclientdest3=ui->le_nom3_2->text();
         QString etat3=ui->comboBox_4->currentText();
         QString paiement3=ui->comboBox_5->currentText();
         QString montant3=ui->le_montant3->text();
         QString adressee=ui->le_adressee->text();
         QString adressed=ui->le_adressed->text();
           courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
            QMessageBox msg;
qDebug()<<ref3;
qDebug()<<nbpiecej;
qDebug()<<nom3;
qDebug()<<idclientdest3;
qDebug()<<montant3;
            if(co.modifiercourrier(ref3))
            {
                ui->tablecourrier->setModel(tccmp.affichercourrier());
                msg.setText("Modification avec succès");
                msg.exec();
            }
}



void MainWindow::on_supprimercourrier_clicked()
{
    int verifsupp=0;
    //ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
    int ref3=ui->le_ref3->text().toInt();
    QString nbpiecej=ui->spinBox_2->cleanText();
     QString nom3=ui->le_nom3->text();
     QString idclientdest3=ui->le_nom3_2->text();
     QString etat3=ui->comboBox_4->currentText();
     QString paiement3=ui->comboBox_5->currentText();
     QString montant3=ui->le_montant3->text();
     QString adressee=ui->le_adressed->text();
     QString adressed=ui->le_adressed->text();
       courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
        QMessageBox msg;

        qDebug()<<ref3;

        if(ref3!=0)
        {
        verifsupp= QMessageBox::question( this, "Confimation De la Suppression", "Voulez Vous Supprmier Cette Courrier ?", QMessageBox::No | QMessageBox::Yes  );
        if(verifsupp==16384)
        {
            co.supprimercourrier(ref3);
            ui->tablecourrier->setModel(tccmp.affichercourrier());
            msg.setText("suppression avec succès");
            msg.exec();
            QMessageBox::information(this,"Information","Courrier qui a la reference "+QString::number(ref3)+" a ete Supprimer");
        }
        if(verifsupp==65536)
        {
        QMessageBox::information(this,"Information","La Suppression du Courrier qui a la reference "+QString::number(ref3)+" a ete annulee  ");
        }
        }
        if(ref3==0)
        {
        QMessageBox::warning(this,"Information","Il faut double click sur tableau Pour Supprimer du Courrier");
        }

}

void MainWindow::on_tricroissantcourrier_clicked()
{//ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
    int ref3=ui->le_ref3->text().toInt();
    QString nbpiecej=ui->spinBox_2->cleanText();
     QString nom3=ui->le_nom3->text();
      QString idclientdest3=ui->le_nom3_2->text();
     QString etat3=ui->comboBox_4->currentText();
     QString paiement3=ui->comboBox_5->currentText();
     QString montant3=ui->le_montant3->text();
     QString adressee=ui->le_adressed->text();
     QString adressed=ui->le_adressed->text();
       courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
        QMessageBox msg;
        if(co.affichertriccourrier())
        {
            ui->tablecourrier->setModel(tccmp.affichertriccourrier());
           // ui->tablelivraisontric->setModel(tmp.affichertric());
            msg.setText("Voilà la liste des coli avec tri croissant selon l'id");
            msg.exec(); }
}

void MainWindow::on_tridecroisscourrier_clicked()
{
    QMessageBox msg;
    ui->tablecourrier->setModel(tccmp.affichertridcourrier());
           // ui->tablelivraisontric->setModel(tmp.affichertric());
            msg.setText("Voilà la liste des coli avec tri croissant selon l'id");
            msg.exec();

}

 void MainWindow::on_comboBox_6_currentIndexChanged(const QString &arg1)
{
    QMessageBox msg;
        QString val=ui->comboBox_6->currentText();
        QSqlQuery qry;
        qry.prepare("select * from courrier where nom3='"+val+"'");
        if(qry.exec())
        {while(qry.next())
           {
            ui->le_nom3->setText(qry.value(3).toString());
            ui->comboBox_4->setCurrentText(qry.value(4).toString());
            ui->comboBox_5->setCurrentText(qry.value(5).toString());
            ui->le_montant3->setText(qry.value(6).toString());
            ui->le_adressee->setText(qry.value(7).toString());
            ui->le_adressed->setText(qry.value(8).toString());}
            msg.setText("");
      }
}

void MainWindow::on_tablecourrier_activated(const QModelIndex &index)
{

    QMessageBox msg;
        QString val=ui->tablecourrier->model()->data(index).toString(); //take the selected index in tablecoli in transform it to val
        qDebug()<< val;
        QSqlQuery qry;
        qry.prepare("select * from courrier where ref3='"+val+"' or nbpiecej='"+val+"' or nom3='"+val+"' or etat3='"+val+"'");
        if(qry.exec())
        {
            {while(qry.next())
               {
                ui->le_ref3->setText(qry.value(0).toString());
                ui->spinBox_2->setPrefix(qry.value(1).toString());
                ui->comboBox_6->setCurrentText(qry.value(2).toString());
                ui->le_nom3_2->setText(qry.value(3).toString());
                ui->comboBox_4->setCurrentText(qry.value(4).toString());
                ui->comboBox_5->setCurrentText(qry.value(5).toString());
                ui->le_montant3->setText(qry.value(6).toString());
                ui->le_adressee->setText(qry.value(7).toString());
                ui->le_adressed->setText(qry.value(8).toString());}
                msg.setText("");
          }

            }else
        {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
}
void MainWindow::on_pbrechcourrier_clicked()
{
    QString ref3 =ui->le_rechcourrier->text();
    qDebug()<< ref3;

    if(ui->comboBox_7->currentText()=="reference")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_ref(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="id_client_exp")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_nom(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="nbpiece")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_nbpiece(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="id_client_dest")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_idclientdest(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="etat")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_etat(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="montant")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_montant(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="adresse_exp")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_adresseed(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="adresse_dest")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_adressee(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="paiment")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_paiment(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }





}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    int i=0;
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Moyen de paiement");
    regen->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    regen->setBrush(QColor(111, 9, 176));
    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;
    labels << "en especes " << "par carte" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,20);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
     ui->customPlot->yAxis->setLabel("Nombre de courriers");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;
int stat100;
int stat500;

QString var1="en especes";
QString var2="par carte";

QSqlQuery query1("select count(*) from courrier where paiement3='"+var1+"'");
while (query1.next()) {

                        stat100 = query1.value(0).toInt();

QSqlQuery query2("select count(*) from courrier where paiement3 ='"+var2+"'  ");
while (query2.next()) {
                           stat500 = query2.value(0).toInt();

                             }
    regenData << stat100 << stat500  ;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
}

void MainWindow::on_ExporterColis_clicked()
{
    QTableView *table;
   table = ui->tablecoli;


   QString filters("CSV files (*.csv);;All files (*.*)");
   QString defaultFilter("CSV files (*.csv)");
   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                      filters, &defaultFilter);
   QFile file(fileName);

   QAbstractItemModel *model =  table->model();
   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
       QTextStream data(&file);
       QStringList strList;
       for (int i = 0; i < model->columnCount(); i++) {
           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
           else
               strList.append("");
       }
       data << strList.join(";") << "\n";
       for (int i = 0; i < model->rowCount(); i++) {
           strList.clear();
           for (int j = 0; j < model->columnCount(); j++) {

               if (model->data(model->index(i, j)).toString().length() > 0)
                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
               else
                   strList.append("");
           }
           data << strList.join(";") + "\n";
       }
       file.close();
       QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
   }
}

void MainWindow::on_ExporterCourriers_clicked()
{

    QTableView *table;
   table = ui->tablecourrier;


   QString filters("CSV files (*.csv);;All files (*.*)");
   QString defaultFilter("CSV files (*.csv)");
   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                      filters, &defaultFilter);
   QFile file(fileName);

   QAbstractItemModel *model =  table->model();
   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
       QTextStream data(&file);
       QStringList strList;
       for (int i = 0; i < model->columnCount(); i++) {
           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
           else
               strList.append("");   }
       data << strList.join(";") << "\n";
       for (int i = 0; i < model->rowCount(); i++) {
           strList.clear();
           for (int j = 0; j < model->columnCount(); j++) {

               if (model->data(model->index(i, j)).toString().length() > 0)
                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
               else
                   strList.append("");
           }
           data << strList.join(";") + "\n";
       }
       file.close();
       QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
   }
}

/*void MainWindow::on_SendEmail_clicked()
{

    QString email=ui->email->text();
    //QString email="insaf921999@gmail.com";
    QString nom=ui->name->text();
    QString prenom=ui->lastname->text();
    QString subject=ui->subject->text();
    QString msg=ui->msg->toPlainText();
    qDebug()<< email;
    Smtp* smtp=new Smtp("insaf.elinkichari@esprit.tn","181JFT2762","smtp.gmail.com");
                   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("", email ,subject,""+nom+" "+prenom+" "+msg+" ");

     if((nom=="") || (prenom=="") || (email=="") || (subject=="") || (msg==""))
     {
         QMessageBox::warning( 0, tr( "Qt Simple SMTP" ), tr( "il Ya un champ Vide!\n\n" ) );
     }

     if((nom!="") && (prenom!="") && (email!="") && (subject!="") && (msg!=""))
     {
     QMessageBox::information( 0, tr( "Qt Simple SMTP" ), tr( "Message sent!\n\n" ) );
     }

}
*/


void MainWindow::on_pushButton_2_clicked()
{
//mailing secdialog;
//secdialog.setModal(true);
//secdialog.exec();
    secdialog =new mailing(this);
    secdialog->show();
}
