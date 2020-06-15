#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "choisir.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/prefix1/632.wav"));
    music->play();
    QPropertyAnimation *animation = new QPropertyAnimation(ui->animation, "geometry");
            animation->setDuration(10000);
            animation->setLoopCount(-1);
            animation->setStartValue(QRect(0, 405, 191,59));
            animation->setEndValue(QRect(690, 405, 191, 59));
            animation->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::research()
{

    QString username = ui->MDP_edit_2->text();
    QString password = ui->MDP_edit->text();
    QSqlQuery query;
    query.prepare("SELECT * from ADMIN WHERE LOGIN = ? AND MDP = ? ");
    query.addBindValue(username);
    query.addBindValue(password);
    query.exec();
    if (query.next())
       { qDebug() << "is logged in";
        return true;}
    else
    {
        qDebug() << "Login failed. Invalid username or password.";
        return false;
    }



}

void MainWindow::on_pushButton_clicked()
{ choisir g;g.exec();
    if (research())
    {g.exec();}


}

void MainWindow::on_pushButton_2_clicked()
{
    ui->MDP_edit_2->setText("");
    ui->MDP_edit->setText("");
}
