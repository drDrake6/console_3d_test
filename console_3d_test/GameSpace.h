#pragma once

class GameSpace
{
	vector<GameObject*> _objects;
public:
	void AddObject(GameObject* item);
	void DeleteObject(int index);
	GameObject* FindObjectByRander(float x, float y) const;
	int FindObjectByCollision(float x, float y) const;
	GameObject* TakeObject(int index);
	GameObject* TakeObjectByCollision(float x, float y);
	int GetSize() const;
	GameObject*& operator[](int index);
	GameObject* operator[](int index) const;
};

