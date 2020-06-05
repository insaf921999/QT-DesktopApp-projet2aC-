#ifndef COURRIER_H
#define COURRIER_H
#include <QString>
#include <QSqlQueryModel>
class courrier
{ int ref3;
  QString nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed;
public:
    courrier();
    courrier(int,QString,QString,QString,QString,QString,QString,QString,QString);
    int getidcourrier();
    void setidcourrier(int);
    //implement les get et les set
    bool ajoutercourrier();
    bool modifiercourrier(int);
    bool supprimercourrier(int);

    virtual QSqlQueryModel * affichercourrier();
    QSqlQueryModel * recherchercourrier_ref(const QString &);
    QSqlQueryModel * recherchercourrier_nom(const QString &);
    QSqlQueryModel * recherchercourrier_nbpiece(const QString &);
    QSqlQueryModel * recherchercourrier_idclientdest(const QString &);
    QSqlQueryModel * recherchercourrier_etat(const QString &);
    QSqlQueryModel * recherchercourrier_montant(const QString &);
    QSqlQueryModel * recherchercourrier_adressee(const QString &);
    QSqlQueryModel * recherchercourrier_adresseed(const QString &);
    QSqlQueryModel * recherchercourrier_paiment(const QString &);

    virtual QSqlQueryModel * affichertriccourrier();
    virtual QSqlQueryModel * affichertridcourrier();
};
#endif // COURRIER_H
