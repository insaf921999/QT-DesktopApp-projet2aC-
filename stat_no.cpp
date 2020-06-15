#include "stat_no.h"
#include "ui_stat_no.h"
#include "parkingcode.h"
#include "QSqlTableModel"
stat_no::stat_no(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_no)
{
    ui->setupUi(this);
    ui->table_no->setModel(tableNoDispo.afficher_stat());

    QSqlTableModel * model= new QSqlTableModel;

    model->setTable("PARKING");
    model->select();
    //ui->table_no_2->setModel(model);


    ui->widget->xAxis->setLabel("numero parking");
    ui->widget->yAxis->setLabel("nbr place");



    QVector<QCPGraphData> timeData(model->rowCount());
      for(int i=0;i<model->rowCount();i++)
        {
            timeData[i].key  = model->index(i, model->fieldIndex("ID")).data().toInt();
            timeData[i].value = model->index(i, model->fieldIndex("NBRPLACE")).data().toInt();
        }
    ui->widget->xAxis->setRange(0,50);
    ui->widget->yAxis->setRange(0,50);
    ui->widget->addGraph();
    ui->widget->graph(0)->data()->set(timeData);
    ui->widget->replot();


}

stat_no::~stat_no()
{
    delete ui;
}
