#include "PlayerStopState.h"



PlayerStopState::PlayerStopState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVx(2);
	acceleratorX = 8;
}


PlayerStopState::~PlayerStopState()
{
}




void PlayerStopState::Update(float dt)
{
	if (!mPlayerData->player->GetReverse())
	{
		if (this->mPlayerData->player->GetVx() <= 20)
			this->mPlayerData->player->AddVx(acceleratorX);
	}
	else
	{
		if (this->mPlayerData->player->GetVx() >= -20)
			this->mPlayerData->player->AddVx(-acceleratorX);
	}
	if (this->mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() == 8)
	{
		this->mPlayerData->player->GetCurrentAnimation()->Reset();
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));

	}
	
}


void PlayerStopState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	//lay phia va cham so voi player
	//GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->player, data);
	//if (impactor->Tag == Entity::LandWood || impactor->Tag == Entity::string) return;

}

PlayerState::StateName PlayerStopState::GetState()
{
	return PlayerState::Stop;
}
