#ifndef PERSISTENCY_BOOKDAL_H_
#define PERSISTENCY_BOOKDAL_H_

#include <iostream>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "MySQLConnector.h"

using namespace std;

/// @brief Data Access Layer. En esta capa se abstraen y realizan la interacción con la base de datos.
class BookDAL {
	private:
		MySQLConnector* dbConnector;
		sql::Connection* connection;
    	sql::Statement* statement;
    	sql::ResultSet* result;
		string table = "libro";

	public:
		BookDAL();
		~BookDAL();
		bool isConnectedToDB();
		bool findBookByISBN(string isbn);
		void insertABook();
		void deleteBookByISBN(string isbn);
		void updateBookByISBN(string isbn);
		void getBookByISBN(string isbn);
		void getAllBooks();
};

#endif // PERSISTENCY_BOOKDAL_H_