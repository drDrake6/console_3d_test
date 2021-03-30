#include "Headers.h"

Minimap::Minimap()
{
}

Minimap::Minimap(float positionX, float positionY, const Map& map,
	float collision_area, float render_area) : Item('=', positionX,
		positionY, map, collision_area, render_area)
{
}

void Minimap::Initialize(float positionX, float positionY, const Map& map, 
	float collision_area, float render_area)
{
	GameObject::Init(positionX, positionY, map, collision_area, render_area);
	_symbol = '=';
}
