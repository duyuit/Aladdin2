#include "Enemy2.h"


vector<RECT> Enemy2::LoadRECT(Enemy2State::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	switch (state)
	{
	case Enemy2State::Die:
		rect.left = 342; rect.top = 23; rect.right = rect.left + 29; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
		rect.left = 383; rect.top = 22; rect.right = rect.left + 31; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
		rect.left = 423; rect.top = 9; rect.right = rect.left + 44; rect.bottom = rect.top + 44; listSourceRect.push_back(rect);
		rect.left = 383; rect.top = 22; rect.right = rect.left + 31; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
		rect.left = 342; rect.top = 23; rect.right = rect.left + 29; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
		break;

	case Enemy2State::None:
		break;
	case Enemy2State::Running:
		rect.left = 2; rect.top = 255; rect.right = rect.left + 47; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 55; rect.top = 253; rect.right = rect.left + 51; rect.bottom = rect.top + 53; listSourceRect.push_back(rect);
		rect.left = 111; rect.top = 252; rect.right = rect.left + 56; rect.bottom = rect.top + 54; listSourceRect.push_back(rect);
		rect.left = 173; rect.top = 253; rect.right = rect.left + 51; rect.bottom = rect.top + 53; listSourceRect.push_back(rect);
		rect.left = 230; rect.top = 255; rect.right = rect.left + 49; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 284; rect.top = 254; rect.right = rect.left + 41; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
		rect.left = 334; rect.top = 251; rect.right = rect.left + 43; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 382; rect.top = 253; rect.right = rect.left + 46; rect.bottom = rect.top + 53; listSourceRect.push_back(rect);
		break;
	case Enemy2State::Fighting:
		rect.left = 6; rect.top = 378; rect.right = rect.left + 54; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 65; rect.top = 386; rect.right = rect.left + 67; rect.bottom = rect.top + 43; listSourceRect.push_back(rect);
		rect.left = 140; rect.top = 388; rect.right = rect.left + 70; rect.bottom = rect.top + 41; listSourceRect.push_back(rect);
		rect.left = 216; rect.top = 387; rect.right = rect.left + 74; rect.bottom = rect.top + 42; listSourceRect.push_back(rect);
		rect.left = 297; rect.top = 385; rect.right = rect.left + 88; rect.bottom = rect.top + 44; listSourceRect.push_back(rect);
		rect.left = 395; rect.top = 384; rect.right = rect.left + 95; rect.bottom = rect.top + 45; listSourceRect.push_back(rect);
		rect.left = 6; rect.top = 447; rect.right = rect.left + 43; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 61; rect.top = 434; rect.right = rect.left + 43; rect.bottom = rect.top + 72; listSourceRect.push_back(rect);
		rect.left = 116; rect.top = 441; rect.right = rect.left + 51; rect.bottom = rect.top + 65; listSourceRect.push_back(rect);
		rect.left = 178; rect.top = 451; rect.right = rect.left + 114; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 300; rect.top = 434; rect.right = rect.left + 91; rect.bottom = rect.top + 72; listSourceRect.push_back(rect);
		break;
	case Enemy2State::Attacked:
		rect.left = 6; rect.top = 538; rect.right = rect.left + 53; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 71; rect.top = 515; rect.right = rect.left + 63; rect.bottom = rect.top + 70; listSourceRect.push_back(rect);
		rect.left = 138; rect.top = 529; rect.right = rect.left + 65; rect.bottom = rect.top + 56; listSourceRect.push_back(rect);
		rect.left = 210; rect.top = 520; rect.right = rect.left + 71; rect.bottom = rect.top + 65; listSourceRect.push_back(rect);
		rect.left = 290; rect.top = 522; rect.right = rect.left + 74; rect.bottom = rect.top + 63; listSourceRect.push_back(rect);
		rect.left = 382; rect.top = 530; rect.right = rect.left + 66; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		break;
	default:
		break;
	}
	return listSourceRect;
}
Enemy2::Enemy2( Player *player, vector<D3DXVECTOR2> list)
{
	mPlayer = player;
	mListPosition = list;


	mAnimationRunning = new Animation("Resources/guard.png", 8, LoadRECT(Enemy2State::Running), (float)1 / 1, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationFighting = new Animation("Resources/guard.png", 11, LoadRECT(Enemy2State::Fighting), (float)1 / 0.25, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationAttacked = new Animation("Resources/guard.png", 6, LoadRECT(Enemy2State::Attacked), (float)1 / 0.5, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(120, 193, 152), Entity::Enemy);
	mAnimationDied = new Animation("Resources/flare.png", 5, LoadRECT(Enemy2State::Die), (float)1 / 0.5, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(186, 254, 202),Entity::flare);
	mAnimationDied->SetScale(D3DXVECTOR2(1.5, 1.5));
	mSprite = new Sprite("Resources/guard.png", LoadRECT(Enemy2State::Fighting).at(0), 0, 0, D3DCOLOR_XRGB(120, 193, 152), D3DXVECTOR2(0.5, 1),GameGlobal::mEnemytexture);

	mCurrentAnimation = nullptr;
	mCurrentState = Enemy2State::None;
	Tag = EntityTypes::Enemy;
	this->mData = new Enemy2Data();
	this->mData->enemy = this;

	


}


Enemy2::~Enemy2()
{

}

void Enemy2::Update()
{
	CheckAction();

	if (Heal == 0)
	{
		positionted.push_back(CurrentPosIndex);
		SetState(new Enemy2Die(this->mData));
	}

	if (mCurrentState != Enemy2State::Attacked && mCurrentState != Enemy2State::Die)
	{
		if (CheckFire)
			SetState(new Enemy2Fighting(this->mData));

		if (CheckRunning)
			SetState(new Enemy2Running(this->mData));

		if (!CheckFire && !CheckRunning)
		{
			mCurrentState = Enemy2State::None;
		}

	}





	if (mCurrentState != Enemy2State::None && mCurrentAnimation != nullptr)
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

void Enemy2::Draw(D3DXVECTOR2 transform)
{

	if (mCurrentAnimation != nullptr && mCurrentState != Enemy2State::None)
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

void Enemy2::SetState(Enemy2State *newState)
{
	delete this->mData->state;

	this->mData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
RECT Enemy2::GetBound()
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

void Enemy2::changeAnimation(Enemy2State::StateName state)
{
	switch (state)
	{
	case Enemy2State::None:
		mCurrentAnimation = nullptr;
		break;
	case Enemy2State::Running:
		mCurrentAnimation = mAnimationRunning;
		break;
	case Enemy2State::Fighting:
		mCurrentAnimation = mAnimationFighting;
		break;
	case Enemy2State::Attacked:
		mCurrentAnimation = mAnimationAttacked;
		break;
	case Enemy2State::Die:
		mCurrentAnimation = mAnimationDied;
		break;
	default:
		break;
	}

	this->width = mCurrentAnimation->GetSprite()->GetWidth();
	this->height = mCurrentAnimation->GetSprite()->GetHeight();
}
void Enemy2::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{

	if (this->mPlayer->getState() == PlayerState::Fighting || (impactor->Tag == Entity::AppleThrow && impactor->GetPosition().x != 0))
	{
		SetState(new Enemy2Attacked(this->mData));
	}
	if (mCurrentState == Enemy2State::Fighting && mCurrentAnimation->GetCurrentFrame() ==4    &&
		mPlayer->mCurrentState == PlayerState::Standing)
	{
		mPlayer->SetState(new PlayerFiredState(mPlayer->mPlayerData));
	}

	if (mCurrentState == Enemy2State::Fighting && mCurrentAnimation->GetCurrentFrame() == 4 && mPlayer->mCurrentState != PlayerState::Standing && !mPlayer->isAttacked)
	{
		mPlayer->HPCount--;
		mPlayer->isAttacked = true;
	}
	if (this->mData->state)
		this->mData->state->OnCollision(impactor, side, data);



	
}
void Enemy2::CheckAction()
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
		if (abs(mPlayer->GetPosition().y - mListPosition.at(i).y) >= 30) continue;
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
	if (deltax <= 180 && deltax >= 50)
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
Animation* Enemy2::GetCurrentAnimation()
{
	return mCurrentAnimation;
}