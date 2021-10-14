#include "login.h"
#include "ui_login.h"
#include "sign_in.h"
#include "mainwindow.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_signUp_clicked()
{
    sign_in sign;
    sign.setWindowTitle("Sign up");
    sign.setModal(true);
    sign.exec();
}

void login::on_login_2_clicked()
{
        QString command1 = "use my_data;";

        QString name = ui->lineEdit->text();
        QString password_ = ui->lineEdit_2->text();
        QSqlQuery query;
        if(query.exec(command1))
        {

           if(db_check(name) && db_check_2(password_))
           {
               QMessageBox  log;
               log.setText("Login Successful");
               log.exec();
           }
           else {
               QMessageBox _mesg;
               _mesg.setText("Error! Access Denied!");
               _mesg.exec();
           }
        }
        else {
            QMessageBox mesg_;
            mesg_.setText("Error! Using my_data database!");
            mesg_.exec();
        }
}

bool login::db_check(QString _name)
{
    bool flag = false;
    QString command = "SELECT name FROM my_val;";
    QSqlQuery query(command);
    while(query.next())
    {
        if(_name == query.value(0).toString())
        {
            flag = true;
        }
        else {
            continue;
        }
    }

    return flag;
}
bool login::db_check_2(QString _pass)
{
    bool flag = false;
    QString command = "SELECT _password FROM my_val;";
    QSqlQuery query(command);
    while(query.next())
    {
        if(_pass == query.value(0).toString())
        {
            flag = true;
        }
        else {
            continue;
        }
    }

    return flag;
}
