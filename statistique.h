#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
/*
namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private:
    Ui::statistique *ui;
};

*/

namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

    void paintEvent(QPaintEvent *);

private:
    Ui::statistique *ui;

};

#endif // STATISTIQUE_H
