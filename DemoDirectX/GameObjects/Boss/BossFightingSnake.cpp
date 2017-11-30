#include "BossFightingSnake.h"



BossFightingSnake::~BossFightingSnake()
{
}




BossFightingSnake::BossFightingSnake(BossData *data)
{
	this->mData = data;
}

void BossFightingSnake::Update()
{
	//	mData->enemy->AddPosition(1, 0);
}
BossFightingSnake::StateName BossFightingSnake::GetState()
{
	return BossState::FightingSnake;
}


void BossFightingSnake::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}

