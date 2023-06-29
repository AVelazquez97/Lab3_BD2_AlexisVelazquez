#include "DTBook.h"

using namespace std;

DTBook::~DTBook() {

}

DTBook::DTBook(){

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

void DTBook::setIsbn(string isbn) {
	this->isbn = isbn;
}

void DTBook::setTitle(string title){
	this->title = title;
}

void DTBook::setEdition(string edition) {
	this->edition = edition;
}

void DTBook::setAuthor(string author) {
	this->author = author;
}

void DTBook::setQtyPages(int qtyPages) {
	this->qtyPages = qtyPages;
}

/* sobrecarga del '<<' para poder imprimir todos los datos del DTBook */
ostream& operator<< (ostream& salida, DTBook book) {
	string qtyPages = (book.getQtyPages() != 0 ? to_string(book.getQtyPages()) : " ");
	
	salida << GREEN "| " NC << setw(13) << book.getIsbn() << GREEN " | " NC << setw(36) << book.getTitle() << GREEN " | " NC
		<< setw(26) << book.getEdition() << GREEN " | " NC << setw(42) << book.getAuthor() << GREEN " | " NC
		<< setw(15) << qtyPages << GREEN " |" NC << endl;

	return salida;
}

//  El poder de la mente subconsciente 