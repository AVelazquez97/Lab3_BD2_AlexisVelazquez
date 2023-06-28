#ifndef ICONTROLLER_H_
#define ICONTROLLER_H_

#include <iostream>
#include <vector>
#include <optional>

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
        virtual void addBook(DTBook* book) = 0; 
        virtual void removeBook(DTBook* book) = 0;
        
        /* Operaciones solicitadas */
        virtual bool createBook(DTBook newBook) = 0;
        virtual bool deleteBookByISBN(string isbn) = 0;
        virtual bool updateBookByISBN(string isbn) = 0;
        virtual void getBookByISBN(string isbn) = 0;
	    virtual vector <DTBook*> getAllBooks() = 0;
};

#endif // ICONTROLLER_H_
