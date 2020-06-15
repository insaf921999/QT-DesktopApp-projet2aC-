#ifndef ABONNEMENTCODE_H
#define ABONNEMENTCODE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class abonnementCode
{
public:
    abonnementCode();
    abonnementCode(int,QString,QString,int,QDate,QDate,QDate);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_numplace();
    QDate get_date_naiss();
    QDate get_date_deb();
    QDate get_date_fin();


    bool ajouter();
QSqlQueryModel * afficherID(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int);
    bool tester(long );
long testerA(long );
private:
    int id;
    QString nom;
    QString prenom;
    int numplace;
    QDate datenaiss;
    QDate datedeb;
    QDate datefin;

};

#endif // ABONNEMENTCODE_H
