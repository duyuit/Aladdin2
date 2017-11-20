#include "DemoScene.h"

DemoScene::DemoScene()
{
    LoadContent();
	mDieScene = new DieScene(this);
}

ManThrowBowl* Bowl1;
ManThrowBowl* Bowl2;
Enemy1* enemy1;
Enemy2* enemy2;
Enemy3* enemy3;
Enemy4* enemy4;

CayBung *cb;
vector<RECT> LoadEatItem()
{
	RECT rect;
	vector<RECT> listSourceRect;
	rect.left = 758; rect.top = 31; rect.right = rect.left + 15; rect.bottom = rect.top + 10; listSourceRect.push_back(rect);
	rect.left = 756; rect.top = 32; rect.right = rect.left + 24; rect.bottom = rect.top + 18; listSourceRect.push_back(rect);
	rect.left = 731; rect.top = 25; rect.right = rect.left + 22; rect.bottom = rect.top + 23; listSourceRect.push_back(rect);
	rect.left = 794; rect.top = 23; rect.right = rect.left + 32; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);
	return listSourceRect;

}
void DemoScene::LoadContent()
{
    //set mau backcolor cho scene o day la mau xanh
    mBackColor = 0x54acd2;

    mMap = new GameMap("Resources/untitled.tmx");

    mCamera = new Camera(GameGlobal::GetWidth(), GameGlobal::GetHeight());
	mCamera->SetPosition(GameGlobal::GetWidth() / 2,
		mMap->GetHeight() - mCamera->GetHeight());

    mMap->SetCamera(mCamera);
	EatItem = new Animation("Resources/Aladdin.png", 4, LoadEatItem(), (float)1 /0.5,D3DXVECTOR2(0.5,0.5),D3DCOLOR_XRGB(255,0,255));
	EatItem->SetScale(D3DXVECTOR2(2, 2));
	EatItem->SetPosition(0, 0);

    mPlayer = new Player();
    mPlayer->SetPosition(2500,300);

	mPlayer->SetCamera(mCamera);

	Bowl1 = new ManThrowBowl(mMap->listBowlPosition1); // Truyen list cho bowl1
	Bowl2 = new ManThrowBowl(mMap->listBowlPosition2);// Truyen list cho bowl2

	enemy1 = new Enemy1(mPlayer,mMap->listEnemy1Position);
	enemy2 = new Enemy2(mPlayer, mMap->listEnemy2Position);
	enemy3 = new Enemy3(mPlayer, mMap->listEnemy3Position);
	enemy4 = new Enemy4(mMap->listEnemy4Position);
	enemy4->mPlayer = mPlayer;


	
}

void DemoScene::Update(float dt)
{
	
	checkCollision(); //Check va cham giua cac vat the
	if (mPlayer->HPCount == 0)
	{
		mDieScene->die->Reset();
		SceneManager::GetInstance()->ReplaceScene(mDieScene);

	}
	mPlayer->HandleKeyboard(keys); //Xu ly ban phim cho player
	mPlayer->Update(dt); //Update player

	CheckCameraAndWorldMap(); //Check camera vuot bien cua map

	for (int i = 0; i < mMap->listCamel.size(); i++) //Update con Lac Da
	{
		mMap->listCamel.at(i)->Update();
	}
	for (int i = 0; i < mMap->listAppleObject.size(); i++) //Update Tao Object
	{
		mMap->listAppleObject.at(i)->Update();
	}
	for (int i = 0; i < mMap->listCayBung.size(); i++) //Update Cay Bung
	{
		mMap->listCayBung.at(i)->Update();
	}

	for (int i = 0; i < mMap->listCheckPointSite.size(); i++) //Update CheckPoint
	{
		mMap->listCheckPointSite.at(i)->Update();
	}

	Bowl1->Update(mPlayer); 
	Bowl2->Update(mPlayer);

	for (int i = 0; i < mMap->listDropBrick.size(); i++) //Update DropBrick
	{
		mMap->listDropBrick.at(i)->Update();
	}

	enemy1->Update();
	enemy2->Update();
	enemy3->Update();
	enemy4->Update(mPlayer);

	EatItem->Update(1);
	if (EatItem->GetCurrentFrame() == 3) EatItem->SetPosition(0, 0);

	


}

void DemoScene::Draw()
{
    mMap->Draw(); //Ve Map
	 
    mPlayer->Draw(); //Ve Player

	

	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x,GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y); //Lay TranSition hien tai

	Bowl1->Draw(D3DXVECTOR3(),RECT(),D3DXVECTOR2(), trans,0, D3DXVECTOR2(),D3DXCOLOR());
	Bowl2->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans, 0, D3DXVECTOR2(), D3DXCOLOR());


	for (int i = 0; i < mMap->listDropBrick.size(); i++) //Draw DropBrick
	{
		mMap->listDropBrick.at(i)->Draw(trans, D3DXVECTOR2());
	}
	for (int i = 0; i < mMap->listCayBung.size(); i++) //
	{
		mMap->listCayBung.at(i)->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(1, 1), trans);
	}


	for (int i = 0; i < mMap->listCheckPointSite.size(); i++) //Draw CheckPoint
	{
		mMap->listCheckPointSite.at(i)->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(1, 1), trans);
	}


	enemy1->Draw(trans);
	enemy2->Draw(trans);
	enemy3->Draw(trans);
	enemy4->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans, 0, D3DXVECTOR2(), D3DXCOLOR());
	mMap->DrawFront(); //Ve mat truoc cua Map
	mPlayer->mUI->Draw(); // Ve UI tren tat ca

	EatItem->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);

}

void DemoScene::OnKeyDown(int keyCode)
{
    keys[keyCode] = true;
    mPlayer->OnKeyPressed(keyCode);

	


}

void DemoScene::OnKeyUp(int keyCode)
{
    keys[keyCode] = false;
	mPlayer->OnKeyUp(keyCode);

	
}

void DemoScene::OnMouseDown(float x, float y)
{
}
void DemoScene::CheckCameraAndWorldMap()
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


void DemoScene::checkCollision()
{
	Entity::EntityTypes tag = Entity::None;

	


#pragma region -Check Collision Enemy1-
	//Check Enemy1 vs Player
	Entity::CollisionReturn re = GameCollision::RecteAndRect(enemy1->GetBound(),
		mPlayer->GetBound());
	if (re.IsCollided)
	{
		enemy1->OnCollision(mPlayer, re, Entity::NotKnow);
	}

	//Check Apple va cham voi Enemy
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{

		Entity::CollisionReturn re = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(), enemy1->GetBound());

		if (re.IsCollided)
		{

			enemy1->OnCollision(mPlayer->listApple.at(i), re, Entity::NotKnow);
			mPlayer->listApple.at(i)->OnCollision(enemy1, re, Entity::NotKnow);
		}
	}
#pragma endregion


#pragma region -Check Collision Enemy2-
	//Check Enemy2 vs Player
	Entity::CollisionReturn re1 = GameCollision::RecteAndRect(enemy2->GetBound(),
		mPlayer->GetBound());
	if (re1.IsCollided)
	{
		enemy2->OnCollision(mPlayer, re1, Entity::NotKnow);
	}

	//Check Apple va cham voi Enemy
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{

		Entity::CollisionReturn re1 = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(), enemy2->GetBound());

		if (re1.IsCollided)
		{

			enemy2->OnCollision(mPlayer->listApple.at(i), re1, Entity::NotKnow);
			mPlayer->listApple.at(i)->OnCollision(enemy2, re1, Entity::NotKnow);
		}
	}



	
#pragma endregion
#pragma region -Check Collision Enemy3-
	//Check Enemy2 vs Player
	Entity::CollisionReturn re3 = GameCollision::RecteAndRect(enemy3->GetBound(),
		mPlayer->GetBound());
	if (re3.IsCollided)
	{
		enemy3->OnCollision(mPlayer, re3, Entity::NotKnow);
	}

	//Check Apple va cham voi Enemy
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{

		Entity::CollisionReturn re1 = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(), enemy3->GetBound());

		if (re1.IsCollided)
		{

			enemy3->OnCollision(mPlayer->listApple.at(i), re1, Entity::NotKnow);
			mPlayer->listApple.at(i)->OnCollision(enemy3, re1, Entity::NotKnow);
		}
	}
	

	//Check Knife Enemy3 with Map Object
	vector<Entity*> listCollisionKnife;
	mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionKnife, enemy3->mKnife);
	for (int i = 0; i < listCollisionKnife.size(); i++)
	{
		Entity::CollisionReturn re = GameCollision::RecteAndRect(enemy3->mKnife->GetBound(),
			listCollisionKnife.at(i)->GetBound());
		if (re.IsCollided)
			enemy3->mKnife->OnCollision(listCollisionKnife.at(i), re, Entity::NotKnow);
	}

	//Check Knife Enemy3 with Player
	if (enemy3->mKnife->GetCurrentState() == AppleState::Flying)
	{
		Entity::CollisionReturn re = GameCollision::RecteAndRect(enemy3->mKnife->GetBound(),
			mPlayer->GetBound());
		if (re.IsCollided)
		{
			enemy3->mKnife->OnCollision(mPlayer, re, Entity::NotKnow);
			mPlayer->OnCollision(enemy3->mKnife, re, Entity::NotKnow);
		}

	}

#pragma endregion
#pragma region - Check Collision Enemy4 Knife
	//Check Coliison with Object Map
	vector<Entity*> listCollisionKnife4;
	mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionKnife4, enemy4->mCurrentKnife);
	for (int i = 0; i < listCollisionKnife4.size(); i++)
	{
		Entity::CollisionReturn re = GameCollision::RecteAndRect(enemy4->mCurrentKnife->GetBound(),
			listCollisionKnife4.at(i)->GetBound());
		if (re.IsCollided)
		{
			enemy4->mCurrentKnife->OnCollision(listCollisionKnife4.at(i), re, Entity::NotKnow);
		}
	}

	//Check Knife Collision with Player
	Entity::CollisionReturn reEnemy3 = GameCollision::RecteAndRect(enemy4->mCurrentKnife->GetBound(),
		mPlayer->GetBound());
	if (reEnemy3.IsCollided && enemy4->mCurrentKnife->GetCurrentState()==AppleState::Flying)
	{
		enemy4->mCurrentKnife->OnCollision(mPlayer, re, Entity::NotKnow);
		mPlayer->OnCollision(enemy4->mCurrentKnife, re, Entity::NotKnow);
	}

	//Check Fight with Player
	Entity::CollisionReturn reEnemy4 = GameCollision::RecteAndRect(enemy4->GetBound(),
		mPlayer->GetBound());
	if (reEnemy4.IsCollided)
	{
		
		enemy4->OnCollision(mPlayer, re, Entity::NotKnow);
		//mPlayer->OnCollision(enemy4->mCurrentKnife, re, Entity::NotKnow);
	}

	//Check with Apple
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{

		Entity::CollisionReturn re = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(), enemy4->GetBound());

		if (re.IsCollided)
		{

			enemy4->OnCollision(mPlayer->listApple.at(i), re, Entity::NotKnow);
			mPlayer->listApple.at(i)->OnCollision(enemy4, re, Entity::NotKnow);
		}
	}
#pragma endregion
	
	//Check player vs DropBrick
	for (int i = 0; i < mMap->listDropBrick.size(); i++)
	{
		
		Entity::CollisionReturn re = GameCollision::RecteAndRect(mMap->listDropBrick.at(i)->GetBound(),
			mPlayer->GetBound());
		if (re.IsCollided)
		{
			Entity::SideCollisions sidePlayer = GameCollision::getSideCollision(mPlayer, re);
			mMap->listDropBrick.at(i)->OnCollision(mPlayer, re, Entity::NotKnow);
			mPlayer->OnCollision(mMap->listDropBrick.at(i), re, sidePlayer);
			tag = Entity::BrickDrop;
	
		}

	}

	//Check Apple va cham voi object
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{
		mPlayer->listApple.at(i)->Update(0);
		if (mPlayer->listApple.at(i)->mCurrentAnim == nullptr || mPlayer->listApple.at(i)->curState == nullptr ) continue;
		vector<Entity*> listCollisionApple;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionApple, mPlayer->listApple.at(i));

		for (size_t j = 0; j < listCollisionApple.size(); j++)
		{
			if (listCollisionApple.at(j)->Tag != Entity::EntityTypes::Land && listCollisionApple.at(j)->Tag != Entity::EntityTypes::LandWood) continue;
			
			Entity::CollisionReturn re = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(),
				listCollisionApple.at(j)->GetBound());

			

			if (re.IsCollided)
			{
				Entity::SideCollisions sidePlayer = GameCollision::getSideCollision(mPlayer, re);
				//Xu ly va cham thang tao o day
				mPlayer->listApple.at(i)->OnCollision(listCollisionApple.at(j),re,sidePlayer);


			}
		}
	}

	
	
	
	//Check bowl Collision voi Map

	if (Bowl1->mCurrentApple->GetCurrentState() != AppleState::NONE)
	{
		vector<Entity*> listCollisionWithBowl;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionWithBowl, Bowl1->mCurrentApple);

		for (size_t i = 0; i < listCollisionWithBowl.size(); i++)
		{
			if (listCollisionWithBowl.at(i)->Tag == Entity::AppleObject) continue;
			Entity::CollisionReturn r = GameCollision::RecteAndRect(Bowl1->mCurrentApple->GetBound(),
				listCollisionWithBowl.at(i)->GetBound());
			if (r.IsCollided)
				Bowl1->mCurrentApple->OnCollision(listCollisionWithBowl.at(i), r, Entity::NotKnow);
		}
	}


	if (Bowl2->mCurrentApple->GetCurrentState() != AppleState::NONE)
	{
		vector<Entity*> listCollisionWithBowl;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionWithBowl, Bowl2->mCurrentApple);

		for (size_t i = 0; i < listCollisionWithBowl.size(); i++)
		{
			if (listCollisionWithBowl.at(i)->Tag == Entity::AppleObject) continue;
			Entity::CollisionReturn r = GameCollision::RecteAndRect(Bowl2->mCurrentApple->GetBound(),
				listCollisionWithBowl.at(i)->GetBound());
			if (r.IsCollided)
				Bowl2->mCurrentApple->OnCollision(listCollisionWithBowl.at(i), r, Entity::NotKnow);
		}
	}


	//Check bowl Collision voi Player
	if (Bowl1->mCurrentApple->GetCurrentState() == AppleState::Flying)
	{
		Entity::CollisionReturn r = GameCollision::RecteAndRect(Bowl1->mCurrentApple->GetBound(), mPlayer->GetBound());
		if (r.IsCollided)
		{
			mPlayer->OnCollision(Bowl1->mCurrentApple, r, Entity::NotKnow);
			Bowl1->mCurrentApple->OnCollision(mPlayer, r, Entity::NotKnow);
		}
	}

	if (Bowl2->mCurrentApple->GetCurrentState() == AppleState::Flying)
	{
		Entity::CollisionReturn r = GameCollision::RecteAndRect(Bowl2->mCurrentApple->GetBound(), mPlayer->GetBound());
		if (r.IsCollided)
		{
			mPlayer->OnCollision(Bowl2->mCurrentApple, r, Entity::NotKnow);
			Bowl2->mCurrentApple->OnCollision(mPlayer, r, Entity::NotKnow);
		}
	}



	/*su dung de kiem tra xem khi nao mario khong dung tren 1 object hoac
	dung qua sat mep trai hoac phai cua object do thi se chuyen state la falling*/
	int widthBottom = 0;

	vector<Entity*> listCollision;
	//Check player va cham voi object
	mMap->GetQuadTree()->getEntitiesCollideAble(listCollision, mPlayer);

	for (size_t i = 0; i < listCollision.size(); i++)
	{
		//if (listCollision.at(i) == nullptr) //Null thi bo qua nha
		//	continue;

		Entity::CollisionReturn r = GameCollision::RecteAndRect(mPlayer->GetBound(),
			listCollision.at(i)->GetBound());
		if (r.IsCollided)
		{
		
			//lay phia va cham cua Entity so voi Player
			Entity::SideCollisions sidePlayer = GameCollision::getSideCollision(mPlayer, r);
			//lay phia va cham cua Player so voi Entity
			Entity::SideCollisions sideImpactor = GameCollision::getSideCollision(listCollision.at(i), r);

			//goi den ham xu ly collision cua Player va Entity
			if (listCollision.at(i)->Tag == Entity::AppleObject)
			{
				mPlayer->AppleCount++;
				//delete listCollision.at(i); //Va cham voi player roi, xoa Apple nay di
				//listCollision.at(i) = nullptr; //Set null
				//continue;
				EatItem->SetPosition(listCollision.at(i)->GetPosition());
			}
			

			listCollision.at(i)->OnCollision(mPlayer, r, sideImpactor);
			//Check táo trùng để cộng 
		
			if (listCollision.at(i)->Tag == Entity::CheckPoint && mPlayer->mCurrentState!=PlayerState::Falling)
			{
				mPlayer->CheckPoint = D3DXVECTOR2(listCollision.at(i)->GetPosition().x+10, listCollision.at(i)->GetPosition().y+15);
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


	if (tag == Entity::string || tag == Entity::BrickDrop || tag==Entity::Bung) return;
	if (mPlayer->getState() == PlayerState::Bung ||
		mPlayer->getState() == PlayerState::ClimbingHori || 
		mPlayer->getState() == PlayerState::ThrowCLimb ||
		mPlayer->getState() == PlayerState::Revive) return;
	//Neu mario dung ngoai mep thi luc nay cho mario rot xuong duoi dat 
	if (widthBottom < Define::PLAYER_BOTTOM_RANGE_FALLING)
	{
		mPlayer->OnNoCollisionWithBottom();
	}
}