#pragma once

#include <string>
#include <vector>
#include <map>
#include "Archetype.h"
#include "ComponentManager.h"

enum class EntityTypesMock { MOCK1, MOCK2, MOCK3 };

class EntityManager
{
public:
	void init();
	void addEntity(int entityType);
	void destroyAllEntities();
	void updateArchetypes(std::map<int, std::vector<Component*>> componentArrays, int count, ...);
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
	std::vector<Component*> getComponents(int entityType, int index);

	~EntityManager(){}
private:
	std::map<int, std::vector<Archetype*>> componentType_archetypesTable;
	std::map<int, Archetype> entityType_archetypeTable;
	std::map<int, std::vector<int>> entityType_componentTypesTable;
	ComponentManager* componentManager = new ComponentManager();
};