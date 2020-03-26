#ifndef PLACE_H
#define PLACE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class place
{
public:
    place();
    place(int,int,int,float);
    int get_id();
    int get_nb_place();
    int get_nb_voiture();
    double get_tarif();
    bool ajouterp();
    QSqlQueryModel * afficherp();
    bool supprimerp(int);
    bool modifierp(int,int,int,double);
    QSqlQueryModel *chercher(int id);
    QSqlQueryModel* trie(int index);
private:
    int id,nb_place,nb_voiture;
    double tarif;

};

#endif // PLACE_H
