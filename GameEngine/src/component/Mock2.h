#pragma once

#include "Component.h"

class Mock2 : public Component
{
public:
	int data = 3;
	char data2 = 1;

	void deserialize(std::vector<std::string> strings) {
		data = std::stoi(strings[0]);
		data2 = strings[1][0];
	}

	void serialize(std::ofstream& file) {
		file << data << ' ' << (short)data2;
	}
	
	~Mock2() {}

private:

};

