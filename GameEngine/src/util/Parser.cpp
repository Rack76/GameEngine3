#include "Parser.h"
#include <exception>

void Parser::deserialize(std::string filename)
{
	try {
	std::ifstream file(filename);
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
