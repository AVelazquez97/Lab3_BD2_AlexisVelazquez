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
		INSERT INTO libro VALUES (isbn, newTitle, newEdition, newAuthor, newPagesQty);

	+ Eliminar:
		DELETE FROM libro
		WHERE isbn = 'isbnToDelete';

	+ Modificar:
		UPDATE libro 
		SET titulo = 'newTitle', edicion = 'newEdition', autor = 'newAuthor', cantPaginas = newPagesQty
		WHERE isbn = 'isbnToModify';

	+ Listar un libro:
		SELECT * FROM libro 
		WHERE isbn = 'isbnToShow';

	+ Mostrar todos los libros:
		SELECT * FROM libro;