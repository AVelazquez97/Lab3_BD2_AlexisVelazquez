#ifndef MENU_H_
#define MENU_H_

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define REDB "\e[41m"

/// @brief Menú de interacción con el usuario. Capa de presentación
class Menu {
	private:
		static void viewMainMenu();
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