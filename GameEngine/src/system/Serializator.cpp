#include "Serializator.h"
#include <vector>
#include <fstream>

void Serializator::init(){
	Parser* parser = this->parser;
	EntityManager* pem = this->ettMnger;

	LOAD_ENTITIES::registerListener(
		 [parser](std::string filename) {
		parser->deserialize(filename);
		});

	SAVE_ENTITIES::registerListener(
		[pem](std::string filename) {
			pem->serialize(filename);
		});
}