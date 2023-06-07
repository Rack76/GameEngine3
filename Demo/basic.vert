#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 perspective;
uniform vec3 cameraPosition;
uniform mat3 cameraOrientation;

void main()
{
    vec4 cameraPosition4 = vec4(cameraPosition, 1.0);
	mat4 view = mat4(cameraOrientation);
	cameraPosition4 = cameraPosition4 * view;
	view = transpose(view);
	view[3] = cameraPosition4;
	view = transpose(view);
	gl_Position = vec4(position, 1.0) ;
}