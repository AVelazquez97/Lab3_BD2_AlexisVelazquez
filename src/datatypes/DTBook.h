#ifndef DATATYPES_DTBOOK_H_
#define DATATYPES_DTBOOK_H_

#include <iostream>
#include <string>
#include <iomanip>

#define NC "\e[0m"
#define GREEN "\e[0;32m"
using namespace std;

class DTBook {
	private:
		string isbn;
		string title;
		string edition;
		string author;
		int qtyPages;
	public:
        ~DTBook();
		DTBook();
		DTBook(string Isbn, string Title, string Edition, string Author, int QtyPages);
		string getIsbn();
		string getTitle();
		string getEdition();
		string getAuthor();
		int getQtyPages();
		void setIsbn(string isbn);
		void setTitle(string title);
		void setEdition(string edition);
		void setAuthor(string author);
		void setQtyPages(int qtyPages);

		friend ostream& operator << (ostream& salida, DTBook book);
};

#endif // DATATYPES_DTBOOK_H_