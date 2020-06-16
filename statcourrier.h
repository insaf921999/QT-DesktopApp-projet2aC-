#ifndef STATCOURRIER_H
#define STATCOURRIER_H

#include <QDialog>

namespace Ui {
class statcourrier;
}

class statcourrier : public QDialog
{
    Q_OBJECT

public:
    explicit statcourrier(QWidget *parent = nullptr);
    ~statcourrier();

private:
    Ui::statcourrier *ui;
};

#endif // STATCOURRIER_H
