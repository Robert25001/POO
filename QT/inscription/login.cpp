#include "login.h"
#include "ui_login.h"
#include "registre.h"

void Login::setName(QString nom)
{
    name = nom ;
}

void Login::setPassword(QString mot_de_passe)
{
    password = mot_de_passe ;
}

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setName("ben") ;
    setPassword("123") ;
}

Login::~Login()
{
    delete ui;
}

QString Login::getName()
{
    return name ;
}

QString Login::getPassword()
{
    return password ;
}

void Login::setText()
{
    ui->reponse->setStyleSheet("background: red;border-radius:10px") ;
    ui->reponse->setText("Nom ou mot de passe incorrect") ;
}

void Login::on_submit_clicked()
{
    QString nom , mot_de_passe , ui_name, ui_password;

    nom = ui->user->text() ;
    mot_de_passe = ui->password->text() ;
    ui_name = getName() ;
    ui_password = getPassword() ;

    if (nom == ui_name && mot_de_passe == ui_password)
    {
        Registre *programme = new Registre() ;
        programme->show() ;
        this->close() ;
    }
    else
    {
        setText() ;
    }
}


