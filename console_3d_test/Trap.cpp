#include "Headers.h"

Trap::Trap()
{
}

Trap::Trap(char symbol, float positionX, float positionY,const Map& map,
	float collision_area, float render_area, bool IsParallelToX_, float damage)
	: Building(symbol, positionX, positionY, map, collision_area, IsParallelToX_)
{
	_damage = damage;
}

float Trap::GetDamage() const
{
	return _damage;
}
