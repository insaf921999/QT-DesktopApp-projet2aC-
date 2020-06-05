#include "coli.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
coli::coli()
{
reference=0; //1
nom="";   //2
idclientdest="";
poids="";    //3
nbpiece="";   //4
etat="";      //5
paiement="";//6
montant="";//7
adresseexp="";//8
adressedest="";
}//9
coli::coli(int reference,QString nom,QString idclientdest,QString poids,QString nbpiece,QString etat,QString paiement,QString montant,QString adresseexp,QString adressedest)
{                      this->reference=reference;
                       this->nom=nom;
                       this->idclientdest=idclientdest;
                       this->poids=poids;
                       this->nbpiece=nbpiece;
                       this->etat=etat;
                       this->paiement=paiement;
                       this->montant=montant;
                       this->adresseexp=adresseexp;
                       this->adressedest=adressedest;

}

                   int coli::getidcoli(){return reference; }
                   void coli::setidcoli(int reference) {this->reference=reference;}
                   QString coli::getidclientdest(){return idclientdest; }

                   QSqlQueryModel * coli::affichercoli()
                   {   QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));
                       return model; }
                   bool coli::ajoutercoli()
{
                       QSqlQuery query;
                       QString res= QString::number(reference);
                        query.prepare("INSERT INTO coli(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest)"
                                           "VALUES (:reference,:nom,:idclientdest,:poids,:nbpiece,:etat,:paiement,:montant,:adresseexp,:adressedest)");
                         query.bindValue(":reference",res);
                         query.bindValue(":nom",nom);
                         query.bindValue(":idclientdest",idclientdest);
                         query.bindValue(":poids",poids);
                         query.bindValue(":nbpiece",nbpiece);
                         query.bindValue(":etat",etat);
                         query.bindValue(":paiement",paiement);
                         query.bindValue(":montant",montant);
                         query.bindValue(":adresseexp",adresseexp);
                         query.bindValue(":adressedest",adressedest);
                          return   query.exec();}

                   bool coli::supprimercoli(int reference)
                   {   QSqlQuery query;
                       QString str="delete from coli where reference ="+QString::number(reference);
                       query.addBindValue(reference);
                       qDebug()<<str;
                       bool res = query.exec(str);
                       return res;                   }
                   bool coli::modifiercoli(int reference)
                   {                     QSqlQuery querry;
                                  querry.prepare("update coli set reference=:reference,nom=:nom,idclientdest=:idclientdest,poids=:poids,nbpiece=:nbpiece,etat=:etat,paiement=:paiement,montant=:montant,adresseexp=:adresseexp,adressedest=:adressedest where reference=:reference");
                                  querry.bindValue(":reference",reference);
                                  querry.bindValue(":nom",nom);
                                  querry.bindValue(":idclientdest",idclientdest);
                                  querry.bindValue(":poids",poids);
                                  querry.bindValue(":nbpiece",nbpiece);
                                  querry.bindValue(":etat",etat);
                                  querry.bindValue(":paiement",paiement);
                                  querry.bindValue(":montant",montant);
                                  querry.bindValue(":adresseexp",adresseexp);
                                  querry.bindValue(":adressedest",adressedest);
                                bool res=querry.exec();
                                return res;                   }

                   QSqlQueryModel * coli::affichertriccoli()
                   {
                       QSqlQueryModel * model= new QSqlQueryModel();

                       model->setQuery("select * from coli ORDER BY reference ASC");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen dePaiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));
                       return model;
                   }
                   QSqlQueryModel * coli::affichertridcoli()
                   {
                       QSqlQueryModel * model= new QSqlQueryModel();

                       model->setQuery("select * from coli ORDER BY reference DESC");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }
                   QSqlQueryModel * coli::recherchercoli_ref(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (reference  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_nom(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (nom  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_idclientdest(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (idclientdest  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_poid(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (poids  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_nbpiece(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (nbpiece  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_etat(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (etat  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_paiment(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (paiement  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_montant(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (montant  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_adressee(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (adresseexp  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

                   QSqlQueryModel * coli::recherchercoli_adresseed(const QString & reference)
                   {
                       QSqlQuery query;
                       query.prepare("reference");
                       query.addBindValue(reference);
                       QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from coli where (adressedest  LIKE '"+reference+"') ");

                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

