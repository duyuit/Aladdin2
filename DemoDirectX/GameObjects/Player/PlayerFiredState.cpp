#include "PlayerFiredState.h"
#include "PlayerStandingState.h"
#include "PlayerRunningState.h"
#include "PlayerJumpingState.h"



PlayerFiredState::~PlayerFiredState()
{
}




PlayerFiredState::PlayerFiredState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
}






void PlayerFiredState::Update(float dt)
{
	if (this->mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() ==11)
	{
		this->mPlayerData->player->GetCurrentAnimation()->Reset();
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
	}

}

void PlayerFiredState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_LEFT] || keys[VK_RIGHT])
	{
		this->mPlayerData->player->SetState(new PlayerRunningState(this->mPlayerData));
		return;
	}
	else if (keys[VK_SPACE])
	{
		this->mPlayerData->player->SetState(new PlayerJumpingState(this->mPlayerData));
		return;
	}
	
	

}


PlayerState::StateName PlayerFiredState::GetState()
{
	return PlayerState::Fired;
}
