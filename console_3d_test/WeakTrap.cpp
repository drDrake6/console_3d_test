#include "Headers.h"

WeakTrap::WeakTrap()
{
}

WeakTrap::WeakTrap(float positionX, float positionY, 
const Map& map, float collision_area, float render_area, bool IsParallelToX_) :
	Trap('T', positionX, positionY, map, collision_area, render_area,
		IsParallelToX_, 5.0f)
{
}

void WeakTrap::Initialize(float positionX, float positionY, const Map& map, float collision_area, bool IsParallelToX)
{
	BuildInit('T', positionX, positionY, map,
		collision_area, IsParallelToX);
	_damage = 5.0f;
}
