#ifndef STAT_NO_H
#define STAT_NO_H
#include "parkingcode.h"
#include <QDialog>

namespace Ui {
class stat_no;
}

class stat_no : public QDialog
{
    Q_OBJECT

public:
    explicit stat_no(QWidget *parent = nullptr);
    ~stat_no();

private:
    Ui::stat_no *ui;
    parkingCode tableNoDispo;
};

#endif // STAT_NO_H
