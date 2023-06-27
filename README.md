# CRUD de MySQL desarrollado con C++

- [Resúmen](#resúmen)
- [1. Consideraciones previas](#1-consideraciones-previas)
  - [A. Instalación y ejecución de MySQL Server](#a-instalación-y-ejecución-de-mysql-server)
  - [B. Creación de la Base de Datos](#b-creación-de-la-base-de-datos)
  - [C. Instalación del conector de MySQL para C++](#c-instalación-del-conector-de-mysql)
  - [D. Descarga del proyecto desde GitHub](#d-descarga-del-proyecto-desde-github)
- [2. Compilación y ejecución del script](#2-compilación-y-ejecución-del-proyecto)
  - [A. Compilación](#a-compilación)
  - [B. Ejecución](#b-ejecución)
- [3. Tecnologías utilizadas](#3-tecnologías-y-librerías-utilizadas)

# Resúmen
Esta es un proyecto universitario para Bases de Datos II. Asignatura que forma parte de la currícula del
[Tecnólgo en Informática, carrera ofrecida por UTEC](https://utec.edu.uy/es/educacion/carrera/tecnologo-en-informatica/).

El objetivo de esta actividad es crear un programa que sea ejecutado a través de la terminal y que cuente con las
operaciones básicas de un CRUD (Create, Read, Update, Delete), realizando una conexión entre C++ y MySQL Server.

Este proyecto se desarrolló con el paradigma de Programación Orientada a Objetos implementando una arquitectura en 
3 capas (presentación, lógica y persistencia).

La capa de entrada, o sea la de presentación, se ve reflejada en los ficheros `main.cpp`, `Menu.h` y `Menu.cpp`.
En estos ficheros se realiza la implementación de un menú básico, el cual muestra y sirve las opciones 
necesarias para invocar cada consulta.

Este menú se visualiza de la siguiente manera:
https://raw.githubusercontent.com/AVelazquez97/Lab3_BD2_AlexisVelazquez/main/assets/img/menu_principal.png

- - -

# 1. Consideraciones previas

## A. Instalación y ejecución de MySQL Server

- Instalación de MySQL Server por línea de comando:
	
    `sudo apt update`

	`sudo apt install mysql-server`

- Comprobación de estado del servicio mysql:
	
	`sudo systemctl status mysql`

	Esto da como respuesta:
    
    https://raw.githubusercontent.com/AVelazquez97/Lab3_BD2_AlexisVelazquez/main/assets/img/mysql_status.png

	Si su estado no es active (running), se puede iniciar con el siguiente comando: 

	`sudo systemctl start mysql`

- Securización de MySQL Server (opcional):
	El siguiente comando ayuda a configurar parámetros de seguridad al servidor de MySQL:
	
    `sudo mysql_secure_installation`

	Con esto, es posible realizar lo siguiente: 
	+ Establecer una contraseña para la cuenta root.
	+ Eliminar el acceso anónimo.
	+ Eliminar la base de datos de test.

## B. Creación de la base de datos
- Ingreso a MySQL Server:
    `sudo mysql -h localhost -root -p`

- Creación de la BD biblioteca y su usuario asignado "tecnologo":
    
    Una vez dentro del servidor MySQL se debe crear la base de datos con el siguiente comando:

    `CREATE DATABASE biblioteca;`

    Luego, para crear el usuario a utilizar para la conexión:
	
    `CREATE USER tecnologo@localhost IDENTIFIED BY "tecnologo";`

	`GRANT ALL PRIVILEGES ON biblioteca.* TO tecnologo@localhost WITH GRANT OPTION;`

- Creación de la tabla libro:
	```
    CREATE TABLE libro (
		isbn VARCHAR(30) NOT NULL,
		titulo VARCHAR(50) NULL,
		edicion VARCHAR(50) NULL,
		autor VARCHAR(50) NULL,
		cantPaginas INT(10) NULL,
		PRIMARY KEY (isbn)
	) ENGINE = InnoDB;
    ```

## C. Instalación del conector de MySQL
- Descarga de la librería del conector en Ubuntu 18.04:
		
    `sudo apt install libmysqlcppconn-dev`
	
- Luego se debe localizar la ruta de inclusión del conector instalado, esto es necesario para la compilación. Con el siguiente comando se van a listar una serie de rutas en las cuales se encuentran los ficheros relacionados al conector:

    `dpkg -L libmysqlcppconn-dev`

- En este caso, como se almacenaron en la ruta "/usr/include/", la misma se debe utilizar al momento de compilar el 
	código fuente que dependa del conector. Por ejemplo: 
	
    `g++ -o main main.cpp -I/usr/include/ -lmysqlcppconn`

Como el proceso de compilación es con make, una instrucción similar se agregó en el fichero makefile.

## D. Descarga del proyecto desde GitHub

- Para descargar el proyecto es necesario tener instalado Git. Luego, es suficiente con ingresar a la terminal e 
ingresar el siguiente comando:

  ```
  git clone https://github.com/AVelazquez97/Lab3_BD2_AlexisVelazquez.git
  ```

- - -

# 2. Compilación y ejecución del proyecto

## A. Compilación

Para este desarrollo se utiliza el compilador g++ y un fichero makefile.
Este fichero contiene las instrucciones de compilación y es ejecutado por la herramiente make.

Para instalar la herramienta make es necesario ingresar los siguientes comandos desde terminal:

`sudo apt update`

`sudo apt install build-essential make`

Luego de instalar la herramienta, es necesario ingresar a la terminal.
Posteriormente, posicionarse en el directorio raíz del proyecto e ingresar el comando "make". 
Este, gracias al makefile, almacenará todos los ficheros .o en el directorio build, y el fichero "crud" compilado
en el directorio raíz.

## B. Ejecución

Teniendo compilado el proyecto, basta con posicionarse en el directorio raíz desde terminal y ejecutar el programa.
Esto se logra con el siguiente comando: 

`./crud`

Un aspecto a tener en cuenta es que si al ejecutar el crud, no se encuentra el servicio de mysql activo,
se lanzará una excepción del siguiente estilo:

`Error de MySQL: 2003 - Can't connect to MySQL server on 'localhost' (111)`

- - -

# 3. Tecnologías y librerías utilizadas
