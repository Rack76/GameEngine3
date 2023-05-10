#pragma once

#include "IComponent.h"
#include <vector>
#include <fstream>
#include <string>

class Component : public IComponent
{
public:
	virtual void deserialize(std::vector<std::string>) = 0;
	virtual void serialize(std::ofstream&) = 0;
	virtual ~Component(){}
};