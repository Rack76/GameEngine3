#include "CppUnitTest.h"
#include "../GameEngine/src/util/math/Mat3.h"
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

			assert(fabs(m.data[0][0] - v1.x < 0.001) &&
				fabs(m.data[0][1] - v1.y < 0.001) &&
				fabs(m.data[0][2] - v1.z < 0.001) &&
				fabs(m.data[1][0] - v2.x < 0.001) &&
				fabs(m.data[1][1] - v2.y < 0.001) &&
				fabs(m.data[1][2] - v2.z < 0.001) &&
				fabs(m.data[2][0] - v3.x < 0.001) &&
				fabs(m.data[2][1] - v3.y < 0.001) &&
				fabs(m.data[2][2] - v3.z < 0.001));
		}
	};
}