#ifndef AGENT_H
#define AGENT_H
#include<QSqlQueryModel>
#include <QString>


class Agent
{public:
    Agent();
    Agent(int,int,int,QString,QString);
    int get_id();
    int get_heuree();
    int get_heures();
    QString get_role();
    QString get_email();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString role,email;
    int id,heuree,heures;
};
#endif // AGENT_H
