#include <iostream>
#include "Menu.h"
using namespace std;

int main(int argc, char* argv[]) {
    int option = 0;

    while(option != 6) {
		option = Menu::selectOption();
		switch (option){
			case 1: { //Ingreso
                Menu::insertBook();
                Menu::toContinue();
                break;
			}
            case 2: { //Elimino
                Menu::deleteBook();
                Menu::toContinue();
                break;
			}
            case 3: { //Modifico
                Menu::updateBook();
                Menu::toContinue();
                break;
			}
            case 4: { //Consulto
                Menu::viewBook();
                Menu::toContinue();
                break;
			}
            case 5: { //Listo
                Menu::viewBooks();
                Menu::toContinue();
                break;
			}
            case 6: { // Fin
                Menu::exit();
                return 0;
            }
        }
        system("clear");
    }
    return 0;
}