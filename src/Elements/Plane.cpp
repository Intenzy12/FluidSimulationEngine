#include "Elements/Plane.h"
#include "Core/Graphics/Mesh.h"
#include <ostream>

std::ostream& operator<<(std::ostream& s, std::vector<unsigned int> j)
{
	for(int i = 0; i + 2 < (int) j.size(); ++i)
	{
		s << "{ " << j[i] << ", " << j[i+1] << ", " << j[i+2] << " }\n";
	}
	return s;
}

std::ostream& operator<<(std::ostream& s, Vertex v)
{
	s << "{\n   Position: {\n      x: " << v.Position.x << "\n      y: " << v.Position.y << "\n      z: " << v.Position.z << "\n   }\n   TextCoord: {\n      x: " << v.TexCoords.x << "\n      y: " << v.TexCoords.y << "\n   }\n}";
	return s;
}

std::ostream& operator<<(std::ostream& s, std::vector<Vertex> v) {
	for (auto a : v)
	{
		s << a << '\n';
	}
	return s;
}

void Plane::init() {
	std::vector<unsigned int> indices = std::vector<unsigned int>();
	std::vector<Vertex> vertices = std::vector<Vertex>();
	vertices.reserve(mResolution * mResolution + 1 + 2*mResolution);
	indices.reserve(mResolution*mResolution*2*3);

	for (int i = 0; i <= mResolution; ++i)
	{
		for(int j = 0; j <= mResolution; ++j)
		{
			Vertex a;
			a.Position = {j*2.0/mResolution - 1.0, i*2.0/mResolution - 1.0, 0.0};
			a.TexCoords = { (float) j / mResolution, (float) i / mResolution };
			vertices.push_back(a);
		}
	}

	for(int i = 0; i < mResolution; ++i)
	{
		for(int j = 0; j < mResolution; ++j)
		{
			int topleft = i*mResolution + j;
			int bottomleft = topleft + mResolution + 1;
			int topright = topleft + 1;
			int bottomright = bottomleft + 1;
			indices.push_back(topleft);
			indices.push_back(topright);
			indices.push_back(bottomleft);
			indices.push_back(bottomleft);
			indices.push_back(topright);
			indices.push_back(bottomright);
		}
	}
	
	std::cout << vertices << '\n';

	mMesh.SetData(vertices, indices);
}
