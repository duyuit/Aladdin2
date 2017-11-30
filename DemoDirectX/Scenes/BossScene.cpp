#include "BossScene.h"



BossScene::BossScene(Player* pl,UI* ui)
{
	mPlayer = pl;
	mUI = ui;
	LoadContent();

}
vector<RECT>  BossScene::loadRect()
{
	vector<RECT> listSourceRect;
	RECT rect;

	rect.left = 310; rect.top = 30; rect.right = rect.left + 21; rect.bottom = rect.top +25; listSourceRect.push_back(rect);
	rect.left = 342; rect.top = 24; rect.right = rect.left + 31; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
	rect.left = 384; rect.top = 21; rect.right = rect.left + 30; rect.bottom = rect.top + 33; listSourceRect.push_back(rect);
	rect.left = 424; rect.top = 7; rect.right = rect.left + 43; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
	rect.left = 481; rect.top = 13; rect.right = rect.left + 38; rect.bottom = rect.top +41; listSourceRect.push_back(rect);
	rect.left = 527; rect.top = 9; rect.right = rect.left + 44; rect.bottom = rect.top + 44; listSourceRect.push_back(rect);
	rect.left = 580; rect.top = 7; rect.right = rect.left + 46; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);

	
	return listSourceRect;
}
BossScene::~BossScene()
{
}
void BossScene::LoadContent()
{
	mBackColor = 0x54acd2;
	EatItem = new Animation("Resources/flare.png", 7, loadRect(), (float)1 / 1, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(186, 254, 202));
	EatItem->SetScale(D3DXVECTOR2(1.5, 1.5));
	EatItem->SetPosition(300, 250);
	mMap = new GameMapBoss("Resources/boss.tmx");
	
	mCamera = new Camera(GameGlobal::GetWidth(), GameGlobal::GetHeight());
	mCamera->SetPosition(GameGlobal::GetWidth() / 2,
		mMap->GetHeight() - mCamera->GetHeight());

	mMap->SetCamera(mCamera);


	mPlayer->SetPosition(200, 50);

	mPlayer->SetCamera(mCamera);

	mBoss = new Boss(mPlayer);
	mBoss->SetPosition(350, 250);

}

void BossScene::Update(float dt)
{
	CheckCameraAndWorldMap();
	checkCollision();
	mPlayer->HandleKeyboard(keys);

	mPlayer->Update(dt);

	mUI->Update();
	EatItem->Update(1);
	if (EatItem->GetCurrentFrame() == 6)
	{
	
		EatItem->SetPosition(0, 0);
	}
	mBoss->Update();
}

void BossScene::Draw()
{

	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x, GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y); //Lay TranSition hien tai
	mMap->Draw(); //Ve Map
	mPlayer->Draw();
	mBoss->Draw(trans);

	EatItem->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);
	
	mUI->Draw();
	

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
	keys[keyCode] = false;
	mPlayer->OnKeyUp(keyCode);

}
void BossScene::OnKeyDown(int keyCode)
{
	keys[keyCode] = true;
	mPlayer->OnKeyPressed(keyCode);
}
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


	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{
		if (mPlayer->listApple.at(i)->mCurrentAnim == nullptr || mPlayer->listApple.at(i)->curState == nullptr) continue;
		Entity::CollisionReturn re = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(),
			mBoss->GetBound());
		if (re.IsCollided)
		{
			EatItem->Reset();
			EatItem->SetPosition(mPlayer->listApple.at(i)->GetPosition());
			mBoss->SetState(new BossStandHuman(mBoss->mData));
			mPlayer->listApple.at(i)->OnCollision(mBoss, re, Entity::NotKnow);
		}

	}
	int widthBottom = 0;
	Entity::EntityTypes tag = Entity::None;
	vector<Entity*> listCollision;
	//Check player va cham voi object
	mMap->GetQuadTree()->getEntitiesCollideAble(listCollision, mPlayer);

	for (size_t i = 0; i < listCollision.size(); i++)
	{

		Entity::CollisionReturn r = GameCollision::RecteAndRect(mPlayer->GetBound(),
			listCollision.at(i)->GetBound());
		if (r.IsCollided)
		{

			//lay phia va cham cua Entity so voi Player
			Entity::SideCollisions sidePlayer = GameCollision::getSideCollision(mPlayer, r);
			if (mPlayer->mCurrentState == PlayerState::Jumping) return;
			if (sidePlayer != Entity::Bottom && sidePlayer != Entity::BottomLeft && sidePlayer != Entity::BottomLeft) return;
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


	
	if (mPlayer->getState() == PlayerState::Revive) return;
	if (widthBottom <20)
	{
		mPlayer->OnNoCollisionWithBottom();
	}
}