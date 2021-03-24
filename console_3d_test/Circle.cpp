#include "Headers.h"

Circle::Circle()
{
}

Circle::Circle(float positionX, float positionY, const Map& map,
	float collision_area, float render_area) : Item('o',  positionX,  
		positionY, map, collision_area,  render_area)
{
}

void Circle::InitialiseCircle(float positionX, float positionY, const Map& map, float collision_area, float render_area)
{
	Initialise(positionX, positionY, map,
		collision_area, render_area, 'o');
}
