#ifndef FACTORY_H_
#define FACTORY_H_

#include "../iController/IController.h"
#include "../controllers/BookController.h"

class Factory {
	public:
		Factory();
		~Factory();
		IController* getInterface();
	private:
};

#endif // FACTORY_H_
