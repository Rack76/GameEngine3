#pragma once

#include <string>
#include <vector>
#include <map>
#include "Archetype.h"

class Component;

class EntityManager
{
public:
	void addEntity(int entityType);
	void updateArchetypes(std::map<int, std::vector<Component*>> componentArrays, int count, ...);
private:
	std::map<int, std::vector<Archetype&>> componentType_archetypesTable;
	std::map<int, Archetype> entityType_archetypeTable;
	std::map<int, std::vector<int>> entityType_componentTypesTable;
};