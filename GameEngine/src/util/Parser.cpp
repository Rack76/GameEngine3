#include "Parser.h"
#include <exception>

void Parser::deserialize(std::string filename)
{
	try {
	std::ifstream file("entities.txt");
	if (file.eof())
		throw std::exception();
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
			std::vector<char> c;
			int size;
			std::vector<std::vector<char>> temp;
			char* dynamicArray;
			int index = -1;
			int loops = 0;
			while (1) {
				do {
					c.push_back(file.get());
					index++;
				} while (loops++, (c[index] != ' ') && (c[index] != '\n') && (c[index] != '*'));
				if (c[index] == '*')
				{
					c.pop_back();
					size = c.size();
					temp.push_back(c);
					break;
				}
				if (c[index] == ' ' || c[index] == '\n')
				{
					c.pop_back();
					index--;
					continue;
				}
			}
			dynamicArray = new char[size];
			for (int i = 0; i < c.size(); i++)
			{
				dynamicArray[i] = c[i];
			}
			IComponent* component = ettMnger->getComponent(entityType, i[entityType], componentType);
			((Component*)component)->deserialize(dynamicArray, size);
				delete[] dynamicArray;
		}
	}
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}
