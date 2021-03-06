#include "Apple.h"


vector<RECT> Apple::LoadRECT(AppleState::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	if(Tag == EntityTypes::Bowl)
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
		if (Tag == EntityTypes::Meteor)
			switch (state)
			{
			case AppleState::Flying:

				rect.left = 171; rect.top = 240; rect.right = rect.left + 74; rect.bottom = rect.top + 213; listSourceRect.push_back(rect);
				rect.left = 457; rect.top = 223; rect.right = rect.left + 76; rect.bottom = rect.top + 234; listSourceRect.push_back(rect);
				rect.left = 750; rect.top = 250; rect.right = rect.left + 73; rect.bottom = rect.top + 205; listSourceRect.push_back(rect);
				rect.left = 1041; rect.top = 229; rect.right = rect.left + 74; rect.bottom = rect.top + 226; listSourceRect.push_back(rect);
				rect.left = 169; rect.top = 570; rect.right = rect.left + 74; rect.bottom = rect.top + 174; listSourceRect.push_back(rect);
				rect.left = 459; rect.top = 566; rect.right = rect.left + 75; rect.bottom = rect.top + 178; listSourceRect.push_back(rect);
				rect.left = 749; rect.top = 518; rect.right = rect.left + 74; rect.bottom = rect.top + 226; listSourceRect.push_back(rect);
				rect.left = 1039; rect.top = 595; rect.right = rect.left + 73; rect.bottom = rect.top + 148; listSourceRect.push_back(rect);
				rect.left = 170; rect.top = 884; rect.right = rect.left + 76; rect.bottom = rect.top + 149; listSourceRect.push_back(rect);
				rect.left = 460; rect.top = 846; rect.right = rect.left + 74; rect.bottom = rect.top + 187; listSourceRect.push_back(rect);
				rect.left = 750; rect.top = 814; rect.right = rect.left + 73; rect.bottom = rect.top + 219; listSourceRect.push_back(rect);
				rect.left = 1042; rect.top = 802; rect.right = rect.left + 74; rect.bottom = rect.top + 230; listSourceRect.push_back(rect);

				break;
			case AppleState::Breaking:
				rect.left = 56; rect.top = 50; rect.right = rect.left + 47; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
				rect.left = 190; rect.top = 32; rect.right = rect.left + 77; rect.bottom = rect.top + 75; listSourceRect.push_back(rect);
				rect.left = 322; rect.top = 18; rect.right = rect.left + 113; rect.bottom = rect.top + 102; listSourceRect.push_back(rect);
				rect.left = 497; rect.top = 7; rect.right = rect.left + 140; rect.bottom = rect.top + 125; listSourceRect.push_back(rect);
				rect.left = 41; rect.top = 189; rect.right = rect.left + 136; rect.bottom = rect.top + 130; listSourceRect.push_back(rect);
				rect.left = 273; rect.top = 183; rect.right = rect.left + 149; rect.bottom = rect.top + 152; listSourceRect.push_back(rect);
				rect.left = 744; rect.top = 194; rect.right = rect.left + 126; rect.bottom = rect.top + 113; listSourceRect.push_back(rect);
				break;
			case AppleState::NONE:
				break;
			default:
				break;
			}
	else
		if (Tag == EntityTypes::AppleThrow)
	{
			switch (state)
			{
			case AppleState::Flying:

				rect.top = 22;
				rect.bottom = 33;
				rect.left = 370;
				rect.right = rect.left + 12;
				listSourceRect.push_back(rect);


				rect.top = 23;
				rect.bottom = rect.top + 11;
				rect.left = 583;
				rect.right = rect.left + 10;
				listSourceRect.push_back(rect);


				rect.top = 25;
				rect.bottom = rect.top + 9;
				rect.left = 607;
				rect.right = rect.left + 8;
				listSourceRect.push_back(rect);


				rect.top = 25;
				rect.bottom = rect.top + 10;
				rect.left = 623;
				rect.right = rect.left + 10;
				listSourceRect.push_back(rect);


				rect.top = 24;
				rect.bottom = rect.top + 9;
				rect.left = 639;
				rect.right = rect.left + 10;
				listSourceRect.push_back(rect);


				rect.top = 25;
				rect.bottom = rect.top + 9;
				rect.left = 656;
				rect.right = rect.left + 8;
				listSourceRect.push_back(rect);


				rect.top = 23;
				rect.bottom = rect.top + 11;
				rect.left = 670;
				rect.right = rect.left + 8;
				listSourceRect.push_back(rect);


				rect.top = 41;
				rect.bottom = rect.top + 9;
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
	}
	else// if (Tag == EntityTypes::KnifeEnemy3)
	{
		switch (state)
		{
		case AppleState::Flying:

			rect.left = 73; rect.top = 678; rect.right = rect.left + 11; rect.bottom = rect.top + 24; listSourceRect.push_back(rect);
			rect.left = 97; rect.top = 680; rect.right = rect.left + 26; rect.bottom = rect.top + 16; listSourceRect.push_back(rect);
			rect.left = 130; rect.top = 675; rect.right = rect.left + 13; rect.bottom = rect.top + 25; listSourceRect.push_back(rect);
			rect.left = 152; rect.top = 682; rect.right = rect.left + 27; rect.bottom = rect.top + 19; listSourceRect.push_back(rect);
			rect.left = 190; rect.top = 677; rect.right = rect.left + 26; rect.bottom = rect.top + 26; listSourceRect.push_back(rect);
			rect.left = 225; rect.top = 675; rect.right = rect.left + 24; rect.bottom = rect.top + 22; listSourceRect.push_back(rect);
			rect.left = 261; rect.top = 678; rect.right = rect.left + 12; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);

			break;
		case AppleState::Breaking:
			rect.left = 758; rect.top = 31; rect.right = rect.left + 15; rect.bottom = rect.top + 10; listSourceRect.push_back(rect);
			rect.left = 756; rect.top = 32; rect.right = rect.left + 24; rect.bottom = rect.top + 18; listSourceRect.push_back(rect);
			rect.left = 731; rect.top = 25; rect.right = rect.left + 22; rect.bottom = rect.top + 23; listSourceRect.push_back(rect);
			rect.left = 794; rect.top = 23; rect.right = rect.left + 32; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);

			rect.left = 0; rect.top = 0; rect.right = rect.left + 0; rect.bottom = rect.top + 0; 
			listSourceRect.push_back(rect);
			listSourceRect.push_back(rect);
			listSourceRect.push_back(rect);
			listSourceRect.push_back(rect);
			listSourceRect.push_back(rect);
			listSourceRect.push_back(rect);

			break;
		case AppleState::NONE:
			break;
		default:
			break;
		}
	}
	
	return listSourceRect;
}
Apple::Apple(EntityTypes type)
{
	Tag = type;
	if (Tag == EntityTypes::Bowl)
	{
		FlyingAnim = new Animation("Resources/civilian.png", 6, LoadRECT(AppleState::Flying), (float)1 / 0.2, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(120, 193, 152), Entity::civilian);
		BreakingAnim = new Animation("Resources/civilian.png",8, LoadRECT(AppleState::Breaking), (float)1 /10, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(120, 193, 152), Entity::civilian);
		
	}
	else if (Tag == EntityTypes::AppleThrow)
	{
		FlyingAnim = new Animation("Resources/Aladdin.png", 8, LoadRECT(AppleState::Flying), (float)1 / 20, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255),Entity::PlayerOne);
		BreakingAnim = new Animation("Resources/Aladdin.png", 5, LoadRECT(AppleState::Breaking), (float)1 / 20, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255), Entity::PlayerOne);
		
	}
	else 
	if (Tag == EntityTypes::Meteor)
	{
		FlyingAnim = new Animation("Resources/meteor.png", 12, LoadRECT(AppleState::Flying), (float)1 / 10, D3DXVECTOR2(0.5,1), D3DCOLOR_XRGB(120, 193, 152));
		BreakingAnim = new Animation("Resources/meteor2.png", 7, LoadRECT(AppleState::Breaking), (float)1 / 10, D3DXVECTOR2(0.5,1), D3DCOLOR_XRGB(120, 193, 152));
		FlyingAnim->SetScale(D3DXVECTOR2(0.3, 0.3));
		BreakingAnim->SetScale(D3DXVECTOR2(0.3, 0.3));
	}
	else
	{
		FlyingAnim = new Animation("Resources/guard.png", 7, LoadRECT(AppleState::Flying), (float)1 / 20, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(120, 193, 152),Entity::Enemy);
	
		BreakingAnim = new Animation("Resources/Aladdin.png", 10, LoadRECT(AppleState::Breaking), (float)1 / 0.4, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255),Entity::PlayerOne);
		BreakingAnim->SetScale(D3DXVECTOR2(2, 2));
	}
	
	
	SetState(AppleState::NONE);

	mReverse = false;


}

Apple::~Apple()
{
	FlyingAnim->~Animation();
	BreakingAnim->~Animation();
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
		mCurrentAnim->Update(1);
		width = mCurrentAnim->GetSprite()->GetWidth();
		height = mCurrentAnim->GetSprite()->GetHeight();
		if (mCurrentAnim == BreakingAnim)
		{
			if (mCurrentAnim->GetCurrentFrame() == mCurrentAnim->GetTotalFrame() - 1)
			{
				this->SetState(AppleState::NONE);

			}
		}
	}
	
	if (curState != nullptr)
	{
		curState->Update(1);
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
	if (Tag != EntityTypes::Meteor)
	{
		rect.left = this->posX - width / 2;// -mCurrentAnim->GetSprite()->GetWidth() / 2;
		rect.right = rect.left + width;// +mCurrentAnim->GetSprite()->GetWidth();
		rect.top = this->posY - height / 2;// -mCurrentAnim->GetSprite()->GetHeight() / 2;
		rect.bottom = rect.top + height;// +mCurrentAnim->GetSprite()->GetHeight();
	}
	else
	{
		rect.left = this->posX - (width*0.3) / 2;// -mCurrentAnim->GetSprite()->GetWidth() / 2;
		rect.right = rect.left + width*0.3;// +mCurrentAnim->GetSprite()->GetWidth();
		rect.top = this->posY - height*0.3;// -mCurrentAnim->GetSprite()->GetHeight() / 2;
		rect.bottom = this->posY;// +mCurrentAnim->GetSprite()->GetHeight();
	}

	return rect;
}

void Apple::SetState(AppleState::StateName newState)
{
	switch (newState)
	{
	case AppleState::Flying:
		curState = new AppleFlyState(D3DXVECTOR3(posX, posY, 0), mReverse,Tag);
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
	if (impactor->Tag == Entity::AppleObject || GetPosition().x==0) return;
	if(Tag==Entity::AppleThrow) 	Sound::getInstance()->play("Apple Splat", false,1);
	if (Tag == Entity::Bowl) 	Sound::getInstance()->play("Clay Pot", false, 1);
	SetState(AppleState::Breaking);
}
AppleState::StateName Apple::GetCurrentState()
{
	if (curState == nullptr) return AppleState::NONE;
	else return curState->GetNameState();
}