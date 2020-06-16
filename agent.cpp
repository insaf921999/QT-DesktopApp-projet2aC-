#include "agent.h"
#include <QDebug>
#include<QVariant>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
Agent::Agent()
{
id=0;
nom="";
prenom="";
role="";
dated="";
}
Agent::Agent(int id,QString nom,QString prenom,QString role,QString dated)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->role=role;
  this->dated=dated;
}
int Agent::get_id(){return  id;}
QString Agent::get_nom(){return nom;}
QString Agent::get_prenom(){return  prenom;}
QString Agent::get_role(){return  role;}


bool verif (QString a){
    int j;
    int i1;
    bool x1=true;
  QString  x="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  for(i1=0;i1<a.length();i1++){

  for(j=0;j<x.length();j++){


      if (a[i1]!=x[j])
         x1=false ;

     }
  }
       return x1;

    }




bool Agent::ajouter()
{
QSqlQuery query;
QString res= QString::number(get_id());



query.prepare("INSERT INTO AGENT (ID,NOM,PRENOM,ROLE,DATED) "
                    "VALUES (:id,:nom,:prenom,:role,:dated)");
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":role",role);
query.bindValue(":dated", dated);


return    query.exec();
}

QSqlQueryModel * Agent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM AGENT");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("ROLE"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATED"));

    return model;
}

bool Agent::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("DELETE FROM AGENT where ID = :id");
query.bindValue(":id", res);
return query.exec();
}

QSqlQueryModel * Agent::cherchera(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from AGENT where ID like :id order by ID ");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ROLE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATED"));

    return model;
}

bool Agent::modifier(int id,QString nom,QString prenom,QString role,QString dated)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("update AGENT set NOM=:nom,PRENOM=:prenom,ROLE=:role,DATED=:dated where ID='"+res+"'");

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":role",role);
       query.bindValue(":dated",dated);
    return query.exec();
}
QSqlQueryModel* Agent::triea(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        model->setQuery("select *FROM AGENT ORDER BY ID ASC");
    }
    if(index == 2)
    {
        model->setQuery("select *FROM AGENT ORDER BY ID DESC ");
    }

qDebug()<<index;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PASS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REPASS"));

    return model;
}
QSqlQueryModel *Agent ::afficherI()
{QSqlQueryModel * model= new QSqlQueryModel();
    QString non="non";
model->setQuery("select nom from Agent ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
