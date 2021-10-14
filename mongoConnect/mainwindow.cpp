#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mongocxx::instance inst{};// this should only be done once
    const auto uri = mongocxx::uri{"mongodb://localhost:27017"};
    mongocxx::client conn{uri};

    mongocxx::database db = conn["test"];

    qDebug() << "reached here";
}

MainWindow::~MainWindow()
{
    delete ui;
}

