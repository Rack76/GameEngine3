#pragma once

#include "../util/event/Events.h"
#include "EntityManager.h"
#include "../util/Parser.h"

class Serializator
{
public:
	Serializator(EntityManager* ettMnger) : ettMnger(ettMnger) {

	}
	void init();

private:
	
	Parser* parser;
	EntityManager* ettMnger;
};