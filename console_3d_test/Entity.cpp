#include "Headers.h"

Entity::Entity(float x, float y, float collision_distanse, float render_area, 
	float conor_of_view, float view_position_increment, float view_position, 
	float walk_speed, float deceleration, float exeleration, Map& map,
	char symbol, int HP) : GameObject(x, y, map, collision_distanse, render_area, symbol)
{
	SetConorOfView(conor_of_view);
	SetViewPositionIncrement(view_position_increment);
	SetViewPosition(view_position);
	SetWalkSpeed(walk_speed);
	SetDeceleration(deceleration);
	SetExeleration(exeleration);
	SetHP(HP);
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

void Entity::SetHP(float HP)
{
	if (HP > 0 && HP <= 100)
		_HP = HP;
	else
		throw out_of_range("error, HP is too few or too big");
}

float Entity::GetHP() const
{
	return _HP;
}

void Entity::GetIntoTrap(GameSpace& gamespace, FPS& _fps)
{
	for (auto i = 0; i < gamespace.GetSize(); i++)
	{
		Trap* trap = dynamic_cast<Trap*>(gamespace[i]);
		if (trap && trap->InCollisionArea(_positionX, _positionY))
		{
			_HP -= (trap->GetDamage() * _fps.GetSecondsPerFrame());
		}
	}
}

bool Entity::CollideWithBuilding(float x, float y, GameSpace& gamespace)
{
	for (auto i = 0; i < gamespace.GetSize(); i++)
	{
		Building* building = dynamic_cast<Building*>(gamespace[i]);
		if (building && building->InRenderArea(x, y))
		{
			return true;
		}
	}

	return false;
}

float Entity::GetConorOfView() const
	{
		return _conor_of_view;
	}

	float Entity::GetView_Position() const
	{
		return _view_position;
	}

	bool Entity::InRenderArea(float x, float y) const
	{
		if (pow((x - _positionX), 2) + pow((y - _positionY), 2) <= pow(max_render_area, 2))
			return true;
		else
			return false;
	}

	bool Entity::InCollisionArea(float x, float y) const
	{
		if (x >= _positionX - _collision_distance &&
			x <= _positionX + _collision_distance &&
			y >= _positionY - _collision_distance &&
			y <= _positionY + _collision_distance)
			return true;
		else
			return false;
	}
