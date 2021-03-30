#include "Headers.h"

Door::Door()
{
}

Door::Door(char symbol, float positionX, float positionY, const Map& map, 
	float collision_area, float render_area, bool IsParallelToX_) 
	: Building(symbol, positionX,  positionY, map, collision_area,
		IsParallelToX_)
{
}
