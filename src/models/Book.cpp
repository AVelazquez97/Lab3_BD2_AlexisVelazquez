#include "Book.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Book::~Book() {

}

Book::Book(string Isbn, string Title, string Edition, string Author, int QtyPages) {
	this->isbn = Isbn;
	this->title = Title;
	this->edition = Edition;
	this->author = Author;
	this->qtyPages = QtyPages; 
}

string Book::getIsbn() {
	return this->isbn;
}

string Book::getTitle(){
	return this->title;
}

string Book::getEdition() {
	return this->edition;
}

string Book::getAuthor() {
	return this->author;
}

int Book::getQtyPages() {
	return this->qtyPages;
}

