#pragma once
class Item : public GameObject
{
protected:
	float width = 0.05f;

public:
	Item();
	Item(char symbol, float positionX, float positionY, const Map& map, 
		 float collision_area, float render_area);

	float GetWidth() const;
	bool InRenderArea(float x, float y) const override;
	bool InCollisionArea(float x, float y) const override;

	virtual ~Item() = 0 {};
};

