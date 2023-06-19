#ifndef PERSISTENCY_DAL_H_
#define PERSISTENCY_DAL_H_

using namespace std;
#include <iostream>
#include <string.h>
#include "MySQLConnector.h"

// Data Access Layer
class DAL {
	private:
		MySQLConnector connector;

	public:
		DAL(const string& host, const string& user, const string& password, const string& database);
};

#endif // PERSISTENCY_DAL_H_