#include "sign_in.h"
#include "ui_sign_in.h"
#include "mainwindow.h"

sign_in::sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
}

sign_in::~sign_in()
{
    delete ui;
}

void sign_in::on_pushButton_clicked()
{
    QString command1 = "use my_data;";
    QSqlQuery query(command1);

    QString  name = ui->lineEdit->text();
    QString  _pass = ui->lineEdit_2->text();
    QString _cpass = ui->lineEdit_3->text();
    QString choice = ui->comboBox->currentText();

    if(query.exec())
    {
    if(db_check(name))
    {
        QMessageBox error_val;
        error_val.setText("Error!, name already exist in the database!");
        error_val.exec();
    }
    else {
        if(_pass == _cpass)
        {
                QDateTime now = QDateTime::currentDateTime();
                 QString  date_ = now.date().toString();
                  QString  time_ = now.time().toString();
                   QString  date_time = date_ +" "+ time_;
                     QString command ="INSERT INTO my_val VALUES('"+name+"','"+_pass+"','"+date_time+"','"+choice+"');";

            QSqlQuery query1(command);
            QMessageBox success;
            success.setText("Sign  up successful");
            success.exec();

        }else {
          QMessageBox _box;
          _box.setText("Error! Passwords do not match!");
          _box.exec();
                    }
                }
             }
    else {
        QMessageBox erro_val;
        erro_val.setText("Error! Using my_data Database");
        erro_val.exec();
    }
}

bool  sign_in::db_check(QString _name)
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

