#pragma once
class MedKit : public Item
{
	float regen = 50.0f;

public:
	MedKit();
	MedKit(float positionX, float positionY, const Map& map,
		float collision_area, float render_area);
	float GetRegen() const;

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override;
};

