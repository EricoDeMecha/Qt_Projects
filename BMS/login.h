#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtWidgets>
#include <QDateTime>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_signUp_clicked();

    void on_login_2_clicked();
 bool db_check(QString);
      bool db_check_2(QString);

private:
    Ui::login *ui;
};

#endif // LOGIN_H
