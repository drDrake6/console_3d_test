#include "Headers.h"

const int Player::max_Inventory_size = 10;

Player::Player(float x, float y, float collision_radius, float render_area, 
	float conor_of_view, float view_position_increment, float view_position, 
	float rotation_speed, float walk_speed, float deceleration, float exeleration, 
	Map& map, char symbol, int HP) : Entity(x, y, collision_radius, render_area, 
	conor_of_view, view_position_increment, view_position, rotation_speed, walk_speed, 
	deceleration, exeleration, map, symbol, HP)
{	
}

bool Player::Controle(Map& map, FPS& _fps, GameSpace& gameSpace)
{
	float walk_speed;

	if (GetAsyncKeyState((unsigned short)BUTTONS::SHIFT))
	{
		walk_speed = _exeleration;
	}
	else
	{
		walk_speed = _walk_speed;
	}

	float collision_radius = _collision_distance;	
	float current_view_conor = _conor_of_view / 2 + _view_position;
	float front_X_incriment = cosf(current_view_conor) * 0.1f * walk_speed * _fps.GetFPS();
	float front_Y_incriment = sinf(current_view_conor) * 0.1f * walk_speed * _fps.GetFPS();
	float side_X_incriment = cosf(_view_position + (90.0f - _conor_of_view) * 2.0f) * 0.1f * walk_speed * _fps.GetFPS();
	float side_Y_incriment = sinf(_view_position + (90.0f - _conor_of_view) * 2.0f) * 0.1f * walk_speed * _fps.GetFPS();	

	if (GetAsyncKeyState((unsigned short)BUTTONS::LEFT) & 0x8000)
	{
		if (_view_position + _view_position_increment * _rotation_speed * _fps.GetFPS() >= pi * 2)
			_view_position = _view_position + _view_position_increment * _rotation_speed * _fps.GetFPS() - pi * 2;
		else
			_view_position += _view_position_increment * _rotation_speed * _fps.GetFPS();
	}
	if (GetAsyncKeyState((unsigned short)BUTTONS::RIGHT) & 0x8000)
	{
		if (_view_position - _view_position_increment * _rotation_speed * _fps.GetFPS() < 0)
			_view_position = _view_position_increment * _rotation_speed * _fps.GetFPS() + pi * 2;
		else
			_view_position -= _view_position_increment * _rotation_speed * _fps.GetFPS();
	}

	if (GetAsyncKeyState((unsigned short)BUTTONS::W) ||
		GetAsyncKeyState((unsigned short)BUTTONS::A) ||
		GetAsyncKeyState((unsigned short)BUTTONS::S) ||
		GetAsyncKeyState((unsigned short)BUTTONS::D))
	{
		if ((GetAsyncKeyState((unsigned short)BUTTONS::W) & 0x8000)
			&& (GetAsyncKeyState((unsigned short)BUTTONS::A) & 0x8000))
		{
			if (map[_positionX + (front_X_incriment + side_X_incriment) / 2]
				[_positionY + (front_Y_incriment + side_Y_incriment) / 2] == '#')
			{
				if (map[_positionX + front_X_incriment][_positionY] != '#')
				{
					_positionX += front_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY + front_Y_incriment] != '#')
				{
					_positionY += front_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX += (front_X_incriment + side_X_incriment) / 2;
				_positionY += (front_Y_incriment + side_Y_incriment) / 2;
			}
		}
		else if ((GetAsyncKeyState((unsigned short)BUTTONS::S) & 0x8000)
			&& (GetAsyncKeyState((unsigned short)BUTTONS::D) & 0x8000))
		{
			if (map[_positionX - (front_X_incriment + side_X_incriment) / 2]
				[_positionY - (front_Y_incriment + side_Y_incriment) / 2] == '#')
			{
				if (map[_positionX - front_X_incriment][_positionY] != '#')
				{
					_positionX -= front_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY - front_Y_incriment] != '#')
				{
					_positionY -= front_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX -= (front_X_incriment + side_X_incriment) / 2;
				_positionY -= (front_Y_incriment + side_Y_incriment) / 2;
			}
		}
		else if ((GetAsyncKeyState((unsigned short)BUTTONS::W) & 0x8000)
			&& (GetAsyncKeyState((unsigned short)BUTTONS::D) & 0x8000))
		{
			if (map[_positionX + (front_X_incriment - side_X_incriment) / 2]
				[_positionY + (front_Y_incriment - side_Y_incriment) / 2] == '#')
			{
				if (map[_positionX + front_X_incriment][_positionY] != '#')
				{
					_positionX += front_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY + front_Y_incriment] != '#')
				{
					_positionY += front_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX += (front_X_incriment - side_X_incriment) / 2;
				_positionY += (front_Y_incriment - side_Y_incriment) / 2;
			}
		}
		else if ((GetAsyncKeyState((unsigned short)BUTTONS::A) & 0x8000)
			&& (GetAsyncKeyState((unsigned short)BUTTONS::S) & 0x8000))
		{
			if (map[_positionX - (front_X_incriment - side_X_incriment) / 2]
				[_positionY - (front_Y_incriment - side_Y_incriment) / 2] == '#')
			{
				if (map[_positionX - front_X_incriment][_positionY] != '#')
				{
					_positionX -= front_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY - front_Y_incriment] != '#')
				{
					_positionY -= front_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX -= (front_X_incriment - side_X_incriment) / 2;
				_positionY -= (front_Y_incriment - side_Y_incriment) / 2;
			}
		}
		else if (GetAsyncKeyState((unsigned short)BUTTONS::W) & 0x8000)
		{
			if (map[_positionX + front_X_incriment][_positionY + front_Y_incriment] == '#')
			{
				if (map[_positionX + front_X_incriment][_positionY] != '#')
				{
					_positionX += front_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY + front_Y_incriment] != '#')
				{
					_positionY += front_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX += front_X_incriment;
				_positionY += front_Y_incriment;
			}
		}
		else if (GetAsyncKeyState((unsigned short)BUTTONS::A))
		{
			if (map[_positionX + side_X_incriment][_positionY + side_Y_incriment] == '#')
			{
				if (map[_positionX + side_X_incriment][_positionY] != '#')
				{
					_positionX += side_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY + side_Y_incriment] != '#')
				{
					_positionY += side_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX += side_X_incriment;
				_positionY += side_Y_incriment;
			}
		}
		else if (GetAsyncKeyState((unsigned short)BUTTONS::S) & 0x8000)
		{
			if (map[_positionX - front_X_incriment][_positionY - front_Y_incriment] == '#')
			{
				if (map[_positionX - front_X_incriment][_positionY] != '#')
				{
					_positionX -= front_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY - front_Y_incriment] != '#')
				{
					_positionY -= front_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX -= front_X_incriment;
				_positionY -= front_Y_incriment;
			}
		}

		else if (GetAsyncKeyState((unsigned short)BUTTONS::D) & 0x8000)
		{
			if (map[_positionX - side_X_incriment][_positionY - side_Y_incriment] == '#')
			{
				if (map[_positionX - side_X_incriment][_positionY] != '#')
				{
					_positionX -= side_X_incriment * _deceleration;
				}
				else if (map[_positionX][_positionY - side_Y_incriment] != '#')
				{
					_positionY -= side_Y_incriment * _deceleration;
				}
			}
			else
			{
				_positionX -= side_X_incriment;
				_positionY -= side_Y_incriment;
			}
		}

		PicItem(gameSpace);
	}
	if (GetAsyncKeyState((unsigned short)BUTTONS::Ecs))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool Player::PutItemToInventory(Item* item)
{
	if (Inventory.size() + 1 <= max_Inventory_size)
	{
		Inventory.push_back(item);
		return true;
	}
	else
	{
		return false;
	}
}

void Player::DropItem(Map& map, GameSpace& gameSpace)
{
	float current_view_conor = _conor_of_view / 2 + _view_position;

	float drop_distanceX = cosf(current_view_conor) * 0.51f;
	float drop_distanceY = sinf(current_view_conor) * 0.51f;

	if (map[drop_distanceX][drop_distanceY] == '#')
		return;

	auto it = Inventory.begin();
	advance(it, current_item);	

	(*it)->SetPosition(drop_distanceX, drop_distanceY, map);
	gameSpace.AddObject(*it);
	Inventory.erase(it);
}

void Player::PicItem(GameSpace& gameSpace)
{
	int index = gameSpace.FindObjectByCollision(_positionX, _positionY);
	Item* item = dynamic_cast<Item*>(gameSpace.TakeObject(index));
	if (item)
	{
		if(PutItemToInventory(item))
			gameSpace.DeleteObject(index);
	}	
}

int Player::GetInventorySize() const
{
	return Inventory.size();
}
