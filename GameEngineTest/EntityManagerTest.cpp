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
			int entityType = (int)EntityTypes::MOCK1;
			ettMnger.addEntity(entityType);
			std::vector<Component*> components;
			components = ettMnger.getComponents(entityType, 0);
			const char* className1 = typeid(*(components[0])).name();
			const char* className2 = typeid(*(components[1])).name();
			assert(!std::strcmp(className1, "class Mock1")
				&& !std::strcmp(className2, "class Mock2"));

			entityType = (int)EntityTypes::MOCK2;
			ettMnger.addEntity(entityType);
			components = ettMnger.getComponents(entityType, 0);
			className1 = typeid(*(components[0])).name();
			assert(!std::strcmp(className1, "class Mock1"));

			ettMnger.addEntity(entityType);
			assert(ettMnger.getEntityCount((int)EntityTypes::MOCK2) == 2);
			assert(ettMnger.getEntityCount((int)EntityTypes::MOCK1) == 1);
			assert(ettMnger.getEntityCount() == 3);
		}

		TEST_METHOD(TestIfDestroyAllEntitiesDestroysAllEntities)
		{
			EntityManager ettMnger;
			ettMnger.init();
			ettMnger.addEntity((int)EntityTypes::MOCK1);
			ettMnger.addEntity((int)EntityTypes::MOCK2);
			ettMnger.addEntity((int)EntityTypes::MOCK3);
			ettMnger.destroyAllEntities();
			assert(ettMnger.getEntityCount() == 0);
		}

		TEST_METHOD(TestIfDestroyEntityDestroysEntities)
		{
			EntityManager ettMnger;
			ettMnger.init();
			ettMnger.addEntity((int)EntityTypes::MOCK1);
			ettMnger.destroyEntity((int)EntityTypes::MOCK1, 0);
			assert(ettMnger.getEntityCount() == 0);
			ettMnger.addEntity((int)EntityTypes::MOCK2);
			ettMnger.addEntity((int)EntityTypes::MOCK3);
			ettMnger.destroyEntity((int)EntityTypes::MOCK2, 0);
			assert(ettMnger.getEntityCount() == 1);
		}
	};
}