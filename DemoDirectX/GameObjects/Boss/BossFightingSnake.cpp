#include "BossFightingSnake.h"


#include "Boss.h"
BossFightingSnake::~BossFightingSnake()
{
}




BossFightingSnake::BossFightingSnake(BossData *data)
{
	this->mData = data;

}

void BossFightingSnake::Update()
{
	if (mData->boss->GetCurrentAnimation()->GetCurrentFrame() ==5)
	{
		if (mData->boss->currentAmmo >= 3) mData->boss->currentAmmo = 0;
		mData->boss->listAmmo.at(mData->boss->currentAmmo)->isActive = true;
		mData->boss->listAmmo.at(mData->boss->currentAmmo)->isLeftorRight = !mData->boss->Reverse;
		
		mData->boss->currentAmmo++;
		mData->boss->GetCurrentAnimation()->SetCurrentFrame(6);

	}
	if (mData->boss->GetCurrentAnimation()->GetCurrentFrame() == 10)
	{
		mData->boss->GetCurrentAnimation()->Reset();
		mData->boss->SetState(new BossStandSnake(mData));

	}
}
BossFightingSnake::StateName BossFightingSnake::GetState()
{
	return BossState::FightingSnake;
}


void BossFightingSnake::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}

