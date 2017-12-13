#pragma once
#include "BossState.h"
class BossSummon : public BossState
{
public:
	BossSummon(BossData *data);
	~BossSummon();
	void Update();
	StateName GetState();
	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);
};

