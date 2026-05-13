#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <string>
#include <vector>
#include "personne.h"

using namespace std ;

QT_BEGIN_NAMESPACE
namespace Ui { class Registre; }
QT_END_NAMESPACE

class Registre : public QMainWindow
{
    Q_OBJECT

public:
    Registre(QWidget *parent = nullptr);
    ~Registre();
    void afficheMembre(int page) ;

private slots:
    void on_edit_clicked();
    void on_ok_clicked();
    void on_effacer_clicked();
    bool on_feminin_clicked();
    bool on_masculin_clicked();
    void setPage(int _page) ;
    int getPage() ;
    void on_next_clicked();
    void on_precedent_clicked();
    void on_actionn_Ouvrir_triggered() ;
    void setCurent_file(QString file) ;
    QString getCurent_file() ;

private:
    Ui::Registre *ui;
    int page = 1 ;
    QString curent_file ;
    vector<personne> membre ;
    vector<QLabel*> mes_labels ;

};
#endif // MAINWINDOW_H

