#include "courrier.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
courrier::courrier()
{
ref3=0;
nbpiecej="";
nom3="";
idclientdest3="";
etat3="";
paiement3="";
montant3="";
adressee="";
adressed="";
}
courrier::courrier(int ref3,QString nbpiecej,QString nom3,QString idclientdest3,QString etat3,QString paiement3,QString montant3,QString adressee, QString adressed)
{
    this->ref3=ref3;
    this->nbpiecej=nbpiecej;
    this->nom3=nom3;
    this->idclientdest3=idclientdest3;
    this->etat3=etat3;
    this->paiement3=paiement3;
    this->montant3=montant3;
    this->adressee=adressee;
    this->adressed=adressed;}
                   int courrier::getidcourrier(){return ref3; }
                   void courrier::setidcourrier(int ref3) {this->ref3=ref3;}

                   QSqlQueryModel * courrier::affichercourrier()
                   {
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from courrier");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                      return model;
                   }
                   bool courrier::ajoutercourrier()
{                      QSqlQuery query;
                       QString res= QString::number(ref3);
                             query.prepare("INSERT INTO courrier(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed)"
                                           "VALUES (:ref3,:nbpiecej,:nom3,:idclientdest3,:etat3,:paiement3,:montant3,:adressee,:adressed)");
                             query.bindValue(":ref3",res);
                             query.bindValue(":nbpiecej",nbpiecej);
                             query.bindValue(":nom3",nom3);
                             query.bindValue(":idclientdest3",idclientdest3);
                             query.bindValue(":etat3",etat3);
                             query.bindValue(":paiement3",paiement3);
                             query.bindValue(":montant3",montant3);
                             query.bindValue(":adressee",adressee);
                             query.bindValue(":adressed",adressed);
                           return   query.exec();}

                   bool courrier::supprimercourrier(int ref3)
                   {
                       QSqlQuery query;
                       QString str="delete from courrier where ref3 ="+QString::number(ref3);
                       query.addBindValue(ref3);
                       qDebug()<<str;
                       bool res = query.exec(str);
                       return res;
                   }




                   bool courrier::modifiercourrier(int refcourier)
                   {
                       QString res= QString::number(ref3);
                       QSqlQuery query;
         query.prepare("update courrier set ref3=:ref3,nbpiecej=:nbpiecej,nom3=:nom3,idclientdest3=:idclientdest3,etat3=:etat3,paiement3=:paiement3,montant3=:montant3,adressee=:adressee,adressed=:adressed where ref3 =:refcourier");
                                  query.bindValue(":ref3",res);
                                  query.bindValue(":nbpiecej",nbpiecej);
                                  query.bindValue(":nom3",nom3);
                                  query.bindValue(":idclientdest3",idclientdest3);
                                  query.bindValue(":etat3",etat3);
                                  query.bindValue(":paiement3",paiement3);
                                  query.bindValue(":montant3",montant3);
                                  query.bindValue(":adressee",adressee);
                                  query.bindValue(":adressed",adressed);
                                  query.bindValue(":refcourier",refcourier);
                                  return    query.exec();
                   }
                   QSqlQueryModel * courrier::affichertriccourrier()
                   {
                       QSqlQueryModel * model= new QSqlQueryModel();

                       model->setQuery("select * from courrier ORDER BY ref3 ASC");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }
                   QSqlQueryModel * courrier::affichertridcourrier()
                   {
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from courrier ORDER BY ref3 desc");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

                   QSqlQueryModel * courrier::recherchercourrier_ref(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where (ref3 LIKE '"+ref3+"')  ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

                   QSqlQueryModel * courrier::recherchercourrier_nom(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (nom3  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

                   QSqlQueryModel * courrier::recherchercourrier_nbpiece(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (nbpiecej  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

                   QSqlQueryModel * courrier::recherchercourrier_idclientdest(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (idclientdest3  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }


                   QSqlQueryModel * courrier::recherchercourrier_etat(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (etat3  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

                   QSqlQueryModel * courrier::recherchercourrier_montant(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (montant3  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

                   QSqlQueryModel * courrier::recherchercourrier_adressee(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (adressee  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

                   QSqlQueryModel * courrier::recherchercourrier_adresseed(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (adressed  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }


                   QSqlQueryModel * courrier::recherchercourrier_paiment(const QString & ref3)
                   {
                       QSqlQuery query;
                       QSqlQueryModel * model= new QSqlQueryModel();
                       //QString str="select * from courrier where ref3 ="+QString::number(ref3);
                       //model->setQuery(str);
                       model->setQuery("select * from courrier where  (paiement3  LIKE '"+ref3+"') ");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference courrier "));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbpiece jointe"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Client destinataire"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de livraison"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mode de Paiement"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse dest"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse exp"));
                       return model;
                   }

