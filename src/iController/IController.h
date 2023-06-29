#ifndef ICONTROLLER_H_
#define ICONTROLLER_H_

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

#include "../datatypes/DTBook.h"

/// @brief interfaz en la que se ofrecen todas las operaciones que realiza el controlador.
/// Todas las operaciones ofrecidas deben ser virtuales y estar igualadas a 0
class IController {
    private: 

    public:
        virtual ~IController();

        /* Operaciones auxiliares */
        virtual bool findBookByISBN(string isbn) = 0; 
        
        /* Operaciones solicitadas */
        virtual bool createBook(DTBook newBook) = 0;
        virtual bool deleteBookByISBN(string isbn) = 0;
        virtual bool updateBookByISBN(DTBook modifiedBook) = 0;
        virtual DTBook getBookByISBN(string isbn) = 0;
	    virtual vector<DTBook> getAllBooks(string order) = 0;
};

#endif // ICONTROLLER_H_
