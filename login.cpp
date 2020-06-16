#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "ui_mainwindow.h"
#include "conge2.h"
#include "coli.h"
#include "agent.h"
#include "mainwindow.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QSqlQuery>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
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

login::~login()
{
    delete ui;
}

void login::on_button_login_clicked()
{
     int verif=0;
    QString username=ui->lineUsername_login->text();
    QString password=ui->Password_login->text();
          if ((password=="test")&&(username=="insaf"))
          {
             verif=1;
             qDebug()<<verif;
             close();
          }
          else
          {
               QMessageBox::warning(this,"Login","Username OR password incorrect !");
          }
      qDebug()<<verif;
  }
