#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define REDB "\e[41m"

#include "datatypes/DTBook.h"
#include "iController/IController.h"
#include "factory/Factory.h"


/// @brief Menú de interacción con el usuario. Esta sería la abstracción de la capa de presentación
class Menu {
	private:
		static void viewMainMenu();
		static int getIntegerInput(const string& prompt);
		static string getStringInput(const string& prompt);
		static string getNonEmptyInput(const string& prompt, const string& errorMessage);

	public:
		static int selectOption();
		static void toContinue();
		static void exit();

		static void insertBook();
		static void deleteBook();
		static void updateBook();
		static void viewBook();
		static void viewBooks();
};



#endif // MENU_H_