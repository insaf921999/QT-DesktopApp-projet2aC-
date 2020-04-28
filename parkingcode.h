#ifndef PARKINGCODE_H
#define PARKINGCODE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class parkingCode
{
public:
    parkingCode();
    parkingCode(int,QString,int,int);
    int get_id();

    QString get_prenom();
    int get_nbrplace();
    int get_nbretage();


    bool ajouter();

    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int);
    bool testerPark(int );
    QSqlQueryModel*  Tri();
      QSqlQueryModel*  Tri2();
      QSqlQueryModel * afficher_stat();
      QSqlQueryModel * afficherid(int);
private:
    int id;
    QString prenom;
    int nbrplace;
    int nbretage;
};

#endif // PARKINGCODE_H
