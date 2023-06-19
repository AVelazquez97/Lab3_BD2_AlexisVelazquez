#ifndef BOOKCONTROLLER_H_
#define BOOKCONTROLLER_H_

#include "../iController/IController.h"
#include "../models/Book.h"
#include <string.h>

class BookController: public IController {
	private:
        BookController();
        static BookController* instance;

	public:
        ~BookController();
        static BookController* getInstance();
		void insertABook(); 
        void deleteABook();
        void updateABook();
        DTBook viewABook();
	    DTBook** viewAllBooks();
};
    
#endif // BOOKCONTROLLER_H_
