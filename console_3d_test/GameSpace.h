#pragma once
class GameSpace
{
	map<pair<float, float>, Item&> _items;
public:
	void AddItem(Item& item);
	Item& FindItem(float x, float y);
	Item& TakeItem(float x, float y);
};

