#include "sqlitehandler.h"


SqliteHandler::SqliteHandler(QString _db_name,QString _con_name){
  setupConn(_db_name, _con_name);// setup the connection
}

SqliteHandler::~SqliteHandler()
{
    db_con.close();// close the database connection
}

void SqliteHandler::setupConn(QString _db_name,QString _con_name)
{
    db_name = _db_name; con_name=_con_name;
    if(!findDrivers()){
        QMessageBox::critical(nullptr, QObject::tr("Critical Error"),
                         QObject::tr("Unable to establish a database connection.\n"
                                     "This project needs SQLite support. Please read "
                                     "the Qt SQL driver documentation for information how "
                                     "to build it.\n\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
        if(!findAndCreateDbConnection()){
            QMessageBox::critical(nullptr, QObject::tr("Critical Error"),
                             QObject::tr("Unable to create database files\n\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}
bool SqliteHandler::findDrivers()
{
        if(!QSqlDatabase::isDriverAvailable(DRIVER)){
            return false;
        }else{
            return true;
        }
}

bool SqliteHandler::findAndCreateDbConnection()
{
    if(db_name.isEmpty()){
        return false;
    }else{
        if(!QFile::exists(db_name)){
            db_con = QSqlDatabase::addDatabase(DRIVER,con_name);
            db_con.setDatabaseName(db_name);
            db_con.open();
        }else{
            db_con = QSqlDatabase::addDatabase(DRIVER,con_name);
            db_con.setDatabaseName(db_name);
            db_con.open();
        }
        return true;
    }
}

bool SqliteHandler::createTable(QString tbl_cmd)
{
    if(tbl_cmd.isEmpty()){
        return false;
    }else{
        if(!execCommand(tbl_cmd)){
           return false;
        }
        return true;
    }
}

QSqlQuery SqliteHandler::selectCommand(QString sql_cmd)
{
    QSqlQuery _query(QSqlDatabase::database(con_name));
    if(!_query.exec(sql_cmd)){
        QMessageBox::critical(nullptr, QObject::tr("Critical Error"),
                         _query.lastError().text(), QMessageBox::Cancel);
    }
    return _query;
}

bool SqliteHandler::execCommand(QString sql_cmd)
{
    if(sql_cmd.isEmpty()){
        return false;
    }
    QSqlQuery _query(QSqlDatabase::database(con_name));
    if(!_query.exec(sql_cmd)){
        _error = _query.lastError();
        return false;
    }
    return true;
}



