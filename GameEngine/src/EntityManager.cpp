#include "EntityManager.h"
#include <iostream>
#include <cassert>
#include <exception>
#include <iterator>
#include <cstdarg>

void EntityManager::init()
{
	//init entityType_componentTypesTable
}

void EntityManager::addEntity(int entityType)
{
	try {
		auto componentTypes = entityType_componentTypesTable.at(entityType);
		for (auto componentType : componentTypes)
		{
			entityType_archetypeTable[entityType].setComponent(componentManager->createComponent(componentType), componentType);
		}
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

void EntityManager::updateArchetypes(std::map<int, std::vector<Component*>> componentArrays, int count, ...)
{
	try {
		va_list arg;
		va_start(arg, count);
		for (int i = 0; i < count; i++)
		{
			int componentType = va_arg(arg, int);
			for (auto archetype : componentType_archetypesTable.at(componentType))
			{
				archetype->setComponentArray(componentArrays.at(componentType), componentType);
			}
		}

		va_end(arg);
	}

	catch(const std::exception &e) {
		std::cerr << e.what();
	}
}