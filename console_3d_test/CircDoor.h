#pragma once
class CircDoor : public Door
{
public:
	CircDoor();
	CircDoor(float positionX, float positionY, const Map& map,
		float collision_area, float render_area, bool IsParallelToX_);

	void Initialize(float positionX, float positionY, const Map& map,
		float collision_area, bool IsParallelToX) override;


	~CircDoor() = default;
};

