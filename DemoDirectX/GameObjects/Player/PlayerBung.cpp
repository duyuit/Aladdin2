#include "PlayerBung.h"

#include "PlayerJumpingState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerJumpThrow.h"
#include "PlayerClimbState.h"
#include "../../GameDefines/GameDefine.h"


PlayerBung::~PlayerBung()
{
}




PlayerBung::PlayerBung(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVy(Define::PLAYER_MIN_JUMP_VELOCITY);

	acceleratorY = 30.0f;
	acceleratorX = 0.0f;

	this->mPlayerData->player->AddVy(-180);
	Sound::getInstance()->play("Canopy Bounce", false, 1);


}



void PlayerBung::Update(float dt)
{
	this->mPlayerData->player->AddVy(acceleratorY);

	if (mPlayerData->player->GetVy() >= 0)
	{
		//acceleratorY *= -1;
		return;
	}

}

void PlayerBung::HandleKeyboard(std::map<int, bool> keys)
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

PlayerBung::StateName PlayerBung::GetState()
{
	return PlayerState::Bung;
}
void PlayerBung::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	if (impactor->Tag == Entity::Bung )
	{
		
		switch (side)
		{
		case Entity::Bottom: case Entity::BottomLeft: case Entity::BottomRight:
			if (mPlayerData->player->GetVy() >= 0)
			this->mPlayerData->player->SetState(new PlayerBung(this->mPlayerData));
			break;
		}

		return;
	}
	if (impactor->Tag == Entity::AppleObject)
		return;
	if (impactor->Tag == Entity::StringHori)
	{
		mPlayerData->player->SetReverse(!mPlayerData->player->GetReverse());
		mPlayerData->player->SetPosition(mPlayerData->player->GetPosition().x, impactor->GetPosition().y);
		mPlayerData->player->SetVy(0);
		mPlayerData->player->SetState(new PlayerClimHori(this->mPlayerData));
		return;
	}
		
	

	this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));
	this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
	
}