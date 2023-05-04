#include "ComponentManager.h"
#include "Mock1.h"
#include "Mock2.h"
#include <exception>
#include <iostream>

void ComponentManager::init()
{
	constructors.insert({ (int)ComponentTypesMock::MOCK1, []()->Component* {return new Mock1(); } });
	constructors.insert({ (int)ComponentTypesMock::MOCK2, []()->Component* {return new Mock2(); } });
}

Component* ComponentManager::createComponent(int componentType)
{
	try {
		return constructors.at(componentType)();
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}
