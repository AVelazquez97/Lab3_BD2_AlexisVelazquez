#include "DTBook.h"

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

/* sobrecarga del '<<' para poder imprimir todos los datos del DTBook */
ostream& operator<< (ostream& salida, DTBook book) {
	string qtyPages = (book.getQtyPages() != 0 ? to_string(book.getQtyPages()) : " ");
	salida << "ISBN: " << book.getIsbn() << endl << 
		"Título: " << book.getTitle() << endl << 
		"Edición: " << book.getEdition() << endl << 
		"Autor: " << book.getAuthor() << endl <<
		"Cantidad de páginas: " << qtyPages << endl ;
	return salida;
}