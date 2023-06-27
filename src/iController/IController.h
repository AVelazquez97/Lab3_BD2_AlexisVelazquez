#ifndef ICONTROLLER_H_
#define ICONTROLLER_H_

#include <ctime>
#include <iostream>

using namespace std;

#include "../datatypes/DTBook.h"

/// @brief interfaz en la que se ofrecen todas las operaciones que realiza el controlador.
/// Todas las operaciones ofrecidas deben ser virtuales y estar igualadas a 0
class IController {
    private: 

    public:
        virtual ~IController();

        /* Operaciones auxiliares */
        virtual bool findBookByISBN() = 0;
        
        /* Operaciones solicitadas */
        virtual void insertABook() = 0;
        virtual void deleteBookByISBN() = 0;
        virtual void updateBookByISBN() = 0;
        virtual void getBookByISBN() = 0;
	    virtual void getAllBooks() = 0;
};

#endif // ICONTROLLER_H_
