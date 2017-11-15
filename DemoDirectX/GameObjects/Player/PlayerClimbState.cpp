#include "PlayerFallingState.h"
#include "Player.h"
#include "PlayerClimbState.h"
#include "../../GameDefines/GameDefine.h"

PlayerClimbState::PlayerClimbState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorY =100;
	
}


PlayerClimbState::~PlayerClimbState()
{
}

void PlayerClimbState::Update(float dt)
{
	mPlayerData->player->SetVy(acceleratorY);
}

void PlayerClimbState::HandleKeyboard(std::map<int, bool> keys)
{
	mPlayerData->player->GetCurrentAnimation()->SetReverse(false);
	if (keys[VK_RIGHT])
	{
		mPlayerData->player->GetCurrentAnimation()->SetCurrentFrame(6);
		mPlayerData->player->SetReverse(false);

		
	}
	else if (keys[VK_LEFT])
	{
		mPlayerData->player->GetCurrentAnimation()->SetCurrentFrame(6);
		mPlayerData->player->SetReverse(true);

	}
	else if (keys[VK_UP])
	{
		acceleratorY = -100;

	}
	else if (keys[VK_DOWN])
	{
		acceleratorY = 100;
		mPlayerData->player->GetCurrentAnimation()->SetReverse(true);
	}
	else
	{
		acceleratorY = 0;
		mPlayerData->player->GetCurrentAnimation()->SetCurrentFrame(6);
		isLeftOrRightKeyPressed = false;
	}

	if (keys[VK_SPACE])
	{
		
		if (1)
		{
			if (mPlayerData->player->GetReverse())
			{
				this->mPlayerData->player->SetPosition(this->mPlayerData->player->GetPosition().x - 40, this->mPlayerData->player->GetPosition().y);
				this->mPlayerData->player->SetVx(-30);
			}
			else
			{
				this->mPlayerData->player->SetPosition(this->mPlayerData->player->GetPosition().x + 40, this->mPlayerData->player->GetPosition().y);
				this->mPlayerData->player->SetVx(30);
			}
			this->mPlayerData->player->SetVy(80);
			this->mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
		}
	}
	
}

PlayerState::StateName PlayerClimbState::GetState()
{
	return PlayerState::Climbing;
}


void PlayerClimbState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}
