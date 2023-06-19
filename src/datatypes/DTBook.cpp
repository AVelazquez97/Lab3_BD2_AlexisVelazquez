#include "DTBook.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

DTBook::~DTBook() {

}

DTBook::DTBook(string Isbn, string Title, string Edition, string Author, int QtyPages) {
	this->isbn = Isbn;
	this->title = Title;
	this->edition = Edition;
	this->author = Author;
	this->qtyPages = QtyPages; 
}

string DTBook::getIsbn() {
	return this->isbn;
}

string DTBook::getTitle(){
	return this->title;
}

string DTBook::getEdition() {
	return this->edition;
}

string DTBook::getAuthor() {
	return this->author;
}

int DTBook::getQtyPages() {
	return this->qtyPages;
}