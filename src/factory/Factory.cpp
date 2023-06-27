#include "Factory.h"

Factory::Factory() {

}

Factory::~Factory() {

}

IController* Factory::getInterface() {
    return BookController::getInstance();
}