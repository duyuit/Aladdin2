#include "DieScene.h"



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
		die = new Animation("Resources/Aladdin.png", 27, listRect, (float)1 / 0.2, D3DXVECTOR2(0.5, 0.5), D3DCOLOR_XRGB(255, 0, 255));
		die->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
		die->GetSprite()->SetScale(D3DXVECTOR2(2, 2));
		dieText = new Sprite("Resources/die.png", RECT{ 0,0,341,87 });
		dieText->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2 + 150);
}
int Count = 0;
void DieScene::Update(float dt)
{
	die->Update(1);
	if (die->GetCurrentFrame() == 26)
		die->SetCurrentFrame(23);
	Count++;
}
void DieScene::Draw()
{
	die->Draw();
	if (Count >= 5)
	{
		dieText->Draw();
		if(Count>=10) Count = 0;
	}
}

void DieScene::OnKeyDown(int keyCode)
{
	if(keyCode==VK_SPACE)
		SceneManager::GetInstance()->ReplaceScene(preScene);




}

void DieScene::OnKeyUp(int keyCode)
{




}