#pragma once
class Item : public GameObject
{
protected:
	char _symbol;
	float width = 0.05f;

public:
	Item(char symbol, float positionX, float positionY, const Map& map, 
		float collision_area, float render_area);

	char GetSymbol() const;
	float GetWidth() const;
	virtual ~Item() = 0 {};
};

