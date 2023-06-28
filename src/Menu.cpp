#include "Menu.h"

using namespace std;

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

/// @brief se modulariza las entradas de int del usuario. Se realiza una verificación de que sea int el dato ingresado
/// @param prompt es el mensaje que se desea imprimir para el usuario 
/// @return retorna el int ingresado por el usuario
int Menu::getIntegerInput(const string& prompt) {
    string input;
    int number;

    while (true) {
        cout << endl << prompt;
        getline(cin, input);

        try {
            number = stoi(input);
            break; // Salir del bucle si la conversión fue exitosa
        } catch (const exception& e) {
            cout << endl << REDB "Error: No has ingresado un número entero." NC << endl;
        }
    }

    return number;
}

/// @brief se modulariza las entradas de string del usuario
/// @param prompt es el mensaje que se desea imprimir para el usuario 
/// @return retorna la cadena de caracteres ingresada por el usuario
string Menu::getStringInput(const string& prompt) {
    string input;
    cout << endl << prompt;
    getline(cin, input);
    return input;
}

/// @brief lo mismo que para la entrada de string pero en esta se valida que el string ingresado no sea vacío
/// @param prompt es el mensaje que se desea imprimir para el usuario 
/// @return retorna una cadena ingresada por el usuario no vacía
string Menu::getNonEmptyInput(const string& prompt, const string& errorMessage) {
    string input;
    do {
        input = getStringInput(prompt);
        if (input.empty()) {
			cout << endl << REDB << errorMessage <<  NC << endl;
        }
    } while (input.empty());
    return input;
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

	Menu::viewMainMenu();
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
	cout << endl <<  CYAN "Presiona ENTER para continuar..." NC;
	getchar();
}

void Menu::exit() {
	cout << endl << endl<< CYAN "Has terminado la ejecución del CRUD. Hasta luego." NC << endl << endl;
}

void Menu::insertBook() {
	bool existBook = true, exit = false, bookCreated = true, isbnEmpty = true;
	string isbn, newTitle, newEdition, newAuthor, response;
	int newPagesQty;

	/* El único propósito de este getchar omitir lo que sea que traiga el buffer asi se evita que se 
	 den posibles omisiones de ingresos */
	getchar();
	
	cout << CYAN "╔════════════════╗" << endl;
	cout << "║ Insertar libro ║" << endl;
	cout << "╚════════════════╝" NC << endl << endl;

	cout << CYAN "NOTA: Los campos con asterisco (*) son obligatorios." NC << endl << endl;

	while (!exit && existBook) {
		isbn = Menu::getNonEmptyInput("Ingrese el ISBN del libro (*): ", "El campo ISBN no puede quedar vacío");
		existBook = controller->findBookByISBN(isbn);

		if (existBook) {
			cout << "Ya existe un libro registrado con ese ISBN." << endl;
			response = Menu::getStringInput("¿Deseas salir o ingresar otro ISBN? (s para salir): ");
			exit = (response == "s" || response == "S");
		}
    }
	if(exit){ return; } // Se termina la ejecución si el usuario desea no ingresar otro ISBN.

	newTitle = Menu::getStringInput("Ingrese el título del libro: ");
	newEdition = Menu::getStringInput("Ingrese la edición del libro: ");
	newAuthor = Menu::getStringInput("Ingrese el autor del libro: ");

	/* Se asegura que el usuario ingrese un número entero */
	newPagesQty = Menu::getIntegerInput("Ingrese cantidad de páginas del libro. (0 para omitir): ");

	DTBook newBook(isbn, newTitle, newEdition, newAuthor, newPagesQty);
	bookCreated = controller->createBook(newBook);
	if(bookCreated){ cout << endl << GREEN "El libro fue añadido correctamente!" NC << endl; }
}

void Menu::deleteBook() {
	bool existBook = false, exit = false,bookDeleted = true, isbnEmpty = true;
	string isbn, response;

	getchar();

	cout << CYAN "╔══════════════╗" << endl;
	cout << "║ Borrar libro ║" << endl;
	cout << "╚══════════════╝" NC << endl << endl;

	// Se pide un ISBN para chequear si existe el libro en la BD
	while (!exit && !existBook) {
		isbn = Menu::getNonEmptyInput("Ingrese el ISBN del libro a eliminar: ", "El campo ISBN no puede quedar vacío");
		existBook = controller->findBookByISBN(isbn);

		if (!existBook) {
			cout << "No existe un libro con el ISBN que has ingresado." << endl;
			response = Menu::getStringInput("¿Deseas salir o ingresar otro ISBN? (s para salir): ");
			exit = (response == "s" || response == "S");
		}
    }
	if(exit){ return; } // Se termina la ejecución si el usuario desea no ingresar otro ISBN.

	// Como existe el libro que se desea eliminar, se debe mostrar sus datos
	// controller->getBookByISBN(isbn);
	
	//3. Si confirma el usuario se borra el libro
	// 	char confirm;
	// 	cout << "¿Está seguro que desea eliminar este libro? (S/N): ";
	// 	cin >> confirm;

	// 	if (confirm == 'S' || confirm == 's') {

	// 		cout << "El libro ha sido eliminado correctamente." << endl;
	// 	} else {
	// 		cout << "La eliminación del libro ha sido cancelada." << endl;
	// 	}
	// } else {
	// 	cout << "No se encontró un libro con el ID especificado." << endl;
	// }

	bookDeleted = controller->deleteBookByISBN(isbn);
	if(bookDeleted){ cout << endl << GREEN "El libro fue eliminado correctamente!" NC << endl; }
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
	vector<DTBook*> bookList;
	cout << CYAN "╔═══════════════════╗" << endl;
	cout << "║ Listado de libros ║" << endl;
	cout << "╚═══════════════════╝" NC << endl << endl;
	bookList = controller->getAllBooks();
	getchar();
}

