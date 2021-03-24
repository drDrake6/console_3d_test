#include "Headers.h"

Item::Item()
{
	_symbol = 0;
}

Item::Item(char symbol, float positionX, float positionY, const Map& map,
	float collision_area, float render_area) : GameObject(positionX, positionY, map,
		 collision_area,  render_area, symbol)
{
}

float Item::GetWidth() const
{
	return width;
}

bool Item::InRenderArea(float x, float y) const
{
	if (x >= _positionX - _render_area &&
		x <= _positionX + _render_area &&
		y >= _positionY - width &&
		y <= _positionY + width)
		return true;
	else
		return false;
}

bool Item::InCollisionArea(float x, float y) const
{
	if (pow((x - _positionX), 2) + pow((y - _positionY), 2) <= pow(_collision_distance, 2))
		return true;
	else
		return false;
}
