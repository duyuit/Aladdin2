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

	}
	return listSourceRect;
}
vector<RECT> Boss::LoadRectFire()
{
	vector<RECT> listSourceRect;
	RECT rect;
	rect.left = 14; rect.top = 193; rect.right = rect.left + 24; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
	rect.left = 46; rect.top = 187; rect.right = rect.left + 21; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
	rect.left = 78; rect.top = 193; rect.right = rect.left + 24; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
	rect.left = 110; rect.top = 190; rect.right = rect.left + 27; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
	rect.left = 150; rect.top = 194; rect.right = rect.left + 35; rect.bottom = rect.top + 45; listSourceRect.push_back(rect);
	return listSourceRect;
}
Boss::Boss(Player* player, D3DXVECTOR3 pos)
{
	SetPosition(pos);
	mPlayer = player;
	mPlayer->AppleCount = 50;
	mAnimationStandHuman = new Animation("Resources/jafar.png", 5, LoadRECT(BossState::StandHuman), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202),Entity::jafar);
	mAnimationMagnet = new Animation("Resources/jafar.png", 8, LoadRECT(BossState::Magnet), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202), Entity::jafar);
	mAnimationFightingSnake = new Animation("Resources/jafar.png", 11, LoadRECT(BossState::FightingSnake), (float)1 / 0.25, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202), Entity::jafar);
	mAnimationStandSnake = new Animation("Resources/jafar.png", 6, LoadRECT(BossState::StandSnake), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202), Entity::jafar);

	mAnimationFire1 = new Animation("Resources/jafar.png", 5, LoadRectFire(), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202), Entity::jafar);
	mAnimationFire2 = new Animation("Resources/jafar.png", 5, LoadRectFire(), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202), Entity::jafar);
	mAnimationFire3 = new Animation("Resources/jafar.png", 5, LoadRectFire(), (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202), Entity::jafar);
	mAnimationFire1->SetScale(D3DXVECTOR2(1, 1.5));
	mAnimationFire2->SetScale(D3DXVECTOR2(1, 1.5));
	mAnimationFire3->SetScale(D3DXVECTOR2(1, 1));
	mAnimationFire1->SetPosition(GetPosition().x - 30, GetPosition().y);
	mAnimationFire2->SetPosition(GetPosition().x + 30, GetPosition().y);
	mAnimationFire3->SetPosition(GetPosition());


	RECT rect;
	rect.left = 198; rect.top = 226; rect.right = rect.left + 27; rect.bottom = rect.top + 13;
	star1 = new Sprite("Resources/jafar.png", rect, 0, 0, D3DCOLOR_XRGB(186, 254, 202),D3DXVECTOR2(0.5,0.5),GameGlobal::mJafartexture);

	rect.left = 238; rect.top = 224; rect.right = rect.left + 23; rect.bottom = rect.top + 15;
	star2 = new Sprite("Resources/jafar.png", rect, 0, 0, D3DCOLOR_XRGB(186, 254, 202), D3DXVECTOR2(0.5, 0.5), GameGlobal::mJafartexture);

	rect.left = 270; rect.top = 225; rect.right = rect.left + 25; rect.bottom = rect.top + 14;
	star3 = new Sprite("Resources/jafar.png", rect, 0, 0, D3DCOLOR_XRGB(186, 254, 202), D3DXVECTOR2(0.5, 0.5), GameGlobal::mJafartexture);

	this->mData = new BossData();
	this->mData->boss = this;

	SetState(new BossSummon(mData));

	rect.left = 0; rect.top = 0; rect.right = rect.left + 173; rect.bottom = rect.top + 105;
	arg = new Sprite("Resources/arg.png", rect, 0, 0, D3DCOLOR_XRGB(255, 0, 255), D3DXVECTOR2(0.5, 0.5));
	arg->SetScale(D3DXVECTOR2(0.5, 0.5));
	arg->SetPosition(350, 180);


	rect.left = 0; rect.top = 0; rect.right = 76; rect.bottom = 12;
	hp_green = new Sprite("Resources/hp_green.png", rect); hp_green->SetPosition(GetPosition().x, GetPosition().y - 120);
	hp_yellow = new Sprite("Resources/hp_yellow.png", rect); hp_yellow->SetPosition(GetPosition().x, GetPosition().y - 120);
	hp_red = new Sprite("Resources/hp_red.png", rect); hp_red->SetPosition(GetPosition().x, GetPosition().y - 120);
	hp_white = new Sprite("Resources/hp_white.png", rect); hp_white->SetPosition(GetPosition().x, GetPosition().y - 120);



	listAmmo.push_back(new FireAmmo(D3DXVECTOR2(GetPosition().x, GetPosition().y)));
	listAmmo.push_back(new FireAmmo(D3DXVECTOR2(GetPosition().x, GetPosition().y)));
	listAmmo.push_back(new FireAmmo(D3DXVECTOR2(GetPosition().x, GetPosition().y)));

	
	listMeteor.push_back(new Apple(Entity::Meteor));
	lastTimeCreateMeteor = GetTickCount();
}


Boss::~Boss()
{
}
void Boss::Update()
{
	if (GetTickCount() - lastTimeCreateMeteor >= 3500 && listMeteor.size() <2)
	{
		listMeteor.push_back(new Apple(Entity::Meteor));
		lastTimeCreateMeteor = GetTickCount();
	}

	if(mCurrentState==BossState::MeteorSummon || mCurrentState == BossState::StandHuman || mCurrentState == BossState::Magnet)
		for (int i = 0; i < listMeteor.size(); i++)
	{

		if (listMeteor.at(i)->GetCurrentState() == AppleState::NONE)
		{
			int left = mPlayer->GetPosition().x - 100;
			int right = mPlayer->GetPosition().x + 100;
			int a = rand() %  (right-left +1) + left;
			listMeteor.at(i)->SetPosition(a, 50);

			listMeteor.at(i)->SetState(AppleState::Flying);
		}
		else
		listMeteor.at(i)->Update(1);

	}


	if (mData->boss->mPlayer->GetPosition().x < mData->boss->GetPosition().x)
		Reverse = true; 
	else if (mData->boss->mPlayer->GetPosition().x > mData->boss->GetPosition().x) 
		Reverse = false; 

	if (BossAttacked)
	{
		if ((GetTickCount() - lastTimeBossAttacked) / 1000.0f >= 0.7f)
			BossAttacked = false;
	}
	if (HPCount < 22 && HPCount > 12 && mCurrentState != BossState::StandHuman  && mCurrentState != BossState::Magnet)
	{
		SetState(new BossMagnetState(mData));
		return;
	}
	if (HPCount == 12 && mCurrentState != BossState::FightingSnake &&  mCurrentState != BossState::StandSnake)
	{
		SetState(new BossFightingSnake(mData));
		return;
	}

	if (mCurrentState == BossState::FightingSnake || mCurrentState == BossState::StandSnake)
	{

		mAnimationFire1->Update(1);
		mAnimationFire2->Update(1);
		mAnimationFire3->Update(1);
	}
	mCurrentAnimation->Update(1);
	

	if (this->mData->state)
	{
		this->mData->state->Update();
	}

	
	for (int i = 0; i < listAmmo.size(); i++)
	{
		listAmmo.at(i)->Update();
	}
	
	int temp;
	if (HPCount >= 22 && HPCount <= 30)
		temp = 30 - HPCount;
	else 
	if (HPCount > 12 && HPCount <= 21)
		 temp = 21 - HPCount;
	else if (HPCount >= 2 && HPCount <= 12)
		temp = 12 - HPCount;
	else return;

	RECT rect{ 0,0,(float)(9 - temp)* (76 / 9.0f),12 };
	hp_yellow->SetSourceRect(rect);
	hp_green->SetSourceRect(rect);
	hp_red->SetSourceRect(rect);




	
		
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
	if (mCurrentState == BossState::FightingSnake || mCurrentState == BossState::StandSnake)
	{
		mAnimationFire1->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);
		mAnimationFire2->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);

	}

	mCurrentAnimation->GetSprite()->FlipVertical(Reverse);
	mCurrentAnimation->SetPosition(GetPosition());
	mCurrentAnimation->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);
	
	if(mCurrentState==BossState::Magnet  && mCurrentAnimation->GetCurrentFrame()==6)
	DrawStar(transform);
	
	if (BossAttacked)
	arg->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);

	if (mCurrentState == BossState::FightingSnake || mCurrentState == BossState::StandSnake)
		mAnimationFire3->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);

	
	for (int i = 0; i <  listAmmo.size(); i++)
	{
		listAmmo.at(i)->Draw(transform);
	}
	hp_white->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);
	if(HPCount >= 22 && HPCount <= 30)
		hp_green->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(),transform, 0, D3DXVECTOR2(0, 0.5));
	else
		if(HPCount > 12 && HPCount <= 21)
			hp_yellow->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform, 0, D3DXVECTOR2(0, 0.5));
	else 
		if (HPCount >= 1 && HPCount <= 12)
			hp_red->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform, 0, D3DXVECTOR2(0, 0.5));

	if (mCurrentState == BossState::MeteorSummon || mCurrentState == BossState::StandHuman || mCurrentState == BossState::Magnet)
	for (int i = 0; i < listMeteor.size(); i++)
	{
		if (listMeteor.at(i)->GetCurrentState() != AppleState::NONE)
			listMeteor.at(i)->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), transform);

	}

}

void Boss::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	if (impactor->Tag == Entity::AppleThrow)
	{
		HPCount--; 
		lastTimeBossAttacked = GetTickCount();
		BossAttacked = true;
	}
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
	case BossState::MeteorSummon:
		mCurrentAnimation = mAnimationStandHuman;
		break;
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