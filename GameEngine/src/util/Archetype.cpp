#include "Archetype.h"
#include <iostream>

void Archetype::addComponent(IComponent* component, int componentType)
{
	componentArrays[componentType].push_back(component);
}

void Archetype::setComponentArray(std::vector<IComponent*> componentArray, int componentType)
{
	try {
		componentArrays.at(componentType) = componentArray;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

std::map<int, IComponent*> Archetype::getComponents(int index)
{
	std::map<int, IComponent*> components;

	try {
		for (auto componentArray : componentArrays)
		{
			components.insert({ componentArray.first, componentArray.second.at(index) });
		}
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}

	return components;
}

void Archetype::destroyArchetype() {
	auto it = componentArrays.begin();
	for (auto& componentArray = it; componentArray != componentArrays.end();)
	{
		std::vector<IComponent*>* components = &componentArray->second;
		componentArray = componentArrays.erase(componentArray);
		for (auto& component : *components)
		{
			delete component;
		}
	}
}

void Archetype::destroyEntity(int index)
{
	try {
		for (auto componentArray = componentArrays.begin(); componentArray != componentArrays.end(); componentArray++)
		{
			delete componentArray->second.at(index);
			componentArray->second.erase(componentArray->second.begin() + index);
		}
	}
	
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}
