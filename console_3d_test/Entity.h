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
public:

	Entity(float x, float y, float collision_distanse, float render_area, float conor_of_view, float view_position_increment,
		float view_position, float rotation_speed, float walk_speed, float deceleration, float exeleration, Map& map);
	void SetConorOfView(float conor_of_view);
	void SetViewPositionIncrement(float view_position_increment);
	void SetViewPosition(float view_position);
	void SetRotationSpeed(float rotation_speed);
	void SetWalkSpeed(float walk_speed);
	void SetDeceleration(float deceleration);
	void SetExeleration(float exeleration);

	float GetConorOfView();
	float GetView_Position();

	virtual bool Controle(Map& map, FPS& _fps) = 0;
	virtual ~Entity() = 0 {};
};

