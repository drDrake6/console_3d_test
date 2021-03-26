#include "Headers.h"

void GameSpace::AddObject(GameObject* item)
{
	_objects.push_back(item);
}

GameObject* GameSpace::FindObjectByRander(float x, float y) const
{
	for (auto i : _objects)
	{
		if (i->InRenderArea(x, y))
			return i;	
	}

	return nullptr;
}

int GameSpace::FindObjectByCollision(float x, float y) const
{
	for (auto i = _objects.begin(); i != _objects.end(); i++)
	{
		if ((*i)->InCollisionArea(x, y))
			return (i - _objects.begin());
	}

	return -1;
}

GameObject* GameSpace::TakeObject(int index)
{
	if (index < 0 || index >= _objects.size())
		return nullptr;

	return _objects[index];
}

GameObject* GameSpace::TakeObjectByCollision(float x, float y)
{
	int index = FindObjectByCollision(x, y);
	return TakeObject(index);
}

void GameSpace::DeleteObject(int index)
{
	_objects.erase(_objects.begin() + index);
}

int GameSpace::GetSize() const
{
	return _objects.size();
}

GameObject*& GameSpace::operator[](int index)
{
	return _objects[index];
}

GameObject* GameSpace::operator[](int index) const
{
	return _objects[index];
}
