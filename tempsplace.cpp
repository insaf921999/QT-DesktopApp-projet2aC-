#include "tempsplace.h"
#include <iostream>
tempsplace::tempsplace()
{

}
/*
int Statistique_partie1()
{

    QSqlQuery query;
    int count=0 ;
    int non1=0;
    int oui2=1;
    QString oui=QString::number(oui2);
    QString non=QString::number(non1);
    QSqlQuery requete("update TABLE_PARK set ETAT='"+non+"') ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}

int Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    int non1=0;
    int oui2=1;
    QString oui=QString::number(oui2);
    QString non=QString::number(non1);;
    QSqlQuery requete("select * from PARKING_PLACE where ETAT='oui'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void paintEvent(QPaintEvent *)
{


    tempsplace *s;
           int a=s->Statistique_partie1();
           int b=s->Statistique_partie2();

           int s1= a*100 ;
               int s2= b*100 ;
               int nb = a+b ;
               int q1 ;
               q1 = s1/nb ;
               int q2 ;
               q2 = s2/nb ;
               int x  ;
               x= (q1*360)/100 ;
               int y  ;
               y = (q2*360)/100 ;

           QPainter painter(this);
           QRectF size=QRectF(50,50,this->width()-100,this->width()-100);

           painter.setBrush(Qt::yellow);
           painter.drawPie(size,0,16*x);
           ui->label_2-> setText("oui") ;
           painter.setBrush(Qt::blue);
           painter.drawPie(size,16*x,16*y);
           ui->label_3->setText("non") ;
           painter.setBrush(Qt::green);


           exec();
          show();
}
*/
