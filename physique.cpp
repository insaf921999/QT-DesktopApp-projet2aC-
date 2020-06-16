#include "physique.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "client.h"


physique::physique()
{


}
physique::physique(int CIN,QString nom, QString prenom, QString date_naissance, QString adresse, QString email )
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date_naissance;
    this->adresse=adresse;
    this->email=email;

}
physique::physique(int CIN,QString nom, QString prenom, QString date_naissance, QString adresse, QString email, int id_client ):client(id_client)
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date_naissance;
    this->adresse=adresse;
    this->email=email;

}
void physique:: setCIN(long cin)
{
    this->CIN =cin;
}
void physique:: setNom(QString n)
{
   this->nom =n;
}
void physique:: setPrenom(QString p)
{
   this->prenom = p;
}
void physique:: setdateNaiss(QString d)
{
   this->date_naissance = d;
}
void physique:: setAdresse(QString a)
{
   this->adresse = a;
}
void physique:: setEmail(QString e)
{
   this->email = e;
}


long physique:: getCIN()
{
    return CIN;
}

QString physique:: getNom()
{
    return nom;
}

QString physique:: getPrenom()
{
    return prenom;
}

QString physique:: getDateNaiss()
{
    return date_naissance ;
}

QString physique:: getAdresse()
{
    return adresse;
}

QString physique:: getEmail()
{
    return email;
}


bool physique::ajouter_physique(int id){

    QSqlQuery query1;

          query1.prepare("INSERT INTO PHYSIQUE( CIN, NOM, PRENOM , DATE_NAISSANCE , ADRESSE , EMAIL , ID_CLIENT) "
                        "VALUES ( :CIN , :nom , :prenom , :date_naissance ,:adresse ,:email, :id_client)");

          query1.bindValue("id_client",id);

          query1.bindValue(":CIN",CIN);
          query1.bindValue(":nom",nom );
          query1.bindValue(":prenom",prenom );
          query1.bindValue(":date_naissance",date_naissance );
          query1.bindValue(":adresse", adresse);
          query1.bindValue(":email", email);

          return  query1.exec();


}


QSqlQueryModel *physique::afficherPH()
{
    //client::afficher1();
   QSqlQueryModel *model = new QSqlQueryModel;
      model->setQuery("SELECT * FROM PHYSIQUE ");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN "));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date_naissance"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
     // model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_Clinet"));
      return model;

}
/*void physique::afficher_physique(QTableWidget *t)
 {
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from PHYSIQUE");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(7);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString(" CIN ; NOM ; PRENOM ; DATE_NAISSANCE ; ADRESSE ; EMAIL ; ID_CLIENT ").split(" ; "));
    i=1;
    qry.exec("select* from  PHYSIQUE");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
               t->setItem(i-1,4,new QTableWidgetItem(qry.value(4).toString()));
               t->setItem(i-1,5,new QTableWidgetItem(qry.value(5).toString()));
               t->setItem(i-1,6,new QTableWidgetItem(qry.value(6).toString()));


    i++;
    }
}*/


bool physique::supprimerPH(long cinn)
{
QSqlQuery query;
QString res= QString::number(cinn);
query.prepare("Delete FROM PHYSIQUE where CIN=:CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}


bool physique::modifier(int cinn)
{

        QSqlQuery query;
        QString res= QString::number(CIN);
        query.prepare("update PHYSIQUE set adresse=:adresse,email=:email where CIN=:cinn ");
        query.bindValue(":Cin", res);
        query.bindValue(":adresse",adresse);
        query.bindValue(":email",email);
        query.bindValue(":cinn",cinn);

        return    query.exec();

}


QSqlQueryModel * physique::rechercher(const QString &cnn)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PHYSIQUE where(CIN LIKE '"+cnn+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL "));
    return model;
}


