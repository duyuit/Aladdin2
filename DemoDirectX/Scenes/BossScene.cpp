#include "BossScene.h"



BossScene::BossScene(Player* pl,UI* ui)
{
	mPlayer = pl;
	mUI = ui;
	LoadContent();

}
vector<RECT>  BossScene::loadRect(bool flag)
{
	vector<RECT> listSourceRect;
	RECT rect;
	if (flag)
	{
		rect.left = 8; rect.top = 180; rect.right = rect.left + 26; rect.bottom = rect.top + 23; listSourceRect.push_back(rect);
		rect.left = 48; rect.top = 155; rect.right = rect.left + 60; rect.bottom = rect.top + 48; listSourceRect.push_back(rect);
		rect.left = 120; rect.top = 118; rect.right = rect.left + 81; rect.bottom = rect.top + 85; listSourceRect.push_back(rect);
		rect.left = 208; rect.top = 123; rect.right = rect.left + 83; rect.bottom = rect.top + 80; listSourceRect.push_back(rect);
		rect.left = 304; rect.top = 124; rect.right = rect.left + 82; rect.bottom = rect.top + 79; listSourceRect.push_back(rect);
		rect.left = 400; rect.top = 128; rect.right = rect.left + 83; rect.bottom = rect.top + 75; listSourceRect.push_back(rect);
		rect.left = 496; rect.top = 131; rect.right = rect.left + 83; rect.bottom = rect.top + 72; listSourceRect.push_back(rect);
		rect.left = 8; rect.top = 214; rect.right = rect.left + 80; rect.bottom = rect.top + 69; listSourceRect.push_back(rect);
		rect.left = 96; rect.top = 217; rect.right = rect.left + 82; rect.bottom = rect.top + 66; listSourceRect.push_back(rect);
		rect.left = 192; rect.top = 222; rect.right = rect.left + 83; rect.bottom = rect.top + 61; listSourceRect.push_back(rect);
		rect.left = 288; rect.top = 231; rect.right = rect.left + 80; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
		rect.left = 376; rect.top = 236; rect.right = rect.left + 76; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		rect.left = 464; rect.top = 243; rect.right = rect.left + 52; rect.bottom = rect.top + 40; listSourceRect.push_back(rect);
		rect.left = 528; rect.top = 244; rect.right = rect.left + 41; rect.bottom = rect.top + 38; listSourceRect.push_back(rect);
		rect.left = 584; rect.top = 251; rect.right = rect.left + 43; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
	}
	else
	{
		rect.left = 758; rect.top = 31; rect.right = rect.left + 15; rect.bottom = rect.top + 10; listSourceRect.push_back(rect);
		rect.left = 756; rect.top = 32; rect.right = rect.left + 24; rect.bottom = rect.top + 18; listSourceRect.push_back(rect);
		rect.left = 731; rect.top = 25; rect.right = rect.left + 22; rect.bottom = rect.top + 23; listSourceRect.push_back(rect);
		rect.left = 794; rect.top = 23; rect.right = rect.left + 32; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);

	}

	
	return listSourceRect;
}
BossScene::~BossScene()
{
}
void BossScene::LoadContent()
{
	
	mBackColor = 0x54acd2;
	EatItem = new Animation("Resources/Aladdin.png", 4, loadRect(false), (float)1 / 0.5, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255),Entity::PlayerOne);
	EatItem->SetScale(D3DXVECTOR2(1.5, 1.5));


	Damage = new Animation("Resources/flare.png",15, loadRect(true), (float)1 / 0.4, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(186, 254, 202),Entity::flare);
	//Damage->SetScale(D3DXVECTOR2(0.5, 0.5));

	mMap = new GameMapBoss("Resources/boss.tmx");
	
	mCamera = new Camera(GameGlobal::GetWidth(), GameGlobal::GetHeight());
	mCamera->SetPosition(GameGlobal::GetWidth() / 2,
		mMap->GetHeight() - mCamera->GetHeight());

	mMap->SetCamera(mCamera);


	mPlayer->SetPosition(200, 50);

	mPlayer->SetCamera(mCamera);

	mBoss = new Boss(mPlayer,D3DXVECTOR3(350, 280,0));

	die = new DieScene(this);

	RECT rect;
	rect.left = 370; rect.top = 45; rect.right = rect.left + 14; rect.bottom = rect.top + 14;
	Sprite* appleSprite1 = new Sprite("Resources/Aladdin.png", rect, 0, 0, D3DCOLOR_XRGB(255, 0, 255), D3DXVECTOR2(0.5, 0.5),GameGlobal::mAladdintexture);
	Sprite* appleSprite2 = new Sprite("Resources/Aladdin.png", rect, 0, 0, D3DCOLOR_XRGB(255, 0, 255), D3DXVECTOR2(0.5, 0.5), GameGlobal::mAladdintexture);
	Sprite* appleSprite3 = new Sprite("Resources/Aladdin.png", rect, 0, 0, D3DCOLOR_XRGB(255, 0, 255), D3DXVECTOR2(0.5, 0.5), GameGlobal::mAladdintexture);
	app1 = new AppleObject(appleSprite1); app1->SetPos(0, 0);
	app2= new AppleObject(appleSprite2); app2->SetPos(0, 0);
	app3 = new AppleObject(appleSprite3); app3->SetPos(0, 0);

	
	myFont = NULL;

	HRESULT rs = D3DXCreateFont(GameGlobal::GetCurrentDevice(), 50, 30, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, (LPCWSTR) "Arial", &myFont);
	if (!SUCCEEDED(rs))
	{
		return;
	}
	myRect.left = 0;
	myRect.top = GameGlobal::GetHeight()/2;
	myRect.bottom = myRect.top + GameGlobal::GetHeight() / 2;
	myRect.right = myRect.left + GameGlobal::GetWidth();
	
	Sound::getInstance()->setVolume(90.0f,"Jafar Laugh");
	Sound::getInstance()->setVolume(90.0f, "Aaah");
	Sound::getInstance()->setVolume(90.0f, "Oooh");
	Sound::getInstance()->setVolume(90.0f, "Jafar Snake");
	Sound::getInstance()->setVolume(100.0f, "bosstheme");
	Sound::getInstance()->play("Jafar Laugh", false, 1);
	Sound::getInstance()->play("bosstheme", true, 0);
}


void BossScene::Update(float dt)
{
	if (GameGlobal::curSong == GameGlobal::Continuene) //Check de reset map
	{
		GameGlobal::curSong = GameGlobal::BossMusic;
		mBoss->HPCount = 30;
		mBoss->SetState(new BossSummon(mBoss->mData));
		mPlayer->AppleCount = 10;
		mPlayer->SetPosition(50, 50);
		return;
	}
	

	CheckCameraAndWorldMap();
	checkCollision();
	mPlayer->HandleKeyboard(keys);
	mPlayer->PlayerLiveCount = GameGlobal::liveCount;
	if (mPlayer->HPCount == 0)
	{
		Sound::getInstance()->play("chet", false, 1);
		Sound::getInstance()->stop("bosstheme");
		GameGlobal::curSong = GameGlobal::BossMusic;
		Sound::getInstance()->stop("Jafar Tractor");
		die->die->Reset();
		SceneManager::GetInstance()->ReplaceScene(die);
	}

	mPlayer->Update(dt);


	mUI->Update();

	EatItem->Update(1);

	if (EatItem->GetCurrentFrame() == 3)
	{
		EatItem->SetPosition(0, 0);
	}

	Damage->Update(1);
	if (Damage->GetCurrentFrame() == 14)
	{

		Damage->SetPosition(0, 0);
	}


	mBoss->Update();
	for (int i = 0; i < mMap->listFlame.size(); i++)
	{
		mMap->listFlame.at(i)->Update();
	}

	AppleObjectHandle();

	if (mBoss->HPCount == 3)
	{
		Sound::getInstance()->stop("bosstheme");
		SceneManager::GetInstance()->ReplaceScene(new LevelComScene(mPlayer,mUI));
	}
	
}

void BossScene::Draw()
{

	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x, GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y); //Lay TranSition hien tai
	mMap->Draw(); //Ve Map
	if (!isEnd)
	{

		mBoss->Draw(trans);
	}
	
	mPlayer->Draw();
	


	EatItem->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);
	Damage->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);

	app1->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);
	app2->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);
	app3->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);
	
	for (int i = 0; i < mMap->listFlame.size(); i++)
	{
		mMap->listFlame.at(i)->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);
	}
	

	mUI->Draw();

	if (myFont  && isEnd)
	{
		int r = rand() % 255 + 1;
		int g = rand() % 255 + 1;
		int b = rand() % 255 + 1;
		myFont->DrawTextA(mUI->hpBar->GetSpriteHandle(), "YOU WIN", -1, &myRect, DT_CENTER, D3DCOLOR_XRGB(r, g, b));
	
	}
	

}
void BossScene::CheckCameraAndWorldMap()
{
	mCamera->SetPosition(mPlayer->GetPosition());

	if (mCamera->GetBound().left < 0)
	{
		//vi position cua camera ma chinh giua camera
		//luc nay o vi tri goc ben trai cua the gioi thuc
		mCamera->SetPosition(mCamera->GetWidth() / 2, mCamera->GetPosition().y);
	}

	if (mCamera->GetBound().right > mMap->GetWidth())
	{
		//luc nay cham goc ben phai cua the gioi thuc
		mCamera->SetPosition(mMap->GetWidth() - mCamera->GetWidth() / 2,
			mCamera->GetPosition().y);
	}

	if (mCamera->GetBound().top < 0)
	{
		//luc nay cham goc tren the gioi thuc
		mCamera->SetPosition(mCamera->GetPosition().x, mCamera->GetHeight() / 2);
	}

	if (mCamera->GetBound().bottom > mMap->GetHeight())
	{
		//luc nay cham day cua the gioi thuc
		mCamera->SetPosition(mCamera->GetPosition().x,
			mMap->GetHeight() - mCamera->GetHeight() / 2);
	}
}
void BossScene::OnKeyUp(int keyCode)
{
	if (isEnd) return;
	keys[keyCode] = false;
	mPlayer->OnKeyUp(keyCode);

}
void BossScene::OnKeyDown(int keyCode)
{
	if (isEnd) return;
	keys[keyCode] = true;
	mPlayer->OnKeyPressed(keyCode);
}
Entity *lastFire = NULL;

void BossScene::checkCollision()
{
	//Check apple va cham voi map
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{
		mPlayer->listApple.at(i)->Update(0);
		if (mPlayer->listApple.at(i)->mCurrentAnim == nullptr || mPlayer->listApple.at(i)->curState == nullptr) continue;
		vector<Entity*> listCollisionApple;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionApple, mPlayer->listApple.at(i));

		for (size_t j = 0; j < listCollisionApple.size(); j++)
		{
			if (listCollisionApple.at(j)->Tag == Entity::box) continue;
			Entity::CollisionReturn re = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(),
				listCollisionApple.at(j)->GetBound());
			if (re.IsCollided)
			{
				Entity::SideCollisions sidePlayer = GameCollision::getSideCollision(mPlayer, re);
				//Xu ly va cham thang tao o day
				mPlayer->listApple.at(i)->OnCollision(listCollisionApple.at(j), re, sidePlayer);


			}
		}
	}

	//Check Apple vs Boss
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{
		if (mPlayer->listApple.at(i)->mCurrentAnim == nullptr || mPlayer->listApple.at(i)->curState == nullptr) continue;
		Entity::CollisionReturn re = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(),
			mBoss->GetBound());
		if (re.IsCollided)
		{
			if (mPlayer->listApple.at(i)->GetCurrentState() == AppleState::Breaking) continue;
			Damage->Reset();
			Damage->SetPosition(mPlayer->listApple.at(i)->GetPosition());
			mBoss->OnCollision(mPlayer->listApple.at(i), re, Entity::NotKnow);
			if((int) GetTickCount()%2==0)
				Sound::getInstance()->play("Aaah", false, 1);
			else
				Sound::getInstance()->play("Oooh", false, 1);
			mPlayer->listApple.at(i)->OnCollision(mBoss, re, Entity::NotKnow);
		}
	}

	//Check Fire Ammo With object
	for (int i = 0; i < mBoss->listAmmo.size(); i++)
	{
		vector<Entity*> listCollision;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollision, mBoss->listAmmo.at(i));

		for (int j = 0; j < listCollision.size(); j++)
		{
			Entity::CollisionReturn r = GameCollision::RecteAndRect(mBoss->listAmmo.at(i)->GetBound(),
				listCollision.at(j)->GetBound());
			if (r.IsCollided)
			{

				mBoss->listAmmo.at(i)->OnCollision(listCollision.at(j), r, Entity::NotKnow);
			}
		}
	}
	//Check Fire Ammo With Player
	for (int i = 0; i < mBoss->listAmmo.size(); i++)
	{
		Entity::CollisionReturn r = GameCollision::RecteAndRect(mBoss->listAmmo.at(i)->GetBound(),
			mPlayer->GetBound());
		if (r.IsCollided)
		{
			if (mBoss->listAmmo.at(i) == lastFire || !mBoss->listAmmo.at(i)->isActive) continue;
			mPlayer->SetState(new PlayerFiredState(mPlayer->mPlayerData));
			lastFire = mBoss->listAmmo.at(i);
		}
	}

	//Check Meteor with Object Map
	for (int i = 0; i < mBoss->listMeteor.size(); i++)
	{
		vector<Entity*> listCollision;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollision, mBoss->listMeteor.at(i));

		for (int j = 0; j < listCollision.size(); j++)
		{
			Entity::CollisionReturn r = GameCollision::RecteAndRect(mBoss->listMeteor.at(i)->GetBound(),
				listCollision.at(j)->GetBound());
			if (r.IsCollided)
			{
				if (listCollision.at(j)->Tag != Entity::Land) continue;
				if(mBoss->listMeteor.at(i)->GetCurrentState()!=AppleState::Flying) continue;
				Sound::getInstance()->play("Sword Spinning", false, 1);
				mBoss->listMeteor.at(i)->OnCollision(listCollision.at(j), r, Entity::NotKnow);
			}
		}
	}

	//Check Meteor with Player
	for (int i = 0; i < mBoss->listMeteor.size(); i++)
	{
		
		Entity::CollisionReturn r = GameCollision::RecteAndRect(mBoss->listMeteor.at(i)->GetBound(),
			mPlayer->GetBound());
		if (r.IsCollided && mBoss->listMeteor.at(i)->GetCurrentState()==AppleState::Flying)
		{
			
			if (mPlayer->mCurrentState == PlayerState::Standing)
			{
				
				//Sound::getInstance()->play("Jafar Laugh", false, 1);
				Sound::getInstance()->play("Fire From Coal", false, 1);
				mPlayer->SetState(new PlayerFiredState(mPlayer->mPlayerData));
			}
			else
			{
				//Sound::getInstance()->play("Jafar Laugh", false, 1);
				Sound::getInstance()->play("Aladdin Hurt", false, 1);
				Sound::getInstance()->play("Fire From Coal", false, 1);
				mPlayer->isAttacked = true;
				mPlayer->HPCount--;
			}
			
			mBoss->listMeteor.at(i)->OnCollision(mPlayer, r, Entity::NotKnow);
		}
	}

	//Check Flame with Player
	for (int i = 0; i < mMap->listFlame.size(); i++)
	{
		if (mPlayer->GetPosition().y > 240) continue;
		Entity::CollisionReturn r = GameCollision::RecteAndRect(mMap->listFlame.at(i)->GetBound(),
			mPlayer->GetBound());
		if (r.IsCollided)
		{
			mMap->listFlame.at(i)->OnCollision(mPlayer, r, Entity::NotKnow);
			if (mPlayer->getState() == PlayerState::Standing &&  mPlayer->GetCurrentAnimation()->GetCurrentFrame()>=2)
				mPlayer->SetState(new PlayerFiredState(mPlayer->mPlayerData));
		}
	}
#pragma region Check AppleObject with Player
	Entity::CollisionReturn App1 = GameCollision::RecteAndRect(mPlayer->GetBound(),
		app1->GetBound());
	if (App1.IsCollided)
	{
	
		mPlayer->AppleCount++;
		EatItem->Reset();
		EatItem->SetPosition(app1->GetPosition());
		app1->OnCollision(NULL, App1, Entity::NotKnow);


	}

	Entity::CollisionReturn App2 = GameCollision::RecteAndRect(mPlayer->GetBound(),
		app2->GetBound());
	if (App2.IsCollided)
	{
		EatItem->Reset();
		EatItem->SetPosition(app2->GetPosition());
		mPlayer->AppleCount++;
		app2->OnCollision(NULL, App2, Entity::NotKnow);
		
	}

	Entity::CollisionReturn App3 = GameCollision::RecteAndRect(mPlayer->GetBound(),
		app3->GetBound());
	if (App3.IsCollided)
	{
		EatItem->Reset();
		EatItem->SetPosition(app3->GetPosition());
		mPlayer->AppleCount++;
		app3->OnCollision(NULL, App3, Entity::NotKnow);
		
	}
#pragma endregion
	
#pragma region player va cham voi object
	//Check player va cham voi object
	int widthBottom = 0;
	Entity::EntityTypes tag = Entity::None;
	vector<Entity*> listCollision;
	
	mMap->GetQuadTree()->getEntitiesCollideAble(listCollision, mPlayer);

	for (size_t i = 0; i < listCollision.size(); i++)
	{

		Entity::CollisionReturn r = GameCollision::RecteAndRect(mPlayer->GetBound(),
			listCollision.at(i)->GetBound());
		if (r.IsCollided)
		{

			//lay phia va cham cua Entity so voi Player
			Entity::SideCollisions sidePlayer = GameCollision::getSideCollision(mPlayer, r);
			
			if (listCollision.at(i)->Tag==Entity::box && sidePlayer != Entity::Bottom && sidePlayer != Entity::BottomLeft && sidePlayer != Entity::BottomLeft) return;
			//lay phia va cham cua Player so voi Entity
			Entity::SideCollisions sideImpactor = GameCollision::getSideCollision(listCollision.at(i), r);

			//goi den ham xu ly collision cua Player va Entity
			if (listCollision.at(i)->Tag == Entity::AppleObject)
			{
				mPlayer->AppleCount++;
				EatItem->SetPosition(listCollision.at(i)->GetPosition());
			}
			else if (listCollision.at(i)->Tag == Entity::Heart)
			{
				mPlayer->HPCount += 5;
				EatItem->SetPosition(listCollision.at(i)->GetPosition());
			}
			


			listCollision.at(i)->OnCollision(mPlayer, r, sideImpactor);
			//Check táo trùng để cộng 

			if (listCollision.at(i)->Tag == Entity::CheckPoint && mPlayer->mCurrentState != PlayerState::Falling)
			{
				mPlayer->CheckPoint = D3DXVECTOR2(listCollision.at(i)->GetPosition().x + 10, listCollision.at(i)->GetPosition().y + 15);
				return;
			}



			mPlayer->OnCollision(listCollision.at(i), r, sidePlayer);
			//kiem tra neu va cham voi phia duoi cua Player 
			if (sidePlayer == Entity::Bottom || sidePlayer == Entity::BottomLeft
				|| sidePlayer == Entity::BottomRight)
			{
				//kiem cha do dai ma mario tiep xuc phia duoi day
				int bot = r.RegionCollision.right - r.RegionCollision.left;

				if (bot > widthBottom)
					widthBottom = bot;
			}
			tag = listCollision.at(i)->Tag;

		}
	}
#pragma endregion

	
	if (mPlayer->getState() == PlayerState::Revive) return;
	if (widthBottom <20)
	{
		mPlayer->OnNoCollisionWithBottom();
	}
}

void BossScene::AppleObjectHandle()
{
	
	if ((GetTickCount()-lastTime)/1000.0f >=10.0f)
	{
		int a = rand() %4 + 1;

		app1->SetPos(mMap->listPosApp1.at(a - 1).x, mMap->listPosApp1.at(a - 1).y);
		app2->SetPos(mMap->listPosApp2.at(a - 1).x, mMap->listPosApp2.at(a - 1).y);
		app3->SetPos(mMap->listPosApp3.at(a - 1).x, mMap->listPosApp3.at(a - 1).y);
		lastTime = GetTickCount();
	}

}