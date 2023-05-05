#pragma once

#include "../component/Component.h"
#include <map>
#include <functional>
#include <vector>
#include <iostream>

enum class ComponentTypes{MOCK1 = 1, 
						  MOCK2 = 2,
						  };

class ComponentManager
{
public:
	void init();

	template<typename T, typename ...Types>
	void linkComponents(int entityType, T arg, Types ...args) {
		try {
			int componentType = arg;
			entityType_componentConstructorsTable[entityType].push_back(std::pair<int, std::function<Component* ()>>(componentType, componentConstructors.at(componentType)));
			linkComponents(entityType, args...);
		}
		catch (const std::exception& e) {
			std::cerr << e.what();
		}
	}

	void linkComponents(int);

	std::vector<std::pair<int, Component*>> constructComponents(int entityType);

	template <class T>
	void addComponentType()
	{
		componentConstructors.insert({ componentTypeCount , []()-> Component* {return new T; } });
		componentTypeCount ++;
	}
private:
	std::map<int, std::function<Component* (void)>> componentConstructors;
	std::map<int, std::vector<std::pair<int, std::function<Component* (void)>>>> entityType_componentConstructorsTable;
	unsigned long componentTypeCount = 0;
};