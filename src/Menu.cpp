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

void Menu::viewHeaders() {
	cout << endl << GREEN "--------------------------------------------------------------"
		<< "--------------------------------------------------------------------------------------" NC << endl
		<< GREEN "| " NC << setw(13) << "ISBN" << GREEN " | " NC << setw(37) << "Título" << GREEN " | " NC
		<< setw(27) << "Edición" << GREEN " | " NC << setw(42) <<  "Autor" << GREEN " | " NC
		<< setw(16) << "Cant. Páginas" << GREEN " |" NC << endl
		<< GREEN "--------------------------------------------------------------------------"
		<< "--------------------------------------------------------------------------" NC << endl;
}

/// @brief se modulariza las entradas de int del usuario. Se realiza una verificación de que sea int el dato ingresado
/// @param prompt es el mensaje que se desea imprimir para el usuario 
/// @return retorna el int ingresado por el usuario
int Menu::getIntegerInput(const string& prompt) {
    string input;
    int number;

    while (true) {
        cout << GREEN << endl << prompt << NC;
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
    cout << GREEN << endl << prompt << NC;
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

int Menu::selectOptionFromMenu() {
	int option;

	Menu::viewMainMenu();
	do {
		/* Se asegura que el usuario ingrese un número entero */
		option = Menu::getIntegerInput("Ingresa una opción(1..6): ");
		if (option < 1 || option > 6) {
			cout << endl << REDB "La opción que has ingresado no es válida. Inténtalo otra vez." NC << endl << endl;
		}
	} while(option < 1 || option > 6);

	system("clear");
	return option;
}

void Menu::toContinue() {
	cout << endl <<  CYAN "Presiona ENTER para continuar..." NC;
	getchar();
}

void Menu::exit() {
	cout << endl << endl<< CYAN "¡Has terminado la ejecución del CRUD, hasta luego!" NC << endl << endl;
}

void Menu::insertBook() {
	bool existBook = true, exit = false, bookCreated = true, isbnEmpty = true;
	string isbn, newTitle, newEdition, newAuthor, response;
	int newPagesQty;

	/* El único propósito de este getchar omitir lo que sea que traiga el buffer asi se evita que se 
	 den posibles omisiones de ingresos */
	// getchar();
	
	cout << CYAN "╔════════════════╗" << endl;
	cout << "║ Insertar libro ║" << endl;
	cout << "╚════════════════╝" NC << endl << endl;

	cout << CYAN "NOTA: Los campos con asterisco (*) son obligatorios." NC << endl << endl;

	while (!exit && existBook) {
		isbn = Menu::getNonEmptyInput("(*) Ingrese el ISBN del libro: ", "El campo ISBN no puede quedar vacío.");
		existBook = controller->findBookByISBN(isbn);

		if (existBook) {
			cout << endl << REDB "¡Ya existe un libro registrado con ese ISBN!" NC << endl;
			response = Menu::getStringInput("¿Deseas salir o ingresar otro ISBN? (S para salir): ");
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
	if(bookCreated){ cout << endl << GREEN "¡El libro fue añadido correctamente!" NC << endl; }
}

void Menu::deleteBook() {
	bool existBook = false, exit = false, isbnEmpty = true;
	string isbn, response, confirmDelete;

	// getchar();

	cout << CYAN "╔══════════════╗" << endl;
	cout << "║ Borrar libro ║" << endl;
	cout << "╚══════════════╝" NC << endl << endl;

	cout << CYAN "NOTA: Los campos con asterisco (*) son obligatorios." NC << endl << endl;

	//1. Se pide un ISBN para chequear si existe el libro en la BD
	while (!exit && !existBook) {
		isbn = Menu::getNonEmptyInput("(*) Ingrese el ISBN del libro a eliminar: ", "El campo ISBN no puede quedar vacío.");
		existBook = controller->findBookByISBN(isbn);

		if (!existBook) {
			cout << endl << REDB "No existe un libro con el ISBN que has ingresado." NC << endl;
			response = Menu::getStringInput("¿Deseas salir o ingresar otro ISBN? (S para salir): ");
			exit = (response == "s" || response == "S");
		}
    }
	if(exit){ return; } // Se termina la ejecución si el usuario desea no ingresar otro ISBN.

	//2. Como existe el libro que se desea eliminar, se debe mostrar sus datos
	try {
		DTBook obtainedBook = controller->getBookByISBN(isbn);
		cout << endl << obtainedBook << endl;
	} catch(invalid_argument const& e) {
		cout << endl << REDB "Error: " << e.what() << "" NC << endl << endl;
	}
	
	//3. Si confirma el usuario se borra el libro
	confirmDelete = Menu::getNonEmptyInput("¿Estás seguro que deseas eliminar este libro? (S/N): ", "La respuesta no puede ser vacía.");

	if (confirmDelete == "S" || confirmDelete == "s") {
		controller->deleteBookByISBN(isbn);
		cout << endl << GREEN "¡El libro fue eliminado correctamente!" NC << endl;
	} else {
		cout << endl << GREEN "¡La eliminación del libro ha sido cancelada!" NC << endl;
	}
}

void Menu::updateBook() {
	bool existBook = false, exit = false, isbnEmpty = true, bookUpdated = true;
	string isbn, newTitle, newEdition, newAuthor, response, confirmUpdate;
	int newPagesQty;

	// getchar();

	cout << CYAN "╔══════════════════╗" << endl;
	cout << "║ Actualizar libro ║" << endl;
	cout << "╚══════════════════╝" NC << endl << endl;

	cout << CYAN "NOTA: Los campos con asterisco (*) son obligatorios." NC << endl << endl;

	//1. Se pide un ISBN para chequear si existe el libro en la BD
	while (!exit && !existBook) {
		isbn = Menu::getNonEmptyInput("(*) Ingrese el ISBN del libro a modificar: ", "¡El campo ISBN no puede quedar vacío!");
		existBook = controller->findBookByISBN(isbn);

		if (!existBook) {
			cout << endl << REDB "¡No existe un libro con el ISBN que has ingresado!" NC << endl;
			response = Menu::getStringInput("¿Deseas salir o ingresar otro ISBN? (S para salir): ");
			exit = (response == "s" || response == "S");
		}
    }
	if(exit){ return; } // Se termina la ejecución si el usuario desea no ingresar otro ISBN.

	//2. Como existe el libro que se desea eliminar, se debe mostrar sus datos
	try {
		DTBook obtainedBook = controller->getBookByISBN(isbn);
		cout << endl << obtainedBook << endl;
	} catch(invalid_argument const& e) {
		cout << endl << REDB "Error: " << e.what() << "" NC << endl << endl;
	}

	//3. Si confirma el usuario se modifica el libro

	confirmUpdate = Menu::getNonEmptyInput("¿Estás seguro que deseas modificar este libro? (S/N): ", "¡La respuesta no puede ser vacía!");

	if (confirmUpdate == "S" || confirmUpdate == "s") {
		newTitle = Menu::getStringInput("Ingrese el título del libro: ");
		newEdition = Menu::getStringInput("Ingrese la edición del libro: ");
		newAuthor = Menu::getStringInput("Ingrese el autor del libro: ");

		/* Se asegura que el usuario ingrese un número entero */
		newPagesQty = Menu::getIntegerInput("Ingrese cantidad de páginas del libro. (0 para omitir): ");

		DTBook modifiedBook(isbn, newTitle, newEdition, newAuthor, newPagesQty);

		bookUpdated = controller->updateBookByISBN(modifiedBook);
		if(bookUpdated){ cout << endl << GREEN "¡El libro fue modificado correctamente!" NC << endl; }
	} else {
		cout << endl << GREEN "¡La modificación del libro ha sido cancelada!" NC << endl;
	}
}

void Menu::viewBook() {
	string isbn;
	bool isbnEmpty = true;

	// getchar();

	cout << CYAN "╔═══════════╗" << endl;
	cout << "║ Ver libro ║" << endl;
	cout << "╚═══════════╝" NC << endl << endl;
	
	cout << CYAN "NOTA: Los campos con asterisco (*) son obligatorios." NC << endl << endl;

	// Se pide un ISBN para chequear si existe el libro en la BD
	isbn = Menu::getNonEmptyInput("(*) Ingrese el ISBN del libro que deseas mostrar: ", "El campo ISBN no puede quedar vacío");

	try {
		DTBook obtainedBook = controller->getBookByISBN(isbn);
		Menu::viewHeaders();
		cout << obtainedBook;
		cout << GREEN "--------------------------------------------------------------------"
			<< "--------------------------------------------------------------------------------" NC << endl;
	} catch(invalid_argument const& e) {
		cout << endl << REDB "Error: " << e.what() << "" NC << endl << endl;
	}
}

void Menu::viewBooks() {
	string order;
	vector<DTBook> bookList;

	// getchar();

	cout << CYAN "╔═══════════════════╗" << endl;
	cout << "║ Listado de libros ║" << endl;
	cout << "╚═══════════════════╝" NC << endl << endl;
	
	cout << CYAN "NOTA: Los campos con asterisco (*) son obligatorios." NC << endl << endl;

	order = Menu::getStringInput(
		"(*) Ingresa el orden en que deseas ver los libros (DESC / ASC - Por defecto es ASC): "
	);

	if(order != "DESC" && order != "desc"){ order = "ASC"; }

	try {
		bookList = controller->getAllBooks(order);
		Menu::viewHeaders();
		for (const auto& book : bookList) {
			cout << book;
			cout << GREEN "--------------------------------------------------------------------";
			cout << "--------------------------------------------------------------------------------" NC << endl;
		}
	} catch(invalid_argument const& e) {
		cout << endl << REDB "Error: " << e.what() << "" NC << endl << endl;
	}
}
