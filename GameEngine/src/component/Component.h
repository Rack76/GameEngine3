#pragma once

#include "IComponent.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Component : public IComponent
{
public:
	virtual void deserialize(std::vector<std::string>) = 0;
	virtual void serialize(std::ofstream&) = 0;
	virtual void serialize(std::ostringstream &) = 0;
	virtual ~Component(){}
};