#include "Apple.h"


vector<RECT> LoadRECT(AppleState::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
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
Apple::Apple()
{
	FlyingAnim = new Animation("Resources/Aladdin.png", 8, LoadRECT(AppleState::Flying), (float)1 / 20,D3DXVECTOR2(0.5,0.5), D3DCOLOR_XRGB(255, 0, 255));
	BreakingAnim = new Animation("Resources/Aladdin.png", 5, LoadRECT(AppleState::Breaking), (float)1 / 20, D3DXVECTOR2(0.5,0.5), D3DCOLOR_XRGB(255, 0, 255));
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
		//FlyingAnim->Reset();
		mCurrentAnim = FlyingAnim;
		BreakingAnim->Reset();
		break;

	case AppleState::Breaking:
		
		mCurrentAnim = BreakingAnim;
		FlyingAnim->Reset();
		break;

	}
	this->width = mCurrentAnim->GetSprite()->GetWidth();
	this->height = mCurrentAnim->GetSprite()->GetHeight();
}

void Apple::Update(float dt)
{

	if (mCurrentAnim != nullptr)
	{
		if (mCurrentAnim == BreakingAnim)
		{
			if (mCurrentAnim->GetCurrentFrame() == 4)
			{
				this->SetState(AppleState::NONE);
				return;
			}
		}
		mCurrentAnim->Update(dt);
	}
	else return;
	if (curState != nullptr)
	{
		curState->Update(dt);
		posX = curState->getPos().x;
		posY = curState->getPos().y;
	}
	else return;
}
void Apple::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	//mCurrentAnimation->GetSprite()->FlipVertical(mCurrentReverse);
	

	if (mCurrentAnim != nullptr)
	{
		mCurrentAnim->SetPosition(this->GetPosition());
		mCurrentAnim->Draw(position, sourceRect, D3DXVECTOR2(2, 2), transform, angle, rotationCenter, colorKey);
		
	}
}

RECT Apple::GetBound()
{
	RECT rect;
	rect.left = this->posX - mCurrentAnim->GetSprite()->GetWidth() / 2;
	rect.right = rect.left + mCurrentAnim->GetSprite()->GetWidth();
	rect.top = this->posY - mCurrentAnim->GetSprite()->GetHeight() / 2;
	rect.bottom = rect.top + mCurrentAnim->GetSprite()->GetHeight();

	return rect;
}

void Apple::SetState(AppleState::StateName newState)
{
	switch (newState)
	{
	case AppleState::Flying:
		curState = new AppleFlyState(D3DXVECTOR3(posX, posY, 0), mReverse);
		break;
	case AppleState::Breaking:
		curState = new AppleBreakState(D3DXVECTOR3(posX, posY, 0));
		break;
	default:
		curState = nullptr;
		mCurrentAnim = nullptr;
		return;
		break;
	}

	this->changeAnim(newState);
}