#include "Headers.h"

RombDoor::RombDoor()
{
}

RombDoor::RombDoor(float positionX, float positionY, const Map& map,
	float collision_area, float render_area, bool IsParallelToX_) : Door('X',
		positionX, positionY, map, collision_area, render_area, IsParallelToX_)
{
}

void RombDoor::Initialize(float positionX, float positionY, const Map& map,
	float collision_area, bool IsParallelToX)
{
	BuildInit('X', positionX, positionY, map,
		collision_area, IsParallelToX);
}