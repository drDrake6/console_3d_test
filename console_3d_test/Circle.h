#pragma once
class Circle : public Item
{
public:
	Circle(float positionX, float positionY, const Map& map,
		float collision_area, float render_area);
};

