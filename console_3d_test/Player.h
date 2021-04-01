#pragma once
#include "Map.h"
class Player final : public Entity
{

	vector<Item*> Inventory;

	int current_item;
	bool _HasMap = false;

	void Initialize(float positionX, float positionY, const Map& map, float collision_area,
		float render_area) override {};

public: 

	enum class BUTTONS
	{
		LEFT = VK_LEFT,
		RIGHT = VK_RIGHT,
		W = 'W',
		A = 'A',
		S = 'S',
		D = 'D',
		Regeneration = 'M',
		Drop = 'Q',
		Interact = 'E',
		Ecs = VK_ESCAPE,
		SHIFT = VK_LSHIFT
	};

	static const int max_Inventory_size;

	Player(float x, float y, float collision_radius, float render_area,
		float conor_of_view, float view_position_increment, float view_position, 
		float rotation_speed, float deceleration, 
		float exeleration, Map& map, char symbol, float HP);

	bool Controle(Map& map, FPS& _fps, GameSpace& gameSpace) override final;

	bool PutItemToInventory(Item* item);
	void DropItem(Map& map, GameSpace& gameSpace);
	void PicItem(GameSpace& gameSpace);
	int GetInventorySize() const;
	int GetCurrentItemIndex() const;
	Item*& operator[](int index);
	Item* operator[](int index) const;
	void ChoseItem();
	bool IsMoving() const;
	int IndexOfNecessarItem(char symbol) const;
	void Regen();
	static int CollideWithDoor(float x, float y, GameSpace& gamespace);
	bool CollideWithExit(GameSpace& gamespace);
	void Interact(Map& map, GameSpace& gameSpace);
	void InteractWithDoor(int indexOfDoor, GameSpace& gameSpace, Map& map);
	bool HasMap() const;
};

