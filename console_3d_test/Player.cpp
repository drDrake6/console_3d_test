#include "Headers.h"

const int Player::max_Inventory_size = 10;

Player::Player(float x, float y, float collision_radius, float render_area, 
	float conor_of_view, float view_position_increment, float view_position, 
	float rotation_speed, float walk_speed, float deceleration, float exeleration, 
	Map& map, char symbol, float HP) : Entity(x, y, collision_radius, render_area, 
	conor_of_view, view_position_increment, view_position, rotation_speed, walk_speed, 
	deceleration, exeleration, map, symbol, HP)
{	
	current_item = 0;
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
	float front_X_incriment = cosf(current_view_conor) * 0.1f * walk_speed * _fps.GetSecondsPerFrame();
	float front_Y_incriment = sinf(current_view_conor) * 0.1f * walk_speed * _fps.GetSecondsPerFrame();
	float side_X_incriment = cosf(_view_position + (90.0f - _conor_of_view) * 2.0f) * 0.1f * walk_speed * _fps.GetSecondsPerFrame();
	float side_Y_incriment = sinf(_view_position + (90.0f - _conor_of_view) * 2.0f) * 0.1f * walk_speed * _fps.GetSecondsPerFrame();	

	if (GetAsyncKeyState((unsigned short)BUTTONS::LEFT) & 0x8000)
	{
		if (_view_position + _view_position_increment * _rotation_speed * _fps.GetSecondsPerFrame() >= pi * 2)
			_view_position = _view_position + _view_position_increment * _rotation_speed * _fps.GetSecondsPerFrame() - pi * 2;
		else
			_view_position += _view_position_increment * _rotation_speed * _fps.GetSecondsPerFrame();
	}
	if (GetAsyncKeyState((unsigned short)BUTTONS::RIGHT) & 0x8000)
	{
		if (_view_position - _view_position_increment * _rotation_speed * _fps.GetSecondsPerFrame() < 0)
			_view_position = _view_position_increment * _rotation_speed * _fps.GetSecondsPerFrame() + pi * 2;
		else
			_view_position -= _view_position_increment * _rotation_speed * _fps.GetSecondsPerFrame();
	}

	if (IsMoving())
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

	GetIntoTrap(gameSpace, _fps);

	if (GetAsyncKeyState((unsigned short)BUTTONS::Regeneration))
	{
		Regen();
	}

	if (GetAsyncKeyState((unsigned short)BUTTONS::Drop) & 0x1)
	{
		DropItem(map, gameSpace);
	}

	ChoseItem();

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
	for (size_t i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i] == nullptr)
		{
			Inventory[i] = item;
			return true;
		}
	}

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
	int size = Inventory.size() - 1;
	float current_view_conor = _conor_of_view / 2 + _view_position;

	float drop_distanceX = cosf(current_view_conor) * 1.0f;
	float drop_distanceY = sinf(current_view_conor) * 1.0f;

	if (map[_positionX + drop_distanceX][_positionY + drop_distanceY] == '#'
		|| size < current_item || Inventory[current_item] == nullptr)
		return;

	auto it = Inventory.begin() + current_item;
	(*it)->SetPosition(_positionX + drop_distanceX, _positionY + drop_distanceY, map);
	gameSpace.AddObject(*it);
	Inventory[current_item] = nullptr;
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

int Player::GetCurrentItemIndex() const
{
	return current_item;
}

Item*& Player::operator[](int index)
{
	return Inventory[index];
}

Item* Player::operator[](int index) const
{
	return Inventory[index];
}

void Player::ChoseItem()
{
	if (GetAsyncKeyState(VK_NUMPAD0) || GetAsyncKeyState(0x30) ||
		GetAsyncKeyState(VK_NUMPAD1) ||	GetAsyncKeyState(0x31) ||
		GetAsyncKeyState(VK_NUMPAD2) || GetAsyncKeyState(0x32) ||
		GetAsyncKeyState(VK_NUMPAD3) || GetAsyncKeyState(0x33) ||
		GetAsyncKeyState(VK_NUMPAD4) || GetAsyncKeyState(0x34) ||
		GetAsyncKeyState(VK_NUMPAD5) || GetAsyncKeyState(0x35) ||
		GetAsyncKeyState(VK_NUMPAD6) || GetAsyncKeyState(0x36) ||
		GetAsyncKeyState(VK_NUMPAD7) || GetAsyncKeyState(0x37) ||
		GetAsyncKeyState(VK_NUMPAD8) || GetAsyncKeyState(0x38) ||
		GetAsyncKeyState(VK_NUMPAD9) || GetAsyncKeyState(0x39))
	{
		if (GetAsyncKeyState(VK_NUMPAD0) || GetAsyncKeyState(0x31))
			current_item = 0;
		else if (GetAsyncKeyState(VK_NUMPAD1) || GetAsyncKeyState(0x32))
			current_item = 1;				  
		else if (GetAsyncKeyState(VK_NUMPAD2) || GetAsyncKeyState(0x33))
			current_item = 2;				 
		else if (GetAsyncKeyState(VK_NUMPAD3) || GetAsyncKeyState(0x34))
			current_item = 3;				
		else if (GetAsyncKeyState(VK_NUMPAD4) || GetAsyncKeyState(0x35))
			current_item = 4;				
		else if (GetAsyncKeyState(VK_NUMPAD5) || GetAsyncKeyState(0x36))
			current_item = 5;				 
		else if (GetAsyncKeyState(VK_NUMPAD6) || GetAsyncKeyState(0x37))
			current_item = 6;				
		else if (GetAsyncKeyState(VK_NUMPAD7) || GetAsyncKeyState(0x38))
			current_item = 7;				
		else if (GetAsyncKeyState(VK_NUMPAD8) || GetAsyncKeyState(0x39))
			current_item = 8;				
		else if (GetAsyncKeyState(VK_NUMPAD9) || GetAsyncKeyState(0x30))
			current_item = 9;
	}

}

bool Player::IsMoving() const
{
	if (GetAsyncKeyState((unsigned short)BUTTONS::W) ||
		GetAsyncKeyState((unsigned short)BUTTONS::A) ||
		GetAsyncKeyState((unsigned short)BUTTONS::S) ||
		GetAsyncKeyState((unsigned short)BUTTONS::D))
		return true;
	else
		return false;
}

void Player::Regen()
{
	for (auto i = Inventory.begin(); i != Inventory.end(); i++)
	{
		if ((*i) && (*i)->GetSymbol() == '+')
		{
			MedKit* mk = dynamic_cast<MedKit*>((*i));
			if (_HP == 100.0f)
			{
				return;
			}
			else if (_HP + mk->GetRegen() <= 100.0f)
			{
				_HP += mk->GetRegen();
			}			
			else
			{
				_HP = 100.0f;
			}
			(*i) = nullptr;
			return;
		}
	}
}
