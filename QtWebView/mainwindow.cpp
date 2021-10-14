#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set up the web widget
    webView = new QWebEngineView();
    ui->hl_webContainer->addWidget(webView);
    connect(ui->lineEdit, SIGNAL(returnPressed()),this, SLOT(onReturnPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReturnPressed(){
    QUrl url = QUrl(ui->lineEdit->text());
    url.setScheme("https");
    webView->page()->load(url);
}
