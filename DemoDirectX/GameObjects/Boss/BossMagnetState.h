#pragma once
#include "BossState.h"
class BossMagnetState: public BossState
{
public:
	BossMagnetState(BossData *data);
	~BossMagnetState();
	void Update();
	virtual StateName GetState();
	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);
};

