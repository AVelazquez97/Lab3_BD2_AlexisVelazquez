#include <mysql_driver.h> 
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <iostream>
#include <string.h>
using namespace sql;
using namespace std;

class MySQLConnector {
    private:
        mysql::MySQL_Driver *driver;
        Connection *connection;

    public:
        MySQLConnector(const string& host, const string& user, const string& password, const string& database) {
            driver = mysql::get_mysql_driver_instance();
            connection = driver->connect(host, user, password);
            connection->setSchema(database);
        }

        ~MySQLConnector() {
            delete connection;
        }

        // Implementa aquí tus métodos para interactuar con la base de datos

};

// int main() {
//     std::string host = "tcp://localhost:3306";
//     std::string user = "tecnologo";
//     std::string password = "tecnologo";
//     std::string database = "biblioteca";

//     MySQLConnector connector(host, user, password, database);

//     // Aquí puedes utilizar la instancia de `connector` para realizar operaciones en la base de datos

//     return 0;
// }
