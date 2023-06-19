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
	sudo apt install libmysqlcppconn-dev

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
	Esto se logra con la siguiente sentencia: 
		
	./crud