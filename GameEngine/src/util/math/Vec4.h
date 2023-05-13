#pragma once
#include <cmath>


namespace Math
{
	template <typename T>
	class Vec4 
	{
	public:

		Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {

		}

		Vec4 operator- (Vec4& vec) {
			return Vec4(this->x - vec.x,
						this->y - vec.y,
						this->z - vec.z,
						this->w - vec.w);
		}

		T x, y, z, w;
	};
}