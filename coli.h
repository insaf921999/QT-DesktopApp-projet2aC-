#ifndef COLI_H
#define COLI_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <qsqlquerymodel.h>
#include<qsqltablemodel.h>
#include <QDate>
class coli
{
     int reference;
     QString nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest;

public:
    coli();
    coli(int,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    int getidcoli();
    void setidcoli(int);
    QString getidclientdest();
    //implement les get et les set
    bool ajoutercoli();
    bool supprimercoli(int);
    bool modifiercoli(int);
    virtual QSqlQueryModel * affichercoli();
    virtual QSqlQueryModel * affichertriccoli();
    virtual QSqlQueryModel * affichertridcoli();

    QSqlQueryModel * recherchercoli_ref(const QString &);
    QSqlQueryModel * recherchercoli_nom(const QString &);
    QSqlQueryModel * recherchercoli_poid(const QString &);
    QSqlQueryModel * recherchercoli_nbpiece(const QString &);
    QSqlQueryModel * recherchercoli_idclientdest(const QString &);
    QSqlQueryModel * recherchercoli_etat(const QString &);
    QSqlQueryModel * recherchercoli_montant(const QString &);
    QSqlQueryModel * recherchercoli_adressee(const QString &);
    QSqlQueryModel * recherchercoli_adresseed(const QString &);
    QSqlQueryModel * recherchercoli_paiment(const QString &);


};

#endif // COLI_H
