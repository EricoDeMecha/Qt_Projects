#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QHeaderView>
#include <algorithm>
#include "login.h"
#include "register.h"
#include "record.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void plotCustomPlot0();
    void plotCustomPlot1();
    void plotCustomPlot2();
    void plotCustomPlot3();
    void plotCustomPlot4();
private:
    Ui::MainWindow *ui;
    unsigned int n_rows  = 1;
    QList<int> comboItems;
    QList<int> comboItems2;
    QPushButton *edit_btn;
    QString btn_style =
            "QPushButton { "\
            "background: #3498db;"\
            "background-image: -ms-linear-gradient(top, #3498db, #2980b9);"\
            "background-image: -o-linear-gradient(top, #3498db, #2980b9);"\
            "background-image: linear-gradient(to bottom, #3498db, #2980b9);"\
            "border-radius: 28px;"\
            "font-family: Georgia;"\
            "color: #ffffff;"\
            "font-size: 10px;"\
            "padding: 2px 2px 2px 2px;"\
            "text-decoration: none;"\
          "}"\
          "QPushButton:hover {"\
            "background: #3cb0fd;"\
            "background-image: -ms-linear-gradient(top, #3cb0fd, #3498db);"\
            "background-image: -o-linear-gradient(top, #3cb0fd, #3498db);"\
            "background-image: linear-gradient(to bottom, #3cb0fd, #3498db);"\
            "text-decoration: none;"\
          "}";
    QVector<QString> labels = {"Andhra Pradesh" , "Arunachal Pradesh", "Assam",
                               "Bihar","Chhattisgarh","Goa","Haryana"};
private:
    QStringList toStringList(const QList<int> list);
public slots:
    void onComboCurrentIndexChanged(int);
};
#endif // MAINWINDOW_H
