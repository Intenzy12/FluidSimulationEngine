#pragma once
#include "Core/Graphics/Mesh.h"

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
