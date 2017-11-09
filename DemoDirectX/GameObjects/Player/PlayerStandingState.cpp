#include "PlayerStandingState.h"
#include "Player.h"
#include "PlayerFallingState.h"
#include "PlayerSit.h"
#include "PlayerFighting.h"
#include "PlayerFiredState.h"
#include "../../GameDefines/GameDefine.h"

PlayerStandingState::PlayerStandingState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    this->mPlayerData->player->SetVx(0);
    this->mPlayerData->player->SetVy(0);
} 


PlayerStandingState::~PlayerStandingState()
{
}

void PlayerStandingState::Update(float dt)
{

}

void PlayerStandingState::HandleKeyboard(std::map<int, bool> keys)
{
    if (keys[VK_LEFT] || keys[VK_RIGHT])
    {
        this->mPlayerData->player->SetState(new PlayerRunningState(this->mPlayerData));
        return;
    }
	else
	if (keys[VK_NUMPAD0])
	{
		
		this->mPlayerData->player->SetState(new PlayerThrowAppleState(this->mPlayerData));
		return;
	}
	else
	if (keys[VK_NUMPAD1])
	{

		this->mPlayerData->player->SetState(new PlayerFighting(this->mPlayerData));
		return;
	}
	else
		if (keys[VK_DOWN])
		{

			this->mPlayerData->player->SetState(new PlayerSit(this->mPlayerData));
			return;
		}
	/*else 
			if (keys[VK_NUMPAD2])
			{
				this->mPlayerData->player->SetState(new PlayerFiredState(this->mPlayerData));
				return;
			}*/
}
void PlayerStandingState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	if(impactor->Tag==Entity::Fired)
		this->mPlayerData->player->SetState(new PlayerFiredState(this->mPlayerData));
}
PlayerState::StateName PlayerStandingState::GetState()
{
    return PlayerState::Standing;
}
