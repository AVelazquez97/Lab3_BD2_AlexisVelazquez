#ifndef PERSISTENCY_MYSQLCONNECTOR_H_
#define PERSISTENCY_MYSQLCONNECTOR_H_

#include <iostream>
using namespace std;

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define REDB "\e[41m"

#include <mysql_driver.h> 
#include <mysql_connection.h>


class MySQLConnector {
    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *connection;
        string host = "tcp://localhost:3306";
        string user = "tecnologo";
        string password = "tecnologo";
        string database = "biblioteca";

    public:
        MySQLConnector();

        sql::Connection* getConnection();
        
        ~MySQLConnector();
};

#endif // PERSISTENCY_MYSQLCONNECTOR_H_