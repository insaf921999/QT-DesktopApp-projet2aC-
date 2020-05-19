#include "cartesolde.h"
#include "gestionsolde.h"
#include "ui_gestionsolde.h"
#include "client.h"
#include <QSqlQuery>
#include<QString>
#include <QVariant>
#include <QSqlQueryModel>
#include <QDate>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QSqlError>
cartesolde::cartesolde()
{


}
/*cartesolde::cartesolde(int  id_compteS,int montant,QDate date_ouverture , int id_client):client (id_client)
{

    this->id_compteS=id_compteS;
    this->montant=montant;
    this->date_ouverture=date_ouverture;
}*/

cartesolde::cartesolde(int id_compteS,int montant, QDate date_ouverture )
{
    this->id_compteS=id_compteS;
    this->montant=montant;
    this->date_ouverture=date_ouverture;

}
void cartesolde:: setID_compteS(int id)
{
    this->id_compteS =id;
}
void cartesolde:: set_Montant(int m)
{
   this->montant = m;
}
void cartesolde:: setDate_ouverture(QDate d)
{
   this->date_ouverture = d;
}

int cartesolde:: get_ID_compteS()
{
    return id_compteS;
}
int cartesolde::getMontant()
{
    return montant;
}
  QDate cartesolde:: getDate_ouverture()
{
    return date_ouverture;
}

bool cartesolde::ajouter_solde(int id){

  //  QSqlQuery query1;
    //query1.prepare("UPDATE CLIENT SET ID_client= :id where id_client = :id ");
    //query1.bindValue(":id_client ", id);
    QSqlQuery query;
    QString res= QString::number(id_compteS);
          query.prepare("INSERT INTO CARTESOLDE(ID_COMPTES, MONTANT, DATE_OUVERTURE, ID_CLIENT) "
                        "VALUES (:id_compteS, :montant, :date_ouverture , :id_client)");
          query.bindValue(":id_client", id);
          query.bindValue(":id_compteS",res);
          query.bindValue(":montant", montant);
          query.bindValue(":date_ouverture", date_ouverture);
          return  (query.exec());
                   //&& (query1.exec()));

}


QSqlQueryModel *cartesolde::afficher()
{
   QSqlQueryModel *model = new QSqlQueryModel;
      model->setQuery("SELECT * FROM CARTESOLDE");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
      model->setHeaderData(1, Qt::Horizontal,  QObject::tr("montant"));
      model->setHeaderData(2, Qt::Horizontal,  QObject::tr("date_ouverture"));
      return model;

}



bool cartesolde::modifier()
{

        QSqlQuery query;
        query.prepare("update CARTESOLDE set montant=:montant where id_compteS=:id_compteS");
        query.bindValue(":id_compteS",id_compteS);
        query.bindValue(":montant", montant);
        return    query.exec();

}


bool cartesolde::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete FROM CARTESOLDE where ID_COMPTES = :id_compteS ");
query.bindValue(":id_compteS", res);
return    query.exec();
}


/*QSqlQueryModel * cartesolde:: recherche(int id_compteS ,bool *test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select* FROM CARETSOLDE where ID_COMPTES= :id_compteS");
    q.exec();
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_compteS"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ouverture"));
    *test=q.first();
    return model;

}

void cartesolde::chercher()
{
    QSqlQuery query1;
    query1.prepare("SELECT MONTANT,DATE_OUVERTURE FROM CARTESOLDE WHERE ID_COMPTES=:id_compteS");
    query1.bindValue(":ID_COMPTES",id_compteS);
    query1.exec();
    while(query1.next())
    {

    montant = query1.value(0).toInt();


    }
}*/

QSqlQueryModel * cartesolde::rechercher(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CARTESOLDE where(ID_COMPTES LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Montant"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date ouvertute "));

    return model;
}

bool cartesolde::mise_ajour()
{
    QSqlQuery query2;
        query2.prepare("UPDATE CARTESOLDE SET ID_COMPTES=:ID_COMPTES,MONTANT=:MONTANT,DATE_OUVERTURE=:DATE_OUVERTURE WHERE ID_COMPES=:ID_COMPTES");
        query2.bindValue(":ID_COMPTES",id_compteS);
        query2.bindValue(":MONTANT",montant);
        query2.bindValue(":DATE_OUVERTURE",date_ouverture);

         return(query2.exec());

}
