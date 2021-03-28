#include "Headers.h"

TrianDoor::TrianDoor()
{
}

TrianDoor::TrianDoor(float positionX, float positionY, const Map& map,
	float collision_area, float render_area, bool IsParallelToX_) : Door('^',
		positionX, positionY, map, collision_area, render_area, IsParallelToX_)
{
}

void TrianDoor::Initialize(float positionX, float positionY, const Map& map,
	float collision_area, bool IsParallelToX)
{
	BuildInit('^', positionX, positionY, map,
		collision_area, IsParallelToX);
}