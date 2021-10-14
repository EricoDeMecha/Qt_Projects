#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>
#include <QCloseEvent>

#include "sqlitehandler.h"
#include "sql.h"

using namespace sql;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool verifyUser();
public:
    QString password = 0;
    QString username = 0;
    bool _exit = false;
    bool _uExit = false;
    int access_level = 0;
private:
    Ui::Login *ui;
    const QString db_name = "users";
    const QString conn_name  = "logins";
    SqliteHandler *hdl;
protected:
    void closeEvent(QCloseEvent* event);
public slots:
    void onOKClicked();
    void onCancelClicked();
};

#endif // LOGIN_H
