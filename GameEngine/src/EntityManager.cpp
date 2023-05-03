#include "EntityManager.h"
#include <iostream>
#include <cassert>
#include <exception>
#include <iterator>
#include <cstdarg>

enum EntityTypesMock{MOCK1, MOCK2, MOCK3};

void EntityManager::init()
{
	//init entityType_componentTypesTable
	std::vector<int> components;
	components.push_back(ComponentTypesMock::MOCK1);
	components.push_back(ComponentTypesMock::MOCK2);
	entityType_componentTypesTable.insert({ EntityTypesMock::MOCK1, components });

	components.push_back(ComponentTypesMock::MOCK1);
	entityType_componentTypesTable.insert({ EntityTypesMock::MOCK2, components });

	components.push_back(ComponentTypesMock::MOCK2);
	entityType_componentTypesTable.insert({ EntityTypesMock::MOCK3, components });
}

void EntityManager::addEntity(int entityType)
{
	try {
		auto componentTypes = entityType_componentTypesTable.at(entityType);
		for (auto componentType : componentTypes)
		{
			entityType_archetypeTable[entityType].addComponent(componentManager->createComponent(componentType), componentType);
		}
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

std::vector<Component*> EntityManager::getComponents(int entityType, int index)
{
	std::vector<Component*> components;
	try {
		entityType_archetypeTable.at(entityType).getComponents(index);
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}

	return components;
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