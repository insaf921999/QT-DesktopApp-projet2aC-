#ifndef PARKING_H
#define PARKING_H

#include <QDialog>

namespace Ui {
class parking;
}

class parking : public QDialog
{
    Q_OBJECT

public:
    explicit parking(QWidget *parent = nullptr);
    ~parking();

private:
    Ui::parking *ui;
};

#endif // PARKING_H
