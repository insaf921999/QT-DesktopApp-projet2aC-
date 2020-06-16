#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <coli.h>
#include <courrier.h>
#include <smtp.h>
#include "mailing.h"
#include "agent.h"
#include "conge2.h"
#include "parkingcode.h"
#include "agent.h"
#include "abonnementcode.h"
#include "physique.h"
#include "moral.h"
#include "cartesolde.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
 //   void on_pushButton_coli_clicked();
 //   void on_pushButton_affich_coli_clicked();
  //  void on_tablecoli_activated(const QModelIndex &index);
 //   void on_comboBox_3_currentIndexChanged(const QString &arg1);
  //  void on_label_linkActivated(const QString &link);
   void on_pushButton_aj_courrier_clicked();
 //   void on_pushButton_clicked();
    void on_ajoutercoli_clicked();
    void on_lirecoli_clicked();
    void on_modifiercoli_clicked();
    void on_suppcoli_clicked();
    void on_tricroisscoli_clicked();
    void on_tridecroissantcoli_clicked();
    void on_tablecoli_activated(const QModelIndex &index);
    void on_comboBox_3_currentIndexChanged(const QString &arg1);
    void on_pushButton_affich_courrier_clicked();
    void on_pbmodifiercourrier_clicked();
    void on_supprimercourrier_clicked();
    void on_tricroissantcourrier_clicked();
    void on_tridecroisscourrier_clicked();
    void on_comboBox_6_currentIndexChanged(const QString &arg1);
    void on_tablecourrier_activated(const QModelIndex &index);
    void on_rechcoli_clicked();
    void on_pbrechcourrier_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_ExporterColis_clicked();
    void on_ExporterCourriers_clicked();
 //   void on_SendEmail_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_8_clicked();
    void on_comboBox_11_currentIndexChanged(const QString &arg1);
    void on_pushButton_9_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pushButton_17_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_RP_clicked();
    void on_pushButton_NBP_clicked();
    void on_pushButton_NBE_clicked();
    void on_pushButton_S_clicked();
  //  void on_pushButton_S_2_clicked();

    void on_pushButton_S_2_clicked();

    void on_ajouter_abon_clicked();

    void on_midifer_abon_clicked();

    void on_supp_abon_clicked();

    void on_pushButton_R_clicked();

    void on_pushButton_ajouterPH_clicked();

    void on_pushButton_modifierPH_clicked();

    void on_pb_supprimerPH_clicked();

    void on_lineEdit_rechercherPH_textChanged(const QString &arg1);

    void on_comboBox_typeclient_activated(const QString &arg1);

    void on_comboBox_13_activated(const QString &arg1);

    void afficher_physique(QTableWidget *t);

    void on_pushButton_afficherPH_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void triClientPH_CIN();

    void trie_nom();

    void on_pushButton_ajouterM_clicked();

    void on_pb_supprimerM_clicked();

    void afficher_moral(QTableWidget *t);

    void on_pushButton_AfficherListe_clicked();

    void on_lineEdit_recherC_textChanged(const QString &arg1);

    void on_pushButton_20_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_chercher_clicked();

    void on_lineEdit_chercher_2_textChanged(const QString &arg1);

    void on_tabWidget_5_currentChanged(int index);

    void afficher_carte(QTableWidget *t);

    void on_comboBox_14_activated(const QString &arg1);

    void trie_id();
    void trie_montant();

    void on_sendBtn_abon_clicked();

    void on_envoyer_email_bott_clicked();

    void on_pushButton_afficherCarte_clicked();

    void on_pushButton_modifier_M_clicked();

private:
    Ui::MainWindow *ui;
       coli tcmp;
       courrier tccmp;
       mailing *secdialog;

    Agent a;
    Conge c;
    QTimer *timer;

     parkingCode tmpparking;
     Agent tmpagent;
     abonnementCode tmpabonnement;
     physique tmpphysique;
     moral tmpmoral;
     cartesolde tmpsolde;
     client tmpclient;


};
#endif // MAINWINDOW_H
