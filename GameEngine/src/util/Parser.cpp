#include <cassert>
#include "Parser.h"
#include <exception>
#include "event/Events.h"


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

void Parser::parseShader(std::string vertexShaderfileName, std::string fragmentShaderfileName) {
	GLuint vertexShaderName = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderName = glCreateShader(GL_FRAGMENT_SHADER);
	loadShaderSource(vertexShaderfileName, vertexShaderName);
	loadShaderSource(fragmentShaderfileName, fragmentShaderName);
	ON_PROGRAM_SOURCE_LOADED::call(vertexShaderName, fragmentShaderName, vertexShaderfileName, fragmentShaderfileName);
}

void Parser::loadShaderSource(std::string shaderfileName, GLuint shader) {
	std::ifstream shaderSource(shaderfileName);
	std::filebuf* fbuf = shaderSource.rdbuf();
	std::ostringstream oss;
	oss << fbuf;
	auto string = oss.str();
	const GLchar* vertexShaderString;
	vertexShaderString = string.c_str();
	glShaderSource(shader, 1, &vertexShaderString, nullptr);
}

void Parser::parseCollada(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line), line.find("<geometry") == std::string::npos)
	{

	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(file, line);
	line = line.substr(line.find(">") + 1);
	line = line.substr(0, line.find("<"));
	std::stringstream ss(line);
	std::vector<GLfloat> vertices;
	float num;
	while (!ss.eof())
	{
		ss >> num;
		vertices.push_back(num);
	}
	while (std::getline(file, line), line.find("mesh-map-0-array", line.find("-")+1) == std::string::npos)
	{
	}
	line = line.substr(line.find(">") + 1);
	line = line.substr(0, line.find("<"));
	ss.str(line);
	ss.seekg(0);
	std::vector<GLfloat> textCoord;
	while (!ss.eof())
	{
		ss >> num;
		textCoord.push_back(num);
	}
	while (std::getline(file, line), line.find("<p>") == std::string::npos)
	{

	}
	line = line.substr(line.find(">") + 1);
	line = line.substr(0, line.find("<"));
	ss.str(line);
	ss.seekg(0);
	std::vector<unsigned int> vertexIndices;
	std::vector<unsigned int> textCoordIndices;
	unsigned int num2;
	while (!ss.eof())
	{
		ss >> num2;
		vertexIndices.push_back(num2);
		ss >> num2;
		ss >> num2;
		textCoordIndices.push_back(num2);
	}
	std::vector<GLfloat> orderedVertices;
	std::vector<GLfloat> orderedTextCoord;

	for (unsigned int i = 0; i < vertexIndices.size(); i++)
	{
		orderedVertices.push_back(vertices[3 * vertexIndices[i]]);
		orderedVertices.push_back(vertices[3 * vertexIndices[i]+1]);
		orderedVertices.push_back(vertices[3 * vertexIndices[i]+2]);
	}
	for (unsigned int i = 0; i < textCoordIndices.size(); i++)
	{
		orderedTextCoord.push_back(textCoord[2 * textCoordIndices[i]]);
		orderedTextCoord.push_back(textCoord[2 * textCoordIndices[i]+1]);
	}

	ON_MODEL3D_PARSED::call(filename, orderedVertices, orderedTextCoord);
}