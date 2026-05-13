#ifndef PERSONE_H
#define PERSONE_H

#include<QString>

class personne
{
private:
    int age ;
    QString nom_complet , adresse ;
    QChar sexe ;

public:
    personne();
    void setNom_complet(const QString &nom) ;
    QString getNom_complet() ;
    void setSexe(const QChar &sex) ;
    QChar getSexe() ;
    void setAge(const int &_age) ;
    int getAge() ;
    void setAdresse(const QString &adress) ;
    QString getAdresse() ;
};

#endif // PERSONE_H
