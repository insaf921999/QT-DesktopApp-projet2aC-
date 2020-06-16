#ifndef CARTESOLDE_H
#define CARTESOLDE_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QAbstractItemModel>
#include <QDate>
#include <QString>
class cartesolde
{
    public:
         cartesolde();
         cartesolde(int,int, QDate);
         cartesolde(int  ,int ,QDate , int );

         void setID_compteS(int);
         void set_Montant(int);
         void setDate_ouverture(QDate);
         int get_ID_compteS();
         int getMontant();
         QDate getDate_ouverture();

          bool ajouter_solde(int );
          QSqlQueryModel* afficher();
          bool modifier();
          bool supprimer(int);
          bool mise_ajour();
          //void chercher();
          QSqlQueryModel * rechercher(const QString &id);

      protected:
         int id_compteS;
         int montant;
         QDate date_ouverture;
};

#endif // CARTESOLDE_H
