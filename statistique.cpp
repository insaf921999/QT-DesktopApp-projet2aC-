#include "statistique.h"
#include "ui_statistique.h"
#include "connexion.h"
#include <QMap>
#include <QVector>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include "QSqlTableModel"
#include "physique.h"
QT_CHARTS_USE_NAMESPACE
statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}

void statistique::paintEvent(QPaintEvent *)

{
    QPainter Painter(this);
    QRectF size=QRectF(ui->customPlot_2->geometry());
    Painter.setBrush(Qt::black);
     QString r0="select * from CLIENT";
    QString r1="select * from CLIENT WHERE name='Moral'";
    QString r2="SELECT * FROM CLIENT WHERE name='Physique'";

    QSqlQuery q0,q1,q2;
    q0.exec(r0);
    q1.exec(r1);
    q2.exec(r2);
     int tot, m,ph;

     while(q0.next())
     {
       tot++;
     }

     while(q1.next())
     {
       m++;
     }
     while(q2.next())
     {
         ph++;
     }

   m= (((m*100)/tot)*360)/100;
   ph= (((ph*100)/tot)*360)/100;
   Painter.drawPie(size,0,m*16);
   Painter.setBrush(Qt::green);
   Painter.drawPie(size, m*16,ph*16);
   Painter.setBrush(Qt::red);
}
