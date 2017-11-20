#pragma once
#include "Enemy3State.h"
class Enemy3Running : public Enemy3State
{
public:
	Enemy3Running();
	Enemy3Running(Enemy3Data *data);
	~Enemy3Running();

	void Update();
	virtual StateName GetState();
	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);
};





