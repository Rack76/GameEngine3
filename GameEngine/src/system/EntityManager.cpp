#include "EntityManager.h"
#include <cassert>
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
		if (getEntityCount() < maxEntityCount)
		{
			std::vector<std::pair<int, IComponent*>> components = componentManager->constructComponents(entityType);
			for (auto& c : components)
			{
				entityType_archetypeTable[entityType]->addComponent(c.second, c.first);
			}
		}
		else
			throw std::exception("max entity count reached !");
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

void EntityManager::destroyAllEntities()
{
	for (auto &archetype : entityType_archetypeTable)
	{
		archetype.second->destroyArchetype();
	}
}

void EntityManager::destroyEntity(int entityType, int index)
{
	try {
		entityType_archetypeTable.at(entityType)->destroyEntity(index);
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

std::map<int, IComponent*> EntityManager::getComponents(int entityType, int index)
{
	try {
		std::map<int, IComponent*> components = entityType_archetypeTable.at(entityType)->getComponents(index);
		return components;
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

IComponent* EntityManager::getComponent(int entityType, int index, int componentType)
{
	try {
		std::map<int, IComponent*> components = entityType_archetypeTable.at(entityType)->getComponents(index);
		return components.at(componentType);
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

void EntityManager::serialize(std::string filename) {
	std::ofstream file(filename);
	for (auto archetype : entityType_archetypeTable)
	{
		archetype.second->serialize(file, archetype.first);
	}
}

void EntityManager::serialize_ss() {
	for (auto archetype : entityType_archetypeTable)
	{
		archetype.second->serialize_ss(archetype.first);
	}
}

void EntityManager::serialize(std::string filename, int entityType, int entity) {
	std::ofstream file(filename, std::ios_base::app);
	entityType_archetypeTable.at(entityType)->serialize(file, entityType, entity);
}