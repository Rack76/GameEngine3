#include "../GameEngine/src/util/math/Plane.h"
#include "CppUnitTest.h"
#include <cmath>

namespace GameEngineTest
{
	TEST_CLASS(PlaneTest)
	{
		TEST_METHOD(TestIsUnder)
		{
			Math::Vec3 point = Math::Vec3(0.0f, 2.0f, 0.0f);
			Math::Plane p = Math::Plane(0.0f, 1.0f, 0.0f, 1.2f);

			assert(p.isUnder(point));
			p.d = 1.0f;
			point.y = 1.0f;

			assert(!p.isUnder(point));
		}

		TEST_METHOD(TestDistanceFrom)
		{
			Math::Vec3 point = Math::Vec3(0.0f, 1.4f, 0.0f);
			Math::Plane p = Math::Plane(0.0f, 1.0f, 0.0f, 1.2f);

			assert( fabs(p.distanceFrom(point) - 0.2 < 0.001));
		}
	};
}