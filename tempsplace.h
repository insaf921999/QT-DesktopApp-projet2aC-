#ifndef TEMPSPLACE_H
#define TEMPSPLACE_H
#include "connexion.h"
#include <QMainWindow>
#include <QPainter>
#include <QDebug>

#include <QSqlQuery>
#include <iostream>

class tempsplace
{
public:
    tempsplace();
    int Statistique_partie1() ;
    int Statistique_partie2() ;
    void paintEvent(QPaintEvent *) ;

};

#endif // TEMPSPLACE_H
