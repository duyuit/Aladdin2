#include "Enemy1.h"


vector<RECT> Enemy1::LoadRECT(Enemy1State::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	switch (state)
	{
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
Enemy1::Enemy1(D3DXVECTOR2 locate, Player *player)
{
	mPlayer = player;
	mAnimationRunning = new Animation("Resources/guard.png", 8, LoadRECT(Enemy1State::Running), (float) 1 /1, D3DXVECTOR2(0.5,1), D3DCOLOR_XRGB(120,193,152));
	mAnimationFighting = new Animation("Resources/guard.png", 6, LoadRECT(Enemy1State::Fighting), (float)1 /0.25, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152));
	mAnimationAttacked = new Animation("Resources/guard.png",9, LoadRECT(Enemy1State::Attacked), (float)1 / 0.25, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152));
	
	mSprite = new Sprite("Resources/guard.png", LoadRECT(Enemy1State::Attacked).at(0), 0, 0, D3DCOLOR_XRGB(120, 193, 152), D3DXVECTOR2(0.5, 1));
	
	mCurrentAnimation = nullptr;
	mCurrentState = Enemy1State::None;
	Tag = EntityTypes::Enemy;
	this->mData = new Enemy1Data();
	this->mData->enemy = this;

	startLocation = locate;
}


Enemy1::~Enemy1()
{

}

void Enemy1::Update()
{
	CheckAction();
	if (mCurrentState != Enemy1State::Attacked)
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
		if (this->mData->state)
		{
			this->mData->state->Update();
		}
		mCurrentAnimation->Update(1);
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
	default:
		break;
	}

	this->width = mCurrentAnimation->GetSprite()->GetWidth();
	this->height = mCurrentAnimation->GetSprite()->GetHeight();
}
void Enemy1::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	if (this->mPlayer->getState() == PlayerState::Fighting || impactor->Tag==Entity::AppleThrow)
	{
		SetState(new Enemy1Attacked(this->mData));
	}
	if (mCurrentState == Enemy1State::Fighting && mCurrentAnimation->GetCurrentFrame()==3 && mPlayer->mCurrentState != PlayerState::Fired)
	{
		mPlayer->SetState(new PlayerFiredState(mPlayer->mPlayerData));
	}
	if(this->mData->state)
	this->mData->state->OnCollision(impactor, side, data);
}
void Enemy1::CheckAction()
{
	int deltax = abs(GetPosition().x - mPlayer->GetPosition().x);
	if (deltax > 150)
	{
		CheckRunning = false;
		CheckFire = false;
		return;
	}
	if(deltax <= 150 && deltax>=50)
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