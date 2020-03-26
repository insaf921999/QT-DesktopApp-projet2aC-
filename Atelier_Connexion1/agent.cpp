#include "agent.h"
#include <QDebug>
#include<QVariant>
#include "connection.h"
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
Agent::Agent()
{
id=0;
heuree=0;
heures=0;
role="";
email="";
}
Agent::Agent(int id,int heuree,int heures,QString role,QString email)
{
  this->id=id;
  this->heuree=heuree;
  this->heures=heures;
  this->role=role;
  this->email=email;
}
QString Agent::get_role(){return  role;}
QString Agent::get_email(){return email;}
int Agent::get_id(){return  id;}
int Agent::get_heuree(){return  heuree;}
int Agent::get_heures(){return  heures;}



bool Agent::ajouter()
{
QSqlQuery query;
QString res= QString::number(get_id());
QString res1= QString::number(get_heuree());
QString res2= QString::number(get_heures());


query.prepare("INSERT INTO AGENT (ID,HEUREE,HEURES,ROLE,EMAIL) "
                    "VALUES (:id,:heuree,:heures,:role,:email)");
query.bindValue(":id" , res);
query.bindValue(":heure", res1);
query.bindValue(":heures", res2);
query.bindValue(":role", get_role());
query.bindValue(":email", get_email());

return    query.exec();
}

QSqlQueryModel * Agent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from AGENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEUREE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURES"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    return model;
}

bool Agent::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("DELETE FROM AGENT where ID = :id ");
query.bindValue(":id", res);
return query.exec();
}


