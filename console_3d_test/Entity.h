#pragma once
class Entity : public GameObject
{
protected:
	float _conor_of_view;
	float _view_position_increment;
	float _view_position;
	float _rotation_speed;
	float _walk_speed;
	float _deceleration;
	float _exeleration;
	int _HP;
public:

	Entity(float x, float y, float collision_distanse, float render_area, 
		float conor_of_view, float view_position_increment, float view_position, 
		float rotation_speed, float walk_speed, float deceleration, float exeleration, 
		Map& map, char symbol, int HP);
	void SetConorOfView(float conor_of_view);
	void SetViewPositionIncrement(float view_position_increment);
	void SetViewPosition(float view_position);
	void SetRotationSpeed(float rotation_speed);
	void SetWalkSpeed(float walk_speed);
	void SetDeceleration(float deceleration);
	void SetExeleration(float exeleration);
	void SetHP(int HP);

	float GetConorOfView() const;
	float GetView_Position() const;

	bool InRenderArea(float x, float y) const override;
	bool InCollisionArea(float x, float y) const override;

	virtual bool Controle(Map& map, FPS& _fps, GameSpace& gameSpace) = 0;
	virtual ~Entity() = 0 {};
};

