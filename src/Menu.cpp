using namespace std;
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>

#include "Menu.h"
#include "datatypes/DTBook.h"
#include "iController/IController.h"
#include "factory/Factory.h"

	Factory fact;
	IController* controller = fact.getInterface();

void Menu::viewMainMenu() {
	system("clear");
	cout << GREEN "╔════════════════╗" << endl;
	cout << "║ Menú principal ║" << endl;
	cout << "╚════════════════╝" << endl;
	cout << "  1. Ingreso" << endl;
	cout << "  2. Elimino" << endl;
	cout << "  3. Modifico" << endl;
	cout << "  4. Consulto" << endl;
	cout << "  5. Listo" << endl;
	cout << "  6. Fin" NC << endl;
}

int Menu::selectOption() {
	/* 
	* Para evitar que el menu entre en bucle cuando el usuario ingrese
	* una cadena de texto donde deberia ir un int se toman las siguientes medidas.

	* Se crea una 'startString' que contiene como base un texto que al ser
	* convertido con stoi() da como resultado el valor entero 0.

	* La explicacion viene de que cuando se agregue la entrada del usuario,
	* si el mismo ingresase solo texto, la funcion stoi() devolveria un
	* error, con esto implementado si el usuario ingresa un valor no valido
	* se leera siempre el 0 como opcion default
	*/
	string startString = "0";
	string addedString = "";

	viewMainMenu();
	do {
		cout << GREEN "Ingresa una opción(1..6): " NC;
		cin >> addedString;

		if (stoi(startString + addedString) < 1 || stoi(startString + addedString) > 6) {
			cout << endl << REDB "La opción que has ingresado no es válida. Inténtalo otra vez." NC << endl << endl;
		}
	}

	while(stoi(startString + addedString) < 1 || stoi(startString + addedString) > 6);

	system("clear");
	return stoi(startString + addedString);
}

void Menu::toContinue() {
	cout << CYAN "Presiona ENTER para continuar..." NC;
	getchar();
}

int getIntegerInput(const string& prompt) {
    string input;
    int number;

    while (true) {
        cout << prompt;
        getline(cin, input);

        try {
            number = stoi(input);
            break; // Salir del bucle si la conversión fue exitosa
        } catch (const exception& e) {
            cout << "Error: Ingrese un número entero válido." << std::endl;
        }
    }

    return number;
}

void Menu::exit() {
	cout << endl << endl<< CYAN "Has terminado la ejecución del CRUD. Hasta luego." NC << endl << endl;
}

void Menu::insertBook() {
	bool existBook = true;
	bool exit = false;
	string respuesta = "";
	string isbn, newTitle, newEdition, newAuthor;
	int newPagesQty;

	/* El único propósito de esta variable es guardar en ella lo que sea que traiga el buffer 
	 asi se evita que se den posibles omisiones de ingresos */
	string clearBuffer; 
	getline(cin, clearBuffer);
	
	cout << CYAN "╔════════════════╗" << endl;
	cout << "║ Insertar libro ║" << endl;
	cout << "╚════════════════╝" NC << endl << endl;

	while(existBook && !exit){
		cout << "Ingrese el ISBN del libro: " << endl;
		getline(cin.ignore(), isbn);
		existBook = controller->findBookByISBN(isbn);
		if(existBook){
			cout << endl << REDB "Ya existe un libro registrado con ese ISBN." NC << endl;
			cout << "¿Deseas salir o ingresar otro ISBN? " << endl;
			getline(cin.ignore(), respuesta);
			exit = (respuesta == "Si") ? true : false;
		}
	}

	cout << "Ingrese el título del libro: " << endl;
	getline(cin.ignore(), newTitle);

	cout << "Ingrese la edición del libro: " << endl;
	getline(cin.ignore(), newEdition);

	cout << "Ingrese el autor del libro: " << endl;
	getline(cin.ignore(), newAuthor);

	string mensaje = "Ingrese cantidad de páginas del libro: ";
	newPagesQty = getIntegerInput(string); //validar que sea int

	DTBook newBook(isbn, newTitle, newEdition, newAuthor, newPagesQty);
	controller->createBook(newBook);

	cout << "El Libro fue añadido correctamente!" << endl;
	getchar();
}

void Menu::deleteBook() {
	string isbn = "";
	cout << CYAN "╔══════════════╗" << endl;
	cout << "║ Borrar libro ║" << endl;
	cout << "╚══════════════╝" NC << endl << endl;
	controller->deleteBookByISBN(isbn);
	getchar();
}

void Menu::updateBook() {
	string isbn = "";
	cout << CYAN "╔══════════════════╗" << endl;
	cout << "║ Actualizar libro ║" << endl;
	cout << "╚══════════════════╝" NC << endl << endl;
	controller->updateBookByISBN(isbn);
	getchar();
}

void Menu::viewBook() {
	string isbn = "";
	cout << CYAN "╔═══════════╗" << endl;
	cout << "║ Ver libro ║" << endl;
	cout << "╚═══════════╝" NC << endl << endl;
	controller->getBookByISBN(isbn);
	getchar();
}

void Menu::viewBooks() {
	cout << CYAN "╔═══════════════════╗" << endl;
	cout << "║ Listado de libros ║" << endl;
	cout << "╚═══════════════════╝" NC << endl << endl;
	controller->getAllBooks();
	getchar();
}

