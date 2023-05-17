#include <cassert>
#include "Parser.h"
#include <exception>


void Parser::deserialize(std::string filename)
{
	try {
	std::ifstream file(filename);
	if (file.eof())
	{
		throw std::exception("error : deserialize : file cannot be empty, serialize it first");
		assert(0 && "error : deserialize : file cannot be empty, serialize it first");
	}
	std::string str;
	std::map<int, int> i;
	for (int a = 0; a < ettMnger->getEntityTypeCount(); a++)
	{
		i.insert({ a, -1 });
	}
	int componentType;
	int entityType;

	while (!(file >> str).eof())
	{

		if (str == "ENTITY"){
			int character;
			file >> entityType;
			i[entityType]++;
			ettMnger->addEntity(entityType);
		}
		else if (str == "COMPONENT") {
			int character;
			file >> componentType;
		}
		else{
			std::vector<std::string> stringArray;
			std::string str;
			int index = 0;
				do {
					file >> str;
					stringArray.push_back(str);
				} while (index++, str != "*");
				index--;
			stringArray.pop_back();
			IComponent* component = ettMnger->getComponent(entityType, i[entityType], componentType);
			((Component*)component)->deserialize(stringArray);
		}
	}
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}

void Parser::deserialize_ss(std::stringstream &ss)
{
	try {
		if (ss.eof())
		{
			throw std::exception("error : deserialize_ss : stringstream cannot be empty, serialize it first");
			assert(0 && "error : deserialize_ss : stringstream cannot be empty, serialize it first");
		}
		std::string str;
		std::map<int, int> i;
		for (int a = 0; a < ettMnger->getEntityTypeCount(); a++)
		{
			i.insert({ a, -1 });
		}
		int componentType;
		int entityType;

		while (!(ss >> str).eof())
		{

			if (str == "ENTITY") {
				int character;
				ss >> entityType;
				i[entityType]++;
				ettMnger->addEntity(entityType);
			}
			else if (str == "COMPONENT") {
				int character;
				ss >> componentType;
			}
			else {
				std::vector<std::string> stringArray;
				std::string str;
				int index = 0;
				do {
					ss >> str;
					stringArray.push_back(str);
				} while (index++, str != "*");
				index--;
				stringArray.pop_back();
				IComponent* component = ettMnger->getComponent(entityType, i[entityType], componentType);
				((Component*)component)->deserialize(stringArray);
			}
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}