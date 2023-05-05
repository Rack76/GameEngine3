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
}

void EntityManager::addEntity(int entityType)
{
	try {
		std::vector<std::pair<int, Component*>> components = componentManager->constructComponents(entityType);
		for (auto & c : components)
		{
			entityType_archetypeTable[entityType].addComponent(c.second, c.first);
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

void EntityManager::destroyEntity(int entityType, int index)
{
	try {
		entityType_archetypeTable.at(entityType).destroyEntity(index);
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

std::map<int, Component*> EntityManager::getComponents(int entityType, int index)
{
	try {
		std::map<int, Component*> components = entityType_archetypeTable.at(entityType).getComponents(index);
		return components;
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