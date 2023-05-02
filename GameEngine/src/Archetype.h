#pragma once

#include "Component.h"
#include <vector>

class Archetype
{
public:
	void setComponent(Component*, int);
	void setComponentArray(std::vector<Component*>, int);
};