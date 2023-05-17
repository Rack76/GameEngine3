#include "CppUnitTest.h"
#include "../GameEngine/src/util/math/Mat3.h"
#include "../GameEngine/src/util/math/Operator.h"
#include <cassert>

namespace GameEngineTest
{
	TEST_CLASS(Mat3Test)
	{
		TEST_METHOD(TestOrtogonalize)
		{
			Math::Vec3 v1 = Math::Vec3(1.0f, 0.0f, 0.0f);
			Math::Vec3 v2 = Math::Vec3(0.0f, 1.0f, 0.0f);
			Math::Vec3 v3 = Math::Vec3(0.0f, 0.0f, 1.0f);

			Math::Mat3 m = Math::Mat3(v1, v2, v3);

			m.orthogonalize();

			assert(fabs(m.rx.x - v1.x < 0.001) &&
				fabs(m.rx.y - v1.y < 0.001) &&
				fabs(m.rx.z - v1.z < 0.001) &&
				fabs(m.ry.x - v2.x < 0.001) &&
				fabs(m.ry.y - v2.y < 0.001) &&
				fabs(m.ry.z - v2.z < 0.001) &&
				fabs(m.rz.x - v3.x < 0.001) &&
				fabs(m.rz.y - v3.y < 0.001) &&
				fabs(m.rz.z - v3.z < 0.001));
		}

		TEST_METHOD(TestOperatorPlus)
		{
			Math::Mat3 m1 = Math::Mat3(Math::Vec3(0.0f, 0.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 0.0f),
				Math::Vec3(1.0f, 0.0f, 0.0f));

			Math::Mat3 m2 = Math::Mat3(Math::Vec3(0.0f, 0.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 0.0f));

			assert(((m2 + m1) == m1));
		}

		TEST_METHOD(TestTranspose)
		{
			Math::Mat3 m1 = Math::Mat3(Math::Vec3(1.0f, 0.0f, 0.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(1.0f, 0.0f, 1.0f));

			m1.transpose();

			assert(Math::Mat3(Math::Vec3(1.0f, 0.0f, 1.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 1.0f)) == m1);
		}

		TEST_METHOD(TestOperatorMultiplyMatMat)
		{
			Math::Mat3 m1 = Math::Mat3(Math::Vec3(1.0f, 0.0f, 2.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 1.0f));

			Math::Mat3 m2 = Math::Mat3(Math::Vec3(1.0f, 0.0f, 0.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(1.5f, 0.0f, 1.0f));

			Math::Mat3 m3 = m1 * m2;

			assert(m3 == Math::Mat3(Math::Vec3(4.0f, 0.0f, 2.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(1.5f, 0.0f, 1.0f)));
		}

		TEST_METHOD(TestOperatorMultiplyMatVec)
		{
			Math::Mat3 m1 = Math::Mat3(Math::Vec3(1.0f, 0.0f, 2.0f),
				Math::Vec3(0.0f, 1.0f, 0.0f),
				Math::Vec3(0.0f, 0.0f, 1.0f));

			Math::Vec3 vec = Math::Vec3(1.0f, 1.0f, 1.0f);

			Math::Vec3 vec2 = m1 * vec;

			assert(vec2 == Math::Vec3(3.0f, 1.0f, 1.0f));

			m1.transpose();

			vec2 = m1 * vec;

			assert(vec2 == Math::Vec3(1.0f, 1.0f, 3.0f));
		}
	};
}