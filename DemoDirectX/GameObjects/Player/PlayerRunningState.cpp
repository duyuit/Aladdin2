#include "PlayerRunningState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerFighting.h"
#include "PlayerStopState.h"
#include "../../GameDefines/GameDefine.h"

PlayerRunningState::PlayerRunningState(PlayerData *playerData)
{
    this->mPlayerData = playerData;

    acceleratorX = 6.5f;

	this->mPlayerData->player->allowMoveLeft = true;
	this->mPlayerData->player->allowMoveRight = true;
}


PlayerRunningState::~PlayerRunningState()
{
}

void PlayerRunningState::Update(float dt)
{
	if (this->mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() == 12)
		this->mPlayerData->player->GetCurrentAnimation()->SetCurrentFrame(2);
}

void PlayerRunningState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT])
	{
		if (mPlayerData->player->GetReverse())
		{
			if (this->mPlayerData->player->GetVx() == Define::PLAYER_MAX_RUNNING_SPEED || this->mPlayerData->player->GetVx() == -Define::PLAYER_MAX_RUNNING_SPEED)
			{/*
				this->mPlayerData->player->GetCurrentAnimation()->Reset();
				this->mPlayerData->player->SetState(new PlayerStopState(this->mPlayerData));*/
				this->mPlayerData->player->SetVx(0);
				return;
			}
			
		}	
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
		if (!mPlayerData->player->GetReverse())
		{
			if (this->mPlayerData->player->GetVx() == Define::PLAYER_MAX_RUNNING_SPEED || this->mPlayerData->player->GetVx() == -Define::PLAYER_MAX_RUNNING_SPEED)
			{

				/*this->mPlayerData->player->GetCurrentAnimation()->Reset();
				this->mPlayerData->player->SetState(new PlayerStopState(this->mPlayerData));
				return;*/
			}
			this->mPlayerData->player->SetVx(0);
		}
		
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
		this->mPlayerData->player->GetCurrentAnimation()->Reset();
		if (this->mPlayerData->player->GetVx() == Define::PLAYER_MAX_RUNNING_SPEED || this->mPlayerData->player->GetVx() == -Define::PLAYER_MAX_RUNNING_SPEED)
		{
	
			this->mPlayerData->player->SetState(new PlayerStopState(this->mPlayerData));
		}
		else
		{
		
			this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		}
		return;
	}
	
}

void PlayerRunningState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{


	if (impactor->Tag == Entity::stair )
	{
		D3DXVECTOR2 A = impactor->GetPosition();
		D3DXVECTOR2 B = D3DXVECTOR2(A.x + impactor->GetWidth() / 2, A.y - impactor->GetHeight() / 2);
		D3DXVECTOR2 vtcp = D3DXVECTOR2(B.x - A.x, B.y - A.y);
		D3DXVECTOR2 vtpt = D3DXVECTOR2(vtcp.y, -vtcp.x);

		float y = (-vtpt.x*(mPlayerData->player->GetPosition().x - A.x)) / vtpt.y + A.y;

		mPlayerData->player->SetPosition(mPlayerData->player->GetPosition().x, y);
		return;
	}

	if (impactor->Tag == Entity::stair2)
	{
		D3DXVECTOR2 A = mPlayerData->player->startStair2;
		D3DXVECTOR2 B = mPlayerData->player->endStair2;
		D3DXVECTOR2 vtcp = D3DXVECTOR2(B.x - A.x, B.y - A.y);
		D3DXVECTOR2 vtpt = D3DXVECTOR2(vtcp.y, -vtcp.x);

		float y = (-vtpt.x*(mPlayerData->player->GetPosition().x - A.x)) / vtpt.y + A.y;

		mPlayerData->player->SetPosition(mPlayerData->player->GetPosition().x, y);
		return;
	}

	if (impactor->Tag == Entity::stair1)
	{
		D3DXVECTOR2 A = mPlayerData->player->startStair1;
		D3DXVECTOR2 B = mPlayerData->player->endStair1;
		D3DXVECTOR2 vtcp = D3DXVECTOR2(B.x - A.x, B.y - A.y);
		D3DXVECTOR2 vtpt = D3DXVECTOR2(vtcp.y, -vtcp.x);

		float y = (-vtpt.x*(mPlayerData->player->GetPosition().x - A.x)) / vtpt.y + A.y;

		mPlayerData->player->SetPosition(mPlayerData->player->GetPosition().x, y);
		return;
	}


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
