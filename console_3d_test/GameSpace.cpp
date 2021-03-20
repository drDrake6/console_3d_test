#include "Headers.h"

void GameSpace::AddItem(Item& item)
{
	_items.emplace(pair<float, float>(item.GetPosition_X(), 
		item.GetPosition_Y()), item);
}

Item& GameSpace::FindItem(float x, float y)
{
	return _items.find({ x, y })->second;
}

Item& GameSpace::TakeItem(float x, float y)
{
	auto i = _items.find({ x, y });
	_items.erase(i);
	return i->second;
}
