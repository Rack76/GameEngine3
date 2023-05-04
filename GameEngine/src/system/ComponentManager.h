#pragma once

#include "../component/Component.h"
#include <map>
#include <functional>
#include <vector>

enum class ComponentTypes{MOCK1 = 1, 
						  MOCK2 = 2,
						  };

class ComponentManager
{
public:
	void init();

	void linkComponents(int, ...);

	std::vector<std::pair<int, Component*>> constructComponents(int entityType);

	template <class T>
	void addComponentType();
private:
	std::map<int, std::function<Component* (void)>> componentConstructors;
	std::map<int, std::vector<std::pair<int, std::function<Component* (void)>>>> entityType_componentConstructorsTable;
	unsigned long componentTypeCount = 1;
};