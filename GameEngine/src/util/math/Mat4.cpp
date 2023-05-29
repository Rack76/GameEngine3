#include <cmath>
#include "glew.h"

namespace Math
{
	void makePerspective(GLfloat perspective[16], float near, float far, float FOV, float aspectRatio) {
		float width = 2 * near * tan(FOV / 2);
		float height = aspectRatio * width;

			perspective[0] = (near / (width / 2));
			perspective[1] = 0;
			perspective[2] = 0;
			perspective[3] = 0;
			perspective[4] = 0;
			perspective[5] = near / (height / 2);
			perspective[6] = 0;
			perspective[7] = 0;
			perspective[8] = 0;
			perspective[9] = 0;
			perspective[10] = -(far + near) / (far - near);
			perspective[11] = 2 * far * near / (far - near);
			perspective[12] = 0;
			perspective[13] = 0;
			perspective[14] = -1;
			perspective[15] = 0;
	}
}