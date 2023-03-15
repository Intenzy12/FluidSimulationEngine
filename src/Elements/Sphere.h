#include "Elements/Element.h"

class Sphere: public Element 
{
public:
	Sphere(int resolution, int shaderId): Element(resolution, shaderId) {}
	~Sphere() {}

	virtual void init() override;

private:
	
};
