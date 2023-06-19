using namespace std;
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define REDB "\e[41m"

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

void Menu::toContinue(){
	cout << CYAN "Presiona ENTER para continuar..." NC;
	getchar();
	getchar();
}

void Menu::exit() {
	cout << endl << endl<< CYAN "Has terminado la ejecución del CRUD. Hasta luego." NC << endl << endl;
}

void Menu::insertBook() {
	controller->insertABook();
}

void Menu::deleteBook() {
	controller->deleteABook();
}

void Menu::updateBook() {
	controller->updateABook();
}

void Menu::viewBook() {
	controller->viewABook();
}

void Menu::viewBooks() {
	controller->viewAllBooks();
}