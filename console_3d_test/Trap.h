#pragma once
class Trap : public Building
{
protected:
	float _damage;
public:
	Trap();
	Trap(char symbol, float positionX, float positionY, const Map& map,
		float collision_area, float render_area, bool IsParallelToX_, float damage);

	float GetDamage() const;

	virtual ~Trap() = 0 {};
};

