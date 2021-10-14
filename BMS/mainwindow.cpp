#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "sign_in.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db =  QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
    {
        QMessageBox msg;
        msg.setText(db.lastError().text());
        msg.exec();
    }
    else {

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    login log;
    log.setModal(true);
    log.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    login log;
    log.setWindowTitle("Login");
    log.setModal(true);
    log.exec();
}
