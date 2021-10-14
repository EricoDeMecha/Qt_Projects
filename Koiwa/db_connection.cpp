#include "db_connection.h"

db_connection::db_connection()
{

}

void  db_connection::connect_db()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3308);
    db.setUserName("<username>");// add your username for your database
    db.setPassword("<password>");//add your password 

    if(db.open())
    {
        qDebug() << "Successfully connected to the database ";
    }
    else
    {
         qDebug() << "Error! Connection to the database failed: db_error: "<< db.lastError().text();
    }
}

void db_connection::execute_query(QString  squery)
{
    QString command_dbname = "USE school";// change <school> to your database name
    QSqlQuery _query(command_dbname);
    if(_query.exec())
    {
        QSqlQuery query(squery);
        if(query.exec())
        {
            qDebug() << "Data succesfully added to the database";
        }
        else
        {
            qDebug() << "Error! Inserting Data to the Table";
        }
    }
     else
    {
        qDebug() << "Error ! Command :"+ command_dbname + "  could not be executed";
    }
}
