- Estructura de la tabla libro: 
	+-------------+-------------+------+-----+---------+-------+
	| Field       | Type        | Null | Key | Default | Extra |
	+-------------+-------------+------+-----+---------+-------+
	| isbn        | varchar(30) | NO   | PRI | NULL    |       |
	| titulo      | varchar(50) | YES  |     | NULL    |       |
	| edicion     | varchar(50) | YES  |     | NULL    |       |
	| autor       | varchar(50) | YES  |     | NULL    |       |
	| cantPaginas | int(10)     | YES  |     | NULL    |       |
	+-------------+-------------+------+-----+---------+-------+


- Poblado inicial de la tabla:
	INSERT INTO libro (isbn, titulo, edicion, autor, cantPaginas) VALUES
	('9781401952010', 'El poder del ahora', '20th Anniversary Edition', 'Eckhart Tolle', 236),
	('9780062315007', 'El monje que vendió su Ferrari', 'Spanish Edition', 'Robin Sharma', 224),
	('9788492929484', 'Mujeres que corren con los lobos', 'Spanish Edition', 'Clarissa Pinkola Estés', 752),
	('9788417248208', 'La magia del orden', 'Spanish Edition', 'Marie Kondo', 256),
	('9781609947920', 'El poder de la mente subconsciente', 'Spanish Edition', 'Joseph Murphy', 400),
	('9780307474864', 'El camino del artista', 'Spanish Edition', 'Julia Cameron', 240),
	('9788479537148', 'El arte de amar', 'Spanish Edition', 'Erich Fromm', 166),
	('9788425343999', 'La buena suerte', 'Spanish Edition', 'Alex Rovira Celma, Fernando Trías de Bes', 208),
	('9786075274606', 'Mentes poderosas', 'Spanish Edition', 'Alberto Coto', 272),
	('9788467028664', 'La inteligencia emocional', '20th Anniversary Edition', 'Daniel Goleman', 384);

- Operaciones que se realizan sobre la tabla libro:
	+ Insertar:
		En caso de seleccionar la opción 1 (ingreso), deberá solicitar los datos correspondientes
		desde el teclado y anexarlo a la tabla si no existe, en caso contrario se deberá mostrar
		los datos y emitir el mensaje de error correspondiente.

		INSERT INTO libro VALUES (isbn, newTitle, newEdition, newAuthor, newPagesQty);

	+ Eliminar:
		En caso de seleccionar la opción 2 (elimino), deberá solicitar el campo clave y verificar
		su existencia, en caso que exista se deberá mostrar los datos para luego solicitarle al
		usuario si lo desea eliminar, en caso que no exista se deberá emitir el correspondiente
		mensaje de error.

		DELETE FROM libro
		WHERE isbn = 'isbnToDelete';

	+ Modificar:
		En caso de seleccionar la opción 3 (modifico), deberá solicitar el campo clave y verificar
		su existencia, en caso que exista se deberá mostrar los datos para luego solicitarle al
		usuario si lo desea modificar, (sólo se modifican los campos no claves) ingresando los
		nuevos datos para luego modificarlos en la tabla. En caso que no exista se deberá
		emitir el correspondiente mensaje de error.

		UPDATE libro 
		SET titulo = 'newTitle', edicion = 'newEdition', autor = 'newAuthor', cantPaginas = newPagesQty
		WHERE isbn = 'isbnToModify';

	+ Listar un libro:
		En caso de seleccionar la opción 4 (consulto), deberá solicitar el campo clave y verificar
		su existencia, en caso que exista se deberá mostrar los datos en caso que no exista se
		deberá emitir el correspondiente mensaje de error.

		SELECT * FROM libro 
		WHERE isbn = 'isbnToShow';

	+ Mostrar todos los libros:
		En caso de seleccionar la opción 5 (listo), se mostrarán en forma de columna todos los
		datos existentes en la tabla. (puede cambiar el orden si lo desea).
		
		SELECT * FROM libro;
