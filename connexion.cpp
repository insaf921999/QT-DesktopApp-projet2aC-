#include "connexion.h"
#include <QDebug>
#include <QSqlError>
connexion::connexion()
{
}
bool connexion::ouvrircnx()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("insaf");
    db.setPassword("insaf");

    if(db.open())
    return true;
    //qDebug()<<db.lastError();
    return false;
}

void connexion::fermercnx()
{  db.close(); }
