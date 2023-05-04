#include "EntityManager.h"
#include <iostream>
#include <cassert>
#include <exception>
#include <iterator>
#include <cstdarg>

void EntityManager::init()
{
	componentManager->init();

	//init entityType_componentTypesTable
	std::vector<int> components;
	components.push_back((int)ComponentTypesMock::MOCK1);
	components.push_back((int)ComponentTypesMock::MOCK2);
	entityType_componentTypesTable.insert({ (int)EntityTypesMock::MOCK1, components });

	components.clear();
	components.push_back((int)ComponentTypesMock::MOCK1);
	entityType_componentTypesTable.insert({ (int)EntityTypesMock::MOCK2, components });

	components.clear();
	components.push_back((int)ComponentTypesMock::MOCK2);
	entityType_componentTypesTable.insert({ (int)EntityTypesMock::MOCK3, components });
}

void EntityManager::addEntity(int entityType)
{
	try {
		auto componentTypes = entityType_componentTypesTable.at(entityType);
		for (auto componentType : componentTypes)
		{
			Component* component = componentManager->createComponent(componentType);
			entityType_archetypeTable[entityType].addComponent(component, componentType);
		}
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

void EntityManager::destroyAllEntities()
{
	for (auto &archetype : entityType_archetypeTable)
	{
		archetype.second.destroyArchetype();
	}
}

std::vector<Component*> EntityManager::getComponents(int entityType, int index)
{
	std::vector<Component*> components;
	try {
		components = entityType_archetypeTable.at(entityType).getComponents(index);
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