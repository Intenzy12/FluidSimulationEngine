#include "Core/Graphics/Mesh.h"
#include "Core/Error.h"
#include <cstddef>

Mesh::Mesh() {
	glGenVertexArrays(1, &VAOid);
	glGenBuffers(1, &VBOid);
	glGenBuffers(1, &VEOid);

	if (!VAOid || !VBOid || !VEOid)
	{
		FatalError("Failed to generate Buffers");
	}

	glBindVertexArray(VAOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VEOid);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, Position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, TexCoords));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
}

Mesh::~Mesh() {}

void Mesh::Draw()
{
	glBindVertexArray(VAOid);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, (void*)0);
	glBindVertexArray(0);
}

void Mesh::SetData(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
	SetIndices(indices);
	SetVertices(vertices);
}

void Mesh::SetVertices(std::vector<Vertex> vertices)
{
	this->vertices = vertices;
	glBindVertexArray(VAOid);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	glBindVertexArray(0);
}

void Mesh::SetIndices(std::vector<unsigned int> indices)
{
	this->indices = indices;
	glBindVertexArray(VAOid);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	glBindVertexArray(0);
}
