#include "BookController.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define REDB "\e[41m"

BookController *BookController::instance = nullptr;

BookController::BookController() {

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

void BookController::insertABook() {
    cout << endl << endl << RED "Sección de ingreso de un nuevo libro." NC << endl << endl;
}

void BookController::deleteABook() {
    cout << endl << endl << RED "Borrar libro." NC << endl << endl;
}

void BookController::updateABook() {
    cout << endl << endl << RED "Actualizar libro." NC << endl << endl; 
}

DTBook BookController::viewABook() {
	cout << endl << endl << RED "Ver libro." NC << endl << endl;
}

DTBook** BookController::viewAllBooks() {
	cout << endl << endl << RED "Ver libros." NC << endl << endl;
}
	