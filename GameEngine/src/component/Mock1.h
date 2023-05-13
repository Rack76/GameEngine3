#pragma once

#include "Component.h"

class Mock1 : public Component
{
public:
	int data = 0;
	float data2 = 8.127;

	void deserialize(std::vector<std::string> strings) {
		data = std::stoi(strings[0]);
		data2 = std::stof(strings[1]);
	}

	void serialize(std::ofstream& file) {
		file << data << ' ' << data2;
	}

	void serialize(std::ostringstream& oss) {
		oss << data << ' ' << data2;
	}

	~Mock1() {}

private:
};
