#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Clock");// main window title
    web_view  = new QWebEngineView();
    profile = new QWebEngineProfile("Prometheus", web_view);
    profile->defaultProfile()->cookieStore()->deleteAllCookies();// delete all cookies
    web_page = new QWebEnginePage(profile, web_view);
    web_view->setPage(web_page);
    ui->horizontalLayout->addWidget(web_view);
    url.setScheme("https");
    web_view->page()->load(url);
}

MainWindow::~MainWindow()
{
    delete ui;
}

