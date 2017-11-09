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
	//this->mPlayerData->player->AddVy(acceleratorY);

	
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

PlayerState::StateName PlayerClimbState::GetState()
{
	return PlayerState::Climbing;
}


void PlayerClimbState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	//lay phia va cham so voi player
	//GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->player, data);

	//switch (side)
	//{
	//case Entity::Left:
	//	if (mPlayerData->player->getMoveDirection() == Player::MoveToLeft)
	//	{
	//		this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
	//		this->mPlayerData->player->SetVx(0);
	//	}
	//	break;

	//case Entity::Right:
	//	if (mPlayerData->player->getMoveDirection() == Player::MoveToRight)
	//	{
	//		this->mPlayerData->player->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
	//		this->mPlayerData->player->SetVx(0);
	//	}
	//	break;

	//case Entity::Top:
	//	break;

	//case Entity::Bottom:
	//case Entity::BottomRight:
	//case Entity::BottomLeft:
	//	if (data.RegionCollision.right - data.RegionCollision.left >= 8.0f)
	//	{

	//		this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top)); //Code cho player đứng trên vật thể
	//		RECT r = this->mPlayerData->player->GetBound();
	//		if (isLeftOrRightKeyPressed)
	//		{
	//			this->mPlayerData->player->SetState(new PlayerRunningState(this->mPlayerData));
	//		}
	//		else
	//		{
	//			this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
	//		}
	//	}
	//	return;

	//default:
	//	break;
	//}
}
