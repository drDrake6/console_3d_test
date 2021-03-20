#include "Headers.h"

Item::Item(char symbol, float positionX, float positionY, const Map& map, 
	float collision_area, float render_area) : GameObject(positionX, positionY, map,
		 collision_area,  render_area)
{
	_symbol = symbol;
}

char Item::GetSymbol() const
{
	return _symbol;
}

float Item::GetWidth() const
{
	return width;
}
