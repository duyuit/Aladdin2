#include "PlayerJumpThrow.h"



PlayerJumpThrow::PlayerJumpThrow(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorY = 20.0f;
}


PlayerJumpThrow::~PlayerJumpThrow()
{
}







void PlayerJumpThrow::Update(float dt)
{
	this->mPlayerData->player->AddVy(acceleratorY);
	if ( mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() == 4)
	{
		mPlayerData->player->GetCurrentAnimation()->Reset();
		mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
		return;
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
