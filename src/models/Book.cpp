#include "Book.h"
using namespace std;

Book::~Book() {

}

Book::Book(){

}

Book::Book(DTBook newBook) {
	this->isbn = newBook.getIsbn();
	this->title = newBook.getTitle();
	this->edition = newBook.getEdition();
	this->author = newBook.getAuthor();
	this->qtyPages = newBook.getQtyPages(); 
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

void Book::setIsbn(string isbn) {
	this->isbn = isbn;
}

void Book::setTitle(string title){
	this->title = title;
}

void Book::setEdition(string edition) {
	this->edition = edition;
}

void Book::setAuthor(string author) {
	this->author = author;
}

void Book::setQtyPages(int qtyPages) {
	this->qtyPages = qtyPages;
}