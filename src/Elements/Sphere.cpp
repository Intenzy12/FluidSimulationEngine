#include "Elements/Sphere.h"
#include "Core/MathConstants.h"
#include <math.h>

void Sphere::init()
{
	std::vector<unsigned int> indices = std::vector<unsigned int>();
	std::vector<Vertex> vertices = std::vector<Vertex>();
	long double deltaAngle = (long double) 1.0 / (mResolution + 4);
	
	Vertex vert;
	vert.Position = glm::vec3(0.0f, 0.0f, 1.0f);
	vert.TexCoords = glm::vec2(0.0f, 1.0f);
	vertices.push_back(vert);

	vert.Position = glm::vec3(0.0f, 0.0f, -1.0f);
	vert.TexCoords = glm::vec2(0.0f, -1.0f);
	vertices.push_back(vert);

	for(int  j = 1; j <= mResolution; ++j)
	{
		for(int i = 0; i < mResolution + 3; ++i)
		{
			long double theta = deltaAngle * i;
			long double alpha = deltaAngle * j;

			vert.Position.x = sin(theta*PI_F15*2) * sin(alpha*PI_F15*2);
			vert.Position.y = cos(theta*PI_F15*2) * sin(alpha*PI_F15*2);
			vert.Position.z = cos(alpha*PI_F15*2);

			vert.TexCoords = {theta, alpha};

			vertices.push_back(vert);
		}
	}

	for(int i = 0; i < mResolution + 3; ++i)
	{
		indices.push_back(1);
		indices.push_back(2 + i);
		indices.push_back(2 + (i + 1) % (mResolution + 3));

		indices.push_back(0);
		indices.push_back(vertices.size() - mResolution - 3 + i);
		indices.push_back(vertices.size() - mResolution - 3 + (i + 1) % (mResolution + 3));
	}

	for(int i = 0; i < mResolution - 1; ++i)
	{
		for(int j = 0; j < mResolution + 3; ++j)
		{
			int h = (j + 1) % (mResolution + 3);
			int rows = mResolution + 3;
			indices.push_back(2 + i*rows + j);
			indices.push_back(2 + i*rows + h);
			indices.push_back(2 + i * rows + j + rows);

			indices.push_back(2 + i*rows + h);
			indices.push_back(2 + i*rows + h + rows);
			indices.push_back(2 + i * rows + j + rows);
		}
	}

	mMesh.SetData(vertices, indices);
};

