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
bool BookController::findBookByISBN() {
    this->bookDAL = new BookDAL();
    string isbn = "";
    this->bookDAL->findBookByISBN(isbn);
}

/* Métodos solicitados */
void BookController::insertABook() {
    this->bookDAL = new BookDAL();
    this->bookDAL->insertABook();
}

void BookController::deleteBookByISBN() {
    this->bookDAL = new BookDAL();
    string isbn = "";
    this->bookDAL->deleteBookByISBN(isbn);
}

void BookController::updateBookByISBN() {
    this->bookDAL = new BookDAL();
    string isbn = "";
    this->bookDAL->updateBookByISBN(isbn); 
}

void BookController::getBookByISBN() {
    this->bookDAL = new BookDAL();
    string isbn = "9781401952010";
	this->bookDAL->getBookByISBN(isbn);
}

void BookController::getAllBooks() {
    this->bookDAL = new BookDAL();
    this->bookDAL->getAllBooks();
}
	