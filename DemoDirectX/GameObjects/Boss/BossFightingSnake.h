#pragma once
#include "BossState.h"
class BossFightingSnake : public BossState
{
public:
	BossFightingSnake(BossData *data);
	~BossFightingSnake();
	void Update();
	virtual StateName GetState();
	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);
};


