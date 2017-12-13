#include "Enemy3.h"


vector<RECT> Enemy3::LoadRECT(Enemy3State::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	switch (state)
	{
	case Enemy3State::Die:
		rect.left = 342; rect.top = 23; rect.right = rect.left + 29; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
		rect.left = 383; rect.top = 22; rect.right = rect.left + 31; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
		rect.left = 423; rect.top = 9; rect.right = rect.left + 44; rect.bottom = rect.top + 44; listSourceRect.push_back(rect);
		rect.left = 383; rect.top = 22; rect.right = rect.left + 31; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
		rect.left = 342; rect.top = 23; rect.right = rect.left + 29; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
		break;

	case Enemy3State::None:
		break;
	case Enemy3State::Running:
		rect.left = 7; rect.top = 784; rect.right = rect.left + 36; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 52; rect.top = 786; rect.right = rect.left + 34; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 93; rect.top = 789; rect.right = rect.left + 36; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
		rect.left = 133; rect.top = 781; rect.right = rect.left + 38; rect.bottom = rect.top + 54; listSourceRect.push_back(rect);
		rect.left = 178; rect.top = 776; rect.right = rect.left + 43; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 233; rect.top = 781; rect.right = rect.left + 38; rect.bottom = rect.top + 54; listSourceRect.push_back(rect);
		rect.left = 281; rect.top = 788; rect.right = rect.left + 36; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 323; rect.top = 785; rect.right = rect.left + 33; rect.bottom = rect.top + 50; listSourceRect.push_back(rect);
		break;
	case Enemy3State::Fighting:
		rect.left = 2; rect.top = 842; rect.right = rect.left + 55; rect.bottom = rect.top + 57; listSourceRect.push_back(rect);
		rect.left = 68; rect.top = 844; rect.right = rect.left + 36; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 115; rect.top = 850; rect.right = rect.left + 60; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 182; rect.top = 856; rect.right = rect.left + 45; rect.bottom = rect.top + 43; listSourceRect.push_back(rect);
		rect.left = 236; rect.top = 848; rect.right = rect.left + 32; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 9; rect.top = 663; rect.right = rect.left + 43; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 9; rect.top = 663; rect.right = rect.left + 43; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 9; rect.top = 663; rect.right = rect.left + 43; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 9; rect.top = 663; rect.right = rect.left + 43; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		break;
	case Enemy3State::Attacked:
		rect.left = 4; rect.top = 919; rect.right = rect.left + 54; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 63; rect.top = 920; rect.right = rect.left + 55; rect.bottom = rect.top + 50; listSourceRect.push_back(rect);
		rect.left = 124; rect.top = 921; rect.right = rect.left + 55; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 185; rect.top = 921; rect.right = rect.left + 55; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 246; rect.top = 923; rect.right = rect.left + 65; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 322; rect.top = 906; rect.right = rect.left + 68; rect.bottom = rect.top + 64; listSourceRect.push_back(rect);
		rect.left = 399; rect.top = 910; rect.right = rect.left + 68; rect.bottom = rect.top + 60; listSourceRect.push_back(rect);
		rect.left = 399; rect.top = 910; rect.right = rect.left + 68; rect.bottom = rect.top + 60; listSourceRect.push_back(rect);
		rect.left = 399; rect.top = 910; rect.right = rect.left + 68; rect.bottom = rect.top + 60; listSourceRect.push_back(rect);
		rect.left = 399; rect.top = 910; rect.right = rect.left + 68; rect.bottom = rect.top + 60; listSourceRect.push_back(rect);
		break;
	default:
		break;
	}
	return listSourceRect;
}
Enemy3::Enemy3(Player *player, vector<D3DXVECTOR2> list)
{
	mPlayer = player;
	mListPosition = list;
	

	mAnimationRunning = new Animation("Resources/guard.png", 8, LoadRECT(Enemy3State::Running), (float)1 / 1, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationFighting = new Animation("Resources/guard.png",9, LoadRECT(Enemy3State::Fighting), (float)1 / 0.2, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationAttacked = new Animation("Resources/guard.png",10, LoadRECT(Enemy3State::Attacked), (float)1 / 0.25, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationDied = new Animation("Resources/flare.png", 5, LoadRECT(Enemy3State::Die), (float)1 / 0.5, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202),Entity::flare);
	mAnimationDied->SetScale(D3DXVECTOR2(1.5, 1.5));

	RECT rect;
	rect.left = 9; rect.top = 663; rect.right = rect.left + 43; rect.bottom = rect.top + 49; 
	mSprite = new Sprite("Resources/guard.png", rect, 0, 0, D3DCOLOR_XRGB(120, 193, 152), D3DXVECTOR2(0.5, 1),GameGlobal::mEnemytexture);

	mCurrentAnimation = nullptr;
	mCurrentState = Enemy3State::None;
	Tag = EntityTypes::Enemy;
	this->mData = new Enemy3Data();
	this->mData->enemy = this;


	mKnife = new Apple(Entity::KnifeEnemy3);
	mKnife->SetState(AppleState::NONE);


}


Enemy3::~Enemy3()
{

}

void Enemy3::Update()
{
	

	CheckAction();

	mKnife->Update(1);
	mKnife->mReverse = !Reverse;


	if (Heal == 0)
	{
		positionted.push_back(CurrentPosIndex);
		SetState(new Enemy3Die(this->mData));
	}

	if (mCurrentState != Enemy3State::Attacked && mCurrentState != Enemy3State::Die)
	{
		if (CheckFire)
		{
			
			SetState(new Enemy3Fighting(this->mData));
			if (mKnife->GetCurrentState() == AppleState::NONE)
			{
				mKnife->SetPosition(GetPosition().x,GetPosition().y-50);
				mKnife->SetState(AppleState::Flying);
			}
		}

		if (CheckRunning)
			SetState(new Enemy3Running(this->mData));

		if (!CheckFire && !CheckRunning)
		{
			mCurrentState = Enemy3State::None;
		}

	}





	if (mCurrentState != Enemy3State::None && mCurrentAnimation != nullptr)
	{

		mCurrentAnimation->Update(1);
		if (this->mData->state)
		{
			this->mData->state->Update();
		}
	}

	

	if (GetPosition().x < mPlayer->GetPosition().x)
		Reverse = true;
	else
		Reverse = false;


}
void Enemy3::Draw(D3DXVECTOR2 transform)
{


	if (mCurrentAnimation != nullptr && mCurrentState != Enemy3State::None)
	{
		mCurrentAnimation->SetPosition(this->GetPosition());

		mCurrentAnimation->GetSprite()->FlipVertical(Reverse);
		mCurrentAnimation->GetSprite()->SetTranslation(transform);
		mCurrentAnimation->Draw();

	}

	else
	{
		mSprite->FlipVertical(Reverse);
		mSprite->SetTranslation(transform);
		mSprite->SetPosition(GetPosition());
		mSprite->Draw();
	}

	
	mKnife->Draw(D3DXVECTOR3(),RECT(),D3DXVECTOR2(1,1),transform);


}

void Enemy3::SetState(Enemy3State *newState)
{
	delete this->mData->state;

	this->mData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
RECT Enemy3::GetBound()
{
	RECT rect;
	if (mCurrentAnimation == nullptr)
	{
		rect.left = this->posX - mSprite->GetWidth() / 2;
		rect.right = rect.left + mSprite->GetWidth();
		rect.top = this->posY - mSprite->GetHeight(); //Chú ý đoạn này
		rect.bottom = this->posY;// + mCurrentAnimation->GetSprite()->GetHeight() / 2;
		return rect;
	}

	rect.left = this->posX - mCurrentAnimation->GetSprite()->GetWidth() / 2;
	rect.right = rect.left + mCurrentAnimation->GetSprite()->GetWidth();
	rect.top = this->posY - mCurrentAnimation->GetSprite()->GetHeight(); //Chú ý đoạn này
	rect.bottom = this->posY;// + mCurrentAnimation->GetSprite()->GetHeight() / 2;

	float cWidth = this->posX;
	float cHeight = this->posY - mCurrentAnimation->GetSprite()->GetHeight() / 2;
	SetCenter(D3DXVECTOR2(cWidth, cHeight));
	return rect;
}

void Enemy3::changeAnimation(Enemy3State::StateName state)
{
	switch (state)
	{
	case Enemy3State::None:
		mCurrentAnimation = nullptr;
		break;
	case Enemy3State::Running:
		mCurrentAnimation = mAnimationRunning;
		break;
	case Enemy3State::Fighting:
		mCurrentAnimation = mAnimationFighting;
		break;
	case Enemy3State::Attacked:
		mCurrentAnimation = mAnimationAttacked;
		break;
	case Enemy3State::Die:
		mCurrentAnimation = mAnimationDied;
		break;
	default:
		break;
	}

	this->width = mCurrentAnimation->GetSprite()->GetWidth();
	this->height = mCurrentAnimation->GetSprite()->GetHeight();
}
void Enemy3::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{

	if (this->mPlayer->getState() == PlayerState::Fighting || (impactor->Tag == Entity::AppleThrow && impactor->GetPosition().x != 0))
	{
		SetState(new Enemy3Attacked(this->mData));
	}
	if (mCurrentState == Enemy3State::Fighting && mCurrentAnimation->GetCurrentFrame() == 4 && mPlayer->mCurrentState != PlayerState::Fired)
	{
		mPlayer->SetState(new PlayerFiredState(mPlayer->mPlayerData));
	}
	if (this->mData->state)
		this->mData->state->OnCollision(impactor, side, data);
}
void Enemy3::CheckAction()
{
	for (int i = 0; i < mListPosition.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j<positionted.size(); j++)
			if (i == positionted.at(j))
			{
				flag = true;
				break;
			}
		if (flag) continue;
		if (abs(mPlayer->GetPosition().y - mListPosition.at(i).y) >= 60) continue;
		int deltay = abs(mPlayer->GetPosition().y - mListPosition.at(i).y);
		int deltax = abs(mPlayer->GetPosition().x - mListPosition.at(i).x);
		if (deltax <= 300 && deltay <= 100)
		{
			if (i == CurrentPosIndex) continue;
			SetPosition(mListPosition.at(i));
			CurrentPosIndex = i;
			break;
		}
	}


	int deltax = abs(GetPosition().x - mPlayer->GetPosition().x);
	if (deltax > 200)
	{
		CheckRunning = false;
		CheckFire = false;
		return;
	}
	if (deltax <=200 && deltax >= 100)
	{
		CheckRunning = true;
		CheckFire = false;
	}
	if (deltax <=150)
	{
		CheckRunning = false;
		CheckFire = true;
	}
}
Animation* Enemy3::GetCurrentAnimation()
{
	return mCurrentAnimation;
} 