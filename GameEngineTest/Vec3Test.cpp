#include "CppUnitTest.h"
#include "../GameEngine/src/util/math/Vec3.h"
#include "../GameEngine/src/util/math/Mat3.h"
#include "../GameEngine/src/util/math/Operator.h"
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

		TEST_METHOD(TestAssignementOperator)
		{
			Math::Vec3<float> vec1 = Math::Vec3(2.0f, 3.0f, 2.0f);
			Math::Vec3<float> vec2 = Math::Vec3(1.0f, 1.0f, 1.0f);

			vec2 = vec1;

			assert(vec2 == Math::Vec3(2.0f, 3.0f, 2.0f));

			{
				Math::Vec3<float> vec3 = Math::Vec3(1.0f, 0.5f, 1.0f);
				vec2 = vec3;
			}

			assert(vec2 == Math::Vec3(1.0f, 0.5f, 1.0f));
		}

		TEST_METHOD(TestMultiplyVecMat)
		{
			Math::Vec3<float> vec = Math::Vec3(2.0f, 3.0f, 2.0f);
			Math::Mat3 m1 = Math::Mat3(Math::Vec3(1.0f, 0.0f, 2.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 1.0f));

			Math::Vec3<float> vec2 = vec * m1;

			assert(vec2 == Math::Vec3(2.0f, 3.0f, 6.0f));

			m1.transpose();
			vec2 = vec * m1;

			assert(vec2 == Math::Vec3(6.0f, 3.0f, 2.0f));
		}
	};
}