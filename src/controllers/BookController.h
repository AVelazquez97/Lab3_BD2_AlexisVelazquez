#ifndef BOOKCONTROLLER_H_
#define BOOKCONTROLLER_H_

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define REDB "\e[41m"

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
        vector<DTBook*> bookList;

	public:
        ~BookController();
        static BookController* getInstance();

        /* Operaciones auxiliares */
		bool findBookByISBN(string isbn);
        void addBook(DTBook* book); // Agregar un libro a la lista
        void removeBook(DTBook* book); // Eliminar un libro de la lista
        
        /* Operaciones solicitadas */
        bool createBook(DTBook newBook); 
        bool deleteBookByISBN(string isbn);
        bool updateBookByISBN(string isbn);
        void getBookByISBN(string isbn);
        vector <DTBook*> getAllBooks();
};
    
#endif // BOOKCONTROLLER_H_
