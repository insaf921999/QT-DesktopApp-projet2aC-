#include "abonnementcode.h"
#include <QDebug>
#include <QString>
abonnementCode::abonnementCode()
{

}


abonnementCode::abonnementCode(int id, QString nom, QString prenom, int numplace,QDate datenaiss,QDate datedeb,QDate datefin )
{

    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
     this->numplace=numplace;
    this->datenaiss=datenaiss;
    this->datedeb=datedeb;
    this->datefin=datefin;

}

int abonnementCode::get_id(){return  id;}
QString abonnementCode::get_nom(){return  nom;}
QString abonnementCode::get_prenom(){return  prenom;}
int abonnementCode::get_numplace(){return  numplace;}
QDate abonnementCode::get_date_naiss(){return  datenaiss;}
QDate abonnementCode::get_date_deb(){return  datedeb;}
QDate abonnementCode::get_date_fin(){return  datefin;}



bool abonnementCode::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);

query.prepare("INSERT INTO abonnements (ID, NOM, PRENOM,NUMPLACE, DATENAISS, DATEDEB, DATEFIN) "
                    "VALUES (:id, :nom, :prenom,:numplace, :datenaiss, :datedeb, :datefin)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":numplace", numplace);
query.bindValue(":datenaiss", datenaiss);
query.bindValue(":datedeb", datedeb);
query.bindValue(":datefin", datefin);


return    query.exec();
}

QSqlQueryModel * abonnementCode::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnements order by ID asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num place"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date de debut"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date fin"));

    return model;
}






bool abonnementCode::modifier(int num , int nouvplace)
{

         QSqlQuery  *q = new QSqlQuery();

         QString res= QString::number(num);
         QString numplace= QString::number(nouvplace);
         q->prepare("UPDATE abonnements set numplace=:numplace WHERE ID=:id ");
         q->bindValue(":id",res);
         q->bindValue(":numplace",numplace);

         if(q->exec())
         {qDebug()<<"modif succée";
             return true;
         }
         else
         {
             qDebug()<<"modif failed";
             return false;
         }

}




bool abonnementCode::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from abonnements where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


bool abonnementCode::tester(long id)
{
    QSqlQuery q;
    QString res= QString::number(id);
    q.prepare("SELECT ID from ABONNEMENTS where ID=:id");
    q.bindValue(":id",res);
    q.exec();
    if(q.next())
    {
        qDebug()<<"abonnement existe";
        return true;

    }
    else
        {
        qDebug()<<"abonnement n'existe pas";
        return false;
}}
long abonnementCode::testerA(long id)
{
    QSqlQuery q;
    QString res= QString::number(id);
    q.prepare("SELECT ID from ABONNEMENTS where ID=:id");
    q.bindValue(":id",res);
    q.exec();
    if(q.next())
    {
        qDebug()<<"abonnement existe";
        return true;

    }
    else
        {
        qDebug()<<"abonnement n'existe pas";
        return false;
}}

QSqlQueryModel *abonnementCode::afficherID(int id)
    {QSqlQueryModel * model= new QSqlQueryModel();

     QString res= QString::number(id);

    QSqlQuery *q = new QSqlQuery;
     q->prepare("SELECT * from ABONNEMENTS where ID LIKE '%"+res+"%'");
      q->addBindValue(res);
       q->exec();
         model->setQuery(*q);


        return model;
    }

