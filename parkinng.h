#ifndef PARKINNG_H
#define PARKINNG_H
#include "parkingcode.h"
#include <QDialog>

namespace Ui {
class parkinng;
}

class parkinng : public QDialog
{
    Q_OBJECT

public:
    explicit parkinng(QWidget *parent = nullptr);
    ~parkinng();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_RP_clicked();

    void on_pushButton_NBE_clicked();

    void on_pushButton_NBP_clicked();

    void on_pushButton_S_clicked();

private:
    Ui::parkinng *ui;
    parkingCode tmpparking;
};

#endif // PARKINNG_H
