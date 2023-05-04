#include "ComponentManager.h"
#include "../component/Mock1.h"
#include "../component/Mock2.h"
#include <exception>
#include <iostream>
#include <cstdarg>
#include <iterator>
#include <cmath>

void ComponentManager::init()
{
	addComponentType<Mock1>();
	addComponentType<Mock2>();
}

template <class T>
void ComponentManager::addComponentType()
{
	componentConstructors.insert({ componentTypeCount , []()-> Component* {return new T; } });
	componentTypeCount * 2;
}

void ComponentManager::linkComponents(int entityType, ...) {
	try {
		va_list list;
		va_start(list, entityType);
		int i = va_arg(list, int);
		int componentType = pow(2, i);
		entityType_componentConstructorsTable.at(entityType).push_back(std::pair<int, std::function<Component*()>>(componentType, componentConstructors.at(componentType)));
		if (i >= 0)
			linkComponents(entityType, list);
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

std::vector<std::pair<int, Component*>> ComponentManager::constructComponents(int entityType) {
	std::vector<std::pair<int, Component*>> vec;
	try {
		//auto it = entityType_componentConstructorsTable.at(entityType);
		for (auto f : entityType_componentConstructorsTable)
		{
			int i = 0;
			vec.push_back(std::pair<int, Component*>({f.second[i].first, f.second[i].second()}));
			i++;
		}

		return vec;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}