#pragma once
#include "PlayerState.h"
#include "Player.h"
class PlayerStopState : public PlayerState
{
public:
	PlayerStopState(PlayerData *playerData);
	~PlayerStopState();
	void Update(float dt);

	
	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);
	virtual StateName GetState();
};



