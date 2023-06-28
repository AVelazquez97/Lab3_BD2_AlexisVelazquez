#include "BookDAL.h"
using namespace std;

BookDAL::BookDAL() {
    this->dbConnector = new MySQLConnector();
    this->connection = this->dbConnector->getConnection();
}

BookDAL::~BookDAL() {
    delete this->dbConnector;
}

/* Métodos auxiliares */
bool BookDAL::isConnectedToDB() {
    if(!this->connection){
        return false;
    }
    return true;
}

// Ningún metodo es en realidad void. Luego se debe modificar para que los datos viajen entre capas
bool BookDAL::findBookByISBN(string isbn) {
    bool exists = false;
    if (this->isConnectedToDB()) {
        try {
            this->preparedStatement = this->connection->prepareStatement("SELECT * FROM libro WHERE isbn = ?");
            this->preparedStatement->setString(1, isbn);
            this->result = this->preparedStatement->executeQuery();

            exists = this->result->next();

            delete this->result;
            delete this->preparedStatement;

            return exists;
        } catch (sql::SQLException& e) {
            cout << endl << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
        }
    }

    return exists;
}

/* Métodos solicitados */
bool BookDAL::insertABook(Book* book) {
    if (this->isConnectedToDB()) {
        try {
            string qry = "INSERT INTO " + this->table + " (isbn, titulo, edicion, autor, cantPaginas) VALUES (?,?,?,?,?)";
            this->preparedStatement = this->connection->prepareStatement(qry);

            this->preparedStatement->setString(1, book->getIsbn());
            this->preparedStatement->setString(2, book->getTitle());
            this->preparedStatement->setString(3, book->getEdition());
            this->preparedStatement->setString(4, book->getAuthor());
            this->preparedStatement->setInt(5, book->getQtyPages());

            this->preparedStatement->executeUpdate();
            delete this->preparedStatement;
        } catch (sql::SQLException& e) {
            cout << endl << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
            return false;
        }

        return true;
    }
}

bool BookDAL::deleteBookByISBN(string isbn) {
    if (this->isConnectedToDB()) {
        try {
            string deleteQry = "DELETE FROM " + this->table + " WHERE isbn = ?";
            this->preparedStatement = this->connection->prepareStatement(deleteQry);
            this->preparedStatement->setString(1, isbn);
            this->preparedStatement->executeUpdate();

            delete this->preparedStatement;
        } catch (sql::SQLException& e) {
            cout << "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << endl;
            return false;
        }
    }
    return true;
}

bool BookDAL::updateBookByISBN(string isbn) {
    if (this->isConnectedToDB()) {

    }
    return true;
}

// optional<Book> BookDAL::getBookByISBN(string isbn) {
Book* BookDAL::getBookByISBN(string isbn) {
    Book* bookObj = nullptr;
    if (this->isConnectedToDB()) {
        try {
            string getQry = "SELECT * FROM " + this->table + " WHERE isbn = ?";
            this->preparedStatement = this->connection->prepareStatement(getQry);
            this->preparedStatement->setString(1, isbn);
            this->result = preparedStatement->executeQuery();

            if (this->result->next()) {
                bookObj = new Book();
                bookObj->setIsbn(this->result->getString("isbn"));
                bookObj->setTitle(this->result->getString("titulo"));
                bookObj->setEdition(this->result->getString("edicion"));
                bookObj->setAuthor(this->result->getString("autor"));
                bookObj->setQtyPages(this->result->getInt("cantPaginas")); 
            }
    
            delete this->result;
            delete this->preparedStatement;
        } catch (sql::SQLException &e) {
            cout << endl << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
        }
    }
    return bookObj;
}

void BookDAL::getAllBooks() {
    if (this->isConnectedToDB()){
        try {
            string qry = "SELECT * FROM " + this->table;
            // Se intenta crear una declaración para ejecutar la consulta SELECT
            this->statement = this->connection->createStatement();
            this->result = this->statement->executeQuery(qry);

            // Itera sobre los resultados y muestra los registros
            while (this->result->next()) {
                cout << "ISBN: " << this->result->getString("isbn") << endl;
                cout << "Título: " << this->result->getString("titulo") << endl;
                cout << "Autor: " << this->result->getString("edicion") << endl;
                cout << "Autor: " << this->result->getString("autor") << endl;
                cout << "Total de Páginas: " << this->result->getInt("cantPaginas") << endl;
                cout << GREEN "---------------------------------------------------------" NC << endl << endl;
            }
            delete this->result;
            delete this->statement;
        } catch (sql::SQLException &e) {
            cout << endl << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
        }
    }
}