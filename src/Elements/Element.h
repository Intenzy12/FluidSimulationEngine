#pragma once
#include "Core/Graphics/Mesh.h"

std::ostream& operator<<(std::ostream& s, Vertex v);
std::ostream& operator<<(std::ostream& s, std::vector<Vertex> v);

class Element 
{
public:
	Element(int resolution, int shaderId): mShaderId(shaderId), mResolution(resolution) { mMesh.Init(); init();}
	virtual ~Element() {}

	virtual void draw() { mMesh.Draw(); }
protected:
	virtual void init() {}
		
	int mShaderId;
	int mResolution;
	Mesh mMesh;
};
