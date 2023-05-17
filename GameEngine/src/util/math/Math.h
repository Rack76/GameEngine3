#pragma once
#include "Vec3.h"

namespace Math
{
	unsigned long one_complement(unsigned long base, unsigned long value);

	template <typename T> 
	 T dot(const Vec3<T> &v1, const Vec3<T> &v2) {
		return (v1.x * v2.x +
			v1.y * v2.y +
			v1.z * v2.z);
	}

	template <typename T>
	Vec3<T> proj(Vec3<T> &v1, Vec3<T> &v2) {
		return v2 * (dot<T>(v1, v2) / dot<T>(v2, v2));
	}

	template <typename T>
	Vec3<T> cross(Vec3<T> &v1, Vec3<T> &v2) {
		return Vec3(v1.y * v2.z - v1.z * v2 .y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x);
	}

	template <typename T>
	T distanceSquared(Vec3<T>& point1, Vec3<T>& point2) {
		T x = point1.x - point2.x;
		T y = point1.y - point2.y;
		T z = point1.z - point2.z;

		return (x * x + y * y + z * z);
	}

	template <typename T>
	T distance(Vec3<T>& point1, Vec3<T>& point2) {
		T x = point1.x - point2.x;
		T y = point1.y - point2.y;
		T z = point1.z - point2.z;

		return sqrt(x * x + y * y + z * z);
	}


}