#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <coli.h>
#include <courrier.h>
#include <smtp.h>
#include "mailing.h"
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

private:
    Ui::MainWindow *ui;
       coli tcmp;
       courrier tccmp;
       mailing *secdialog;

};
#endif // MAINWINDOW_H
