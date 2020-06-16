#ifndef CONGE2_H
#define CONGE2_H
#include<QSqlQueryModel>
#include <QString>
class Conge
{public:
    Conge();
    Conge(int,QString,QString,QString,QString,QString);
    QString get_nom();

    int get_id();
    QString get_enconge();
    QString  get_type();
       QString get_dated();
    QString get_datef();
    bool ajouter();
    QSqlQueryModel * afficherI();
    bool supprimerI(int);
     QSqlQueryModel *cherchera(int id);
      QSqlQueryModel *chercheraI(QString nom);
     bool modifier(int,QString,QString,QString,QString,QString);
      QSqlQueryModel* triea(int index);


private:
    QString enconge,type,dated,datef,nom;
    int id;

};

#endif // CONGE2_H
