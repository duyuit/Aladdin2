#include "PLayerThrowClimb.h"


#include "Player.h"
#include "PlayerClimbState.h"


PLayerThrowClimb::PLayerThrowClimb(PlayerData *playerData)
{
	this->mPlayerData = playerData;

}


PLayerThrowClimb::~PLayerThrowClimb()
{
}

void PLayerThrowClimb::Update(float dt)
{
	
	int curFrame = mPlayerData->player->GetCurrentAnimation()->GetCurrentFrame();
	if (curFrame == 4)
	{
		this->mPlayerData->player->GetCurrentAnimation()->Reset();

		this->mPlayerData->player->SetState(new PlayerFallingState(mPlayerData));
	}
}
void PLayerThrowClimb::HandleKeyboard(std::map<int, bool> keys)
{


}

PlayerState::StateName PLayerThrowClimb::GetState()
{
	return PlayerState::ThrowCLimb;
}

void PLayerThrowClimb::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}
