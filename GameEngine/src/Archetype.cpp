#include "Archetype.h"
#include <iostream>

void Archetype::addComponent(Component* component, int componentType)
{
	componentArrays[componentType].push_back(component);
}

void Archetype::setComponentArray(std::vector<Component*> componentArray, int componentType)
{
	try {
		componentArrays.at(componentType) = componentArray;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}

std::vector<Component*> Archetype::getComponents(int index)
{
	std::vector<Component*> components;

	try {
		for (auto componentArray : componentArrays)
		{
			components.push_back(componentArray.second.at(index));
		}
	}

	catch (const std::exception& e) {
		std::cerr << e.what();
	}

	return components;
}
