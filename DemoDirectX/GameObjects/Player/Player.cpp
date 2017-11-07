#include "Player.h"
#include "PlayerStandingState.h"
#include "PlayerJumpingState.h"

vector<RECT> LoadRECT(PlayerState::StateName state)
{
	vector<RECT> listSourceRect;
	RECT rect;
	switch (state)
	{
	case PlayerState::Fired:
		rect.left = 9; rect.top = 2167; rect.right = rect.left + 42; rect.bottom = rect.top + 45; listSourceRect.push_back(rect);
		rect.left = 58; rect.top = 2161; rect.right = rect.left + 55; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 122; rect.top = 2162; rect.right = rect.left + 59; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
		rect.left = 189; rect.top = 2163; rect.right = rect.left + 80; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 282; rect.top = 2160; rect.right = rect.left + 61; rect.bottom = rect.top + 50; listSourceRect.push_back(rect);
		rect.left = 351; rect.top = 2161; rect.right = rect.left + 59; rect.bottom = rect.top + 48; listSourceRect.push_back(rect);
		break;
	case PlayerState::Standing:
		rect.left = 3;  rect.top = 9;  rect.right = rect.left + 37;  rect.bottom = rect.top + 49; 	listSourceRect.push_back(rect);
		rect.left = 47;  rect.top = 11;  rect.right = rect.left + 41;  rect.bottom = rect.top + 46;	listSourceRect.push_back(rect);
		rect.left = 95;  rect.top = 6;  rect.right = rect.left + 40;  rect.bottom = rect.top + 51;	listSourceRect.push_back(rect);
		rect.left = 143;  rect.top = 3;  rect.right = rect.left + 44;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);
		rect.left = 197;  rect.top = 6; rect.right = rect.left + 41;  rect.bottom = rect.top + 50;	listSourceRect.push_back(rect);
		rect.left = 250;  rect.top = 5;  rect.right = rect.left + 42;  rect.bottom = rect.top + 50;	listSourceRect.push_back(rect);
		rect.left = 303;  rect.top = 2;  rect.right = rect.left + 44;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 6;  rect.top = 83; rect.right = rect.left + 40; rect.bottom = rect.top + 51;	listSourceRect.push_back(rect);
		rect.left = 51; rect.top = 81; rect.right = rect.left + 61; rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 116; rect.top = 80; rect.right = rect.left + 62; rect.bottom = rect.top + 53;	listSourceRect.push_back(rect);
		rect.left = 180; rect.top = 81; rect.right = rect.left + 41;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 228; rect.top = 81; rect.right = rect.left + 39; rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 275; rect.top = 81; rect.right = rect.left + 36;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 319; rect.top = 81;  rect.right = rect.left + 40; rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 366; rect.top = 79; rect.right = rect.left + 41;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);
		rect.left = 417; rect.top = 61; rect.right = rect.left + 42; rect.bottom = rect.top + 72;	listSourceRect.push_back(rect);

		rect.left = 465; rect.top = 57; rect.right = rect.left + 41;  rect.bottom = rect.top + 76;	listSourceRect.push_back(rect);
		rect.left = 516;  rect.top = 63;  rect.right = rect.left + 41; rect.bottom = rect.top + 70;	listSourceRect.push_back(rect);
		rect.left = 568;  rect.top = 72;  rect.right = rect.left + 41; rect.bottom = rect.top + 61;	listSourceRect.push_back(rect);
		rect.left = 619;  rect.top = 80; rect.right = rect.left + 41; rect.bottom = rect.top + 53;	listSourceRect.push_back(rect);
		rect.left = 668; rect.top = 80; rect.right = rect.left + 40; rect.bottom = rect.top + 53;	listSourceRect.push_back(rect);
		rect.left = 715;  rect.top = 81; rect.right = rect.left + 39; rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 3; rect.top = 165; rect.right = rect.left + 36; rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 46; rect.top = 165;  rect.right = rect.left + 40;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		rect.left = 91; rect.top = 163; rect.right = rect.left + 41;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);
		rect.left = 140; rect.top = 155;  rect.right = rect.left + 37; rect.bottom = rect.top + 62;	listSourceRect.push_back(rect);
		rect.left = 188; rect.top = 151; rect.right = rect.left + 40; rect.bottom = rect.top + 66;	listSourceRect.push_back(rect);
		rect.left = 238; rect.top = 159; rect.right = rect.left + 42; rect.bottom = rect.top + 57;	listSourceRect.push_back(rect);
		rect.left = 287;  rect.top = 168;  rect.right = rect.left + 38;  rect.bottom = rect.top + 48;	listSourceRect.push_back(rect);
		rect.left = 334;  rect.top = 168;  rect.right = rect.left + 39; rect.bottom = rect.top + 48;	listSourceRect.push_back(rect);
		rect.left = 378; rect.top = 168; rect.right = rect.left + 39; rect.bottom = rect.top + 48;	listSourceRect.push_back(rect);
		rect.left = 425; rect.top = 156; rect.right = rect.left + 37; rect.bottom = rect.top + 60;	listSourceRect.push_back(rect);
		rect.left = 472; rect.top = 150; rect.right = rect.left + 37;  rect.bottom = rect.top + 66;	listSourceRect.push_back(rect);
		rect.left = 519; rect.top = 143;  rect.right = rect.left + 35; rect.bottom = rect.top + 73;	listSourceRect.push_back(rect);
		rect.left = 568; rect.top = 138; rect.right = rect.left + 38; rect.bottom = rect.top + 78;	listSourceRect.push_back(rect);
		rect.left = 615; rect.top = 155; rect.right = rect.left + 41; rect.bottom = rect.top + 61;	listSourceRect.push_back(rect);
		rect.left = 666; rect.top = 163; rect.right = rect.left + 41; rect.bottom = rect.top + 53;	listSourceRect.push_back(rect);
		rect.left = 715; rect.top = 163; rect.right = rect.left + 40; rect.bottom = rect.top + 53;	listSourceRect.push_back(rect);
		rect.left = 762; rect.top = 164;  rect.right = rect.left + 39; rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
		
		break;
	case PlayerState::Running:
		for (int i = 1; i <= 13; i++)
		{
			rect.top = 1212;
			rect.bottom = 1275;
			switch (i)
			{
			case 1:
			{
				rect.left = 7;
				rect.right = 57;
				break;
			}
			case 2:
			{
				rect.left = 60;
				rect.right = 110;
				break;
			}
			case 3:
			{
				rect.left = 113;
				rect.right = 163;
				break;
			}
			case 4:
			{
				rect.left = 162;
				rect.right = 212;
				break;
			}
			case 5:
			{
				rect.left = 219;
				rect.right = 279;
				break;
			}
			case 6:
			{
				rect.left = 276;
				rect.right = 334;
				break;
			}
			case 7:
			{
				rect.left = 326;
				rect.right = 386;
				break;
			}
			case 8:
			{
				rect.left = 376;
				rect.right = 436;
				break;
			}
			case 9:
			{
				rect.left = 431;
				rect.right = 479;
				break;
			}
			case 10:
			{
				rect.left = 487;
				rect.right = 543;
				break;
			}
			case 11:
			{
				rect.left = 547;
				rect.right = 608;
				break;
			}
			case 12:
			{
				rect.left = 609;
				rect.right = 671;
				break;
			}
			case 13:
			{
				rect.left = 669;
				rect.right = 731;
				break;
			}
			}


			listSourceRect.push_back(rect);
		}
		break;
	case PlayerState::Falling:
		break;
	case PlayerState::Jumping:
				rect.top = 703;
				rect.bottom = rect.top + 45;
				rect.left = 7;
				rect.right = rect.left + 44;
				listSourceRect.push_back(rect);

				rect.top = 683;
				rect.bottom = rect.top + 79;
				rect.left = 66;
				rect.right = rect.left + 45;
				listSourceRect.push_back(rect);
			
				rect.top = 686;
				rect.bottom = rect.top + 60;
				rect.left = 124;
				rect.right = rect.left + 57;
				listSourceRect.push_back(rect);

				rect.top = 697;
				rect.bottom = rect.top + 44;
				rect.left = 199;
				rect.right = rect.left + 59;
				listSourceRect.push_back(rect);
			
				rect.top = 694;
				rect.bottom = rect.top + 50;
				rect.left = 273;
				rect.right = rect.left + 63;
				listSourceRect.push_back(rect);
			
				rect.top = 692;
				rect.bottom = rect.top + 52;
				rect.left = 348;
				rect.right = rect.left + 61;
				listSourceRect.push_back(rect);
			
				rect.top = 687;
				rect.bottom = rect.top + 59;
				rect.left = 419;
				rect.right = rect.left + 54;
				listSourceRect.push_back(rect);
			
				rect.top = 680;
				rect.bottom = rect.top + 86;
				rect.left = 490;
				rect.right = rect.left + 51;
				listSourceRect.push_back(rect);
			
				rect.top = 718;
				rect.bottom = rect.top + 45;
				rect.left = 560;
				rect.right = rect.left + 61;
				listSourceRect.push_back(rect);

				break;
	case PlayerState::Die:
		break;
	case PlayerState::Throwing:
		rect.top = 234;
		rect.bottom = rect.top + 58;
		rect.left = 6;
		rect.right = rect.left + 44;
		listSourceRect.push_back(rect);

		rect.top = 230;
		rect.bottom = rect.top + 61;
		rect.left = 56;
		rect.right = rect.left + 43;
		listSourceRect.push_back(rect);

		rect.top = 230;
		rect.bottom = rect.top + 61;
		rect.left = 106;
		rect.right = rect.left + 42;
		listSourceRect.push_back(rect);

		rect.top = 230;
		rect.bottom = rect.top + 60;
		rect.left = 161;
		rect.right = rect.left + 59;
		listSourceRect.push_back(rect);

		rect.top = 233;
		rect.bottom = rect.top + 60;
		rect.left = 220;
		rect.right = rect.left + 40;
		listSourceRect.push_back(rect);

		rect.top = 237;
		rect.bottom = rect.top + 55;
		rect.left = 267;
		rect.right = rect.left + 40;
		listSourceRect.push_back(rect);
		break;
	case PlayerState::Climbing:
		for (int i = 1; i <= 10; i++)
		{
			RECT rect;
			rect.top = 1360;
			float x = 44;
			rect.right = x * i;
			rect.left = x * i - x + 1;
			rect.bottom = 1440;
			listSourceRect.push_back(rect);
		}
	case PlayerState::Fighting:
		rect.top = 313;
		rect.bottom = 388;
		rect.left = 6;
		rect.right = rect.left + 44;
		listSourceRect.push_back(rect);
	
		rect.top = 313;
		rect.bottom = 388;
		rect.left = 54;
		rect.right = rect.left + 52;
		listSourceRect.push_back(rect);
	
		rect.top = 313;
		rect.bottom = 388;
		rect.left = 113;
		rect.right = rect.left + 47;
		listSourceRect.push_back(rect);
	
		rect.top = 313;
		rect.bottom = 388;
		rect.left = 171;
		rect.right = rect.left + 83;
		listSourceRect.push_back(rect);
	
		rect.top = 313;
		rect.bottom = 388;
		rect.left = 260;
		rect.right = rect.left + 51;
		listSourceRect.push_back(rect);
		break;
	case PlayerState::Sit:
		rect.top = 499;
		rect.bottom = 550;
		rect.left = 204;
		rect.right = rect.left + 43;
		listSourceRect.push_back(rect); 

		rect.top = 499;
		rect.bottom = 550;
		rect.left = 258;
		rect.right = rect.left + 49;
		listSourceRect.push_back(rect);

		rect.top = 499;
		rect.bottom = 550;
		rect.left = 314;
		rect.right = rect.left + 56;
		listSourceRect.push_back(rect);

		rect.top = 499;
		rect.bottom = 550;
		rect.left = 377;
		rect.right = rect.left + 55;
		listSourceRect.push_back(rect);
		break;
	case PlayerState::SitFight:
		rect.left = 7;
		rect.top = 638;
		rect.right = rect.left + 50;
		rect.bottom = rect.top + 35;
		listSourceRect.push_back(rect);

	
		rect.left = 62;
		rect.top = 640;
		rect.right = rect.left + 49;
		rect.bottom = rect.top + 34;
		listSourceRect.push_back(rect);

		rect.left = 114;
		rect.top = 640;
		rect.right = rect.left + 72;
		rect.bottom = rect.top + 34;
		listSourceRect.push_back(rect);

		rect.left = 189;
		rect.top = 639;
		rect.right = rect.left + 95;
		rect.bottom = rect.top + 34;
		listSourceRect.push_back(rect);

		rect.left = 298;
		rect.top = 640;
		rect.right = rect.left + 84;
		rect.bottom = rect.top + 34;
		listSourceRect.push_back(rect);

		rect.left = 391;
		rect.top = 640;
		rect.right = rect.left + 73;
		rect.bottom = rect.top + 34;
		listSourceRect.push_back(rect);

		rect.left = 473;
		rect.top = 640;
		rect.right = rect.left + 48;
		rect.bottom = rect.top + 34;
		listSourceRect.push_back(rect);

		break;
	case PlayerState::JumpThrow:
		rect.left = 19; rect.top = 1005; rect.right = rect.left + 49; rect.bottom = rect.top + 54; listSourceRect.push_back(rect);
		rect.left = 77; rect.top = 1007; rect.right = rect.left + 43; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);
		rect.left = 132; rect.top = 1008; rect.right = rect.left + 38; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
		rect.left = 185; rect.top = 1008; rect.right = rect.left + 52; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
		rect.left = 253; rect.top = 1012; rect.right = rect.left + 40; rect.bottom = rect.top + 51; listSourceRect.push_back(rect);

	case PlayerState::SitThrow:
		rect.left = 9; rect.top = 571; rect.right = rect.left + 36; rect.bottom = rect.top + 43; listSourceRect.push_back(rect);
		rect.left = 58; rect.top = 567; rect.right = rect.left + 37; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 107; rect.top = 571; rect.right = rect.left + 50; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 164; rect.top = 578; rect.right = rect.left + 82; rect.bottom = rect.top + 36; listSourceRect.push_back(rect);
		rect.left = 256; rect.top = 579; rect.right = rect.left + 57; rect.bottom = rect.top + 36; listSourceRect.push_back(rect);
	default:
		break;
	}
	
	return listSourceRect;
}

int curApple = 0;
Player::Player()
{
	mAnimationStanding = new Animation("Resources/Aladdin.png", 39, LoadRECT(PlayerState::Standing), (float)1 / 15,D3DXVECTOR2(0.5,1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationJumping = new Animation("Resources/Aladdin.png", 9, LoadRECT(PlayerState::Jumping), (float)1 / 30, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationRunning = new Animation("Resources/Aladdin.png", 13, LoadRECT(PlayerState::Running), (float)1 / 30, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationThrowing = new Animation("Resources/Aladdin.png", 6, LoadRECT(PlayerState::Throwing), (float)1 / 25, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationClimbing = new Animation("Resources/Aladdin.png", 10, LoadRECT(PlayerState::Climbing), (float)1 / 30, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationFighting=new Animation("Resources/Aladdin.png", 5, LoadRECT(PlayerState::Fighting), (float)1 / 20, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationSiting= new Animation("Resources/Aladdin.png", 4, LoadRECT(PlayerState::Sit), (float)1 / 20, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationSitFight= new Animation("Resources/Aladdin.png",7, LoadRECT(PlayerState::SitFight), (float)1 / 20, D3DXVECTOR2(0.2, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationJumpThrow= new Animation("Resources/Aladdin.png",5, LoadRECT(PlayerState::JumpThrow), (float)1 /50, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationSitThrow = new Animation("Resources/Aladdin.png", 5, LoadRECT(PlayerState::SitThrow), (float)1 / 20, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	mAnimationFired=new Animation("Resources/Aladdin.png", 6, LoadRECT(PlayerState::Fired), (float)1 / 20, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	Tag = Entity::EntityTypes::Enemy;
	this->mPlayerData = new PlayerData();
	this->mPlayerData->player = this;
	this->vx = 0;
	this->vy = 0;
	this->SetState(new PlayerFallingState(this->mPlayerData));

	listApple.push_back(new Apple());
	listApple.push_back(new Apple());
	listApple.push_back(new Apple());
	
	allowJump = true;
	allowThrow = true;


	mUI = new UI();
}

Player::~Player()
{
}

void Player::Update(float dt)
{


	
	if (this->mPlayerData->state)
	{
		this->mPlayerData->state->Update(dt);
	}
	mCurrentAnimation->Update(dt);

	Entity::Update(dt);
	for (int i = 0; i < listApple.size(); i++)
	{
		Apple *temp = listApple.at(i);

		temp->Update(dt);
	}
	mUI->Update(0, AppleCount);
}

void Player::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->mPlayerData->state)
	{
		this->mPlayerData->state->HandleKeyboard(keys);
	}
}

void Player::OnKeyPressed(int key)
{
	if (key == VK_SPACE)
	{	
		if (allowJump)
		{
			if (mCurrentState == PlayerState::Running || mCurrentState == PlayerState::Standing)
			{
				//vx = 150;
				this->SetState(new PlayerJumpingState(this->mPlayerData));
			}

			allowJump = false;
		}
	}
	if (key == VK_NUMPAD0)
	{
		if (allowThrow)
		{
		
			if (AppleCount < 1) return;
			if (curApple > 2)
				curApple = 0;
			if(mCurrentState==PlayerState::Sit)
				listApple.at(curApple)->SetPosition(D3DXVECTOR3(posX, posY - 30, 0));
			else
				listApple.at(curApple)->SetPosition(D3DXVECTOR3(posX, posY - 50, 0));
			listApple.at(curApple)->mReverse= mCurrentReverse;
			listApple.at(curApple)->SetState(AppleState::Flying);
			curApple++;
			AppleCount--;
		}
		allowThrow = false;
	}
}

void Player::OnKeyUp(int key)
{
	if (key == VK_SPACE)
		allowJump = true;
	if (key == VK_NUMPAD0)
		allowThrow = true;
}



void Player::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	mCurrentAnimation->GetSprite()->FlipVertical(mCurrentReverse);
	mCurrentAnimation->SetPosition(this->GetPosition());
	
	if (mCamera)
	{
		D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x,
			GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y);

		mCurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0), sourceRect, scale, trans, angle, rotationCenter, colorKey);
		for (int i = 0; i < listApple.size(); i++)
			listApple.at(i)->Draw(listApple.at(i)->GetPosition(), sourceRect, scale, trans, angle, rotationCenter, colorKey);
	
		
	}
	else
	{
		mCurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
		for (int i = 0; i < listApple.size(); i++)
			listApple.at(i)->Draw();

	}
	

}

void Player::SetState(PlayerState *newState)
{
	delete this->mPlayerData->state;

	this->mPlayerData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}

RECT Player::GetBound()
{
	RECT rect;
	rect.left = this->posX - mCurrentAnimation->GetSprite()->GetWidth() / 2;
	rect.right = rect.left + mCurrentAnimation->GetSprite()->GetWidth();
	rect.top = this->posY - mCurrentAnimation->GetSprite()->GetHeight(); //Chú ý đoạn này
	rect.bottom = this->posY;// + mCurrentAnimation->GetSprite()->GetHeight() / 2;

	float cWidth = this->posX;
	float cHeight= this->posY- mCurrentAnimation->GetSprite()->GetHeight()/2;
	SetCenter(D3DXVECTOR2(cWidth, cHeight));
	return rect;
}

void Player::changeAnimation(PlayerState::StateName state)
{
	switch (state)
	{
	case PlayerState::Fired:
		mCurrentAnimation = mAnimationFired;
		break;
	case PlayerState::Running:
		mCurrentAnimation = mAnimationRunning;
		break;

	case PlayerState::Standing:
		mCurrentAnimation = mAnimationStanding;
		break;

	case PlayerState::Falling:
		mCurrentAnimation = mAnimationJumping;
		break;

	case PlayerState::Jumping:
		mCurrentAnimation = mAnimationJumping;
		break;

	case PlayerState::Throwing:
		mCurrentAnimation = mAnimationThrowing;
		break;
	case PlayerState::Climbing:
		mCurrentAnimation = mAnimationClimbing;
		break;
	case PlayerState::Fighting:
		mCurrentAnimation = mAnimationFighting;
		break;
	case PlayerState::Sit:
		mCurrentAnimation = mAnimationSiting;
		break;
	case PlayerState::SitFight:
		mCurrentAnimation = mAnimationSitFight;
		break;
	case PlayerState::JumpThrow:
		mCurrentAnimation = mAnimationJumpThrow;
		break;
	case PlayerState::SitThrow:
		mCurrentAnimation = mAnimationSitThrow;
		break;
	}

	this->width = mCurrentAnimation->GetSprite()->GetWidth();
	this->height = mCurrentAnimation->GetSprite()->GetHeight();
}

Player::MoveDirection Player::getMoveDirection()
{
	if (this->vx > 0)
	{
		return MoveDirection::MoveToRight;
	}
	else if (this->vx < 0)
	{
		return MoveDirection::MoveToLeft;
	}

	return MoveDirection::None;
}

PlayerState::StateName Player::getState()
{
	return mCurrentState;
}

PlayerData* Player::GetCurrentPlayerData()
{
	return mPlayerData;
}
void Player::SetCamera(Camera *camera)
{
	this->mCamera = camera;
}

Animation* Player::GetCurrentAnimation()
{
	return mCurrentAnimation;
}
bool Player::GetallowThrow()
{
	return allowThrow;
}
void Player::SetallowThrow(bool flag)
{
	allowThrow = flag;
}

void Player::OnNoCollisionWithBottom()
{
	if (mCurrentState != PlayerState::Jumping && mCurrentState != PlayerState::Falling && mCurrentState != PlayerState::JumpThrow)
	{
		this->SetState(new PlayerFallingState(this->mPlayerData));
	}
}
void Player::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mPlayerData->state->OnCollision(impactor, side, data);
}

void Player::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}
bool Player::GetReverse()
{
	return mCurrentReverse;
}