#include "client.h"
#include<QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QMessageBox>
#include "QString"

client::client()
{


}

client::client(int id_client)
{

    this->id_client = id_client;
}

client::client(int id_client, QString Type)
{
    this->id_client = id_client;
    this->Type = Type;


}
void client:: setID_client(int id)
{
    this->id_client =id;
}

void client::set_type(QString t)
{
    Type = t;
}

int client:: get_ID_client()
{
    return id_client;
}
QString client:: get_type()
{
    return Type;
}


bool client::ajouter_client(){
    QSqlQuery query;
    QString res= QString::number(id_client);
          query.prepare("INSERT INTO CLIENT(ID_CLIENT, TYPE) "
                        "VALUES (:id_client, :Type)");
          query.bindValue(":id_client",res);
          query.bindValue(":Type", Type);

          return  query.exec();

}

QSqlQueryModel *client::afficher1()
{
   QSqlQueryModel *model = new QSqlQueryModel;
      model->setQuery("SELECT * FROM CLIENT");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
      model->setHeaderData(1, Qt::Horizontal,  QObject::tr("Type"));

      return model;

}

void client::chercher (int id_client){

QSqlQuery query1;
query1.prepare("SELECT ID_CLIENT, TYPE WHERE ID_CLIENT =:ID_CLIENT");
query1.bindValue(":id_client",id_client);
query1.exec();
while(query1.next())
{
id_client= query1.value(0).toInt();
Type = query1.value(1).toString();

}
}

QSqlQueryModel * client::afficher_liste_client(){

QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select ID_CLIENT from CLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));


    return model;

}

/*bool client:: authentification()
{
    QSqlQuery q;
    q.prepare("SELECT * FROM CLIENT WHERE (ID_CLIENT=:id_client) and (TYPE=:Type)");
    q.bindValue(":id_client",id_client);
    q.bindValue(":Type",Type);
    q.exec();
    return q.first();

}


bool client::verif(){
    if(ui->ineEdit_idC->text()==""){
        QMessageBox::warning(this, tr("ERREUR"), tr("merci de saisir votre id .\n"));
    }else if(ui->ineEdit_type->text()==""){
        QMessageBox::warning(this, tr("ERREUR"), tr("merci de saisir votre mot_de_passe \n"));

    }


    return((ui->ineEdit_idC->text()!="")&&(ui->ineEdit_type->text()!=""));

}
*/



void client::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select TYPE from CLIENT");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}
