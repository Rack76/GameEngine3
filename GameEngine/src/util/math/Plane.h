#pragma once
#include "Vec3.h"
#include "Math.h"

namespace Math
{
	template <typename T>
	class Plane
	{
	public:
		Plane(T nx, T ny, T nz, T d) : n(Vec3(nx, ny, nz)), d(d) {
			
		}

		bool isUnder(Vec3<T> point) {
			T proj = dot(point, n);
			return  proj > d ? true : false;
		}

		T distanceFrom(Vec3<T> point) {
			T proj = dot(point, n);
			return proj - d;
		}

		Vec3<T> n;
		T d;
	};
}
