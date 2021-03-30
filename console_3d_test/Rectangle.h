#pragma once
class Minimap : public Item
{
public:
	Minimap();
	Minimap(float positionX, float positionY, const Map& map,
		float collision_area, float render_area);

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override;
};

