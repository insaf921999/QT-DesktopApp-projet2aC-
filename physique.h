#ifndef PHYSIQUE_H
#define PHYSIQUE_H
#include <QSqlQueryModel>
#include <QAbstractItemModel>
#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QDialog>
#include <QtWidgets>
#include "client.h"

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
     bool modifier(int);
     bool supprimerPH(long);
     void chercher();
      QSqlQueryModel * rechercher(const QString &cnn);

     //void afficher_physique(QTableWidget *t);
     //void triClientPH_CIN();

//protected:

    int CIN;
    QString nom;
    QString prenom;
    QString date_naissance;
    QString adresse;
    QString email;

};



#endif // PHYSIQUE_H
