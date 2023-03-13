#pragma once

#include "Elements/Element.h"

class Plane: public Element
{
public:
	Plane(int resolution, int shaderId): Element(resolution, shaderId) { init(); }
	~Plane() { }

protected:
	virtual void init() override;
};
