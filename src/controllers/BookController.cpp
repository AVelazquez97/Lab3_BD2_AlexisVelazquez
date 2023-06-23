#include <iostream>
#include "BookController.h"
using namespace std;

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define REDB "\e[41m"

BookController *BookController::instance = nullptr;

BookController::BookController() {
    this->bookDAL = new BookDAL();
}

BookController::~BookController() {

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

bool BookController::findBookByISBN() {
    this->bookDAL->findBookByISBN();
}

void BookController::insertABook() {
    this->bookDAL->insertABook();
}

void BookController::deleteBookByISBN() {
    this->bookDAL->deleteBookByISBN();
}

void BookController::updateBookByISBN() {
    this->bookDAL->updateBookByISBN(); 
}

DTBook BookController::getBookByISBN() {
	this->bookDAL->getBookByISBN();
}

DTBook** BookController::viewAllBooks() {
    this->bookDAL->getAllBooks();
}
	