#ifndef CHOISIR_H
#define CHOISIR_H

#include <QDialog>

namespace Ui {
class choisir;
}

class choisir : public QDialog
{
    Q_OBJECT

public:
    explicit choisir(QWidget *parent = nullptr);
    ~choisir();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::choisir *ui;
};

#endif // CHOISIR_H
