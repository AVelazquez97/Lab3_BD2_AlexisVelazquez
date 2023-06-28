#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <string.h>

#include "../datatypes/DTBook.h"
using namespace std;


class Book {
	private:
		string isbn;
		string title;
		string edition;
		string author;
		int qtyPages;
	public:
        ~Book();
		Book();
		Book(DTBook newBook);
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

};

#endif // BOOK_H_