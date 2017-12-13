#include "Enemy1.h"


vector<RECT> Enemy1::LoadRECT(Enemy1State::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	switch (state)
	{
	case Enemy1State::Die:
		rect.left = 342; rect.top = 23; rect.right = rect.left + 29; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
		rect.left = 383; rect.top = 22; rect.right = rect.left + 31; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
		rect.left = 423; rect.top = 9; rect.right = rect.left + 44; rect.bottom = rect.top + 44; listSourceRect.push_back(rect);
		rect.left = 383; rect.top = 22; rect.right = rect.left + 31; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
		rect.left = 342; rect.top = 23; rect.right = rect.left + 29; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
		break;

	case Enemy1State::None:
		break;
	case Enemy1State::Running:
		rect.left = 2; rect.top = 9; rect.right = rect.left + 45; rect.bottom = rect.top + 66; listSourceRect.push_back(rect);
		rect.left = 53; rect.top = 10; rect.right = rect.left + 45; rect.bottom = rect.top + 65; listSourceRect.push_back(rect);
		rect.left = 109; rect.top = 11; rect.right = rect.left + 45; rect.bottom = rect.top + 64; listSourceRect.push_back(rect);
		rect.left = 164; rect.top = 11; rect.right = rect.left + 45; rect.bottom = rect.top + 64; listSourceRect.push_back(rect);
		rect.left = 214; rect.top = 10; rect.right = rect.left + 37; rect.bottom = rect.top + 65; listSourceRect.push_back(rect);
		rect.left = 259; rect.top = 9; rect.right = rect.left + 42; rect.bottom = rect.top + 66; listSourceRect.push_back(rect);
		rect.left = 308; rect.top = 9; rect.right = rect.left + 49; rect.bottom = rect.top + 66; listSourceRect.push_back(rect);
		rect.left = 363; rect.top = 11; rect.right = rect.left + 35; rect.bottom = rect.top + 64; listSourceRect.push_back(rect);
		break;
	case Enemy1State::Fighting:
		rect.left = 9; rect.top = 82; rect.right = rect.left + 36; rect.bottom = rect.top + 73; listSourceRect.push_back(rect);
		rect.left = 53; rect.top = 96; rect.right = rect.left + 49; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 109; rect.top = 98; rect.right = rect.left + 91; rect.bottom = rect.top + 57; listSourceRect.push_back(rect);
		rect.left = 203; rect.top = 97; rect.right = rect.left + 85; rect.bottom = rect.top + 58; listSourceRect.push_back(rect);
		rect.left = 292; rect.top = 96; rect.right = rect.left + 76; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 382; rect.top = 96; rect.right = rect.left + 40; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		break;
	case Enemy1State::Attacked:
		rect.left = 8; rect.top = 175; rect.right = rect.left + 44; rect.bottom = rect.top + 57; listSourceRect.push_back(rect);
		rect.left = 59; rect.top = 185; rect.right = rect.left + 40; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 114; rect.top = 160; rect.right = rect.left + 38; rect.bottom = rect.top + 72; listSourceRect.push_back(rect);
		rect.left = 161; rect.top = 165; rect.right = rect.left + 41; rect.bottom = rect.top + 67; listSourceRect.push_back(rect);
		rect.left = 210; rect.top = 171; rect.right = rect.left + 46; rect.bottom = rect.top + 61; listSourceRect.push_back(rect);
		rect.left = 268; rect.top = 162; rect.right = rect.left + 41; rect.bottom = rect.top + 70; listSourceRect.push_back(rect);
		rect.left = 318; rect.top = 184; rect.right = rect.left + 46; rect.bottom = rect.top + 48; listSourceRect.push_back(rect);
		rect.left = 378; rect.top = 185; rect.right = rect.left + 40; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 433; rect.top = 166; rect.right = rect.left + 45; rect.bottom = rect.top + 66; listSourceRect.push_back(rect);
		break;
	default:
		break;
	}
	return listSourceRect;
}
Enemy1::Enemy1( Player *player, vector<D3DXVECTOR2> list)
{
	mPlayer = player;
	mListPosition = list;


	mAnimationRunning = new Animation("Resources/guard.png", 8, LoadRECT(Enemy1State::Running), (float) 1 /1, D3DXVECTOR2(0.5,1), D3DCOLOR_XRGB(120,193,152),Entity::Enemy);
	mAnimationFighting = new Animation("Resources/guard.png", 6, LoadRECT(Enemy1State::Fighting), (float)1 /0.25, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationAttacked = new Animation("Resources/guard.png",9, LoadRECT(Enemy1State::Attacked), (float)1 / 0.5, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationDied = new Animation("Resources/flare.png",5, LoadRECT(Enemy1State::Die), (float)1 / 0.5, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202),Entity::flare);
	mAnimationDied->SetScale(D3DXVECTOR2(1.5, 1.5));
	mSprite = new Sprite("Resources/guard.png", LoadRECT(Enemy1State::Attacked).at(0), 0, 0, D3DCOLOR_XRGB(120, 193, 152), D3DXVECTOR2(0.5, 1),GameGlobal::mEnemytexture);
	
	mCurrentAnimation = nullptr;
	mCurrentState = Enemy1State::None;
	Tag = EntityTypes::Enemy;
	this->mData = new Enemy1Data();
	this->mData->enemy = this;


	
	
}


Enemy1::~Enemy1()
{

}

void Enemy1::Update()
{
	CheckAction();

	if (Heal == 0)
	{
		positionted.push_back(CurrentPosIndex);
		SetState(new Enemy1Die(this->mData));
	}
	
	if (mCurrentState != Enemy1State::Attacked && mCurrentState != Enemy1State::Die)
	{
		if (CheckFire)
			SetState(new Enemy1Fighting(this->mData));

		if (CheckRunning)
			SetState(new Enemy1Running(this->mData));

		if (!CheckFire && !CheckRunning)
		{
			mCurrentState = Enemy1State::None;
		}

	}

	



	if (mCurrentState != Enemy1State::None && mCurrentAnimation != nullptr)
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
void Enemy1::Draw(D3DXVECTOR2 transform)
{

	if (mCurrentAnimation != nullptr && mCurrentState != Enemy1State::None)
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
	

}

void Enemy1::SetState(Enemy1State *newState)
{
	delete this->mData->state;

	this->mData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
RECT Enemy1::GetBound()
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

void Enemy1::changeAnimation(Enemy1State::StateName state)
{
	switch (state)
	{
	case Enemy1State::None:
		mCurrentAnimation = nullptr;
		break;
	case Enemy1State::Running:
		mCurrentAnimation = mAnimationRunning;
		break;
	case Enemy1State::Fighting:
		mCurrentAnimation = mAnimationFighting;
		break;
	case Enemy1State::Attacked:
		mCurrentAnimation = mAnimationAttacked;
		break;
	case Enemy1State::Die:
		mCurrentAnimation = mAnimationDied;
		break;
	default:
		break;
	}

	this->width = mCurrentAnimation->GetSprite()->GetWidth();
	this->height = mCurrentAnimation->GetSprite()->GetHeight();
}
void Enemy1::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	if (this->mPlayer->getState() == PlayerState::Fighting || (impactor->Tag==Entity::AppleThrow && impactor->GetPosition().x!=0))
	{
		SetState(new Enemy1Attacked(this->mData));

	}

	if (mCurrentState == Enemy1State::Fighting && mCurrentAnimation->GetCurrentFrame() == 4 &&
		mPlayer->mCurrentState == PlayerState::Standing)
	{
		mPlayer->SetState(new PlayerFiredState(mPlayer->mPlayerData));
	}

	if (mCurrentState == Enemy1State::Fighting && mCurrentAnimation->GetCurrentFrame() == 4 && mPlayer->mCurrentState != PlayerState::Standing && !mPlayer->isAttacked)
	{
		mPlayer->HPCount--;
		mPlayer->isAttacked = true;
	}
	if (this->mData->state)
		this->mData->state->OnCollision(impactor, side, data);




}
void Enemy1::CheckAction()
{
	for (int i = 0; i < mListPosition.size(); i++)
	{
		bool flag = false;
		for(int j=0;j<positionted.size();j++)
			if (i == positionted.at(j))
			{
				flag = true;
				break;
			}
		if (flag) continue;
		if (abs(mPlayer->GetPosition().y - mListPosition.at(i).y)>=50) continue;
		int deltay = mPlayer->GetPosition().y - mListPosition.at(i).y;
		int deltax = abs(mPlayer->GetPosition().x - mListPosition.at(i).x);
		if (deltax <= 300 && deltay <= 150)
		{
			if (i == CurrentPosIndex) continue;
			SetPosition(mListPosition.at(i));
			CurrentPosIndex = i;
			break;
		}
	}


	int deltax = abs(GetPosition().x - mPlayer->GetPosition().x);
	if (deltax > 180)
	{
		CheckRunning = false;
		CheckFire = false;
		return;
	}
	if(deltax <= 180 && deltax>=50)
	{
		CheckRunning = true;
		CheckFire = false;
	}
	if (deltax <= 50)
	{
		CheckRunning = false;
		CheckFire = true;
	}
}
Animation* Enemy1::GetCurrentAnimation()
{
	return mCurrentAnimation;
}