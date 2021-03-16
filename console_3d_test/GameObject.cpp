#include "Headers.h"

const float GameObject::max_collision_radius = 0.74f;
const float GameObject::pi = 3.1415926f;

GameObject::GameObject(float x, float y, const Map& map, float collision_radius)
{
	SetPosition (x, y, map);
	SetCollision_radius(collision_radius);
}

void GameObject::SetPosition(float x, float y, const Map& map)
{
	if (x > 0 && x < map.GetHeight() &&
		y > 0 && y < map.GetWidth() &&
		map[x][y] == ' ')
	{
		_positionX = x;
		_positionY = y;
	}
	else
	{
		_positionX = 1;
		_positionY = 1;
	}
}

void GameObject::SetCollision_radius(float collision_radius)
{
	if (collision_radius > 0 && collision_radius <= max_collision_radius)
	{
		_collision_radius = collision_radius;
	}
	else
	{
		_collision_radius = 0.475f;
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

float GameObject::GetCollision_radius() const
{
	return _collision_radius;
}
