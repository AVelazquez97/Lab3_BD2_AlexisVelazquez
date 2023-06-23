#include <iostream>
using namespace std;
#include "BookDAL.h"

BookDAL::BookDAL() {
    this->dbConnector = new MySQLConnector();
    this->connection = this->dbConnector->getConnection();
}

// Ningún metodo es en realidad void. Luego se debe modificar para que los datos viajen entre capas
bool BookDAL::findBookByISBN() {
    cout << endl << endl << RED "BookDAL -> Buscar Libro" NC << endl << endl;
}

void BookDAL::insertABook() {
    cout << endl << endl << RED "BookDAL -> Insertar Libro" NC << endl << endl;
}

void BookDAL::deleteBookByISBN() {
    cout << endl << endl << RED "BookDAL -> Borrar Libro" NC << endl << endl;
}

void BookDAL::updateBookByISBN() {
    cout << endl << endl << RED "BookDAL -> Actualizar Libro" NC << endl << endl;
}

void BookDAL::getBookByISBN() {
	cout << endl << endl << RED "BookDAL -> Obtener Libro" NC << endl << endl;
}

void BookDAL::getAllBooks() {
    try {
        // Se intenta crear una declaración para ejecutar la consulta SELECT
        this->statement = this->connection->createStatement();
        this->result = this->statement->executeQuery("SELECT * FROM libro");

        // Itera sobre los resultados y muestra los registros
        while (this->result->next()) {
			cout << "ISBN: " << this->result->getString("isbn") << endl;
            cout << "Título: " << this->result->getString("titulo") << endl;
            cout << "Autor: " << this->result->getString("edicion") << endl;
            cout << "Autor: " << this->result->getString("autor") << endl;
			cout << "Total de Páginas: " << this->result->getInt("cantPaginas") << endl;
            cout << "-----" << endl;
        }

		/* isbn -> varchar(30) | titulo -> varchar(50) | edicion -> varchar(50) | autor -> varchar(50) | cantPaginas  */
        // Libera los recursos
        delete this->result;
        delete this->statement;
    } catch (sql::SQLException &e) {
        cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << endl;
    }
}