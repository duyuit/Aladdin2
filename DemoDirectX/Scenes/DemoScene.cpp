#include "DemoScene.h"

DemoScene::DemoScene()
{
    LoadContent();
}

ManThrowBowl* Bowl1;
ManThrowBowl* Bowl2;
Enemy1* test;
void DemoScene::LoadContent()
{
    //set mau backcolor cho scene o day la mau xanh
    mBackColor = 0x54acd2;

    mMap = new GameMap("Resources/untitled.tmx");

    mCamera = new Camera(GameGlobal::GetWidth(), GameGlobal::GetHeight());
	mCamera->SetPosition(GameGlobal::GetWidth() / 2,
		mMap->GetHeight() - mCamera->GetHeight());

    mMap->SetCamera(mCamera);

    mPlayer = new Player();
    mPlayer->SetPosition(10,400);

	mPlayer->SetCamera(mCamera);

	Bowl1 = new ManThrowBowl(mMap->listBowlPosition1);
	Bowl2 = new ManThrowBowl(mMap->listBowlPosition2);

	test = new Enemy1(D3DXVECTOR2(300, 800),mPlayer);
	test->SetPosition(400, 635);
	//test->SetState(new Enemy1Running(test->mData));
	
}

void DemoScene::Update(float dt)
{
	
	checkCollision(); //Check va cham giua cac vat the
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

	
	Bowl1->Update(mPlayer); 
	Bowl2->Update(mPlayer);

	for (int i = 0; i < mMap->listDropBrick.size(); i++) //Update DropBrick
	{
		mMap->listDropBrick.at(i)->Update();
	}
	
	test->Update();


}

void DemoScene::Draw()
{
    mMap->Draw(); //Ve Map
	 
    mPlayer->Draw(); //Ve Player

	mMap->DrawFront(); //Ve mat truoc cua Map
	mPlayer->mUI->Draw(); // Ve UI tren tat ca

	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x,GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y); //Lay TranSition hien tai

	Bowl1->Draw(D3DXVECTOR3(),RECT(),D3DXVECTOR2(), trans,0, D3DXVECTOR2(),D3DXCOLOR());
	Bowl2->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans, 0, D3DXVECTOR2(), D3DXCOLOR());


	for (int i = 0; i < mMap->listDropBrick.size(); i++) //Update DropBrick
	{
		mMap->listDropBrick.at(i)->Draw(trans, D3DXVECTOR2());
	}
	test->Draw(trans);
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


#pragma region -Check Collision Enemy-
	//Check Enemy1 vs Player
	Entity::CollisionReturn re = GameCollision::RecteAndRect(test->GetBound(),
		mPlayer->GetBound());
	if (re.IsCollided)
	{
		test->OnCollision(mPlayer, re, Entity::NotKnow);
	}

	//Check Apple va cham voi Enemy
	for (int i = 0; i < mPlayer->listApple.size(); i++)
	{

		Entity::CollisionReturn re = GameCollision::RecteAndRect(mPlayer->listApple.at(i)->GetBound(), test->GetBound());

		if (re.IsCollided)
		{

			test->OnCollision(mPlayer->listApple.at(i), re, Entity::NotKnow);
			mPlayer->listApple.at(i)->OnCollision(test, re, Entity::NotKnow);
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
			
			mPlayer->OnCollision(listCollision.at(i), r, sidePlayer);

			listCollision.at(i)->OnCollision(mPlayer, r, sideImpactor);
			//Check táo trùng để cộng 
			if (listCollision.at(i)->Tag == Entity::AppleObject) 
			{
				mPlayer->AppleCount++;
				//delete listCollision.at(i); //Va cham voi player roi, xoa Apple nay di
				//listCollision.at(i) = nullptr; //Set null
				//continue;
			}
			

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


	if (tag == Entity::string || tag == Entity::BrickDrop) return;

	//Neu mario dung ngoai mep thi luc nay cho mario rot xuong duoi dat 
	if (widthBottom < Define::PLAYER_BOTTOM_RANGE_FALLING)
	{
		mPlayer->OnNoCollisionWithBottom();
	}
}