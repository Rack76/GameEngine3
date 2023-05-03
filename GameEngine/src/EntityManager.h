#pragma once

#include <string>
#include <vector>
#include <map>
#include "Archetype.h"
#include "ComponentManager.h"

class Component;

class EntityManager
{
public:
	void init();
	void addEntity(int entityType);
	void updateArchetypes(std::map<int, std::vector<Component*>> componentArrays, int count, ...);
	std::vector<Component*> getComponents(int entityType, int index);
private:
	std::map<int, std::vector<Archetype*>> componentType_archetypesTable;
	std::map<int, Archetype> entityType_archetypeTable;
	std::map<int, std::vector<int>> entityType_componentTypesTable;
	ComponentManager* componentManager;
};