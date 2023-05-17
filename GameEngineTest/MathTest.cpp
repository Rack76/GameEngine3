#include "CppUnitTest.h"
#include "../GameEngine/src/util/math/Math.h"
#include "../GameEngine/src/util/math/Mat3.h"
#include "../GameEngine/src/util/math/Operator.h"
#include <cassert>
#define _USE_MATH_DEFINES
#include <math.h>

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

		TEST_METHOD(TestCross)
		{
			Math::Vec3 v1 = Math::Vec3(1.0f, 0.0f, 0.0f);
			Math::Vec3 v2 = Math::Vec3(0.0f, 2.0f, 0.0f);

			Math::Vec3 v3 = Math::cross(v1, v2);

			assert(v3 == Math::Vec3(0.0f, 0.0f, 2.0f));
		}

		TEST_METHOD(MakeRot)
		{
			Math::Vec3 v1 = Math::Vec3(1.0f, 0.0f, 0.0f);
			Math::Mat3 m = Math::makeRot(v1, 0.0f);

			assert(m == Math::Mat3(Math::Vec3(1.0f, 0.0f, 0.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 1.0f)));

			m = Math::makeRot(Math::Vec3(0.0f, 1.0f, 0.0f) , 90.0f / 180.0f * (float)M_PI);
			m.transpose();
			v1 = m * v1;

			assert(v1 == Math::Vec3(0.0f, 0.0f, 1.0f));
		}
	};
}