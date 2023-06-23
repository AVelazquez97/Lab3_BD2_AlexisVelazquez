#include <iostream>
#include "MySQLConnector.h"

using namespace std;

MySQLConnector::MySQLConnector() {
    try {
        // Se intenta crear una instancia del controlador de MySQL
        this->driver = sql::mysql::get_mysql_driver_instance();

        // Se intenta establecer la conexión a la base de datos
        this->connection = driver->connect(this->host, this->user, this->password);
        this->connection->setSchema(this->database);
    } catch (sql::SQLException& e) {
        cout << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl;
    }
}

sql::Connection* MySQLConnector::getConnection() {
    return this->connection;
}

MySQLConnector::~MySQLConnector() {
    delete this->connection;
}
 
 
