#pragma once
#include "BossState.h"
class BossStandHuman : public BossState
{
public:
	BossStandHuman(BossData *data);
	~BossStandHuman();
	void Update();
	virtual StateName GetState();
	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);
};

