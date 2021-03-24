#pragma once
class GameObject
{
protected:
	char _symbol;
	float _positionX;
	float _positionY;
	float _collision_distance;
	float _render_area;
	
public:
	static const float max_collision_distance;
	static const float max_render_area;
	static const float pi;

	GameObject();
	GameObject(float positionX, float positionY, const Map& map, float collision_area, 
		float render_area, char symbol);

	void Initialise(float positionX, float positionY, const Map& map, float collision_area,
		float render_area, char symbol);
	void SetPosition(float x, float y, const Map& map);
	void SetCollision_distanse(float collision_area);
	void SetRender_area(float render_area);

	float GetPosition_X() const;
	float GetPosition_Y() const;
	float GetCollision_distanse() const;
	float GetRender_area() const;
	char GetSymbol() const;

	virtual bool InRenderArea(float x, float y) const = 0;
	virtual bool InCollisionArea(float x, float y) const = 0;

	virtual ~GameObject() = 0 {};
};

