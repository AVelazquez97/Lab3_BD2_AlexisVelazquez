crud: main.o Menu.o Factory.o IController.o BookController.o
	g++ -o crud build/*.o

main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o

Menu.o: src/Menu.h src/Menu.cpp Factory.o IController.o DTBook.o
	g++ -c src/Menu.cpp -o build/Menu.o

Factory.o: src/factory/Factory.h src/factory/Factory.cpp IController.o BookController.o
	g++ -c src/factory/Factory.cpp -o build/Factory.o

BookController.o: src/controllers/BookController.h src/controllers/BookController.cpp Book.o
	g++ -c src/controllers/BookController.cpp -o build/BookController.o

IController.o: src/iController/IController.h src/iController/IController.cpp DTBook.o
	g++ -c src/iController/IController.cpp -o build/IController.o

DTBook.o: src/datatypes/DTBook.h src/datatypes/DTBook.cpp
	g++ -c src/datatypes/DTBook.cpp -o build/DTBook.o

Book.o: src/models/Book.h src/models/Book.cpp
	g++ -c src/models/Book.cpp -o build/Book.o

clean:
	rm -f crud build/*.o build/*.out