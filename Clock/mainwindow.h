#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets>
#include <QWebEngineView>
#include <QtWebView/QtWebView>
#include <QWebEngineProfile>
#include <QWebEnginePage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWebEngineView* web_view;
    QUrl url = QUrl("https://time.is");
    QWebEngineProfile *profile;
    QWebEnginePage* web_page;
};
#endif // MAINWINDOW_H
