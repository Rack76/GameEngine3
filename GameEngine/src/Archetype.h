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

private:
	std::map<int, std::vector<Component*>> componentArrays;
};