#pragma once

#include "Component.h"

class Mock1 : public Component
{
public:
	int data = 0;
	float data2 = 8.127;

	void deserialize(char* dynamicArray, int size) {
		data = (int)(dynamicArray[0]);
		data2 = (float)(dynamicArray[0]);
	}

	void serialize(std::ofstream& file) {
		file << data << ' ' << data2;
	}

	~Mock1() {}

private:
};
