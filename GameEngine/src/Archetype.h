#pragma once

#include "Component.h"
#include <vector>
#include <map>

class Archetype
{
public:
	void addComponent(Component*, int);
	void setComponentArray(std::vector<Component*>, int);
	std::vector<Component*> getComponents(int);

	void destroyArchetype();
	
	int getSize() {
		auto it = componentArrays.begin();
		if(!componentArrays.empty())
			return componentArrays.at(it->first).size();
		return 0;
	}

private:
	std::map<int, std::vector<Component*>> componentArrays;
};