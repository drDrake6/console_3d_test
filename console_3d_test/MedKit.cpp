#include "Headers.h"

MedKit::MedKit()
{
}

MedKit::MedKit(float positionX, float positionY, const Map& map, 
	float collision_area, float render_area) : Item('+', positionX,
		positionY, map, collision_area, render_area)
{
}

float MedKit::GetRegen() const
{
	return regen;
}

void MedKit::Initialize(float positionX, float positionY, const Map& map, 
	float collision_area, float render_area)
{
	GameObject::Init(positionX, positionY, map, collision_area, render_area);
	_symbol = '+';
}
