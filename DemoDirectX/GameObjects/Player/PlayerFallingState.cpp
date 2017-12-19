
#include "Player.h"
#include "../../GameDefines/GameDefine.h"
#include "PlayerClimbState.h"
#include "PlayerJumpingState.h"

PlayerFallingState::PlayerFallingState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    acceleratorY =10.0f;
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
	//if (mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame() == 3) mPlayerData->player->GetCurrentAnimation()->SetCurrentFrame(2);
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
	if (impactor->Tag == Entity::stair )
	{
		D3DXVECTOR2 A = impactor->GetPosition();
		D3DXVECTOR2 B = D3DXVECTOR2(A.x + impactor->GetWidth() / 2, A.y - impactor->GetHeight() / 2);
		D3DXVECTOR2 vtcp = D3DXVECTOR2(B.x - A.x, B.y - A.y);
		D3DXVECTOR2 vtpt = D3DXVECTOR2(vtcp.y, -vtcp.x);

		float y = (-vtpt.x*(mPlayerData->player->GetPosition().x - A.x)) / vtpt.y + A.y;

		if (y - mPlayerData->player->GetPosition().y <= 30)
		{
		
			mPlayerData->player->SetPosition(mPlayerData->player->GetPosition().x, y);
			mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		}
		return;
	}



	if (impactor->Tag == Entity::CheckPoint) return;
	if (impactor->Tag == Entity::string)
	{
		mPlayerData->player->SetPosition(impactor->GetPosition().x, mPlayerData->player->GetPosition().y);
		mPlayerData->player->SetVx(0);
		mPlayerData->player->SetVy(0);
		mPlayerData->player->SetState(new PlayerClimbState(this->mPlayerData));
		return;
	}
	if (impactor->Tag == Entity::StringHori)
	{
		mPlayerData->player->SetReverse(!mPlayerData->player->GetReverse());
		mPlayerData->player->SetPosition(mPlayerData->player->GetPosition().x,impactor->GetPosition().y);
		mPlayerData->player->SetVy(0);
		mPlayerData->player->SetState(new PlayerClimHori(this->mPlayerData));
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

	case Entity::TopRight: case Entity::TopLeft: case Entity::Top:
	{
		this->mPlayerData->player->AddPosition(0, data.RegionCollision.bottom - data.RegionCollision.top);
		this->mPlayerData->player->SetVy(0);
		break;

	}

	case Entity::Bottom:
	case Entity::BottomRight:
	case Entity::BottomLeft:

		if (impactor->Tag == Entity::Bung)
		{
		
			mPlayerData->player->SetState(new PlayerBung(this->mPlayerData));
			return;
		}
		if (impactor->Tag == Entity::Camel)
		{
			this->mPlayerData->player->SetState(new PlayerJumpingState(this->mPlayerData));
			return;
		}
		if (data.RegionCollision.right - data.RegionCollision.left >= 16.0f)
		{

			this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top)); //Code cho player đứng trên vật thể
			RECT r = this->mPlayerData->player->GetBound();
			if (isLeftOrRightKeyPressed)
			{
				mPlayerData->player->GetCurrentAnimation()->Reset();
				this->mPlayerData->player->SetState(new PlayerRunningState(this->mPlayerData));
			}
			else
			{
				mPlayerData->player->GetCurrentAnimation()->Reset();
				this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
			}
		}
		return;

	default:
		break;
	}
}
