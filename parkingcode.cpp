#include "parkingcode.h"
#include <QDebug>
#include <QString>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
parkingCode::parkingCode()
{

}
parkingCode::parkingCode(int id, QString prenom, int nbrplace,int nbretage )
{
    this->id=id;
    this->nbrplace=nbrplace;
    this->nbretage=nbretage;
    this->prenom=prenom;
}

int parkingCode::get_id(){return  id;}
QString parkingCode::get_prenom(){return  prenom;}
int parkingCode::get_nbrplace(){return  nbrplace;}
int parkingCode::get_nbretage(){return  nbretage;}



bool parkingCode::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO parking (ID, PRENOM, NBRPLACE, NBRETAGE) "
                    "VALUES (:id, :prenom, :nbrplace, :nbretage)");

query.bindValue(":id", res);
query.bindValue(":prenom", prenom);
query.bindValue(":nbrplace", nbrplace);
query.bindValue(":nbretage", nbretage);


return    query.exec();
}

QSqlQueryModel * parkingCode::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from parking order by ID asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbr place"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbr d etage"));


    return model;
}






bool parkingCode::modifier(int num , int nouvCode)
{

         QSqlQuery  *q = new QSqlQuery();

         QString res= QString::number(num);
         QString code= QString::number(nouvCode);
         q->prepare("UPDATE parking set nbretage=:nbretage WHERE ID=:id ");
         q->bindValue(":id",res);
         q->bindValue(":nbretage",code);

         if(q->exec() )
         {qDebug()<<"modif succée";
             return true;
         }
         else
         {
             qDebug()<<"modif failed";
             return false;
         }

}




bool parkingCode::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from parking where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool parkingCode::testerPark(int idd)
{
    QSqlQuery q;
    QString res= QString::number(idd);

    q.prepare("SELECT ID from PARKING where ID=:idd");
    q.bindValue(":idd",res);

    q.exec();
    if(q.next())
    {
        qDebug()<<"parking existe";
        return true;
    }
    else
        {
        qDebug()<<"parking n'existe pas";
        return false;
}}
QSqlQueryModel*  parkingCode::Tri(){

    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *p  = new QSqlQuery();
     p->prepare("SELECT * FROM PARKING order by NBRPLACE asc");
     p->exec();
     model->setQuery(*p);
     return model ;

}
QSqlQueryModel*  parkingCode::Tri2()
{

    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *p  = new QSqlQuery();
     p->prepare("SELECT * FROM PARKING order by NBRETAGE asc");
     p->exec();
     model->setQuery(*p);
     return model ;

}

QSqlQueryModel * parkingCode::afficher_stat()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT SUM(parking.nbrplace) place, SUM(parking.nbretage) num, AVG(parking.nbrplace) moy, AVG(parking.nbretage) FROM parking  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nombres des places dispo places"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nombre total des etages"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("moyenne des places"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("moyenne des etages"));



    return model;
}

QSqlQueryModel *parkingCode::afficherid(int id)
    {QSqlQueryModel * model= new QSqlQueryModel();

     QString res= QString::number(id);

    QSqlQuery *q = new QSqlQuery;
     q->prepare("SELECT * from PARKING where ID LIKE '%"+res+"%'");
      q->addBindValue(res);
       q->exec();
         model->setQuery(*q);


        return model;
    }


