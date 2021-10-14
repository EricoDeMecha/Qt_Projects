#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <QObject>
#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

class db_connection
{
public:
    db_connection();
    void connect_db();
    void execute_query(QString);
};

#endif // DB_CONNECTION_H
