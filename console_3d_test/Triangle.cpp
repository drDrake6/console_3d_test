#include "Headers.h"

Triangle::Triangle()
{
}

Triangle::Triangle(float positionX, float positionY, const Map& map, float collision_area, 
	float render_area) : Item('^', positionX,
		positionY, map, collision_area, render_area)
{
}

void Triangle::Initialize(float positionX, float positionY, const Map& map, float collision_area, float render_area)
{
	GameObject::Init(positionX, positionY, map, collision_area, render_area);
	_symbol = '^';
}