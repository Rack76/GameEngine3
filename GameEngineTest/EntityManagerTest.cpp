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

		TEST_METHOD(TestIfGetArchetypesReturnsTheRightArchetypes)
		{
			EntityManager ettMnger;
			ettMnger.init();
			ettMnger.addEntityType(0, 0, 1);
			ettMnger.addEntity(0);
			ettMnger.addEntityType(1, 0);
			ettMnger.addEntity(1);
			ettMnger.addEntityType(2, 1);
			ettMnger.addEntity(2);
			std::vector<Archetype*> archetype = ettMnger.getArchetypes(0);
			assert(archetype.size() == 1);
			std::map<int, IComponent*> c = archetype[0]->getComponents(0);
			int a = dynamic_cast<Mock1*>(c.at(0))->data;
			int b = dynamic_cast<Mock2*>(c.at(1))->data;
			assert((a == 0) && (b == 3));

			archetype = ettMnger.getArchetypes(1);
			assert(archetype.size() == 2);

			archetype = ettMnger.getArchetypes(2);
			assert(archetype.size() == 2);
			c = archetype[0]->getComponents(0);
			b = dynamic_cast<Mock2*>(c.at(1))->data;
			assert(b == 3);
		}

		TEST_METHOD(TestIfSerializeSerializes)
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
		}
	};
}