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
			parser.deserialize("entities");
			assert(ettMngr.getEntityCount() == 4);
		}
	};
}