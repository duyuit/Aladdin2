#include "BossStandHuman.h"
#include "Boss.h"




BossStandHuman::~BossStandHuman()
{
}




int StartTime;


BossStandHuman::BossStandHuman(BossData *data)
{
	this->mData = data;
	StartTime = GetTickCount();
}


void BossStandHuman::Update()
{
	if (GetTickCount() - StartTime >= 2000) mData->boss->SetState(new BossMagnetState(mData));

}
BossStandHuman::StateName BossStandHuman::GetState()
{
	return BossState::StandHuman;
}


void BossStandHuman::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}

