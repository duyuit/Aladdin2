#include "BossSummon.h"



BossSummon::BossSummon(BossData *data)
{
	this->mData = data;
}


BossSummon::~BossSummon()
{
}
void BossSummon::Update()
{

}
BossState::StateName BossSummon::GetState()
{
	return BossState::MeteorSummon;
}


void BossSummon::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}
