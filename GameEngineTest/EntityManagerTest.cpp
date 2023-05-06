#include "CppUnitTest.h"
#include "../GameEngine/src/system/EntityManager.h"
#include <cassert>
#include "../GameEngine/src/component/Mock1.h"
#include "../GameEngine/src/component/Mock2.h"

namespace GameEngineTest 
{
	TEST_CLASS(EntityManagerTest)
	{
	public:
		TEST_METHOD(TestIfAddEntityAddEntities)
		{
			EntityManager ettMnger;
			ettMnger.init();
			ettMnger.addEntityType(0, 0, 1);
			ettMnger.addEntity(0);

			ettMnger.addEntityType(1, 0);
			ettMnger.addEntity(1);

			ettMnger.addEntity(1);
			assert(ettMnger.getEntityCount(1) == 2);
			assert(ettMnger.getEntityCount(0) == 1);
			assert(ettMnger.getEntityCount() == 3);
		}

		TEST_METHOD(TestIfDestroyAllEntitiesDestroysAllEntities)
		{
			EntityManager ettMnger;
			ettMnger.init();
			ettMnger.addEntityType(0, 0, 1);
			ettMnger.addEntityType(1, 0);
			ettMnger.addEntityType(2, 1);
			ettMnger.addEntity(0);
			ettMnger.addEntity(1);
			ettMnger.addEntity(2);
			assert(ettMnger.getEntityCount() == 3);
			ettMnger.destroyAllEntities();
			assert(ettMnger.getEntityCount() == 0);
		}

		TEST_METHOD(TestIfDestroyEntityDestroysEntities)
		{
			EntityManager ettMnger;
			ettMnger.init();
			ettMnger.addEntityType(0, 0, 1);
			ettMnger.addEntity(0);
			ettMnger.destroyEntity(0, 0);
			assert(ettMnger.getEntityCount() == 0);
			ettMnger.addEntityType(1, 0);
			ettMnger.addEntity(1);
			ettMnger.addEntityType(2, 1);
			ettMnger.addEntity(2);
			ettMnger.destroyEntity(1, 0);
			assert(ettMnger.getEntityCount() == 1);
		}
	};
}