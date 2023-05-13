#pragma once
#include "Math.h"

namespace Math
{
	template <typename T>
	class Mat3
	{
	public:
		Mat3(Vec3<T> x, Vec3<T> y, Vec3<T> z) {

			x.x = data[0][0];
			x.y = data[0][1];
			x.z = data[0][2];
			y.x = data[1][0];
			y.y = data[1][1];
			y.z = data[1][2];
			z.x = data[2][0];
			z.y = data[2][1];
			z.z = data[2][2];

		}

		//Mat3 operator+ (Mat3)

		void orthogonalize() {
			y = cross(z, x);
			z = cross(x, y);
		}

		Vec3<T> x, y, z;
		T data[3][3];

	private:
		static int counter;
	};

	static int counter = 3;
}