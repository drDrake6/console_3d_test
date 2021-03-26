#pragma once
class Triangle : public Item
{
public:
	Triangle();
	Triangle(float positionX, float positionY, const Map& map,
		float collision_area, float render_area);

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override;
};

