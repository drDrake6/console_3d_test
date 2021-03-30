#pragma once
class Door : public Building
{
public:
	Door();
	Door(char symbol, float positionX, float positionY, const Map& map,
		float collision_area, float render_area, bool IsParallelToX_);

	virtual ~Door() = 0 {};
};

