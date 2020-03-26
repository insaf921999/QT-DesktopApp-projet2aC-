#include "place.h"

place::place()
{
    id=0;
    nb_place=0;
    nb_voiture=0;
    tarif=0;
}

place::place(int id,int nb_place,int nb_voiture,float tarif)
{
    this->id=id;
    this->nb_place=nb_place;
    this->nb_voiture=nb_voiture;
    this->tarif=tarif;
}

int place::get_id(){return id;}
int place::get_nb_place(){return nb_place;}
int place::get_nb_voiture(){return nb_voiture;}
double place::get_tarif(){return tarif;}

bool place::ajouterp()
{
    QSqlQuery query;
    query.prepare("insert into place (ID,NB_PLACE,NB_VOITURE) VALUES (:id,:nb_place,:nb_voiture)");
    query.bindValue(":id",id);
    query.bindValue(":nb_place",nb_place);
    query.bindValue(":nb_voiture",nb_voiture);
    //query.bindValue(":tarif",tarif);

    return query.exec();
}

QSqlQueryModel * place::afficherp()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from place");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_place "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_voiture"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tarif"));
    return model;
}

bool place::supprimerp(int id)
{
    QSqlQuery query;
query.prepare("Delete from place where id =:id ");
query.bindValue(":id", id);
return    query.exec();
}

bool place::modifierp(int id,int nb_place,int nb_voiture,double tarif)
{
    QSqlQuery query;
    query.prepare("update place set nb_place=:nb_place,nb_voiture=:nb_voiture,tarif=:tarif where id=:id");
    query.bindValue(":id",id);
    query.bindValue(":nb_place",nb_place);
    query.bindValue(":nb_voiture",nb_voiture);
    query.bindValue(":tarif",tarif);
    return query.exec();
}
QSqlQueryModel * place::chercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from place where id like :id order by tarif ");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nb_place"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("nb_voiture"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("tarif"));
    return model;
}
QSqlQueryModel* place::trie(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        model->setQuery("select *FROM place ORDER BY ID ASC");
    }
    else
    {
        model->setQuery("select *FROM place ORDER BY ID DESC ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_place"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_voiture"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tarif"));

    return model;
}

