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

bool BookDAL::updateBookByISBN(Book* book) {
    if (this->isConnectedToDB()) {
        try {
            string qry = "UPDATE " + this->table + " SET titulo = ?, edicion = ?, autor = ?, cantPaginas = ? WHERE isbn = ?";
            this->preparedStatement = this->connection->prepareStatement(qry);

            this->preparedStatement->setString(1, book->getTitle());
            this->preparedStatement->setString(2, book->getEdition());
            this->preparedStatement->setString(3, book->getAuthor());
            this->preparedStatement->setInt(4, book->getQtyPages());
            this->preparedStatement->setString(5, book->getIsbn());

            this->preparedStatement->executeUpdate();
            delete this->preparedStatement;
        } catch (sql::SQLException& e) {
            cout << endl << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
            return false;
        }

        return true;
    }
}

/// @return retorna un puntero unico, el cual es autogestionable y libera automaticamente la memoria utilizada
unique_ptr<Book> BookDAL::getBookByISBN(string isbn) {
    unique_ptr<Book> book;
    if (this->isConnectedToDB()) {
        try {
            string getQry = "SELECT * FROM " + this->table + " WHERE isbn = ?";
            this->preparedStatement = this->connection->prepareStatement(getQry);
            this->preparedStatement->setString(1, isbn);
            this->result = preparedStatement->executeQuery();

            if (this->result->next()) {
                unique_ptr<Book> bookObj = make_unique<Book>();
                bookObj->setIsbn(this->result->getString("isbn"));
                bookObj->setTitle(this->result->getString("titulo"));
                bookObj->setEdition(this->result->getString("edicion"));
                bookObj->setAuthor(this->result->getString("autor"));
                bookObj->setQtyPages(this->result->getInt("cantPaginas")); 
                book = move(bookObj);
            }

            delete this->result;
            delete this->preparedStatement;
        } catch (sql::SQLException &e) {
            cout << endl << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
        }
    }
    return book;
}

/// @return retorna un vetor de punteros unicos, el cual es autogestionable y libera automaticamente la memoria utilizada
vector<unique_ptr<Book>> BookDAL::getAllBooks(string order) {
    vector<unique_ptr<Book>> books;
    if (this->isConnectedToDB()) {
        try {
            string getQry = "SELECT * FROM " + this->table + " ORDER BY isbn " + order;
            // Se intenta crear una declaración para ejecutar la consulta SELECT
            this->statement = this->connection->createStatement();
            this->result = this->statement->executeQuery(getQry);

            // Itera sobre los resultados y se almacena cada columna
            while (this->result->next()) {
                unique_ptr<Book> book = make_unique<Book>();
                book->setIsbn(this->result->getString("isbn"));
                book->setTitle(this->result->getString("titulo"));
                book->setEdition(this->result->getString("edicion"));
                book->setAuthor(this->result->getString("autor"));
                book->setQtyPages(this->result->getInt("cantPaginas"));
                books.push_back(move(book));
            }

            delete this->result;
            delete this->statement;
        } catch (sql::SQLException& e) {
            cout << endl << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
        }
    }
    return books;
}