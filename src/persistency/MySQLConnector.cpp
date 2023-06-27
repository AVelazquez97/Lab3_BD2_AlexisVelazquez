#include "MySQLConnector.h"

using namespace std;

MySQLConnector::MySQLConnector(): driver(nullptr), connection(nullptr) {
    try {
        this->host = "tcp://localhost:3306";
        this->user = "tecnologo";
        this->password = "tecnologo";
        this->database = "biblioteca";

        // Se intenta crear una instancia del controlador de MySQL
        this->driver = sql::mysql::get_mysql_driver_instance();

        // Se intenta establecer la conexión a la base de datos
        this->connection = driver->connect(this->host, this->user, this->password);
        this->connection->setSchema(this->database);
    } catch (sql::SQLException& e) {
        cout << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
        delete this->connection;
        this->connection = nullptr;
        this->driver = nullptr;
    }
}

sql::Connection* MySQLConnector::getConnection() {
    return this->connection;
}

MySQLConnector::~MySQLConnector() {
    delete this->connection;
}
 
 
