#include "statcourrier.h"
#include "ui_statcourrier.h"

statcourrier::statcourrier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statcourrier)
{
    ui->setupUi(this);
}

statcourrier::~statcourrier()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    int i=0;
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Moyen de paiement");
    regen->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    regen->setBrush(QColor(111, 9, 176));
    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;
    labels << "en especes " << "par carte" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,20);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
     ui->customPlot->yAxis->setLabel("Nombre de courriers");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;
int stat100;
int stat500;

QString var1="en especes";
QString var2="par carte";

QSqlQuery query1("select count(*) from courrier where paiement3='"+var1+"'");
while (query1.next()) {

                        stat100 = query1.value(0).toInt();

QSqlQuery query2("select count(*) from courrier where paiement3 ='"+var2+"'  ");
while (query2.next()) {
                           stat500 = query2.value(0).toInt();

                             }
    regenData << stat100 << stat500  ;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
}
