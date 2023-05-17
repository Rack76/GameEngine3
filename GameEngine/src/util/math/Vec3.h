#pragma once
#include <cassert>
#include <iostream>
#include <exception>
#include <malloc.h>

namespace Math
{
	template <typename T>
	class Vec3
	{
	public:

		Vec3(T _x, T _y, T _z) : x(data[0]), y(data[1]), z(data[2]) {
			data[0] = _x;
			data[1] = _y;
			data[2] = _z;
		}

		Vec3(T _data1[3], T _data2[3], T _data3[3], int i) : x(_data1[i]), y(_data2[i]), z(_data3[i]) {
			data[0] = 0;
			data[1] = 0;
			data[2] = 0;
		}

		Vec3(T _data[9], int i) : x(_data[0 + i * 3]), y(_data[1 + i * 3]), z(_data[2 + i * 3]) {
			data[0] = 0;
			data[1] = 0;
			data[2] = 0;
		}

		void operator= (const Vec3& vec) {
			data[0] = vec.x;
			data[1] = vec.y;
			data[2] = vec.z;
		}

		Vec3 operator- (const Vec3& vec) const{
			return Vec3(this->x - vec.x,
				this->y - vec.y,
				this->z - vec.z);
		}

		Vec3 operator+ (const Vec3& vec) const{
			return Vec3(this->x + vec.x,
				this->y + vec.y,
				this->z + vec.z);
		}

		Vec3 operator* (const T & v) const {
			return Vec3(this->x * v,
				this->y * v,
				this->z * v);
		}

		Vec3 operator/ (const T& v) const {
			return Vec3(this->x / v.x,
				this->y / v.y,
				this->z / v.z);
		}

		T operator[] (int i) const {
			return data[i];
		}

		void normalize() {
			T len = length();
			assert(len == 0);
			try {
				if (len == 0)
				{
					throw std::exception ("cannot normalize null vector");
					return;
				}
			}
			catch (std::exception& e){
				std::cerr << e.what();
			}

			x /= len;
			y /= len;
			z /= len;
		}

		T length() const{
			return sqrt(x * x + y * y + z * z);
		}

		T lengthSquared() {
			return x * x + y * y + z * z;
		}

		T &x, &y, &z;
		T data[3];
	};
}