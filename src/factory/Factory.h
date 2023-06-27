#ifndef FACTORY_H_
#define FACTORY_H_

#include "../iController/IController.h"
#include "../controllers/BookController.h"

/// @brief Implementación del patrón Factory. Su principal objetivo es desacoplar las dependencias
/// entre la capa de presentación y la capa lógica
/// @return con el método getInterface(), se retorna la instancia del controlador
class Factory {
	public:
		Factory();
		~Factory();
		IController* getInterface();
	private:
};

#endif // FACTORY_H_
