#include "conge2.h"
#include <QDebug>
#include<QVariant>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
Conge::Conge()
{
    nom="";
    id=0;
    enconge="";
    type="";
    dated="";
    datef="";

}
Conge::Conge(int id,QString nom,QString enconge,QString type,QString dated,QString datef)
{
    this->id=id;
  this->nom=nom;
  this->enconge=enconge;
  this->type=type;
  this->dated=dated;
  this->datef=datef;
}

int Conge::get_id(){return id;}
QString Conge::get_nom(){return  nom;}
QString Conge::get_enconge(){return enconge;}
QString Conge::get_type(){return  type;}
QString Conge::get_dated(){return  dated;}
QString Conge::get_datef(){return  datef;}

bool Conge::ajouter()
{
QSqlQuery query;
QString res= QString::number(get_id());



query.prepare("INSERT INTO CONGE (ID,NOM,ENCONGE,TYPE,DATED,DATEF) "
                    "VALUES (:id,:nom,:enconge,:type,:dated,:datef)");
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":enconge",enconge);
query.bindValue(":type",type);
query.bindValue(":dated",dated);
query.bindValue(":datef", datef);

return    query.exec();
}

QSqlQueryModel * Conge::afficherI()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * FROM CONGE");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("ETAT"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("ENCONGE "));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date début"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("Date fin"));
    return model;
}

bool Conge::supprimerI(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("DELETE FROM CONGE where ID = :id");
query.bindValue(":id", res);
return query.exec();
}


QSqlQueryModel * Conge::cherchera(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from CONGE where ID like :id order by ID ");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ENCONGE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date début"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Date fin"));

    return model;
}
QSqlQueryModel * Conge::chercheraI(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from CONGE where ID like :NOM order by ID ");
    query.bindValue(":NOM",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ENCONGE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date début"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Date fin"));

    return model;
}

bool Conge ::modifier(int id,QString nom,QString enconge,QString type,QString datedebut,QString datefin)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("update CONGE set nom=:nom,enconge=:enconge,type=:type,datedebut=:datedebut,datefin=:datefin where ID='"+res+"'");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);

    query.bindValue(":enconge",enconge);
    query.bindValue(":type",type);
       query.bindValue(":datedebut",datedebut);
              query.bindValue(":datefin",datefin);
    return query.exec();
}



QSqlQueryModel* Conge::triea(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        model->setQuery("select *FROM CONGE ORDER BY TYPE DESC");
    }
    else if (index==1)
    {
        model->setQuery("select *FROM CONGE ORDER BY NOM ASC ");
    }
    else if(index==2)
    {
        model->setQuery("select *FROM CONGE ORDER BY DATED ASC ");
    }



    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ENCONGE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date début"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Date fin"));


    return model;
}


