#include "BookController.h"
using namespace std;

BookController *BookController::instance = nullptr;

BookController::BookController() {
}

BookController::~BookController() {
    /* Se liberan los recursos utilizados por la clase */
    delete this->bookDAL;  // Liberar la instancia del BookDAL
}

/// @brief implementación del singleton.
/// Si la clase aún no se ha instanciado, se instancia por primera vez.
/// @return siempre retorna la misma instancia del Bookcontroller 
BookController *BookController::getInstance() {
    if (instance == nullptr) {
        instance = new BookController();
    }
    return instance;
}

/* Métodos auxiliares */
bool BookController::findBookByISBN(string isbn) {
    this->bookDAL = new BookDAL();
    string isbn = "";
    this->bookDAL->findBookByISBN(isbn);
    delete this->bookDAL;
}

/* Métodos solicitados */
void BookController::createBook(DTBook newBook) {
    this->bookDAL = new BookDAL();
    this->bookDAL->insertABook();
    delete this->bookDAL;
}

void BookController::deleteBookByISBN(string isbn) {
    this->bookDAL = new BookDAL();
    string isbn = "";
    this->bookDAL->deleteBookByISBN(isbn);
    delete this->bookDAL;
}

void BookController::updateBookByISBN(string isbn) {
    this->bookDAL = new BookDAL();
    string isbn = "";
    this->bookDAL->updateBookByISBN(isbn); 
    delete this->bookDAL;
}

void BookController::getBookByISBN(string isbn) {
    this->bookDAL = new BookDAL();
    string isbn = "9781401952010";
	this->bookDAL->getBookByISBN(isbn);
    delete this->bookDAL;
}

void BookController::getAllBooks() {
    this->bookDAL = new BookDAL();
    this->bookDAL->getAllBooks();
    delete this->bookDAL;
}
	