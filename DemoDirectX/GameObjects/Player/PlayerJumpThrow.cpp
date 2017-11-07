#include "PlayerJumpThrow.h"



PlayerJumpThrow::PlayerJumpThrow(PlayerData *playerData)
{
	this->mPlayerData = playerData;
}


PlayerJumpThrow::~PlayerJumpThrow()
{
}







void PlayerJumpThrow::Update(float dt)
{
	if (this->mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() == 4)
	{
		this->mPlayerData->player->GetCurrentAnimation()->Reset();
		this->mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
	}
}

void PlayerJumpThrow::HandleKeyboard(std::map<int, bool> keys)
{


}

void PlayerJumpThrow::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	//lay phia va cham so voi player
	//GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->player, data);
	//if (impactor->Tag == Entity::LandWood || impactor->Tag == Entity::string) return;

}

PlayerState::StateName PlayerJumpThrow::GetState()
{
	return PlayerState::JumpThrow;
}
