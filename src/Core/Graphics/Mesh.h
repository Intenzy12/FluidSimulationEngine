#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>

struct Vertex {
    glm::vec3 Position;
    glm::vec2 TexCoords;
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	void SetVertices(std::vector<Vertex>);
	void SetIndices(std::vector<unsigned int>);
	void SetData(std::vector<Vertex>, std::vector<unsigned int>);
	void Draw();
	void Init();

private:
	GLuint VAOid;
	GLuint VBOid;
	GLuint VEOid;
};
