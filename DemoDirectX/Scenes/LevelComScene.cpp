#include "LevelComScene.h"


vector<RECT> LevelComScene::LoadRECT(bool f)
{
	vector<RECT> listSourceRect;
	RECT rect;
	if (f==true)
	{
		rect.left = 3; rect.top = 2565; rect.right = rect.left + 43; rect.bottom = rect.top + 61; listSourceRect.push_back(rect);
		rect.left = 60; rect.top = 2566; rect.right = rect.left + 48; rect.bottom = rect.top + 58; listSourceRect.push_back(rect);
		rect.left = 123; rect.top = 2566; rect.right = rect.left + 35; rect.bottom = rect.top + 56; listSourceRect.push_back(rect);
		rect.left = 166; rect.top = 2565; rect.right = rect.left + 40; rect.bottom = rect.top + 60; listSourceRect.push_back(rect);
		rect.left = 215; rect.top = 2567; rect.right = rect.left + 35; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 263; rect.top = 2564; rect.right = rect.left + 37; rect.bottom = rect.top + 62; listSourceRect.push_back(rect);
		rect.left = 310; rect.top = 2565; rect.right = rect.left + 47; rect.bottom = rect.top + 58; listSourceRect.push_back(rect);
		rect.left = 372; rect.top = 2564; rect.right = rect.left + 37; rect.bottom = rect.top + 60; listSourceRect.push_back(rect);
	}
	else
	{
		rect.left = 18; rect.top = 84; rect.right = rect.left + 25; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
		rect.left = 52; rect.top = 84; rect.right = rect.left + 41; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
		rect.left = 101; rect.top = 85; rect.right = rect.left + 52; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
		rect.left = 161; rect.top = 80; rect.right = rect.left + 40; rect.bottom = rect.top + 36; listSourceRect.push_back(rect);
		rect.left = 211; rect.top = 81; rect.right = rect.left + 34; rect.bottom = rect.top + 35; listSourceRect.push_back(rect);
		rect.left = 255; rect.top = 81; rect.right = rect.left + 44; rect.bottom = rect.top + 35; listSourceRect.push_back(rect);
		rect.left = 312; rect.top = 83; rect.right = rect.left + 49; rect.bottom = rect.top + 33; listSourceRect.push_back(rect);
		rect.left = 371; rect.top = 86; rect.right = rect.left + 46; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
	}
	return listSourceRect;
}
LevelComScene::LevelComScene(Player *player, UI* ui)
{
	pl = player;
	this->ui = ui;
	background = new Sprite("Resources/levelcomplete.png", RECT{ 0,0,1920,1080 });
	background->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
	background->SetScale(D3DXVECTOR2(0.208, 0.209));



	aladdin = new Animation("Resources/Aladdin.png", 8, LoadRECT(true), (float)1 / 15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	aladdin->GetSprite()->SetPosition(GameGlobal::GetWidth()+20, GameGlobal::GetHeight()-20);


	anbu= new Animation("Resources/abu.png", 8, LoadRECT(false), (float)1 / 15, D3DXVECTOR2(0.5, 1), D3DCOLOR_XRGB(255, 0, 255));
	anbu->GetSprite()->SetPosition(GameGlobal::GetWidth()-25, GameGlobal::GetHeight() - 20);


	Sound::getInstance()->loadSound("Resources/sound/level_complete.wav", "level_complete");
	Sound::getInstance()->setVolume(100.0f, "level_complete");
	Sound::getInstance()->play("level_complete", false, 1);
	

}
bool CheckTurn = true;
void LevelComScene::Update(float dt)
{
	if (aladdin->GetSprite()->GetPosition().x <= 0)
	{

		if (CheckTurn)
		{
			SceneManager::GetInstance()->ReplaceScene(new BossScene(pl, ui));
			CheckTurn = false;
		}else SceneManager::GetInstance()->ReplaceScene(new EndScene());
			
	}
	aladdin->Update(dt);
	aladdin->SetPosition(aladdin->GetSprite()->GetPosition().x - 1.8, aladdin->GetSprite()->GetPosition().y);

	anbu->Update(dt);
	anbu->SetPosition(anbu->GetSprite()->GetPosition().x - 1.8, anbu->GetSprite()->GetPosition().y);


}
void LevelComScene::Draw()
{
	
	background->Draw(); 
	aladdin->Draw();
	anbu->Draw();
}
void LevelComScene::LoadContent()
{

}
LevelComScene::~LevelComScene()
{
}
