#pragma once

#include "../component/Component.h"
#include <iostream>
#include <type_traits>
#include <vector>
#include <map>
#include <sstream>

class Archetype
{
public:
	template <typename T>
	Archetype(T arg) {
		std::vector<IComponent*> vec;
		componentArrays.insert(std::make_pair(arg, vec));
	}

	Archetype(int arg) {
		std::vector<IComponent*> vec;
		componentArrays.insert(std::make_pair(arg, vec));
	}

	template <typename T,  typename ...Types>
	Archetype(T arg, Types ...args) {
		if (sizeof...(Types) == 1){
			T a = std::get<0>(std::make_tuple(args...));
			std::vector<IComponent*> vec;
			componentArrays.insert(std::make_pair(arg, vec));
			componentArrays.insert(std::make_pair(a, vec));
		}
		else {
			std::vector<IComponent*> vec;
			componentArrays.insert(std::make_pair(arg, vec));
			Archetype(args...);
		}
	}

	Archetype(){}

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

	void serialize(std::ofstream& filename, int entityType);
	void serialize(std::ofstream& file, int entityType, int entity);

	void serialize_ss(int);

	bool operator<(Archetype& archetype);
private:
	std::map<int, std::vector<IComponent*>> componentArrays;
};