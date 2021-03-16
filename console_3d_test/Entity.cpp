#include "Headers.h"

Entity::Entity(float x, float y, float collision_radius, float conor_of_view,
	float view_position_increment, float view_position, float rotation_speed,
	float walk_speed, float deceleration, float exeleration, Map& map) 
	: GameObject(x, y, map, collision_radius)
{
	SetConorOfView(conor_of_view);
	SetViewPositionIncrement(view_position_increment);
	SetViewPosition(view_position);
	SetRotationSpeed(rotation_speed);
	SetWalkSpeed(walk_speed);
	SetDeceleration(deceleration);
	SetExeleration(exeleration);
}

void Entity::SetConorOfView(float conor_of_view)
{
	if (conor_of_view >= 45 && conor_of_view <= 100)
	{
		_conor_of_view = (conor_of_view * pi) / 180;
	}
	else
	{
		_conor_of_view = (60.0f * pi) / 180;
	}
}

void Entity::SetViewPositionIncrement(float view_position_increment)
{
	if (view_position_increment > 0 && view_position_increment < 360)
	{
		_view_position_increment = view_position_increment;
	}
	else
	{
		_view_position_increment = 1.5;
	}
}

void Entity::SetViewPosition(float view_position)
{
	if (view_position >= 0 && view_position < 360)
	{
		_view_position = (view_position * pi) / 180;
	}
	else
	{
		_view_position = (60.0f * pi) / 180;
	}
}

void Entity::SetRotationSpeed(float rotation_speed)
{
	if (rotation_speed > 0 && rotation_speed <= 10)
	{
		_rotation_speed = rotation_speed;
	}
	else
	{
		_rotation_speed = 1.0f;
	}
}

void Entity::SetWalkSpeed(float walk_speed)
{
	if (walk_speed > 0 && walk_speed <= 100)
	{
		_walk_speed = walk_speed;
	}
	else
	{
		_walk_speed = 30.0f;
	}
}

void Entity::SetDeceleration(float deceleration)
{
	if (deceleration > 0 && deceleration < 1)
	{
		_deceleration = deceleration;
	}
	else
	{
		_deceleration = 0.25;
	}

}

void Entity::SetExeleration(float exeleration)
{
	if (exeleration > 0 && exeleration < 10)
	{
		_exeleration = exeleration * _walk_speed;
	}
	else
	{
		_exeleration = 2.0 * _walk_speed;
	}
}

	float Entity::GetConorOfView()
	{
		return _conor_of_view;
	}

	float Entity::GetView_Position()
	{
		return _view_position;
	}
