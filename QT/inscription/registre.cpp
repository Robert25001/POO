#include "registre.h"
#include "./ui_registre.h"
#include "personne.h"

using namespace std ;

Registre::Registre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Registre)
{
    ui->setupUi(this);
    mes_labels.push_back(ui->label_1) ;
    ui->label_1->setText("") ;
    mes_labels.push_back(ui->label_2) ;
    ui->label_2->setText("") ;
    mes_labels.push_back(ui->label_3) ;
    ui->label_3->setText("") ;
    mes_labels.push_back(ui->label_4) ;
    ui->label_4->setText("") ;
    mes_labels.push_back(ui->label_5) ;
    ui->label_5->setText("") ;
    mes_labels.push_back(ui->label_6) ;
    ui->label_6->setText("") ;
    mes_labels.push_back(ui->label_7) ;
    ui->label_7->setText("") ;
    mes_labels.push_back(ui->label_8) ;
    ui->label_8->setText("") ;
    mes_labels.push_back(ui->label_9) ;
    ui->label_9->setText("") ;
    mes_labels.push_back(ui->label_10) ;
    ui->label_10->setText("") ;
}

Registre::~Registre()
{
    delete ui;
}

void Registre::on_edit_clicked()
{



}

void Registre::afficheMembre(int _page)
{
    ui->page->setText("Page: " + QString::number(_page)) ;
    QString nom , adresse;
    QChar sexe ;
    int i = 0 , age ;
    int i_membre ;
    i_membre = (_page - 1) * 10 ;

    for (i = 0 ; i < 10 ; i++, i_membre++)
    {
        if (i_membre < effectif)
        {
            nom = membre[i].getNom_complet() ;
            sexe = membre[i].getSexe() ;
            age = membre[i].getAge() ;
            adresse = membre[i].getAdresse() ;
            mes_labels[i]->setText(QString::number(i_membre + 1) + "\t" +  nom + "\t" + adresse + "\t" + QString::number(age) + "\t" + sexe) ;
        }
        else
        {
            mes_labels [i]->setText("") ;
        }
    }
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
        setPage(page_actuel) ;
        Registre::afficheMembre(page) ;
    }
}
