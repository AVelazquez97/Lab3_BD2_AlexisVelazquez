#ifndef PERSISTENCY_BOOKDAL_H_
#define PERSISTENCY_BOOKDAL_H_

#include <iostream>
using namespace std;
#include "MySQLConnector.h"

#include <cppconn/resultset.h>
#include <cppconn/statement.h>

// Data Access Layer
// En esta capa se realizan las consultas a la BD
class BookDAL {
	private:
		MySQLConnector* dbConnector;
		sql::Connection* connection;
    	sql::Statement* statement;
    	sql::ResultSet* result;

	public:
		BookDAL();
		bool findBookByISBN();
		void insertABook();
		void deleteBookByISBN();
		void updateBookByISBN();
		void getBookByISBN();
		void getAllBooks();
};

#endif // PERSISTENCY_BOOKDAL_H_