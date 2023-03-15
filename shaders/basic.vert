#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

uniform mat4x4 transform;
uniform mat4x4 projection;

out vec2 outTexCoord;

void main()
{
	gl_Position = projection * transform * vec4(position , 1.0f);
	outTexCoord = texCoord;
}
