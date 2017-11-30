#include "PlayerJumpingState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerJumpThrow.h"
#include "PlayerClimbState.h"
#include "../../GameDefines/GameDefine.h"

PlayerJumpingState::PlayerJumpingState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    this->mPlayerData->player->SetVy(Define::PLAYER_MIN_JUMP_VELOCITY);

    acceleratorY =20.0f;
    acceleratorX = 0.0f;

	
	
	this->mPlayerData->player->AddVy(100);
    noPressed = false;
}


PlayerJumpingState::~PlayerJumpingState()
{

}

void PlayerJumpingState::Update(float dt)
{
    this->mPlayerData->player->AddVy(acceleratorY);   
	if (mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() == 5) mPlayerData->player->GetCurrentAnimation()->SetCurrentFrame(4);
    if (mPlayerData->player->GetVy() >= 0)
    {
		mPlayerData->player->GetCurrentAnimation()->Reset();
        mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
        return;
    }

}

void PlayerJumpingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_NUMPAD0])
	{
		this->mPlayerData->player->SetState(new PlayerJumpThrow(this->mPlayerData));
	}
    if (keys[VK_RIGHT])
    {
        mPlayerData->player->SetReverse(false);

        //di chuyen sang phai
        if (this->mPlayerData->player->GetVx() < Define::PLAYER_MAX_RUNNING_SPEED)
        {
            //this->mPlayerData->player->AddVx(acceleratorX);
			this->mPlayerData->player->SetVx(150);
            if (this->mPlayerData->player->GetVx() >= Define::PLAYER_MAX_RUNNING_SPEED)
            {
                this->mPlayerData->player->SetVx(Define::PLAYER_MAX_RUNNING_SPEED);
            } 
        }

        noPressed = false;
    }
    else if (keys[VK_LEFT])
    {
        mPlayerData->player->SetReverse(true);

        //di chuyen sang trai
        if (this->mPlayerData->player->GetVx() > -Define::PLAYER_MAX_RUNNING_SPEED)
        {
            //this->mPlayerData->player->AddVx(-acceleratorX);
			this->mPlayerData->player->SetVx(-150);
            if (this->mPlayerData->player->GetVx() < -Define::PLAYER_MAX_RUNNING_SPEED)
            {
                this->mPlayerData->player->SetVx(-Define::PLAYER_MAX_RUNNING_SPEED);
            }
        }

        noPressed = false;
    }
	
    else
    {
        noPressed = true;
    }
	
}

PlayerState::StateName PlayerJumpingState::GetState()
{
    return PlayerState::Jumping;
}
void PlayerJumpingState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	if (impactor->Tag == Entity::Bung || impactor->Tag == Entity::stair || impactor->Tag == Entity::stair1 || impactor->Tag == Entity::stair2) return;
	if (impactor->Tag == Entity::string)
	{
		mPlayerData->player->SetPosition(impactor->GetPosition().x, mPlayerData->player->GetPosition().y);
		mPlayerData->player->SetVx(0);
		mPlayerData->player->SetVy(0);
		//mPlayerData->player->allowJump = true;
		mPlayerData->player->SetState(new PlayerClimbState(this->mPlayerData));

	
		return;
	}

	if (impactor->Tag == Entity::AppleObject)
		return;


	switch (side)
	{
	case Entity::Left:
	{
		if (impactor->Tag != Entity::LandWood)
		{
			this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
			this->mPlayerData->player->SetVx(0);
		}
		break;
	}

	case Entity::Right:
	{
		if (impactor->Tag != Entity::LandWood)
		{
			this->mPlayerData->player->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
			this->mPlayerData->player->SetVx(0);
		}
		break;
	}

	case Entity::TopRight: case Entity::TopLeft: case Entity::Top:
	{
		break;
	}

	case Entity::BottomRight: case Entity::BottomLeft: case Entity::Bottom:
	{
		
		this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));
	}

	default:
		break;
	}
}