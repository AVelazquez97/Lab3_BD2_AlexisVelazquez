#include "BookController.h"
using namespace std;

BookController *BookController::instance = nullptr;

BookController::BookController() {

}

BookController::~BookController() {
    /* Se liberan los recursos utilizados por la clase */
    for (auto book : bookList) {
        delete book;
    }
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
    bool existBook = true;
    this->bookDAL = new BookDAL();
    existBook = this->bookDAL->findBookByISBN(isbn);
    delete this->bookDAL;
    return existBook;
}

void BookController::addBook(DTBook* book) {
    bookList.push_back(book);
}

void BookController::removeBook(DTBook* book) {
    // Buscar y eliminar el libro de la lista
    auto it = find(bookList.begin(), bookList.end(), book);
    if (it != bookList.end()) {
        bookList.erase(it);
    }
}

/* Métodos solicitados */
bool BookController::createBook(DTBook newBook) {
    bool result;
    Book* bookObj = new Book(newBook);
    this->bookDAL = new BookDAL();
    result = this->bookDAL->insertABook(bookObj);
    
    delete this->bookDAL;
    delete bookObj;
    return result;
}

bool BookController::deleteBookByISBN(string isbn) {
    bool result;
    this->bookDAL = new BookDAL();
    this->bookDAL->deleteBookByISBN(isbn);

    delete this->bookDAL;
    return result;
}

bool BookController::updateBookByISBN(string isbn) {
    this->bookDAL = new BookDAL();
    this->bookDAL->updateBookByISBN(isbn); 
    delete this->bookDAL;
}

void BookController::getBookByISBN(string isbn) {
    this->bookDAL = new BookDAL();
    isbn = "9781401952010";
	this->bookDAL->getBookByISBN(isbn);
    delete this->bookDAL;
}

vector <DTBook*> BookController::getAllBooks() {
    this->bookDAL = new BookDAL();
    this->bookDAL->getAllBooks();
    delete this->bookDAL;
    return this->bookList;
}
	