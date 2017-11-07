#include "PlayerState.h"


PlayerState::PlayerState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
}

PlayerState::PlayerState()
{

}

PlayerState::~PlayerState()
{
}

void PlayerState::Update(float dt)
{

}

void PlayerState::HandleKeyboard(std::map<int, bool> keys)
{

}
float PlayerState::GetAcceX()
{
	return acceleratorX;
}

float PlayerState::GetAcceY()
{
	return acceleratorY;
}
void PlayerState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}