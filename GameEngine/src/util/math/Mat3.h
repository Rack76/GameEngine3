#pragma once
#include "Math.h"
#include <iostream> 

namespace Math
{
	template <typename T>
	class Mat3
	{
	public:
		Mat3(Vec3<T> x, Vec3<T> y, Vec3<T> z, bool _ortho = true) : ortho(_ortho), rx(_array, 0), ry(_array, 1), rz(_array, 2),
			cx(&_array[0], &_array[3], &_array[6], 0), cy(&_array[0], &_array[3], &_array[6], 1), cz(&_array[0], &_array[3], &_array[6], 2) {
			_array[0] = x.x;
			_array[1] = x.y;
			_array[2] = x.z;
			_array[3] = y.x;
			_array[4] = y.y;
			_array[5] = y.z;
			_array[6] = z.x;
			_array[7] = z.y;
			_array[8] = z.z;
		}

		void operator= (const Mat3& mat) {
			_array[0] = mat._array[0];
			_array[1] = mat._array[1]; 
			_array[2] = mat._array[2];
			_array[3] = mat._array[3];
			_array[4] = mat._array[4];
			_array[5] = mat._array[5];
			_array[6] = mat._array[6];
			_array[7] = mat._array[7];
			_array[8] = mat._array[8];
		}

		Mat3 operator+ (const Mat3& mat) const {
			return Mat3(Vec3(_array[0] + mat._array[0], _array[1] + mat._array[1], _array[2] + mat._array[2]),
				Vec3(_array[3] + mat._array[3], _array[4] + mat._array[4], _array[5] + mat._array[5]),
				Vec3(_array[6] + mat._array[6], _array[7] + mat._array[7], _array[8] + mat._array[8]));
		}

		Mat3 operator- (const Mat3& mat) const {
			return Mat3(Vec3(_array[0] - mat._array[0], _array[1] - mat._array[1], _array[2] - mat._array[2]),
				Vec3(_array[3] - mat._array[3], _array[4] - mat._array[4], _array[5] - mat._array[5]),
				Vec3(_array[6] - mat._array[6], _array[7] - mat._array[7], _array[8] - mat._array[8]));
		}

		Mat3 operator* (const Mat3& mat) const {
			Mat3 m = Mat3(Vec3(dot(rx, mat.cx), dot(rx, mat.cy), dot(rx, mat.cz)),
				Vec3(dot(ry, mat.cx), dot(ry, mat.cy), dot(ry, mat.cz)),
				Vec3(dot(rz, mat.cx), dot(rz, mat.cy), dot(rz, mat.cz)));
			m.fix();
			return m;
		}

		void transpose() {
			auto element1 = _array[1];
			auto element2 = _array[2];
			auto element3 = _array[1 * 3 + 2];

			_array[1] = _array[1 * 3 + 0];
			_array[2] = _array[2 * 3 + 0];
			_array[1 * 3 + 2] = _array[2 * 3 + 1];

			_array[1 * 3 + 0] = element1;
			_array[2 * 3 + 0] = element2;
			_array[2 * 3 + 1] = element3;
		}

		void orthogonalize() {

			Vec3 x = Vec3(_array[0], _array[1], _array[2]);
			Vec3 z = Vec3(_array[6], _array[7], _array[8]);
			Vec3 y = cross(z, x);
			z = cross(x, y);

			_array[0] = x.x;
			_array[1] = x.y;
			_array[2] = x.z;
			_array[3] = y.x;
			_array[4] = y.y;
			_array[5] = y.z;
			_array[6] = z.x;
			_array[7] = z.y;
			_array[8] = z.z;
		}

		static void setFixRate(int fixRate) {
			counterMaxValue = fixRate;
		}

		void fix() {
			if (ortho) {
				if (counter == 0){
					orthogonalize();
					counter = counterMaxValue;
				}
				else
					counter--;
			}
		}

		T* getData() {
			return _array;
		}

		Vec3<T> rx, ry, rz;
		Vec3<T> cx, cy, cz;
		T _array[9];

		static int counterMaxValue;

	private:
		bool ortho;
		static int counter;
	};

	template <typename T>
	int Mat3<T>::counterMaxValue = 5;

	template <typename T>
	int Mat3<T>::counter = counterMaxValue;

	template <typename T>
	Mat3<T> makeRot(Vec3<T> vec, T angle) {
		float t = 1 - cos(angle);
		float c = cos(angle);
		float s = sin(angle);
		return Mat3(Vec3(t * vec.x * vec.x + c , t * vec.x * vec.y - s * vec.z, t * vec.x * vec.z + s * vec.y),
		Vec3(t * vec.x * vec.y + s * vec.z, t * vec.y * vec.y + c, t * vec.y * vec.z - s * vec.x),
		Vec3(t * vec.x * vec.z - s * vec.y, t * vec.y * vec.z + s * vec.x, t * vec.z * vec.z + c));
	}
}