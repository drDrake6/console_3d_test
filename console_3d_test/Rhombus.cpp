#include "Headers.h"

Rhombus::Rhombus()
{
}

Rhombus::Rhombus(float positionX, float positionY, const Map& map, 
	float collision_area, float render_area) : Item('X', positionX,
		positionY, map, collision_area, render_area)
{
}

void Rhombus::Initialize(float positionX, float positionY, const Map& map, float collision_area, float render_area)
{
	GameObject::Init(positionX, positionY, map, collision_area, render_area);
	_symbol = 'X';
}
