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
    abonnementCode(int,QString,QString,QDate,QDate,QDate,int);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QDate get_date_naiss();
    QDate get_date_deb();
    QDate get_date_fin();
    int get_numplace();

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
    QDate datenaiss;
    QDate datedeb;
    QDate datefin;
    int numplace;


};

#endif // ABONNEMENTCODE_H
