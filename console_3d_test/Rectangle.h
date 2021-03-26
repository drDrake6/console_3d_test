#pragma once
class Rect : public Item
{
public:
	Rect();
	Rect(float positionX, float positionY, const Map& map,
		float collision_area, float render_area);

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override;
};

