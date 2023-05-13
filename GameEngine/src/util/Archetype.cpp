#include "Archetype.h"
#include <iostream>
#include <string>

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

void Archetype::serialize(std::ofstream &file, int entityType)
{
	int entityCount = componentArrays.begin()->second.size();
	int entityIndex = 0;
	if (entityCount != 0)
	{
		int componentTypeCount = componentArrays.size();
		for (int a = 0; a < entityCount; a++)
		{
			auto componentArry = componentArrays.begin();
			file << "ENTITY" << '\n' << entityType << '\n';
			for (int i = 0; i < componentTypeCount; i++)
			{
				file << "COMPONENT " << componentArry->first << ' ' << '*' << '\n';
				((Component*)(componentArry->second[entityIndex]))->serialize(file);
				file << ' ' << '*' << '\n';
				std::advance(componentArry, 1);
			}
			entityIndex++;
		}
	}
}

void Archetype::serialize(std::ofstream& file, int entityType, int entity) {
	int entityCount = componentArrays.begin()->second.size();
	if (entityCount != 0)
	{
		int componentTypeCount = componentArrays.size();
		auto componentArry = componentArrays.begin();
		file << "ENTITY" << '\n' << entityType << '\n';
		for (int i = 0; i < componentTypeCount; i++)
		{
			file << "COMPONENT " << componentArry->first << ' ' << '*' << '\n';
			((Component*)(componentArry->second[entity]))->serialize(file);
			file << ' ' << '*' << '\n';
			std::advance(componentArry, 1);
		}
	}
}

void Archetype::serialize_ss(int entityType)
{
	std::ostringstream ossName;
	int entityCount = componentArrays.begin()->second.size();
	int entityIndex = 0;
	if (entityCount != 0)
	{
		int componentTypeCount = componentArrays.size();
		for (int a = 0; a < entityCount; a++)
		{
			auto componentArry = componentArrays.begin();
			ossName << "ENTITY" << '\n' << entityType << '\n';
			for (int i = 0; i < componentTypeCount; i++)
			{
				ossName << "COMPONENT " << componentArry->first << ' ' << '*' << '\n';
				((Component*)(componentArry->second[entityIndex]))->serialize(ossName);
				ossName << ' ' << '*' << '\n';
				std::advance(componentArry, 1);
			}
			entityIndex++;
		}
	}
}

bool Archetype::operator<(Archetype& archetype) {
	if (componentArrays.size() < archetype.componentArrays.size())
	{
		for (auto& componentArray : componentArrays)
		{
			if (archetype.componentArrays.find(componentArray.first) == archetype.componentArrays.end())
				return false;
		}
		return true;
	}
	else
		return false;
}

