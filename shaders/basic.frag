#version 330 core

out vec4 color;

in vec2 texCoord;
uniform sampler2D myTexture;

void main()
{
	color = texture(myTexture, texCoord);
	/* color = vec4(0.5f, 1.0f, 1.0f, 1.0f); */
}
