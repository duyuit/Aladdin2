#include "BossMagnetState.h"
#include "Boss.h"
#include "BossStandHuman.h"

BossMagnetState::~BossMagnetState()
{
}



int StartTimeMagnet, CurTime;
BossMagnetState::BossMagnetState(BossData *data)
{
	this->mData = data;
	StartTimeMagnet = GetTickCount();
	Sound::getInstance()->play("Jafar Tractor", true, 0);
}
bool CheckLeftorRight;

void BossMagnetState::Update()
{
	if (mData->boss->GetCurrentAnimation()->GetCurrentFrame()>=6)
	{
		
		if (mData->boss->mPlayer->GetPosition().x > mData->boss->GetPosition().x)
		{
			mData->boss->mPlayer->AddPosition(D3DXVECTOR2(-2, 0));
			CheckLeftorRight = false;
		}
		if (mData->boss->mPlayer->GetPosition().x < mData->boss->GetPosition().x)
		{
			mData->boss->mPlayer->AddPosition(D3DXVECTOR2(2, 0));
			CheckLeftorRight = true;
		}
		if (abs(mData->boss->mPlayer->GetPosition().x - mData->boss->GetPosition().x)<10)
		{
			if (CheckLeftorRight)
				mData->boss->mPlayer->AddPosition(D3DXVECTOR2(50, 0));
			else
				mData->boss->mPlayer->AddPosition(D3DXVECTOR2(-50, 0));
			CheckLeftorRight = !CheckLeftorRight;
			mData->boss->GetCurrentAnimation()->Reset();
			if( mData->boss->mPlayer->mCurrentState != PlayerState::Fired )
			mData->boss->mPlayer->SetState(new PlayerFiredState(mData->boss->mPlayer->mPlayerData));
			Sound::getInstance()->play("Jafar Laugh", false, 1);
			mData->boss->SetState(new BossStandHuman(mData));
			return;
		}
		mData->boss->GetCurrentAnimation()->SetCurrentFrame(6);

	}
	
	



	D3DXVECTOR3 A;
	if(mData->boss->mPlayer->GetPosition().x > mData->boss->GetPosition().x)
	 A = D3DXVECTOR3(mData->boss->GetPosition().x+30, mData->boss->GetPosition().y-50,0);
	else A = D3DXVECTOR3(mData->boss->GetPosition().x - 30, mData->boss->GetPosition().y - 50, 0);
	D3DXVECTOR3 B = D3DXVECTOR3(mData->boss->mPlayer->GetPosition().x, mData->boss->mPlayer->GetPosition().y-10,0);
	D3DXVECTOR2 vtcp = D3DXVECTOR2(B.x - A.x, B.y - A.y);
	D3DXVECTOR2 vtpt = D3DXVECTOR2(vtcp.y, -vtcp.x);

	mData->boss->starPos.clear();
	if (A.x < B.x)
	{
		for (int i = A.x; i < B.x;i+=20)
		{
			float y = (-vtpt.x*(i - A.x)) / vtpt.y + A.y;
			mData->boss->starPos.push_back(D3DXVECTOR3(i, y,0));
		}
	}
	else
	{
		for (int i = B.x; i < A.x; i+=20)
		{
			float y = (-vtpt.x*(i - A.x)) / vtpt.y + A.y;
			mData->boss->starPos.push_back(D3DXVECTOR3(i, y,0));
		}
	}


	
	if (GetTickCount() - StartTimeMagnet >= 2000)
	{
		Sound::getInstance()->stop("Jafar Tractor");
		mData->boss->GetCurrentAnimation()->Reset();
		mData->boss->SetState(new BossStandHuman(mData));
	}


}
BossMagnetState::StateName BossMagnetState::GetState()
{
	return BossState::Magnet;
}


void BossMagnetState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	return;
}

