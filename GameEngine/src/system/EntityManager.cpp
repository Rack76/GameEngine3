#include "EntityManager.h"
#include <cassert>
#include <iterator>
#include <cstdarg>
#include "../util/event/Events.h"

void EntityManager::init()
{
	componentManager->init();
	addEntityType((int)EntityTypes::RENDERER, (int)ComponentTypes::MODEL3D, (int)ComponentTypes::SHADER);
	addEntityType((int)EntityTypes::CAMERA, (int)ComponentTypes::CAMERA);
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
			int index = entityType_archetypeTable[entityType]->getSize() - 1;
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

	try {
		if (getEntityCount() == 0) {
			throw std::exception("error : serialize_ss : empty world,  you must create at least one entity before serializing");
			assert(0 && "error : serialize_ss : empty world,  you must create at least one entity before serializing");
		}
		else {
			std::ofstream file(filename);
			for (auto archetype : entityType_archetypeTable)
			{
				archetype.second->serialize(file, archetype.first);
			}
		}
	}
	catch(std::exception &e) {
		std::cerr << e.what();
	}
}

void EntityManager::serialize_oss(std::ostringstream & oss) {
	try {
		if (getEntityCount() == 0){
			throw std::exception("error : serialize_ss : empty world,  you must create at least one entity before serializing");
			assert(0 && "error : serialize_ss : empty world,  you must create at least one entity before serializing");
		}
		else {
			for (auto archetype : entityType_archetypeTable)
			{
				archetype.second->serialize_oss(archetype.first, oss);
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what();
	}
}

void EntityManager::serialize_oss(std::ostringstream& oss, int entityType, int entity)
{
	entityType_archetypeTable.at(entityType)->serialize_oss(oss, entityType, entity);
}

void EntityManager::serialize(std::string filename, int entityType, int entity) {
	try {
		if (getEntityCount() == 0) {
			throw std::exception("error : serialize : empty world,  you must create at least one entity before serializing");
			assert(0 && "error : serialize : empty world,  you must create at least one entity before serializing");
		}
		else {
			std::ofstream file(filename, std::ios_base::app);
			entityType_archetypeTable.at(entityType)->serialize(file, entityType, entity);
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}