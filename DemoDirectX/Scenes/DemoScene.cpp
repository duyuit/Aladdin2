#include "DemoScene.h"

DemoScene::DemoScene()
{
    LoadContent();
}

ManThrowBowl* test;
ManThrowBowl* test2;

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
    mPlayer->SetPosition(1500,400);

	mPlayer->SetCamera(mCamera);

	test = new ManThrowBowl(mMap->listBowl1);
	test2 = new ManThrowBowl(mMap->listBowl2);

	
	
	
}

void DemoScene::Update(float dt)
{
	
	checkCollision();
	mPlayer->HandleKeyboard(keys);
	mPlayer->Update(dt);

	CheckCameraAndWorldMap();

	for (int i = 0; i < mMap->listCamel.size(); i++)
	{
		mMap->listCamel.at(i)->Update();
	}
	for (int i = 0; i < mMap->listAppleObject.size(); i++)
	{
		mMap->listAppleObject.at(i)->Update();
	}

	
	test->Update(mPlayer);
	test2->Update(mPlayer);


}

void DemoScene::Draw()
{
    mMap->Draw();

    mPlayer->Draw();

	mMap->DrawFront();
	mPlayer->mUI->Draw(); // Ve UI tren tat ca

	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x,GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y);

	test->Draw(D3DXVECTOR3(),RECT(),D3DXVECTOR2(), trans,0, D3DXVECTOR2(),D3DXCOLOR());
	test2->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans, 0, D3DXVECTOR2(), D3DXCOLOR());
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

	//if (keyCode == VK_NUMPAD3)
	//{
	//	test->mCurrentApple->SetPosition(test->GetPosition());
	//	test->mCurrentApple->SetState(AppleState::Flying);
	//}
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
	/*su dung de kiem tra xem khi nao mario khong dung tren 1 object hoac
	dung qua sat mep trai hoac phai cua object do thi se chuyen state la falling*/
	int widthBottom = 0;

	vector<Entity*> listCollision;

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

	if (test->mCurrentApple->GetCurrentState() != AppleState::NONE)
	{
		vector<Entity*> listCollisionWithBowl;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionWithBowl, test->mCurrentApple);

		for (size_t i = 0; i < listCollisionWithBowl.size(); i++)
		{
		
			Entity::CollisionReturn r = GameCollision::RecteAndRect(test->mCurrentApple->GetBound(),
				listCollisionWithBowl.at(i)->GetBound());
			if (r.IsCollided)
				test->mCurrentApple->OnCollision(listCollisionWithBowl.at(i), r, Entity::NotKnow);
		}
	}


	if (test2->mCurrentApple->GetCurrentState() != AppleState::NONE)
	{
		vector<Entity*> listCollisionWithBowl;
		mMap->GetQuadTree()->getEntitiesCollideAble(listCollisionWithBowl, test2->mCurrentApple);

		for (size_t i = 0; i < listCollisionWithBowl.size(); i++)
		{

			Entity::CollisionReturn r = GameCollision::RecteAndRect(test2->mCurrentApple->GetBound(),
				listCollisionWithBowl.at(i)->GetBound());
			if (r.IsCollided)
				test2->mCurrentApple->OnCollision(listCollisionWithBowl.at(i), r, Entity::NotKnow);
		}
	}


	//Check bowl Collision voi Player
	if (test->mCurrentApple->GetCurrentState() == AppleState::Flying)
	{
		Entity::CollisionReturn r = GameCollision::RecteAndRect(test->mCurrentApple->GetBound(), mPlayer->GetBound());
		if (r.IsCollided)
		{
			mPlayer->OnCollision(test->mCurrentApple, r, Entity::NotKnow);
			test->mCurrentApple->OnCollision(mPlayer, r, Entity::NotKnow);
		}
	}

	if (test2->mCurrentApple->GetCurrentState() == AppleState::Flying)
	{
		Entity::CollisionReturn r = GameCollision::RecteAndRect(test2->mCurrentApple->GetBound(), mPlayer->GetBound());
		if (r.IsCollided)
		{
			mPlayer->OnCollision(test2->mCurrentApple, r, Entity::NotKnow);
			test2->mCurrentApple->OnCollision(mPlayer, r, Entity::NotKnow);
		}
	}





	//Check player va cham voi object
	mMap->GetQuadTree()->getEntitiesCollideAble(listCollision, mPlayer);
	Entity::EntityTypes tag = Entity::None;
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

	//Neu mario dung ngoai mep thi luc nay cho mario rot xuong duoi dat 
	if (tag == Entity::string) return;
	if (widthBottom < Define::PLAYER_BOTTOM_RANGE_FALLING)
	{

		mPlayer->OnNoCollisionWithBottom();
	}
}