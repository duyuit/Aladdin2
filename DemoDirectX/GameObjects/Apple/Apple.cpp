#include "Apple.h"


vector<RECT> Apple::LoadRECT(AppleState::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	if(mType == EntityTypes::Bowl)
		switch (state)
		{
		case AppleState::Flying:

			rect.left = 15; rect.top = 97; rect.right = rect.left + 28; rect.bottom = rect.top + 20; listSourceRect.push_back(rect);
			rect.left = 56; rect.top = 95; rect.right = rect.left + 24; rect.bottom = rect.top + 23; listSourceRect.push_back(rect);
			rect.left = 90; rect.top = 95; rect.right = rect.left + 26; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);
			rect.left = 127; rect.top = 98; rect.right = rect.left + 26; rect.bottom = rect.top + 15; listSourceRect.push_back(rect);
			rect.left = 164; rect.top = 92; rect.right = rect.left + 24; rect.bottom = rect.top + 23; listSourceRect.push_back(rect);
			rect.left = 204; rect.top = 94; rect.right = rect.left + 21; rect.bottom = rect.top + 24; listSourceRect.push_back(rect);
			

			break;
		case AppleState::Breaking:
			rect.left = 235; rect.top = 100; rect.right = rect.left + 37; rect.bottom = rect.top + 14; listSourceRect.push_back(rect);
			rect.left = 292; rect.top = 94; rect.right = rect.left + 67; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);
			rect.left = 376; rect.top = 94; rect.right = rect.left + 75; rect.bottom = rect.top + 25; listSourceRect.push_back(rect);
			rect.left = 472; rect.top = 88; rect.right = rect.left + 85; rect.bottom = rect.top + 33; listSourceRect.push_back(rect);
			rect.left = 578; rect.top = 85; rect.right = rect.left + 95; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
			rect.left = 695; rect.top = 83; rect.right = rect.left + 95; rect.bottom = rect.top + 35; listSourceRect.push_back(rect);
			rect.left = 814; rect.top = 84; rect.right = rect.left + 101; rect.bottom = rect.top + 35; listSourceRect.push_back(rect);
			rect.left = 954; rect.top = 81; rect.right = rect.left + 101; rect.bottom = rect.top + 29; listSourceRect.push_back(rect);
			break;
		case AppleState::NONE:
			break;
		default:
			break;
		}
	else
		switch (state)
	{
		case AppleState::Flying:

			rect.top = 22;
			rect.bottom = 33;
			rect.left = 370;
			rect.right = rect.left + 12;
			listSourceRect.push_back(rect);


			rect.top = 23;
			rect.bottom = rect.top +11;
			rect.left = 583;
			rect.right = rect.left + 10;
			listSourceRect.push_back(rect);


			rect.top = 25;
			rect.bottom = rect.top + 9;
			rect.left = 607;
			rect.right = rect.left + 8;
			listSourceRect.push_back(rect);


			rect.top = 25;
			rect.bottom = rect.top +10 ;
			rect.left = 623;
			rect.right = rect.left + 10;
			listSourceRect.push_back(rect);


			rect.top = 24;
			rect.bottom = rect.top + 9;
			rect.left = 639;
			rect.right = rect.left + 10;
			listSourceRect.push_back(rect);


			rect.top = 25;
			rect.bottom = rect.top +9 ;
			rect.left = 656;
			rect.right = rect.left + 8;
			listSourceRect.push_back(rect);


			rect.top = 23;
			rect.bottom = rect.top + 11;
			rect.left = 670;
			rect.right = rect.left + 8;
			listSourceRect.push_back(rect);


			rect.top = 41;
			rect.bottom = rect.top +9 ;
			rect.left = 585;
			rect.right = rect.left + 11;
			listSourceRect.push_back(rect);

			break;
	case AppleState::Breaking:
		rect.top = 20;
		rect.bottom = rect.top + 16;
		rect.left = 391;
		rect.right = rect.left + 13;
		listSourceRect.push_back(rect);

		rect.top = 18;
		rect.bottom = rect.top + 19;
		rect.left = 412;
		rect.right = rect.left + 24;
		listSourceRect.push_back(rect);

		rect.top = 15;
		rect.bottom = rect.top + 24;
		rect.left = 442;
		rect.right = rect.left + 32;
		listSourceRect.push_back(rect);

		rect.top = 14;
		rect.bottom = rect.top + 26;
		rect.left = 485;
		rect.right = rect.left + 32;
		listSourceRect.push_back(rect);


		rect.top = 12;
		rect.bottom = rect.top + 28;
		rect.left = 531;
		rect.right = rect.left + 32;
		listSourceRect.push_back(rect);
		break;
	case AppleState::NONE:
		break;
	default:
		break;
	}
	
	return listSourceRect;
}
Apple::Apple(EntityTypes type)
{
	mType = type;
	if (mType == EntityTypes::Bowl)
	{
		FlyingAnim = new Animation("Resources/civilian.png", 6, LoadRECT(AppleState::Flying), (float)1 / 0.2, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(120, 193, 152));
		BreakingAnim = new Animation("Resources/civilian.png",8, LoadRECT(AppleState::Breaking), (float)1 /10, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(120, 193, 152));
		
	}
	else
	{
		FlyingAnim = new Animation("Resources/Aladdin.png", 8, LoadRECT(AppleState::Flying), (float)1 / 20, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255));
		BreakingAnim = new Animation("Resources/Aladdin.png", 5, LoadRECT(AppleState::Breaking), (float)1 / 20, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255));
		
	}
	
	SetState(AppleState::NONE);
	mReverse = false;


}

Apple::~Apple()
{
}

 
void Apple::changeAnim(AppleState::StateName state)
{
	switch (state)
	{
	case AppleState::Flying:
		mCurrentAnim = FlyingAnim;
		BreakingAnim->Reset();
		break;

	case AppleState::Breaking:
		
		mCurrentAnim = BreakingAnim;
		FlyingAnim->Reset();
		break;

	default:
		return;
		break;
	}
	this->width = mCurrentAnim->GetSprite()->GetWidth();
	this->height = mCurrentAnim->GetSprite()->GetHeight();
}

void Apple::Update(float dt)
{

	if (mCurrentAnim != nullptr)
	{
		mCurrentAnim->Update(dt);
		width = mCurrentAnim->GetSprite()->GetWidth();
		height = mCurrentAnim->GetSprite()->GetHeight();
		if (mCurrentAnim == BreakingAnim)
		{
			if (mCurrentAnim->GetCurrentFrame() == mCurrentAnim->GetTotalFrame()-1)
			{
				this->SetState(AppleState::NONE);
				
			}
		}
	}
	
	if (curState != nullptr)
	{
		curState->Update(dt);
		posX = curState->getPos().x;
		posY = curState->getPos().y;
	}

}
void Apple::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	//mCurrentAnimation->GetSprite()->FlipVertical(mCurrentReverse);
	

	if (mCurrentAnim != nullptr)
	{
		mCurrentAnim->SetPosition(this->GetPosition());
		mCurrentAnim->Draw(position, sourceRect, D3DXVECTOR2(), transform, angle, rotationCenter, colorKey);
		
	}
}

RECT Apple::GetBound()
{

	RECT rect;
	rect.left = this->posX - width/2;// -mCurrentAnim->GetSprite()->GetWidth() / 2;
	rect.right = rect.left +width;// +mCurrentAnim->GetSprite()->GetWidth();
	rect.top = this->posY - height/2;// -mCurrentAnim->GetSprite()->GetHeight() / 2;
	rect.bottom = rect.top +height;// +mCurrentAnim->GetSprite()->GetHeight();

	return rect;
}

void Apple::SetState(AppleState::StateName newState)
{
	switch (newState)
	{
	case AppleState::Flying:
		curState = new AppleFlyState(D3DXVECTOR3(posX, posY, 0), mReverse,mType);
		break;
	case AppleState::Breaking:
		curState = new AppleBreakState(D3DXVECTOR3(posX, posY, 0));
		break;
	case AppleState::NONE:
		curState = nullptr;
		mCurrentAnim = nullptr;
		return;
		break;
	}

	this->changeAnim(newState);
}

void Apple::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	
	SetState(AppleState::Breaking);
}
AppleState::StateName Apple::GetCurrentState()
{
	if (curState == nullptr) return AppleState::NONE;
	else return curState->GetNameState();
}