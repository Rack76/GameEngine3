#pragma once

#include "Component.h"

class Mock2 : public Component
{
public:
	int data = 3;
	char data2 = 1;

	void deserialize(char* dynamicArray, int size) {
		data = (int)(dynamicArray[0]);
		data2 = (char)(dynamicArray[0]);
	}

	void serialize(std::ofstream& file) {
		file << data << ' ' << (short)data2;
	}
	
	~Mock2() {}

private:

};

