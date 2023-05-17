#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "../system/EntityManager.h"

class Parser {
public:
	Parser(EntityManager* ettMnger) : ettMnger(ettMnger) {

	}

	void deserialize(std::string filename);
	void deserialize_ss(std::stringstream&);
	
private:
	EntityManager* ettMnger;
};