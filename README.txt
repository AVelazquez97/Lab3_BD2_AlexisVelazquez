- Instalación de MySQL Server:
	sudo apt update
	sudo apt install mysql-server

- Securización de MySQL Server (opcional):
	El siguiente comando ayuda a configurar parámetros de seguridad al servidor de MySQL:
	sudo mysql_secure_installation

	Con esto, es posible realizar lo siguiente: 
	+ Establecer una contraseña para la cuenta root.
	+ Eliminar el acceso anónimo.
	+ Eliminar la base de datos de test.

- Creación de la BD biblioteca y su usuario asignado "tecnologo":
	CREATE DATABASE biblioteca;

	CREATE USER tecnologo@localhost IDENTIFIED BY "tecnologo";

	GRANT ALL PRIVILEGES ON biblioteca.* TO tecnologo@localhost WITH GRANT OPTION;

- Creación de la tabla libro:
	CREATE TABLE libro (
		isbn VARCHAR(30) NOT NULL,
		titulo VARCHAR(50) NULL,
		edicion VARCHAR(50) NULL,
		autor VARCHAR(50) NULL,
		cantPaginas INT(10) NULL,
		PRIMARY KEY (isbn)
	) ENGINE = InnoDB;

- Instalación del conector de MySQL para C++ en Ubuntu 18.04:
	Para instalar la librería del conector:
		sudo apt install libmysqlcppconn-dev
	
	Luego se debe localizar la ruta de inclusión del conector instalado, esto es necesario para la compilación.
	Con el siguiente comando se van a listar una serie de rutas en las cuales se encuentran los ficheros relacionados
	al conector:
		dpkg -L libmysqlcppconn-dev

	En este caso, como se almacenaron en la ruta "/usr/include/", la misma se debe utilizar al momento de compilar el 
	código fuente que dependa del conector. Por ejemplo: 
		g++ -o main main.cpp -I/usr/include/ -lmysqlcppconn

	En este caso, como el proceso de compilación es con make, una instrucción similar se agregará en el makefile.

- Proceso de compilación:
	Para este desarrollo se utiliza el compilador g++ y un fichero makefile.
	Este fichero contiene las instrucciones de compilación y es ejecutado por la herramiente make.

	Para instalar la herramienta make es necesario ingresar los siguientes comandos desde terminal:
		sudo apt update
		sudo apt install build-essential make

	Luego de instalar la herramienta, es necesario ingresar a la terminal.
	Posteriormente, posicionarse en el directorio raíz del proyecto e ingresar el comando "make". 
	Este, gracias al makefile, almacenará todos los ficheros .o en el directorio build, y el fichero "crud" compilado
	en el directorio raíz.

- Ejecución:
	Teniendo compilado el proyecto, basta con posicionarse en el directorio raíz desde terminal y ejecutar el programa.
	Esto se logra con el siguiente comando: 
		./crud

	Un aspecto a tener en cuenta es que si al ejecutar el crud, se lanza una excepción del siguiente estilo:

	`Error de MySQL: 2003 - Can't connect to MySQL server on 'localhost' (111)`

	Esto quiere decir que el proceso de MySQL está detenido, es posible chequearlo con el siguiente comando desde 
	terminal:
	
	`sudo systemctl status mysql`

	Dando como respuesta:

	Si su estado no es active (running), como en la imágen, se puede iniciar con el siguiente comando: 
	`sudo systemctl start mysql`

