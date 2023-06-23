#ifndef BOOKCONTROLLER_H_
#define BOOKCONTROLLER_H_

#include "../iController/IController.h"
#include "../models/Book.h"
#include "../persistency/BookDAL.h"

class BookController: public IController {
	private:
        BookController();
        static BookController* instance;
		BookDAL* bookDAL;

	public:
        ~BookController();
        static BookController* getInstance();
		bool findBookByISBN(); //Operación auxiliar
        void insertABook(); 
        void deleteBookByISBN();
        void updateBookByISBN();
        DTBook getBookByISBN();
        DTBook** viewAllBooks();
};
    
#endif // BOOKCONTROLLER_H_
