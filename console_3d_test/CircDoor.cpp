#include "Headers.h"

CircDoor::CircDoor()
{
}

CircDoor::CircDoor(float positionX, float positionY, const Map& map, 
	float collision_area, float render_area, bool IsParallelToX_) : Door('o', 
	positionX, positionY, map, collision_area,  render_area, IsParallelToX_)
{
}

void CircDoor::Initialize(float positionX, float positionY, const Map& map, 
	float collision_area, bool IsParallelToX)
{
	BuildInit('o', positionX, positionY, map,
		collision_area, IsParallelToX);
}
