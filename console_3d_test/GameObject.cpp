#include "Headers.h"

const float GameObject::max_collision_distance = 0.49f;
const float GameObject::max_render_area = 0.49f;
const float GameObject::pi = 3.1415926f;

GameObject::GameObject()
{
	_positionX = 0;
	_positionY = 0;
	_collision_distance = 0;
	_render_area = 0;
}

GameObject::GameObject(float x, float y, const Map& map, float collision_area, float render_area, char symbol)
{
	SetPosition (x, y, map);
	SetCollision_distanse(collision_area);
	SetRender_area(render_area);
	_symbol = symbol;
}

void GameObject::Initialise(float x, float y, const Map& map, float collision_area, float render_area, char symbol)
{
	SetPosition(x, y, map);
	SetCollision_distanse(collision_area);
	SetRender_area(render_area);
	_symbol = symbol;
}

void GameObject::SetPosition(float x, float y, const Map& map)
{
	if (x > 0 && x < map.GetHeight() &&
		y > 0 && y < map.GetWidth() &&
		map[x][y] != '#')
	{
		_positionX = x;
		_positionY = y;
	}
	else
	{
		throw PositionError("impermissible position");
	}
}

void GameObject::SetCollision_distanse(float collision_area)
{
	if (collision_area > 0 && collision_area <= max_collision_distance)
	{
		_collision_distance = collision_area;
	}
	else
	{
		_collision_distance = 0.475f;
	}
}

void GameObject::SetRender_area(float render_area)
{
	if (render_area > 0 && render_area <= max_render_area)
	{
		_render_area = render_area;
	}
	else
	{
		_render_area = 0.475f;
	}
}

float GameObject::GetPosition_X() const
{
	return _positionX;
}

float GameObject::GetPosition_Y() const
{
	return _positionY;
}

float GameObject::GetCollision_distanse() const
{
	return _collision_distance;
}

float GameObject::GetRender_area() const
{
	return _render_area;
}

char GameObject::GetSymbol() const
{
	return _symbol;
}
