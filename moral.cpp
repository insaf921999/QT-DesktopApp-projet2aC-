#include "moral.h"
#include "client.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlQueryModel>
#include <QMessageBox>
moral::moral()
{


}
moral::moral(int RIB,int matricule, QString nom_entreprise )
{
    this->RIB=RIB;
    this->matricule=matricule;
    this->nom_entreprise=nom_entreprise;
}
moral::moral(int  RIB,int matricule,QString nom_entreprise, int id_client ):client (id_client)
{
    this->RIB=RIB;
    this->matricule=matricule;
    this->nom_entreprise=nom_entreprise;
}

void moral:: setRIB(int rib)
{
    this->RIB =rib;
}
void moral:: setMatricule(int m)
{
   this->matricule = m;
}
void moral :: setNom_entreprise(QString nom)
{
   this->nom_entreprise = nom;
}

int moral:: getRIB()
{
    return RIB;
}
int moral::getMatricule()
{
    return matricule;
}

QString moral:: getNom_entreprise()
{
    return nom_entreprise;
}


bool moral::ajouter_moral(int id){
    QSqlQuery query;

          query.prepare("INSERT INTO MORAL (RIB,MATRICULE, NOM_ENTREPRISE, ID_CLIENT) "
                        "VALUES (:RIB, :matricule, :nom_entreprise,:id_client )");

          query.bindValue(":id_client", id);
          query.bindValue(":RIB",RIB);
          query.bindValue(":matricule", matricule);
          query.bindValue(":nom_entreprise", nom_entreprise);



          return  query.exec();
}
//(client::ajouter_client())



QSqlQueryModel *moral::afficherM()
{
    //client::afficher1();
   QSqlQueryModel *model = new QSqlQueryModel;
      model->setQuery("SELECT * FROM MORAL");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("RIB"));
      model->setHeaderData(1, Qt::Horizontal,  QObject::tr("matricule"));
      model->setHeaderData(2, Qt::Horizontal,  QObject::tr("nom_entreprise"));
      return model;

}


/*bool moral::modifier()
{

        QSqlQuery query;
        query.prepare("update CLIENT set montant=:montant where id_compteS=:id_compteS");
        query.bindValue(":id_compteS",id_compteS);
        query.bindValue(":montant", montant);
        return    query.exec();

}*/



bool moral::supprimer(int ribb)
{
QSqlQuery query;
QString res= QString::number(ribb);
query.prepare("Delete FROM MORAL where RIB = :RIB ");
query.bindValue(":RIB", res);
return    query.exec();
}

void moral::chercher (int id_client){
client::chercher(id_client);
QSqlQuery query1;
query1.prepare("SELECT RIB,MAREICULE, NOM_ENTREPRISE FROM MORAL WHERE ID_CLIENT=:id_client");
query1.bindValue(":ID_CLIENT",id_client);
query1.exec();
while(query1.next())
{
RIB = query1.value(0).toString().toInt();
matricule = query1.value(1).toString().toInt();
nom_entreprise = query1.value(2).toString();}
}


QSqlQueryModel * moral::recherche(const QString &rib)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MORAL where(ID_CLIENT LIKE '"+rib+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("RIB"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Matricule "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_client "));

    return model;
}
