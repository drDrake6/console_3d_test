#pragma once
class Item : public GameObject
{
protected:
	char symbol;

public:
	virtual void PrintLineOfObject(float Ray_size, int current_rays_amount) = 0;
	virtual ~Item() = 0 {};
};

