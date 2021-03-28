#include "Headers.h"

Bilding::Bilding()
{
	_symbol = 0;
	width = 0;
}

Bilding::Bilding(char symbol, float positionX, float positionY, const Map& map,
	float collision_area, bool IsParallelToX)
{
	_symbol = symbol;
	SetCollision_distanse(collision_area);
	_IsParallelToX = IsParallelToX;
	SetPosition(map);
}

float Bilding::GetWidth() const
{
	return width;
}

void Bilding::BuildInit(char symbol, float positionX, float positionY, const Map& map, float collision_area, bool IsParallelToX)
{
	GameObject::SetPosition(positionX, positionY, map);
	SetCollision_distanse(collision_area);
	_symbol = symbol;
	_IsParallelToX = IsParallelToX;
	SetPosition(map);
}

bool Bilding::InRenderArea(float x, float y) const
{
	if (x >= _positionX - _render_area &&
		x <= _positionX + _render_area &&
		y >= _positionY - width &&
		y <= _positionY + width)
		return true;
	else
		return false;
}

bool Bilding::InCollisionArea(float x, float y) const
{
	if (_IsParallelToX)
	{
		if (_positionY - trunc(_positionY) < 0.5f)
		{
			if (pow((x - _positionX), 2) <= -0.25f * (y - _positionY - 1)
				&& y >= _positionY - 0.05)
				return true;
			else
				return false;
		}
		else
		{
			if (pow((x - _positionX), 2) <= 0.25f * (y - _positionY + 1)
				&& y <= _positionY + 0.05)
				return true;
			else
				return false;
		}
	}
	else
	{
		if (_positionX - trunc(_positionX) < 0.5f)
		{
			if (pow((y - _positionY), 2) <= -0.25f * (x - _positionX - 1)
				&& x >= _positionX - 0.05)
				return true;
			else
				return false;
		}
		else
		{
			if (pow((y - _positionY), 2) <= 0.25f * (x - _positionX + 1)
				&& x <= _positionX + 0.05f)
				return true;
			else
				return false;
		}
	}
	
}

bool Bilding::IsParallelToX()
{
	return _IsParallelToX;
}

void Bilding::Reverse(const Map& map)
{
	_IsParallelToX = !_IsParallelToX;

	SetPosition(map);
}

void Bilding::SetPosition(const Map& map)
{
	if (_IsParallelToX)
	{
		_render_area = 0.5f;
		width = 0.05f;
		if (_positionY - trunc(_positionY) <= 0.5f)
			GameObject::SetPosition(trunc(_positionX) + 0.5f, trunc(_positionY)
				+ 0.05f, map);
		else
			GameObject::SetPosition(trunc(_positionX) + 0.5f, trunc(_positionY)
				+ 0.95f, map);
	}
	else
	{
		_render_area = 0.05f;
		width = 0.5;
		if (_positionX - trunc(_positionX) <= 0.5f)
			GameObject::SetPosition(trunc(_positionX) + 0.05, trunc(_positionY) + 0.5f, map);
		else
			GameObject::SetPosition(trunc(_positionX) + 0.95, trunc(_positionY) + 0.5f, map);
	}
}
