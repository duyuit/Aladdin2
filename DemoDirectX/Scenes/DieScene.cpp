#include "DieScene.h"
#include "ContinueScene.h"


DieScene::DieScene(Scene* sc)
{
	LoadContent();
	preScene = sc;
}


DieScene::~DieScene()
{
}

void DieScene::LoadContent()
{
	
		mBackColor = D3DCOLOR_XRGB(0,0,0);
		vector<RECT> listRect;
		RECT rect;
		rect.left = 1; rect.top = 2234; rect.right = rect.left + 80; rect.bottom = rect.top + 47; listRect.push_back(rect);
		rect.left = 87; rect.top = 2231; rect.right = rect.left + 61; rect.bottom = rect.top + 50; listRect.push_back(rect);
		rect.left = 160; rect.top = 2224; rect.right = rect.left + 45; rect.bottom = rect.top + 57; listRect.push_back(rect);
		rect.left = 213; rect.top = 2224; rect.right = rect.left + 45; rect.bottom = rect.top + 57; listRect.push_back(rect);
		rect.left = 264; rect.top = 2231; rect.right = rect.left + 39; rect.bottom = rect.top + 49; listRect.push_back(rect);
		rect.left = 312; rect.top = 2230; rect.right = rect.left + 40; rect.bottom = rect.top + 50; listRect.push_back(rect);
		rect.left = 361; rect.top = 2230; rect.right = rect.left + 34; rect.bottom = rect.top + 50; listRect.push_back(rect);
		rect.left = 407; rect.top = 2230; rect.right = rect.left + 35; rect.bottom = rect.top + 50; listRect.push_back(rect);
		rect.left = 454; rect.top = 2232; rect.right = rect.left + 38; rect.bottom = rect.top + 48; listRect.push_back(rect);
		rect.left = 505; rect.top = 2227; rect.right = rect.left + 43; rect.bottom = rect.top + 55; listRect.push_back(rect);
		rect.left = 560; rect.top = 2228; rect.right = rect.left + 40; rect.bottom = rect.top + 52; listRect.push_back(rect);
		rect.left = 614; rect.top = 2232; rect.right = rect.left + 39; rect.bottom = rect.top + 49; listRect.push_back(rect);
		rect.left = 661; rect.top = 2232; rect.right = rect.left + 40; rect.bottom = rect.top + 50; listRect.push_back(rect);
		rect.left = 2; rect.top = 2335; rect.right = rect.left + 37; rect.bottom = rect.top + 50; listRect.push_back(rect);
		rect.left = 49; rect.top = 2329; rect.right = rect.left + 37; rect.bottom = rect.top + 56; listRect.push_back(rect);
		rect.left = 97; rect.top = 2331; rect.right = rect.left + 42; rect.bottom = rect.top + 54; listRect.push_back(rect);
		rect.left = 148; rect.top = 2333; rect.right = rect.left + 60; rect.bottom = rect.top + 52; listRect.push_back(rect);
		rect.left = 223; rect.top = 2336; rect.right = rect.left + 61; rect.bottom = rect.top + 50; listRect.push_back(rect);
		rect.left = 296; rect.top = 2310; rect.right = rect.left + 75; rect.bottom = rect.top + 82; listRect.push_back(rect);
		rect.left = 383; rect.top = 2309; rect.right = rect.left + 77; rect.bottom = rect.top + 84; listRect.push_back(rect);
		rect.left = 476; rect.top = 2309; rect.right = rect.left + 75; rect.bottom = rect.top + 84; listRect.push_back(rect);
		rect.left = 567; rect.top = 2311; rect.right = rect.left + 68; rect.bottom = rect.top + 82; listRect.push_back(rect);
		rect.left = 654; rect.top = 2313; rect.right = rect.left + 66; rect.bottom = rect.top + 80; listRect.push_back(rect);
		rect.left = 734; rect.top = 2321; rect.right = rect.left + 66; rect.bottom = rect.top + 73; listRect.push_back(rect);
		rect.left = 811; rect.top = 2323; rect.right = rect.left + 66; rect.bottom = rect.top + 73; listRect.push_back(rect);
		rect.left = 888; rect.top = 2323; rect.right = rect.left + 66; rect.bottom = rect.top + 73; listRect.push_back(rect);
		rect.left = 970; rect.top = 2325; rect.right = rect.left + 66; rect.bottom = rect.top + 73; listRect.push_back(rect);
		rect.left = 1049; rect.top = 2325; rect.right = rect.left + 66; rect.bottom = rect.top + 73; listRect.push_back(rect);
		die = new Animation("Resources/Aladdin.png", 27, listRect, (float)1 / 0.15, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255));
		die->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
		die->GetSprite()->SetScale(D3DXVECTOR2(1,1));
		dieText = new Sprite("Resources/die.png", RECT{ 0,0,341,87 });
		dieText->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2+80);
		dieText->SetScale(D3DXVECTOR2(0.5, 0.5));
		
		vector<RECT> listSourceRect;
		rect.left = 11; rect.top = 32; rect.right = rect.left + 68; rect.bottom = rect.top + 28; listSourceRect.push_back(rect);
		rect.left = 86; rect.top = 25; rect.right = rect.left + 57; rect.bottom = rect.top + 35; listSourceRect.push_back(rect);
		rect.left = 152; rect.top = 17; rect.right = rect.left + 57; rect.bottom = rect.top + 43; listSourceRect.push_back(rect);
		rect.left = 218; rect.top = 7; rect.right = rect.left + 58; rect.bottom = rect.top + 53; listSourceRect.push_back(rect);
		rect.left = 285; rect.top = 8; rect.right = rect.left + 51; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
		rect.left = 350; rect.top = 13; rect.right = rect.left + 63; rect.bottom = rect.top + 47; listSourceRect.push_back(rect);
		abu = new Animation("Resources/abu.png",6, listSourceRect, (float)1 / 0.2, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255));
		abu->SetPosition(GameGlobal::GetWidth()-80, GameGlobal::GetHeight() -80);
		
}
int Count = 0;
void DieScene::Update(float dt)
{

	abu->Update(1);
	die->Update(1);

	Sound::getInstance()->setVolume(100.0f, "chet");
	
	if (die->GetCurrentFrame() == 26)
	{
		if (GameGlobal::liveCount < 0)
		{
			SceneManager::GetInstance()->ReplaceScene(new ContinueScene(preScene));
			return;
		}
		die->SetCurrentFrame(23);
	}
	Count++;
}
void DieScene::Draw()
{
	abu->Draw();
	die->Draw();
	if (Count >= 5)
	{
		dieText->Draw();
		if(Count>=10) Count = 0;
	}
}

void DieScene::OnKeyDown(int keyCode)
{
	if (keyCode == VK_SPACE)
	{
		if (GameGlobal::liveCount >= 0)
		{
			Sound::getInstance()->stop("chet");
			if (GameGlobal::curSong==GameGlobal::Demo)
				Sound::getInstance()->play("background_market", true, 0);
			else 
				if (GameGlobal::curSong == GameGlobal::BossMusic)
				Sound::getInstance()->play("bosstheme", true, 0);
			SceneManager::GetInstance()->ReplaceScene(preScene);
		}
	}




}

void DieScene::OnKeyUp(int keyCode)
{




}