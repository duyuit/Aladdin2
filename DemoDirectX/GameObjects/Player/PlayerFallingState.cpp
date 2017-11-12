﻿#include "PlayerFallingState.h"
#include "Player.h"
#include "PlayerStandingState.h"
#include "PlayerClimbState.h"
#include "PlayerJumpingState.h"
#include "../../GameDefines/GameDefine.h"

PlayerFallingState::PlayerFallingState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    acceleratorY = 15.0f;
    acceleratorX = 3.0f;

    if (this->mPlayerData->player->GetVx() == 0)
    {
        allowMoveX = false;
    }
    else
    {
        allowMoveX = true;
    }
}


PlayerFallingState::~PlayerFallingState()
{
}

void PlayerFallingState::Update(float dt)
{
    this->mPlayerData->player->AddVy(acceleratorY);

    if (mPlayerData->player->GetVy() > Define::PLAYER_MAX_JUMP_VELOCITY)
    {
        mPlayerData->player->SetVy(Define::PLAYER_MAX_JUMP_VELOCITY);
    }
}

void PlayerFallingState::HandleKeyboard(std::map<int, bool> keys)
{
    if (keys[VK_RIGHT])
    {
        mPlayerData->player->SetReverse(false);

        isLeftOrRightKeyPressed = true;
        //di chuyen sang phai
        if (this->mPlayerData->player->GetVx() < Define::PLAYER_MAX_RUNNING_SPEED)
        {
          //  this->mPlayerData->player->AddVx(acceleratorX);
			this->mPlayerData->player->SetVx(120);
            if (this->mPlayerData->player->GetVx() >= Define::PLAYER_MAX_RUNNING_SPEED)
            {
                this->mPlayerData->player->SetVx(Define::PLAYER_MAX_RUNNING_SPEED);
            }
        }
    }
    else if (keys[VK_LEFT])
    {
        mPlayerData->player->SetReverse(true);

        isLeftOrRightKeyPressed = true;
        //di chuyen sang trai
        if (this->mPlayerData->player->GetVx() > -Define::PLAYER_MAX_RUNNING_SPEED)
        {
          //  this->mPlayerData->player->AddVx(-acceleratorX);
			this->mPlayerData->player->SetVx(-120);
            if (this->mPlayerData->player->GetVx() <= -Define::PLAYER_MAX_RUNNING_SPEED)
            {
                this->mPlayerData->player->SetVx(-Define::PLAYER_MAX_RUNNING_SPEED);
            }
        }
    }
    else
    {
        isLeftOrRightKeyPressed = false;    
    }
}

PlayerState::StateName PlayerFallingState::GetState()
{
    return PlayerState::Falling;
}


void PlayerFallingState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	//lay phia va cham so voi player
	//GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->player, data);
	if (impactor->Tag == Entity::string)
	{
		mPlayerData->player->SetPosition(impactor->GetPosition().x, mPlayerData->player->GetPosition().y);
		mPlayerData->player->SetVx(0);
		mPlayerData->player->SetVy(0);
		mPlayerData->player->SetState(new PlayerClimbState(this->mPlayerData));
		return;
	}

	if (impactor->Tag == Entity::AppleObject)
		return;


	switch (side)
	{
	case Entity::Left:
		if (mPlayerData->player->getMoveDirection() == Player::MoveToLeft)
		{
			this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
			this->mPlayerData->player->SetVx(0);
		}
		break;

	case Entity::Right:
		if (mPlayerData->player->getMoveDirection() == Player::MoveToRight)
		{
			this->mPlayerData->player->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
			this->mPlayerData->player->SetVx(0);
		}
		break;

	case Entity::Top:
		break;

	case Entity::Bottom:
	case Entity::BottomRight:
	case Entity::BottomLeft:

		if (impactor->Tag == Entity::Camel)
		{
			this->mPlayerData->player->SetState(new PlayerJumpingState(this->mPlayerData));
			return;
		}
		if (data.RegionCollision.right - data.RegionCollision.left >= 8.0f)
		{

			this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top)); //Code cho player đứng trên vật thể
			RECT r = this->mPlayerData->player->GetBound();
			if (isLeftOrRightKeyPressed)
			{
				this->mPlayerData->player->SetState(new PlayerRunningState(this->mPlayerData));
			}
			else
			{
				this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
			}
		}
		return;

	default:
		break;
	}
}