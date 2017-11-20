#include "Enemy3Fighting.h"

#include "Enemy3.h"


Enemy3Fighting::Enemy3Fighting()
{
}


Enemy3Fighting::~Enemy3Fighting()
{
}




Enemy3Fighting::Enemy3Fighting(Enemy3Data *data)
{
	this->mData = data;
}

void Enemy3Fighting::Update()
{
	//	mData->enemy->AddPosition(1, 0);
}
Enemy3State::StateName Enemy3Fighting::GetState()
{
	return Enemy3State::Fighting;
}


void Enemy3Fighting::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}

