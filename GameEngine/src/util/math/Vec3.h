#pragma once
#include <cassert>
#include <iostream>
#include <exception>

namespace Math
{
	template <typename T>
	class Vec3
	{
	public:
		Vec3() : x(data[0]), y(data[1]), z(data[2]) {

		}

		Vec3(T _x, T _y, T _z) : x(data[0]), y(data[1]) , z(data[2]) {
			data[0] = _x;
			data[1] = _y;
			data[2] = _z;
		}

		bool operator== (Vec3 vec) {
			auto len = (*this - vec).length();
			auto average = (((*this).length() + vec.length()) / 2);
			return (len / average) < 0.0005;
		}

		void operator= (const Vec3& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
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

		T operator[] (const T& i) const {
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

		T length() {
			return sqrt(x * x + y * y + z * z);
		}

		T lengthSquared() {
			return x * x + y * y + z * z;
		}

		T &x, &y, &z;
		T data[3];
	};
}