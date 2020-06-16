#ifndef AGENT_H
#define AGENT_H
#include<QSqlQueryModel>
#include <QString>


class Agent
{public:
    Agent();
    Agent(int,QString,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString  get_prenom();
       QString get_role();
    QString get_pass();
    QString get_repass();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     QSqlQueryModel *cherchera(int id);
     bool modifier(int,QString,QString,QString,QString);
      QSqlQueryModel* triea(int index);
      bool verif(QString);
QSqlQueryModel * afficherI();
private:
    QString role,dated,nom,prenom;
    int id;
};
#endif // AGENT_H
