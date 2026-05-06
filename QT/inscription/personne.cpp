#include "personne.h"

personne::personne()
{

}

void personne::setAge(const int &_age)
{
    age = _age ;
}

void personne::setSexe(const QChar &sex)
{
    sexe = sex ;
}

void personne::setNom_complet(const QString &nom)
{
    nom_complet = nom ;
}

void personne::setAdresse(const QString &adress)
{
    adresse = adress ;
}

QString personne::getNom_complet()
{
    return nom_complet ;
}

QChar personne::getSexe()
{
    return sexe ;
}

int personne::getAge()
{
    return age ;
}

QString personne::getAdresse()
{
    return adresse ;
}
