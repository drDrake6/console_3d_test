#include "Headers.h"

void GameSpace::AddItem(GameObject* item)
{
	_objects.push_back(item);
}

GameObject* GameSpace::FindItemByRander(float x, float y) const
{
	for (auto i : _objects)
	{
		if (i->InRenderArea(x, y))
			return i;	
	}

	return nullptr;
}

int GameSpace::FindItemByCollision(float x, float y) const
{
	for (auto i = _objects.begin(); i != _objects.end(); i++)
	{
		if ((*i)->InCollisionArea(x, y))
			return (i - _objects.begin());
	}

	return -1;
}

GameObject* GameSpace::TakeItem(int index)
{
	if (index < 0 || index >= _objects.size())
		throw out_of_range("out of game objects");

	return _objects[index];
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
