#pragma once
#include "Player.h"
#include "PlayerState.h"
class PlayerBung : public PlayerState
{
public:
	PlayerBung(PlayerData *playerData);
	~PlayerBung();
	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);
	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	virtual StateName GetState();

};



