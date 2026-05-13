#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString getName() ;
    QString getPassword() ;
    void setName(QString nom) ;
    void setPassword(QString mot_de_passe) ;
    void setText() ;

private slots:

public slots:
    void on_submit_clicked();

private:
    Ui::Login *ui;
    QString name , password ;
};

#endif
