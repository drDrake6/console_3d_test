#include "Headers.h"

Exit::Exit()
{
}

Exit::Exit(float positionX, float positionY, const Map& map,
	float collision_area, float render_area, bool IsParallelToX_) : Building('E',
		positionX, positionY, map, collision_area, IsParallelToX_)
{
}

void Exit::Initialize(float positionX, float positionY, const Map& map,
	float collision_area, bool IsParallelToX)
{
	BuildInit('E', positionX, positionY, map,
		collision_area, IsParallelToX);
}