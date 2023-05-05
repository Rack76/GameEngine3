#include "CppUnitTest.h"
#include "../GameEngine/src/system/EntityManager.h"
#include <cassert>

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
			std::map<int, Component*> components;
			components = ettMnger.getComponents(0, 0);
			const char* className1 = typeid(*(components.at(0))).name();
			const char* className2 = typeid(*(components.at(1))).name();
			assert(!std::strcmp(className1, "class Mock1")
				&& !std::strcmp(className2, "class Mock2"));

			ettMnger.addEntityType(1, 0);
			ettMnger.addEntity(1);
			components = ettMnger.getComponents(1, 0);
			className1 = typeid(*(components[0])).name();
			assert(!std::strcmp(className1, "class Mock1"));

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