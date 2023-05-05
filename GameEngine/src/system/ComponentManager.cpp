#include "ComponentManager.h"
#include "../component/Mock1.h"
#include "../component/Mock2.h"
#include <exception>
#include <cstdarg>
#include <iterator>
#include <cmath>

void ComponentManager::init()
{
	addComponentType<Mock1>();
	addComponentType<Mock2>();
}

void ComponentManager::linkComponents(int entityType) {
	return;
}

std::vector<std::pair<int, Component*>> ComponentManager::constructComponents(int entityType) {
	std::vector<std::pair<int, Component*>> vec;
	try {
		for (auto f : entityType_componentConstructorsTable[entityType])
		{
			
			vec.push_back(std::pair<int, Component*>({f.first, f.second()}));
		}

		return vec;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}