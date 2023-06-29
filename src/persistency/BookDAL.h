#ifndef PERSISTENCY_BOOKDAL_H_
#define PERSISTENCY_BOOKDAL_H_

#include <iostream>
#include <memory>
#include <vector>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "MySQLConnector.h"
#include "../models/Book.h"

using namespace std;

/// @brief Data Access Layer. En esta capa se abstraen y realizan la interacción con la base de datos.
class BookDAL {
	private:
		MySQLConnector* dbConnector;
		sql::Connection* connection;
    	sql::Statement* statement;
		sql::PreparedStatement* preparedStatement;
    	sql::ResultSet* result;
		string table = "libro";

	public:
		BookDAL();
		~BookDAL();
		/* Operaciones auxiliares */
		bool isConnectedToDB();
		bool findBookByISBN(string isbn);

		/* Operaciones solicitadas */
		bool insertABook(Book* book);
		bool deleteBookByISBN(string isbn);
		bool updateBookByISBN(Book* book);
		unique_ptr<Book> getBookByISBN(string isbn);
		vector<unique_ptr<Book>> getAllBooks(string order);
};

#endif // PERSISTENCY_BOOKDAL_H_