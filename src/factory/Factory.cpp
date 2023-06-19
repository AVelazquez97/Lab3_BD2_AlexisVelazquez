#include "Factory.h"

Factory::Factory() {

}

Factory::~Factory() {

}

/// @brief Implementación del patrón Factory
/// @return retorna la instancia del controlador. La cual es única y global
IController* Factory::getInterface() {
    return BookController::getInstance();
}