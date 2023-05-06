#pragma once

#include "../component/Component.h"
#include <vector>
#include <map>

class Archetype
{
public:
	void addComponent(IComponent*, int);
	void setComponentArray(std::vector<IComponent*>, int);
	std::map<int, IComponent*> getComponents(int);

	void destroyArchetype();
	void destroyEntity(int);
	
	int getSize() {
		auto it = componentArrays.begin();
		if(!componentArrays.empty())
			return componentArrays.at(it->first).size();
		return 0;
	}

private:
	std::map<int, std::vector<IComponent*>> componentArrays;
};