#pragma once
class Rhombus : public Item
{
public:
	Rhombus();
	Rhombus(float positionX, float positionY, const Map& map,
		float collision_area, float render_area);

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override;
};

