#include "ContinueScene.h"
#include "MenuScene.h"


ContinueScene::ContinueScene(Scene* preSce)
{

	this->preScene = preSce;
	background = new Sprite("Resources/wish.png", RECT{ 0,0,1920,1080 });
	background->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
	background->SetScale(D3DXVECTOR2(0.208, 0.209));
	RECT rect;
	vector<RECT> listSourceRect;
	rect.left = 3;  rect.top = 9;  rect.right = rect.left + 37;  rect.bottom = rect.top + 49; 	listSourceRect.push_back(rect);
	rect.left = 47;  rect.top = 11;  rect.right = rect.left + 41;  rect.bottom = rect.top + 46;	listSourceRect.push_back(rect);
	rect.left = 95;  rect.top = 6;  rect.right = rect.left + 40;  rect.bottom = rect.top + 51;	listSourceRect.push_back(rect);

	rect.left = 143;  rect.top = 3;  rect.right = rect.left + 44;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);
	rect.left = 143;  rect.top = 3;  rect.right = rect.left + 44;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);
	rect.left = 143;  rect.top = 3;  rect.right = rect.left + 44;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);
	rect.left = 143;  rect.top = 3;  rect.right = rect.left + 44;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);
	rect.left = 143;  rect.top = 3;  rect.right = rect.left + 44;  rect.bottom = rect.top + 54;	listSourceRect.push_back(rect);


	rect.left = 197;  rect.top = 6; rect.right = rect.left + 41;  rect.bottom = rect.top + 50;	listSourceRect.push_back(rect);
	rect.left = 250;  rect.top = 5;  rect.right = rect.left + 42;  rect.bottom = rect.top + 50;	listSourceRect.push_back(rect);
	rect.left = 303;  rect.top = 2;  rect.right = rect.left + 44;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
	rect.left = 303;  rect.top = 2;  rect.right = rect.left + 44;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
	rect.left = 303;  rect.top = 2;  rect.right = rect.left + 44;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
	rect.left = 303;  rect.top = 2;  rect.right = rect.left + 44;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
	rect.left = 303;  rect.top = 2;  rect.right = rect.left + 44;  rect.bottom = rect.top + 52;	listSourceRect.push_back(rect);
	ald = new Animation("Resources/Aladdin.png", 15, listSourceRect, (float)1 / 0.15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255), Entity::Entity::EntityTypes::PlayerOne);
	ald->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() - 30);

	listSourceRect.clear();
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
	run= new Animation("Resources/Aladdin.png", 13, listSourceRect, (float)1 / 0.3, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255), Entity::Entity::EntityTypes::PlayerOne);
	run->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() - 30);
}

void ContinueScene::Draw()
{
	background->Draw();
	if(!active)
	ald->Draw();
	else
	{
		if (isLeft)
			run->GetSprite()->FlipVertical(true);
		run->Draw();
	}
	
}
void ContinueScene::OnKeyDown(int key)
{
	if (key == VK_LEFT)
	{
		if (!active)
		{
			active = true;
			isLeft = true;
		}
	}
	else if (key == VK_RIGHT)
		{
			if (!active)
			{
				active = true;
				isLeft = false;
			}
		}
}

void ContinueScene::Update(float dt)
{
	if(!active)
	ald->Update(1);
	else
	{
		if (isLeft)
			run->SetPosition(run->GetSprite()->GetPosition().x - 2, run->GetSprite()->GetPosition().y);
		else
			run->SetPosition(run->GetSprite()->GetPosition().x + 2, run->GetSprite()->GetPosition().y);
		run->Update(1);
	}
	if (run->GetSprite()->GetPosition().x < 0)
	{
		SceneManager::GetInstance()->ReplaceScene(new MenuScene());
		return;
	}
	if (run->GetSprite()->GetPosition().x > GameGlobal::GetWidth())
	{
		GameGlobal::liveCount = 3;
		if (GameGlobal::curSong == GameGlobal::Demo)
		{
			Sound::getInstance()->play("background_market", true, 0);
			
		}

		else
			if (GameGlobal::curSong == GameGlobal::BossMusic)
			{
				Sound::getInstance()->play("bosstheme", true, 0);
			
			}
		GameGlobal::curSong = GameGlobal::Continuene;
		SceneManager::GetInstance()->ReplaceScene(preScene);
		return;
	}
}
ContinueScene::~ContinueScene()
{
}
