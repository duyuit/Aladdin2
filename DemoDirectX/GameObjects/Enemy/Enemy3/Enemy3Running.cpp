#include "Enemy3Running.h"

#include "Enemy3.h"


Enemy3Running::Enemy3Running()
{
}


Enemy3Running::~Enemy3Running()
{
}




Enemy3Running::Enemy3Running(Enemy3Data *data)
{
	this->mData = data;
}

void Enemy3Running::Update()
{
	if (mData->enemy->Reverse)
		mData->enemy->AddPosition(1, 0);
	else
		mData->enemy->AddPosition(-1, 0);
}
Enemy3State::StateName Enemy3Running::GetState()
{
	return Enemy3State::Running;;
}


void Enemy3Running::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}

