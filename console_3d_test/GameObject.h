#pragma once
class GameObject
{
protected:
	float _positionX;
	float _positionY;
	float _collision_radius;
	
public:
	static const float max_collision_radius;
	static const float pi;

	GameObject(float positionX, float positionY, const Map& map, float colision_radius);

	void SetPosition(float x, float y, const Map& map);
	void SetCollision_radius(float collision_radius);

	float GetPosition_X() const;
	float GetPosition_Y() const;
	float GetCollision_radius() const;

	virtual ~GameObject() = 0 {};
};

