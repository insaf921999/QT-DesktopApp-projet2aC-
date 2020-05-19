#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQueryModel>
#include <QAbstractItemModel>
#include <QString>

class client
{
public:
    client();
    client(int);
    client(int,QString);
    void setID_client(int);
    void set_type(QString);

    int get_ID_client();
    QString get_type();

     bool ajouter_client();
    QSqlQueryModel* afficher1();
    bool authentification();
    bool verif();
    void chercher(int );
     void statistique(QVector<double>*,QVector<QString>*);
    QSqlQueryModel *  afficher_liste_client();


   protected:

    int id_client;
    QString Type;




};

#endif // CLIENT_H
