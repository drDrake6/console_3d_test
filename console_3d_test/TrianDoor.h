#pragma once
class TrianDoor : public Door
{
public:
	TrianDoor();
	TrianDoor(float positionX, float positionY, const Map& map,
		float collision_area, float render_area, bool IsParallelToX_);

	void Initialize(float positionX, float positionY, const Map& map,
		float collision_area, bool IsParallelToX) override;


	~TrianDoor() = default;
};

