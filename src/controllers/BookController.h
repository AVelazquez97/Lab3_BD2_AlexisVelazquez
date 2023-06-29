#ifndef BOOKCONTROLLER_H_
#define BOOKCONTROLLER_H_

#include "../iController/IController.h"
#include "../persistency/BookDAL.h"
#include "../models/Book.h"

/// @brief el controlador realiza todas las operaciones del sistema.
/// es en esta capa donde se desarrolla la lógica del programa, por 
/// Como utiliza el patrón singleton, aunque se intente instanciar n veces, siempre va a devolver una única instancia 
class BookController: public IController {
	private:
        BookController();
        static BookController* instance;
		BookDAL* bookDAL;

	public:
        ~BookController();
        static BookController* getInstance();

        /* Operaciones auxiliares */
		bool findBookByISBN(string isbn);
        
        /* Operaciones solicitadas */
        bool createBook(DTBook newBook); 
        bool deleteBookByISBN(string isbn);
        bool updateBookByISBN(DTBook modifiedBook);
        DTBook getBookByISBN(string isbn);
        vector <DTBook> getAllBooks(string order);
};
    
#endif // BOOKCONTROLLER_H_
