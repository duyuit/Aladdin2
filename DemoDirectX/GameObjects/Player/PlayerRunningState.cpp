#include "PlayerRunningState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerFighting.h"
#include "../../GameDefines/GameDefine.h"

PlayerRunningState::PlayerRunningState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    
    acceleratorX = 50.0f;

	this->mPlayerData->player->allowMoveLeft = true;
	this->mPlayerData->player->allowMoveRight = true;
}


PlayerRunningState::~PlayerRunningState()
{
}

void PlayerRunningState::Update(float dt)
{

}

void PlayerRunningState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT])
	{
		if (mPlayerData->player->allowMoveRight)
		{
			mPlayerData->player->SetReverse(false);

			//di chuyen sang phai
			if (this->mPlayerData->player->GetVx() < Define::PLAYER_MAX_RUNNING_SPEED)
			{
				this->mPlayerData->player->AddVx(acceleratorX);

				if (this->mPlayerData->player->GetVx() >= Define::PLAYER_MAX_RUNNING_SPEED)
				{
					this->mPlayerData->player->SetVx(Define::PLAYER_MAX_RUNNING_SPEED);
				}
			}
		}
	}
	else if (keys[VK_LEFT])
	{
		if (mPlayerData->player->allowMoveLeft)
		{
			mPlayerData->player->SetReverse(true);

			//di chuyen sang trai
			if (this->mPlayerData->player->GetVx() > -Define::PLAYER_MAX_RUNNING_SPEED)
			{
				this->mPlayerData->player->AddVx(-acceleratorX);

				if (this->mPlayerData->player->GetVx() < -Define::PLAYER_MAX_RUNNING_SPEED)
				{
					this->mPlayerData->player->SetVx(-Define::PLAYER_MAX_RUNNING_SPEED);
				}
			}
		}
	}
	else
	{
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		return;
	}
	//if (keys[VK_NUMPAD1])
	//{
	//	this->mPlayerData->player->SetState(new PlayerFighting(this->mPlayerData));
	//	return;
	//}
}

void PlayerRunningState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	//lay phia va cham so voi player
	//GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->player, data);
	//if (impactor->Tag == Entity::LandWood || impactor->Tag == Entity::string) return;
	switch (side)
	{
	case Entity::Left:
	{
		//va cham phia ben trai player
	
		if (impactor->Tag != Entity::LandWood)
		{
			if (this->mPlayerData->player->getMoveDirection() == Player::MoveToLeft)
			{
				this->mPlayerData->player->allowMoveLeft = false;

				//day Player ra phia ben phai de cho player khong bi xuyen qua object
				this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);

				this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
			}

			return;
		}
		break;
	}

	case Entity::Right:
	{
		
		//va cham phia ben phai player
		if (impactor->Tag != Entity::LandWood)
		{

			if (this->mPlayerData->player->getMoveDirection() == Player::MoveToRight)
			{
				this->mPlayerData->player->allowMoveRight = false;
				this->mPlayerData->player->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
				this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
			}
			return; 
		}
		break;
	}

	case Entity::Top:
		break;

	case Entity::Bottom: case Entity::BottomLeft: case Entity::BottomRight:
	{
		
			this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));

			this->mPlayerData->player->SetVy(0);

		break;
	}
	}
}

PlayerState::StateName PlayerRunningState::GetState()
{
	return PlayerState::Running;
}
