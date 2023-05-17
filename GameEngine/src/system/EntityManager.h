#pragma once

#include <string>
#include <vector>
#include <map>
#include "../util/Archetype.h"
#include "ComponentManager.h"
#include <exception>
#include <iostream>
#include <sstream>

enum class EntityTypes{ MOCK1, 
					    MOCK2, 
					    MOCK3,
						PLAYER,
						VOXEL,
						};

class EntityManager
{
public:
	void init();
	void addEntity(int entityType);
	void destroyAllEntities();
	void destroyEntity(int entityType, int index);

	template <typename ...Types>
	void addEntityType(int entityType, Types ... args)
	{
		entityTypeCount++;
		bool sorted =  (... < args);
		try {
			if (!sorted)
				throw std::exception("you must specify component types in increasing order!");
		}
		catch (std::exception& e){
			std::cerr << e.what();
		}

		componentManager->linkComponents(entityType, args...);

		Archetype* ptemp = new Archetype(args...);

		for (auto archetypes : entityType_archetypeTable)
		{
			auto& archetype = archetypes.second;
			if (*archetype < *ptemp)
				entityType_archetypesTable[archetypes.first].push_back(ptemp);
			else if(*ptemp < *archetype)
				entityType_archetypesTable[entityType].push_back(archetype);
		}

		entityType_archetypesTable[entityType].push_back(ptemp);
		entityType_archetypeTable.insert({ entityType, ptemp });
	}


	int getEntityCount(int entityType) {
		return entityType_archetypeTable.at(entityType)->getSize();
	}
	int getEntityCount() {
		int size = 0;
		for (auto &archetype : entityType_archetypeTable)
		{
			size += archetype.second->getSize();
		}
		return size;
	}

	std::vector<Archetype*> getArchetypes(int entityType) {
		try {
			return entityType_archetypesTable.at(entityType);
		}
		catch(std::exception &e) {
			std::cerr << e.what();
		}
	}

	static constexpr int getMaxEntityCount() {
		return maxEntityCount;
	}
	
	int getEntityTypeCount() {
		return entityTypeCount;
	}

	void serialize(std::string filename);
	void serialize(std::string filename, int entityType, int entity);

	void serialize_oss(std::ostringstream& oss);
	void serialize_oss(std::ostringstream& oss, int entityType, int entity);

	static constexpr int getComponentTypeCount() {
		return ComponentManager::getMaxComponentTypeCount();
	}

	std::map<int, IComponent*> getComponents(int entityType, int index);
	IComponent* getComponent(int entityType, int index, int ComponentType);

	~EntityManager(){
		destroyAllEntities();
		for (auto& archetype : entityType_archetypeTable)
		{
			delete archetype.second;
		}
	}
private:
	static constexpr int maxEntityCount = 50;
	int entityTypeCount = 0;
	std::map<int, std::vector<Archetype*>> entityType_archetypesTable;
	std::map<int, Archetype*> entityType_archetypeTable;
	ComponentManager* componentManager = new ComponentManager();
};