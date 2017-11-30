#include "Boss.h"


vector<RECT> Boss::LoadRECT(BossState::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	switch (state)
	{
	case BossState::StandHuman:
		rect.left = 8; rect.top = 9; rect.right = rect.left + 64; rect.bottom = rect.top + 70; listSourceRect.push_back(rect);
		rect.left = 80; rect.top = 10; rect.right = rect.left + 57; rect.bottom = rect.top + 69; listSourceRect.push_back(rect);
		rect.left = 144; rect.top = 11; rect.right = rect.left + 55; rect.bottom = rect.top + 68; listSourceRect.push_back(rect);
		rect.left = 208; rect.top = 12; rect.right = rect.left + 51; rect.bottom = rect.top + 67; listSourceRect.push_back(rect);
		rect.left = 272; rect.top = 11; rect.right = rect.left + 64; rect.bottom = rect.top + 68; listSourceRect.push_back(rect);
		break;
	case BossState::StandSnake:
		rect.left = 240; rect.top = 104; rect.right = rect.left + 71; rect.bottom = rect.top + 71; listSourceRect.push_back(rect);
		rect.left = 320; rect.top = 92; rect.right = rect.left + 68; rect.bottom = rect.top + 83; listSourceRect.push_back(rect);
		rect.left = 400; rect.top = 93; rect.right = rect.left + 68; rect.bottom = rect.top + 82; listSourceRect.push_back(rect);
		rect.left = 480; rect.top = 94; rect.right = rect.left + 69; rect.bottom = rect.top + 81; listSourceRect.push_back(rect);
		rect.left = 560; rect.top = 94; rect.right = rect.left + 69; rect.bottom = rect.top + 81; listSourceRect.push_back(rect);
		rect.left = 644; rect.top = 93; rect.right = rect.left + 63; rect.bottom = rect.top + 83; listSourceRect.push_back(rect);
		break;
	case BossState::Magnet:
		rect.left = 8; rect.top = 9; rect.right = rect.left + 64; rect.bottom = rect.top + 70; listSourceRect.push_back(rect);
		rect.left = 80; rect.top = 10; rect.right = rect.left + 57; rect.bottom = rect.top + 69; listSourceRect.push_back(rect);
		rect.left = 144; rect.top = 11; rect.right = rect.left + 55; rect.bottom = rect.top + 68; listSourceRect.push_back(rect);
		rect.left = 208; rect.top = 12; rect.right = rect.left + 51; rect.bottom = rect.top + 67; listSourceRect.push_back(rect);
		rect.left = 272; rect.top = 11; rect.right = rect.left + 64; rect.bottom = rect.top + 68; listSourceRect.push_back(rect);
		rect.left = 344; rect.top = 11; rect.right = rect.left + 82; rect.bottom = rect.top + 68; listSourceRect.push_back(rect);
		rect.left = 440; rect.top = 11; rect.right = rect.left + 85; rect.bottom = rect.top + 68; listSourceRect.push_back(rect);
		rect.left = 536; rect.top = 11; rect.right = rect.left + 68; rect.bottom = rect.top + 68; listSourceRect.push_back(rect);
		break;
	case BossState::FightingSnake:
	
		rect.left = 320; rect.top = 92; rect.right = rect.left + 68; rect.bottom = rect.top + 83; listSourceRect.push_back(rect);
		rect.left = 400; rect.top = 93; rect.right = rect.left + 68; rect.bottom = rect.top + 82; listSourceRect.push_back(rect);
		rect.left = 480; rect.top = 94; rect.right = rect.left + 69; rect.bottom = rect.top + 81; listSourceRect.push_back(rect);
		rect.left = 560; rect.top = 94; rect.right = rect.left + 69; rect.bottom = rect.top + 81; listSourceRect.push_back(rect);
		rect.left = 644; rect.top = 93; rect.right = rect.left + 63; rect.bottom = rect.top + 83; listSourceRect.push_back(rect);
		rect.left = 716; rect.top = 95; rect.right = rect.left + 64; rect.bottom = rect.top + 81; listSourceRect.push_back(rect);
		rect.left = 788; rect.top = 116; rect.right = rect.left + 71; rect.bottom = rect.top + 60; listSourceRect.push_back(rect);

		rect.left = 8; rect.top = 118; rect.right = rect.left + 70; rect.bottom = rect.top + 57; listSourceRect.push_back(rect);
		rect.left = 88; rect.top = 112; rect.right = rect.left + 64; rect.bottom = rect.top + 63; listSourceRect.push_back(rect);
		rect.left = 160; rect.top = 104; rect.right = rect.left + 67; rect.bottom = rect.top + 71; listSourceRect.push_back(rect);
		rect.left = 240; rect.top = 104; rect.right = rect.left + 71; rect.bottom = rect.top + 71; listSourceRect.push_back(rect);
		break;
	case BossState::Die:
		break;
	default:
		break;
	}
	return listSourceRect;
}
Boss::Boss(Player* player)
{
	mPlayer = player;
	mAnimationStandHuman= new Animation("Resources/jafar.png", 5, LoadRECT(BossState::StandHuman), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202));
	mAnimationMagnet= new Animation("Resources/jafar.png", 8, LoadRECT(BossState::Magnet), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202));
	mAnimationFightingSnake =new Animation("Resources/jafar.png", 11, LoadRECT(BossState::FightingSnake), (float)1 / 0.5, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202));
	mAnimationStandSnake= new Animation("Resources/jafar.png",6, LoadRECT(BossState::StandSnake), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202));
	
	RECT rect;
	rect.left = 198; rect.top = 226; rect.right = rect.left + 27; rect.bottom = rect.top + 13; 
	star1 = new Sprite("Resources/jafar.png", rect, 0, 0, D3DCOLOR_XRGB(186, 254, 202));

	rect.left = 238; rect.top = 224; rect.right = rect.left + 23; rect.bottom = rect.top + 15;
	star2 = new Sprite("Resources/jafar.png", rect, 0, 0, D3DCOLOR_XRGB(186, 254, 202));

	rect.left = 270; rect.top = 225; rect.right = rect.left + 25; rect.bottom = rect.top + 14;
	star3 = new Sprite("Resources/jafar.png", rect, 0, 0, D3DCOLOR_XRGB(186, 254, 202));

	this->mData = new BossData();
	this->mData->boss = this;

	SetState(new BossMagnetState(mData));
}


Boss::~Boss()
{
}
void Boss::Update()
{

	mCurrentAnimation->Update(1);
	if (this->mData->state)
	{
		this->mData->state->Update();
	}
	
}
void Boss::DrawStar(D3DXVECTOR2 transform)
{
	//srand(time(NULL));
	for (int i = 0; i < starPos.size(); i++)
	{
		int a = rand() % 3 + 1;
		if(a==1)
			star1->Draw(D3DXVECTOR3(starPos.at(i).x, starPos.at(i).y - a*4, 0), RECT(), D3DXVECTOR2(), transform); 
		if (a == 2)
			star2->Draw(D3DXVECTOR3(starPos.at(i).x, starPos.at(i).y +a*4, 0), RECT(), D3DXVECTOR2(), transform);
		if (a == 3)
			star3->Draw(D3DXVECTOR3(starPos.at(i).x, starPos.at(i).y -a*4, 0), RECT(), D3DXVECTOR2(), transform);
		
		
	}
}
void Boss::Draw(D3DXVECTOR2 transform)
{
	if (mData->boss->mPlayer->GetPosition().x < mData->boss->GetPosition().x) 	mCurrentAnimation->GetSprite()->FlipVertical(true);
	else if (mData->boss->mPlayer->GetPosition().x > mData->boss->GetPosition().x) mCurrentAnimation->GetSprite()->FlipVertical(false);
	mCurrentAnimation->SetPosition(GetPosition());
	mCurrentAnimation->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);
	
	if(mCurrentState==BossState::Magnet  && mCurrentAnimation->GetCurrentFrame()==6)
	DrawStar(transform);
	

	
}

void Boss::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{

}
void Boss::SetState(BossState *newState)
{
	delete this->mData->state;

	this->mData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
void Boss::changeAnimation(BossState::StateName state)
{
	switch (state)
	{
	case BossState::None:
		mCurrentAnimation = nullptr;
		break;
	case BossState::StandHuman:
		mCurrentAnimation = mAnimationStandHuman;
		break;
	case BossState::StandSnake:
		mCurrentAnimation = mAnimationStandSnake;
		break;
	case BossState::Magnet:
		mCurrentAnimation = mAnimationMagnet;
		break;
	case BossState::FightingSnake:
		mCurrentAnimation = mAnimationFightingSnake;
		break;
	default:
		break;
	}

	this->width = mCurrentAnimation->GetSprite()->GetWidth();
	this->height = mCurrentAnimation->GetSprite()->GetHeight();
}


Animation* Boss::GetCurrentAnimation()
{
	return mCurrentAnimation;
}
RECT Boss::GetBound()
{
	RECT rect;
	rect.left = this->posX - mCurrentAnimation->GetSprite()->GetWidth() / 2;
	rect.right = rect.left + mCurrentAnimation->GetSprite()->GetWidth();
	rect.top = this->posY - mCurrentAnimation->GetSprite()->GetHeight(); //Chú ý đoạn này
	rect.bottom = this->posY;

	float cWidth = this->posX;
	float cHeight = this->posY - mCurrentAnimation->GetSprite()->GetHeight() / 2;
	SetCenter(D3DXVECTOR2(cWidth, cHeight));
	return rect;
}