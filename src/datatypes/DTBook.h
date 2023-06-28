#ifndef DATATYPES_DTBOOK_H_
#define DATATYPES_DTBOOK_H_

using namespace std;
#include <iostream>
#include <string.h>

class DTBook {
	private:
		string isbn;
		string title;
		string edition;
		string author;
		int qtyPages;
	public:
        ~DTBook();
		DTBook(string Isbn, string Title, string Edition, string Author, int QtyPages);
		string getIsbn();
		string getTitle();
		string getEdition();
		string getAuthor();
		int getQtyPages();
		friend ostream& operator << (ostream& salida, DTBook book);
};

#endif // DATATYPES_DTBOOK_H_