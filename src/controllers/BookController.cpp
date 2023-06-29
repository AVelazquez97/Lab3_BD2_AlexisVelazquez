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
    bool existBook = true;
    this->bookDAL = new BookDAL();
    existBook = this->bookDAL->findBookByISBN(isbn);
    delete this->bookDAL;
    return existBook;
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

bool BookController::updateBookByISBN(DTBook modifiedBook) {
    bool result;
    Book* bookObj = new Book(modifiedBook);
    this->bookDAL = new BookDAL();
    
    result = this->bookDAL->updateBookByISBN(bookObj); 

    delete this->bookDAL;
    delete bookObj;
    return result;
}

DTBook BookController::getBookByISBN(string isbn) {
    this->bookDAL = new BookDAL();
    unique_ptr<Book> bookPtr = this->bookDAL->getBookByISBN(isbn);
    
    if(!bookPtr){ throw invalid_argument("¡No se encontró ningun libro con el ISBN recibido.!"); };

    DTBook book (
        bookPtr->getIsbn(),
        bookPtr->getTitle(),
        bookPtr->getEdition(),
        bookPtr->getAuthor(),
        bookPtr->getQtyPages()
    );

    delete this->bookDAL;
    return book;
}

vector <DTBook> BookController::getAllBooks(string order) {
    this->bookDAL = new BookDAL();
    vector<unique_ptr<Book>> books = this->bookDAL->getAllBooks(order);
    vector<DTBook> booklist;

    if(books.empty()){ throw invalid_argument("Aún no hay libros en la base de datos."); };
    
    for (const auto& bookPtr : books) {
        DTBook book (
            bookPtr->getIsbn(),
            bookPtr->getTitle(),
            bookPtr->getEdition(),
            bookPtr->getAuthor(),
            bookPtr->getQtyPages()
        );
        booklist.push_back(book);
    }
    delete this->bookDAL;
    return booklist;
}
	