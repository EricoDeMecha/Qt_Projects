#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QDebug>
#include <QCloseEvent>

#include "sqlitehandler.h" // for  database management
#include "sql.h"

using namespace sql;


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
public:
    QString fullname = "";
    QString security_number = "";
    QString username = "";
    QString password = "";
    QString confirm_password = "";
    int access_level = 0;
    bool _exit = false;
private:
    Ui::Register *ui;
    const QString db_name = "users";
    const QString conn_name  = "registers";
    SqliteHandler *hdl_register;
    const QString crt_table =
            "CREATE TABLE users ( "
            "full_name TEXT, security_number TEXT, user_name TEXT, password TEXT, access_level INTEGER)";

protected:
    void closeEvent(QCloseEvent* event);
private:
   bool saveUser();
public slots:
    void onOKClicked();
    void onCancelClicked();
    void onValueChanged(int);
};

#endif // REGISTER_H
