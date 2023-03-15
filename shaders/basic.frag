#version 330 core

out vec4 color;

in vec2 outTexCoord;
uniform sampler2D myTexture;

void main()
{
	color = texture(myTexture, outTexCoord;
	color = vec4(texCoord, 1.0f, 1.0f);
}
