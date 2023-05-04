#pragma once

#include <string>
#include <vector>
#include <map>
#include "../util/Archetype.h"
#include "ComponentManager.h"

enum class EntityTypes{ MOCK1, 
					    MOCK2, 
					    MOCK3 };

class EntityManager
{
public:
	void init();
	void addEntity(int entityType);
	void destroyAllEntities();
	void destroyEntity(int entityType, int index);
	void updateArchetypes(std::map<int, std::vector<Component*>> componentArrays, int count, ...);

	void addEntityType(unsigned long, ...);

	int getEntityCount(int entityType) {
		return entityType_archetypeTable.at(entityType).getSize();
	}
	int getEntityCount() {
		int size = 0;
		for (auto &archetype : entityType_archetypeTable)
		{
			size += archetype.second.getSize();
		}
		return size;
	}
	std::vector<Component*>& getComponents(int entityType, int index);

	~EntityManager(){}
private:
	std::map<int, std::vector<Archetype*>> componentType_archetypesTable;
	std::map<int, Archetype> entityType_archetypeTable;
	ComponentManager* componentManager = new ComponentManager();
};