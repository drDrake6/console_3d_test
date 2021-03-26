#include "Headers.h"

Circle::Circle()
{
}

Circle::Circle(float positionX, float positionY, const Map& map,
	float collision_area, float render_area) : Item('o',  positionX,  
		positionY, map, collision_area,  render_area)
{
}

void Circle::Initialize(float positionX, float positionY, const Map& map, float collision_area, float render_area)
{
	GameObject::Init(positionX, positionY, map, collision_area, render_area);
	_symbol = 'o';
}
