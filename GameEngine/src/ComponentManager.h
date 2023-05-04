#pragma once

#include "Component.h"
#include <map>
#include <functional>

enum class ComponentTypesMock{MOCK1, MOCK2};

class ComponentManager
{
public:
	void init();
	Component* createComponent(int componentType);
private:
	std::map<int, std::function<Component* (void)>> constructors;
};