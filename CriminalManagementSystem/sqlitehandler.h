#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QStringList>
#include <QFile>
#include <QDebug>

class SqliteHandler 
{
public:
    SqliteHandler(QString _db_name,QString _con_name);
    SqliteHandler() = default;// default constructor
    ~SqliteHandler();
    void setupConn(QString, QString);
    bool findDrivers();
    bool findAndCreateDbConnection();
    bool createTable(QString);
    QSqlQuery selectCommand(QString);
    bool execCommand(QString);
public:
    QSqlError _error;
private:
    QString db_name;
    QString con_name;
    const QString DRIVER = "QSQLITE";
    QSqlDatabase db_con;
private:
};

#endif // SQLITEHANDLER_H
