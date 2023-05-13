#include "CppUnitTest.h"
#include "../GameEngine/src/util/math/Vec3.h"
#include <cassert>

namespace GameEngineTest
{
	TEST_CLASS(Vec3Test)
	{
		TEST_METHOD(minusOperatorTest)
		{
			Math::Vec3<float> vec1 =Math::Vec3(2.0f, 3.0f, 2.0f);
			Math::Vec3<float> vec2 = Math::Vec3(1.0f, 1.0f, 1.0f);

			assert(vec1 - vec2 == Math::Vec3(1.0f, 2.0f, 1.0f));
		}
	};
}