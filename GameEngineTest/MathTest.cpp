#include "CppUnitTest.h"
#include "../GameEngine/src/util/math/Math.h"
#include <cassert>

namespace GameEngineTest
{
	TEST_CLASS(MathTest)
	{
		TEST_METHOD(TestProj)
		{
			Math::Vec3 v1 = Math::Vec3(1.0f, 0.0f, 0.0f);
			Math::Vec3 v2 = Math::Vec3(0.5f, 2.0f, 0.0f);
			assert(Math::proj(v2, v1) == Math::Vec3(0.5f, 0.0f, 0.0f));
		}
	};
}