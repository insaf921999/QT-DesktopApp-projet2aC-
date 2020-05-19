#ifndef PHYSIQUE_H
#define PHYSIQUE_H
#include "client.h"
#include <QSqlQueryModel>
#include <QAbstractItemModel>
#include <QString>
#include <QDate>

class physique : public client
{


public:
    physique();
    physique(int,QString, QString,QString,QString,QString);
    physique(int,QString , QString, QString, QString, QString , int  );

    void setCIN(long);
    void setNom(QString);
    void setPrenom(QString);
    void setdateNaiss(QString);
    void setAdresse(QString);
    void setEmail(QString);

     long getCIN();
     QString getNom();
     QString getPrenom();
    QString getDateNaiss();
    QString getAdresse();
     QString getEmail();

     bool ajouter_physique(int );
     QSqlQueryModel* afficherPH();
     bool modifier();
     bool supprimerPH(long);
     void chercher();
      QSqlQueryModel * rechercher(const QString &cnn);


protected:

    int CIN;
    QString nom;
    QString prenom;
    QString date_naissance;
    QString adresse;
    QString email;

};



#endif // PHYSIQUE_H
