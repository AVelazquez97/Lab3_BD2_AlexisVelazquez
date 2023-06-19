using namespace std;
#include <iostream>
#include <string.h>
#include "DAL.h"

DAL::DAL(
  const string& host,
  const string& user,
  const string& password,
  const string& database
): connector(host, user, password, database){
}