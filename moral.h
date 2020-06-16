#ifndef MORAL_H
#define MORAL_H
#include <QSqlQueryModel>
#include <QAbstractItemModel>
#include <QString>
#include "client.h"

class moral : public client
{


public:
    moral();
    moral(int,int, QString);
    moral(int  RIB,int matricule,QString nom_entreprise, int id_client);

    void setRIB(int);
    void setMatricule(int);
    void setNom_entreprise(QString);

    int getRIB();
    int getMatricule();
    QString getNom_entreprise();

     bool ajouter_moral(int );
     QSqlQueryModel* afficherM();
     bool modifier(int);
     bool supprimer(int);
     void chercher();
     void chercher (int id_client);
     QSqlQueryModel * recherche(const QString &rib);

protected:

    int RIB;
    int matricule;
    QString nom_entreprise;
    int id_client;
};



#endif // MORAL_H
