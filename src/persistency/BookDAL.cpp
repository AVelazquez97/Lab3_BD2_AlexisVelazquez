#include "BookDAL.h"
using namespace std;

BookDAL::BookDAL() {
    this->dbConnector = new MySQLConnector();
    this->connection = this->dbConnector->getConnection();
}

BookDAL::~BookDAL() {
    /* Se liberan los recursos utilizados por la clase */
    delete this->result;          // Liberar el objeto ResultSet
    delete this->statement;       // Liberar el objeto Statement
    delete this->connection;      // Liberar el objeto Connection
    delete this->dbConnector;     // Liberar el objeto MySQLConnector
}

bool BookDAL::isConnectedToDB() {
    if(!this->connection){
        return false;
    }
    return true;
}

// Ningún metodo es en realidad void. Luego se debe modificar para que los datos viajen entre capas
bool BookDAL::findBookByISBN(string isbn) {
    if (this->isConnectedToDB()) {
        
    }
}

void BookDAL::insertABook() {
    if (this->isConnectedToDB()) {
        
    }
}

void BookDAL::deleteBookByISBN(string isbn) {
    if (this->isConnectedToDB()) {
        
    }
}

void BookDAL::updateBookByISBN(string isbn) {
    if (this->isConnectedToDB()) {

    }
}

void BookDAL::getBookByISBN(string isbn) {
    if (this->isConnectedToDB()) {
        try {
            string query = "SELECT * FROM "  + this->table + " WHERE isbn = " + isbn;
            // Se intenta crear una declaración para ejecutar la consulta SELECT
            this->statement = this->connection->createStatement();
            this->result = this->statement->executeQuery(query);

            // Itera sobre los resultados y muestra los registros
            while (this->result->next()) {
                cout << "ISBN: " << this->result->getString("isbn") << endl;
                cout << "Título: " << this->result->getString("titulo") << endl;
                cout << "Autor: " << this->result->getString("edicion") << endl;
                cout << "Autor: " << this->result->getString("autor") << endl;
                cout << "Total de Páginas: " << this->result->getInt("cantPaginas") << endl << endl;
            }
        } catch (sql::SQLException &e) {
            cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << endl << endl;
        }
    }
}

void BookDAL::getAllBooks() {
    if (this->isConnectedToDB()){
        try {
            string query = "SELECT * FROM " + this->table;
            // Se intenta crear una declaración para ejecutar la consulta SELECT
            this->statement = this->connection->createStatement();
            this->result = this->statement->executeQuery(query);

            // Itera sobre los resultados y muestra los registros
            while (this->result->next()) {
                cout << "ISBN: " << this->result->getString("isbn") << endl;
                cout << "Título: " << this->result->getString("titulo") << endl;
                cout << "Autor: " << this->result->getString("edicion") << endl;
                cout << "Autor: " << this->result->getString("autor") << endl;
                cout << "Total de Páginas: " << this->result->getInt("cantPaginas") << endl;
                cout << GREEN "---------------------------------------------------------" NC << endl << endl;
            }
        } catch (sql::SQLException &e) {
            cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << endl << endl;
        }
    }
}