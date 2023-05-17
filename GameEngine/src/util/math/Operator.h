#include "Vec3.h"
#include "Mat3.h"

namespace Math 
{
	template <typename T>
	Vec3<T> operator* (const Mat3<T>& mat, const Vec3<T>& vec) {
		return Vec3(dot(mat.rx, vec), dot(mat.ry, vec), dot(mat.rz, vec));
	}

	template <typename T>
	Vec3<T> operator* (const Vec3<T>& vec, const Mat3<T>& mat) {
		return Vec3(dot(mat.cx, vec), dot(mat.cy, vec), dot(mat.cz, vec));
	}

	template <typename T>
	bool operator== (const Mat3<T>& mat1, const Mat3<T>& mat2) {
		bool cond1 = (mat1.rx == mat2.rx);
		bool cond2 = (mat1.ry == mat2.ry);
		bool cond3 = (mat1.rz == mat2.rz);
		return  cond1 &&
			cond2 &&
			cond3;
	}

	template <typename T>
	bool operator== (const Vec3<T>  vec1, const Vec3<T>  vec2) {
		auto len = (vec1 - vec2).length();
		auto average = ((vec1.length() + vec2.length()) / 2);
		return average == 0 ? true : (len / average) < 0.0005;
	}
}