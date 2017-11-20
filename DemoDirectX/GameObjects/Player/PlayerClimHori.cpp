#include "PlayerClimHori.h"


#include "Player.h"
#include "PlayerJumpingState.h"

#include "../../GameDefines/GameDefine.h"






PlayerClimHori::PlayerClimHori(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorX= -100;

}


PlayerClimHori::~PlayerClimHori()
{
}

void PlayerClimHori::Update(float dt)
{
	mPlayerData->player->SetVx(acceleratorX);
}
bool flag = false;
void PlayerClimHori::HandleKeyboard(std::map<int, bool> keys)
{

	if (keys[VK_RIGHT])
	{
		acceleratorX = 100;
	
		mPlayerData->player->SetReverse(true);
		flag = false;


	}
	else if (keys[VK_LEFT])
	{
		acceleratorX = -100;
	
		mPlayerData->player->SetReverse(false);
		flag = true;
	}
	else
	{
		acceleratorX = 0;
		mPlayerData->player->GetCurrentAnimation()->SetCurrentFrame(3);
	}
	
	if (keys[VK_SPACE])
	{
		this->mPlayerData->player->SetPosition(this->mPlayerData->player->GetPosition().x, this->mPlayerData->player->GetPosition().y+80);
		this->mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
	}

	
	if (keys[VK_NUMPAD0])
	{
		mPlayerData->player->SetReverse(flag);
		this->mPlayerData->player->mAnimationThrowClimb->GetSprite()->SetCenterDraw(D3DXVECTOR2(0.5, 0));
		this->mPlayerData->player->SetState(new PLayerThrowClimb(this->mPlayerData));
	}
}

PlayerState::StateName PlayerClimHori::GetState()
{
	return PlayerState::ClimbingHori;
}


void PlayerClimHori::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	switch (side)
	{
	case Entity::Left:
	{
		//va cham phia ben trai player

		if (impactor->Tag == Entity::Land)
		{
			if (this->mPlayerData->player->getMoveDirection() == Player::MoveToLeft)
			{
				this->mPlayerData->player->allowMoveLeft = false;

				//day Player ra phia ben phai de cho player khong bi xuyen qua object
				this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
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
