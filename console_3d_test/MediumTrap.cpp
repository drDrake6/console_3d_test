#include "Headers.h"

MediumTrap::MediumTrap()
{
}

MediumTrap::MediumTrap(float positionX, float positionY, const Map& map, 
	float collision_area, float render_area, bool IsParallelToX_) :
	Trap('T', positionX, positionY, map, collision_area, render_area,
		IsParallelToX_, 40.0f)
{
}

void MediumTrap::Initialize(float positionX, float positionY, const Map& map, float collision_area, bool IsParallelToX)
{
	BuildInit('T', positionX, positionY, map,
		collision_area, IsParallelToX);
	_damage = 40.0f;
}
