#include "Headers.h"

Triangle::Triangle()
{
}

Triangle::Triangle(float positionX, float positionY, const Map& map, float collision_area, 
	float render_area) : Item('^', positionX,
		positionY, map, collision_area, render_area)
{
}

void Triangle::InitialiseTriangle(float positionX, float positionY, const Map& map, float collision_area, float render_area)
{
	Initialise(positionX, positionY, map,
		collision_area, render_area, '^');
}
