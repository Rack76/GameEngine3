#pragma once

#include "IComponent.h"
#include <vector>
#include <fstream>

class Component : public IComponent
{
public:
	virtual void deserialize(char* dynamicArray, int size) = 0;
	virtual void serialize(std::ofstream&) = 0;
	virtual ~Component(){}
};