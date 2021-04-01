#include "Headers.h"

StrongTrap::StrongTrap()
{
}

StrongTrap::StrongTrap(float positionX, float positionY, const Map& map,
	float collision_area, float render_area, bool IsParallelToX_) :
	Trap('T', positionX, positionY, map, collision_area, render_area,
		IsParallelToX_, 60.0f)
{
}

void StrongTrap::Initialize(float positionX, float positionY, const Map& map, float collision_area, bool IsParallelToX)
{
	BuildInit('T', positionX, positionY, map,
		collision_area, IsParallelToX);
	_damage = 60.0f;
}