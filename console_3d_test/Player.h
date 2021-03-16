#pragma once
#include "Map.h"
class Player final : public Entity
{
	enum class BUTTONS {LEFT = VK_LEFT, RIGHT = VK_RIGHT, W = 'W', A = 'A', S = 'S', D = 'D', Ecs = VK_ESCAPE, SHIFT = VK_LSHIFT};

public: 
	Player(float x, float y, float collision_radius, float conor_of_view, float view_position_increment,
		float view_position, float rotation_speed, float walk_speed, float deceleration,
		float exeleration, Map& map);

	virtual bool Controle(Map& map, FPS& _fps) override final;
};

