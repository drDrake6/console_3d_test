#include "Headers.h"

Rhombus::Rhombus()
{
}

Rhombus::Rhombus(float positionX, float positionY, const Map& map, 
	float collision_area, float render_area) : Item('X', positionX,
		positionY, map, collision_area, render_area)
{
}

void Rhombus::InitialiseRhombus(float positionX, float positionY, const Map& map, float collision_area, float render_area)
{
	Initialise(positionX, positionY, map,
		collision_area, render_area, 'X');
}
