#ifndef STAT_H
#define STAT_H
#include "parking.h"
#include <QDialog>

namespace Ui {
class Stat;
}

class Stat : public QDialog
{
    Q_OBJECT

public:
    explicit Stat(QWidget *parent = nullptr);
    ~Stat();

private:
    Ui::Stat *ui;
    parking tableDispo;
};

#endif // STAT_H
