#pragma once

class GameSpace
{
	vector<GameObject*> _objects;
public:
	void AddItem(GameObject* item);
	GameObject* FindItemByRander(float x, float y) const;
	int FindItemByCollision(float x, float y) const;
	GameObject* TakeItem(int index);
	int GetSize() const;
	GameObject*& operator[](int index);
	GameObject* operator[](int index) const;
};

