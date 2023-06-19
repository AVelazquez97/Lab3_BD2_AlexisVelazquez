#ifndef MENU_H_
#define MENU_H_

class Menu {
	private:
		static void viewMainMenu();
	public:
        ~Menu();

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