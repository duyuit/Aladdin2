#include "PlayerJumpString.h"
#include "../../GameDefines/GameDefine.h"
#include "PlayerClimbState.h"
#include "PlayerFallingState.h"

PlayerJumpString::PlayerJumpString(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVy(Define::PLAYER_MIN_JUMP_VELOCITY);

	acceleratorY = 20.0f;
	acceleratorX = 0.0f;



	this->mPlayerData->player->AddVy(50);
}


PlayerJumpString::~PlayerJumpString()
{
}





void PlayerJumpString::Update(float dt)
{
	if(mPlayerData->player->GetVy() < 0)
		this->mPlayerData->player->AddVy(acceleratorY);
	else
	{
		this->mPlayerData->player->AddVy(-acceleratorY);
	}

}

void PlayerJumpString::HandleKeyboard(std::map<int, bool> keys)
{
	
		if (keys[VK_RIGHT])
		{

			mPlayerData->player->SetReverse(false);

			//di chuyen sang phai
			if (this->mPlayerData->player->GetVx() < Define::PLAYER_MAX_RUNNING_SPEED)
			{
				//this->mPlayerData->player->AddVx(acceleratorX);
				this->mPlayerData->player->SetVx(200);
				if (this->mPlayerData->player->GetVx() >= Define::PLAYER_MAX_RUNNING_SPEED)
				{
					this->mPlayerData->player->SetVx(Define::PLAYER_MAX_RUNNING_SPEED);
				}
			}

		
		}
		else if (keys[VK_LEFT])
		{
			mPlayerData->player->SetReverse(true);

			//di chuyen sang trai
			if (this->mPlayerData->player->GetVx() > -Define::PLAYER_MAX_RUNNING_SPEED)
			{
				//this->mPlayerData->player->AddVx(-acceleratorX);
				this->mPlayerData->player->SetVx(-200);
				if (this->mPlayerData->player->GetVx() < -Define::PLAYER_MAX_RUNNING_SPEED)
				{
					this->mPlayerData->player->SetVx(-Define::PLAYER_MAX_RUNNING_SPEED);
				}
			}

		
		}


}

PlayerState::StateName PlayerJumpString::GetState()
{
	return PlayerState::JumpString;
}
void PlayerJumpString::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	
	if (impactor->Tag == Entity::string && mPlayerData->player->GetVy() > 0)
	{
		mPlayerData->player->SetPosition(impactor->GetPosition().x, mPlayerData->player->GetPosition().y);
		mPlayerData->player->SetVx(0);
		mPlayerData->player->SetVy(0);
		//mPlayerData->player->allowJump = true;
		mPlayerData->player->SetState(new PlayerClimbState(this->mPlayerData));


		return;
	}
}