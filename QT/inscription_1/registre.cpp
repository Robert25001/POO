#include "registre.h"
#include "./ui_registre.h"
#include "personne.h"
#include <QFileDialog>
#include <QFile>
//#include <QTextStream>
//#include <QStringList>

using namespace std ;

Registre::Registre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Registre)
{
    ui->setupUi(this);
    ui->affichageMembre->setRowCount(10) ;
    ui->affichageMembre->setColumnCount(4) ;
}

Registre::~Registre()
{
    delete ui;
}

void Registre::on_edit_clicked()
{



}

void Registre::setCurent_file(QString file)
{
    curent_file = file ;
}

QString Registre::getCurent_file()
{
    return curent_file ;
}

void Registre::afficheMembre(int _page)
{
    ui->page->setText("Page: " + QString::number(_page)) ;

    QString line ;
    QStringList fields ;
    QString filePath ;

    int i = 0 , row = 0 ;
    int i_membre ;
    i_membre = (_page - 1) * 10 ;

    filePath = Registre::getCurent_file() ;
    QFile file(filePath) ;
    QTextStream stream(&file) ;
    QTableWidgetItem *item0 = new QTableWidgetItem() ;
    QTableWidgetItem *item1 = new QTableWidgetItem() ;
    QTableWidgetItem *item2 = new QTableWidgetItem() ;
    QTableWidgetItem *item3 = new QTableWidgetItem() ;

    while (!stream.atEnd())
    {
        i++ ;
        line = stream.readLine();

        if (i < i_membre)
        {
            continue ;
        }
        if (row > 9)
        {
            break ;
        }

        fields = line.split(':');

        item0->setText(fileds[0]) ;
        item1->setText(fileds[1]) ;
        item2->setText(fileds[2]) ;
        item3->setText(fileds[3]) ;

        ui->affichageMembre->setItem(row, 0, item0);
        ui->affichageMembre->setItem(row, 1, item1);
        ui->affichageMembre->setItem(row, 2, item2) ;
        ui->affichageMembre->setItem(row, 3, item3) ;
        row++ ;

    }
    file.close();
}

void Registre::on_ok_clicked()
{
    effectif += 1 ;
    personne nouveau ;
    QString nom, adresse ;
    QChar sexe ;
    int age;

    age = ui->age->text().toInt() ;
    nom = ui->nom_complet->text() ;
    adresse = ui->adresse->text() ;
    if (Registre::on_feminin_clicked())
    {
        sexe = 'F' ;
    }
    if (Registre::on_masculin_clicked())
    {
        sexe = 'M' ;
    }

    nouveau.setNom_complet(nom) ;
    nouveau.setAdresse(adresse) ;
    nouveau.setAge(age) ;
    nouveau.setSexe(sexe) ;

    membre.push_back(nouveau) ;

    Registre::afficheMembre(page) ;
}


void Registre::on_effacer_clicked()
{
    if (effectif == 0)
    {
        return ;
    }
    else
    {
        effectif -= 1 ;
    }
}

void Registre::setPage(int _page)
{
    page = _page ;
}

int Registre::getPage()
{
    return page ;
}

bool Registre::on_feminin_clicked()
{
    return ui->feminin->isChecked() ;
}

bool Registre::on_masculin_clicked()
{
    return ui->masculin->isChecked() ;
}

void Registre::on_next_clicked()
{
    int page_disponible ;
    int page_actuel ;
    page_disponible = (int)(effectif / 10) ;
    if (effectif % 10 > 0)
    {
        page_disponible += 1 ;
    }
    page_actuel = getPage() ;
    page_actuel += 1 ;

    if (page_disponible != 0 && page_actuel <= page_disponible)
    {
        setPage(page_actuel) ;
        Registre::afficheMembre(page) ;
    }
}

void Registre::on_precedent_clicked()
{
    int page_actuel ;
    page_actuel = getPage() ;
    page_actuel -= 1 ;
    if (page_actuel > 0)
    {
        Registre::setPage(page_actuel) ;
        Registre::afficheMembre(page) ;
    }
}

void Registre::on_action_Ouvrir_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QDir::homePath() , "Tous les fichiers(*.csv)");
    Registre::setCurent_file(filePath) ;
    Registre::setPage(1);
    Registre::afficheMembre(1) ;
}

