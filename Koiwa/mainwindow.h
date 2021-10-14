#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>
#include <QPushButton>
#include <QStackedWidget>
#include <QAction>
#include <QFileDialog>
#include <QPixmap>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_admission_clicked();

    void on_students_clicked();

    void on_pushButton_2_clicked();

    void on_Thome_clicked();

    void on_SHome_clicked();

    void on_NtCancel_clicked();

    void on_TCancel_clicked();

    void on_tstaff_clicked();

    void on_ntstaff_clicked();

    void on_Scancel_clicked();

    //void  on_SUploadPass_clicked();

    void on_SSubmit_clicked();

    void on_NTSubmit_clicked();

    void on_ButtonTstaff_clicked();

private:
    Ui::MainWindow *ui;

    void display_add();
    void changeWidget(int);
    void showCharts();
    void getWindowData();
    void getWindowDataTstaff();
    void getWindowDataNTstaff();
};

#endif // MAINWINDOW_H
