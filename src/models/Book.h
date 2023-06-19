#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <string.h>
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
		Book(string Isbn, string Title, string Edition, string Author, int qtyPages);
		string getIsbn();
		string getTitle();
		string getEdition();
		string getAuthor();
		int getQtyPages();
};

#endif // BOOK_H_