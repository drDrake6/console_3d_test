#pragma once
class Circle : public Item
{
public:
	Circle();
	Circle(float positionX, float positionY, const Map& map,
		float collision_area, float render_area);

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override;
};

