#pragma once
#include "Map.h"
class Player final : public Entity
{
	enum class BUTTONS 
	{
		LEFT = VK_LEFT, 
		RIGHT = VK_RIGHT, 
		W = 'W', 
		A = 'A', 
		S = 'S', 
		D = 'D', 
		Drop = 'Q',
		Ecs = VK_ESCAPE, 
		SHIFT = VK_LSHIFT
	};

	list<Item*> Inventory;

	int current_item;

public: 

	static const int max_Inventory_size;

	Player(float x, float y, float collision_radius, float render_area, float conor_of_view, float view_position_increment,
		float view_position, float rotation_speed, float walk_speed, float deceleration,
		float exeleration, Map& map, char symbol);

	virtual bool Controle(Map& map, FPS& _fps, GameSpace& gameSpace) override final;

	void PicItem(Item* item);

	void DropItem(Map& map, GameSpace& gameSpace);
};

