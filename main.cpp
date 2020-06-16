#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    connexion c;
    QMessageBox msgBox;
    if(c.ouvrircnx())
    {

         msgBox.setText("Connexion avec succès");
         msgBox.exec();

         w.show();


    } else
    {msgBox.setText("Echec de la connexion");
        msgBox.exec(); }

    return a.exec();
}
