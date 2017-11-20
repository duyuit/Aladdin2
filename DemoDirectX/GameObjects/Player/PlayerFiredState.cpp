#include "PlayerFiredState.h"
#include "PlayerStandingState.h"
#include "PlayerRunningState.h"
#include "PlayerJumpingState.h"
#include "PlayerFighting.h"


PlayerFiredState::~PlayerFiredState()
{
}




PlayerFiredState::PlayerFiredState(PlayerData *playerData)
{
	this->mPlayerData = playerData;

	mPlayerData->player->HPCount--;
	mPlayerData->player->isAttacked = true;

}






void PlayerFiredState::Update(float dt)
{
	if (this->mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() ==5)
	{
		this->mPlayerData->player->isAttacked = false;
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
	else if (keys[VK_NUMPAD0])
	{
		this->mPlayerData->player->SetState(new PlayerFighting(this->mPlayerData));
		return;
	}
	
	

}


PlayerState::StateName PlayerFiredState::GetState()
{
	return PlayerState::Fired;
}
