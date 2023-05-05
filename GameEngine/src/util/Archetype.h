#pragma once

#include "../component/Component.h"
#include <vector>
#include <map>

class Archetype
{
public:
	void addComponent(Component*, int);
	void setComponentArray(std::vector<Component*>, int);
	std::map<int, Component*> getComponents(int);

	void destroyArchetype();
	void destroyEntity(int);
	
	int getSize() {
		auto it = componentArrays.begin();
		if(!componentArrays.empty())
			return componentArrays.at(it->first).size();
		return 0;
	}

private:
	std::map<int, std::vector<Component*>> componentArrays;
};