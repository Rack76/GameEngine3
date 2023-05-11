#include "CppUnitTest.h"
#include "../GameEngine/src/system/EntityManager.h"
#include "../GameEngine/src/util/Parser.h"
#include <cassert>

namespace GameEngineTest
{
	TEST_CLASS(ParserTest)
	{
	public:
		TEST_METHOD(TestIfDeserializeDeserializes)
		{
			EntityManager ettMngr;
			ettMngr.init();
			Parser parser(&ettMngr);
			ettMngr.addEntityType(0, 0);
			ettMngr.addEntityType(1, 0, 1);
			ettMngr.addEntityType(2, 1);
			ettMngr.addEntity(0);
			int n = ettMngr.getEntityCount();
			ettMngr.addEntity(2);
			ettMngr.addEntity(2);
			n = ettMngr.getEntityCount();
			ettMngr.serialize("a.txt");
			ettMngr.destroyAllEntities();
			parser.deserialize("a.txt");
			n = ettMngr.getEntityCount();
			assert(n == 3);
		}

		TEST_METHOD(TestSerializeAndDeserialize)
		{
			EntityManager ettMnger;
			ettMnger.init();
			ettMnger.addEntityType(0, 0, 1);
			ettMnger.addEntity(0);
			ettMnger.addEntity(0);
			ettMnger.addEntityType(1, 0);
			ettMnger.addEntity(1);
			ettMnger.addEntityType(2, 1);
			ettMnger.addEntity(2);
			ettMnger.serialize("mesEntites.txt");
			ettMnger.destroyAllEntities();
			Parser parser(&ettMnger);
			parser.deserialize("mesEntites.txt");
			int n = ettMnger.getEntityCount();
			assert(n == 4);
			ettMnger.addEntity(2);
			ettMnger.addEntity(2);
			n = ettMnger.getEntityCount();
			assert(n == 6);
			ettMnger.serialize("mesEntites.txt");
			ettMnger.destroyAllEntities();
			parser.deserialize("mesEntites.txt");
			n = ettMnger.getEntityCount();
			assert(n == 6);
		}
	};
}