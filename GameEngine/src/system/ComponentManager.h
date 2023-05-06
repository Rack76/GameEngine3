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
			entityType_componentConstructorsTable[entityType].push_back(std::pair<int, std::function<IComponent* ()>>(componentType, componentConstructors.at(componentType)));
			linkComponents(entityType, args...);
		}
		catch (const std::exception& e) {
			std::cerr << e.what();
		}
	}

	void linkComponents(int);

	std::vector<std::pair<int, IComponent*>> constructComponents(int entityType);

	template <class T>
	void addComponentType()
	{
		componentConstructors.insert({ componentTypeCount , []()-> IComponent* {return new T; } });
		componentTypeCount ++;
	}
private:
	std::map<int, std::function<IComponent* (void)>> componentConstructors;
	std::map<int, std::vector<std::pair<int, std::function<IComponent* (void)>>>> entityType_componentConstructorsTable;
	unsigned long componentTypeCount = 0;
};