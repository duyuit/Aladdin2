#include "EndScene.h"

vector<RECT> EndScene::LoadRect(bool f)
{
	vector<RECT>listSourceRect;
	RECT rect;
	if (f)
	{
		rect.left = 0; rect.top = 0; rect.right = rect.left + 811; rect.bottom = rect.top + 274; listSourceRect.push_back(rect);
		rect.left = 0; rect.top = 289; rect.right = rect.left + 810; rect.bottom = rect.top + 278; listSourceRect.push_back(rect);
		rect.left = 0; rect.top = 605; rect.right = rect.left + 809; rect.bottom = rect.top + 285; listSourceRect.push_back(rect);
		rect.left = 0; rect.top = 907; rect.right = rect.left + 810; rect.bottom = rect.top + 275; listSourceRect.push_back(rect);

	}
	else
	{
		rect.left = 333; rect.top = 2643; rect.right = rect.left + 46; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 388; rect.top = 2644; rect.right = rect.left + 47; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 441; rect.top = 2645; rect.right = rect.left + 45; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 493; rect.top = 2646; rect.right = rect.left + 44; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 548; rect.top = 2648; rect.right = rect.left + 45; rect.bottom = rect.top + 58; listSourceRect.push_back(rect);
		rect.left = 603; rect.top = 2650; rect.right = rect.left + 41; rect.bottom = rect.top + 57; listSourceRect.push_back(rect);
		rect.left = 654; rect.top = 2653; rect.right = rect.left + 48; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 715; rect.top = 2653; rect.right = rect.left + 48; rect.bottom = rect.top + 56; listSourceRect.push_back(rect);
		rect.left = 773; rect.top = 2655; rect.right = rect.left + 48; rect.bottom = rect.top + 56; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);

		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 830; rect.top = 2656; rect.right = rect.left + 49; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 773; rect.top = 2655; rect.right = rect.left + 48; rect.bottom = rect.top + 56; listSourceRect.push_back(rect);
		rect.left = 715; rect.top = 2653; rect.right = rect.left + 48; rect.bottom = rect.top + 56; listSourceRect.push_back(rect);
		rect.left = 654; rect.top = 2653; rect.right = rect.left + 48; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
		rect.left = 603; rect.top = 2650; rect.right = rect.left + 41; rect.bottom = rect.top + 57; listSourceRect.push_back(rect);
		rect.left = 548; rect.top = 2648; rect.right = rect.left + 45; rect.bottom = rect.top + 58; listSourceRect.push_back(rect);
		rect.left = 493; rect.top = 2646; rect.right = rect.left + 44; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 441; rect.top = 2645; rect.right = rect.left + 45; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 388; rect.top = 2644; rect.right = rect.left + 47; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 333; rect.top = 2643; rect.right = rect.left + 46; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 333; rect.top = 2643; rect.right = rect.left + 46; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 333; rect.top = 2643; rect.right = rect.left + 46; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 333; rect.top = 2643; rect.right = rect.left + 46; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 333; rect.top = 2643; rect.right = rect.left + 46; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
		rect.left = 333; rect.top = 2643; rect.right = rect.left + 46; rect.bottom = rect.top + 59; listSourceRect.push_back(rect);
	}
	return listSourceRect;
}

EndScene::EndScene()
{
	mBackColor = 0x0000;
	end= new Animation("Resources/theend.png", 4, LoadRect(true), (float)1 / 0.1, D3DXVECTOR2(0.5, 0.5));
	end->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
	end->SetScale(D3DXVECTOR2(0.208, 0.209));

	kiss=new Animation("Resources/Aladdin.png", LoadRect(false).size(), LoadRect(false), (float)1 / 0.1, D3DXVECTOR2(0.5, 1),D3DCOLOR_XRGB(255,0,255));
	kiss->SetPosition(GameGlobal::GetWidth() / 2+100, GameGlobal::GetHeight() / 2+30);

	intro = new Sprite("Resources/intro.png", RECT{ 0,0,1134,570 },0,0, D3DCOLOR_XRGB(0,0,0),D3DXVECTOR2(0.5,1));
	intro->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight()+100);
	intro->SetScale(D3DXVECTOR2(0.3, 0.2));

	Sound::getInstance()->loadSound("Resources/sound/Ending.wav", "Ending");
	Sound::getInstance()->setVolume(100.0f, "Ending");
	Sound::getInstance()->play("Ending", true, 0);
}
void EndScene::Draw()
{
	end->Draw();
	kiss->Draw();
	intro->Draw();
}
void EndScene::Update(float dt)

{
	if(intro->GetPosition().y>0)
	intro->SetPosition(GameGlobal::GetWidth() / 2, intro->GetPosition().y - 0.5);
	end->Update(1);
	kiss->Update(1);
}
EndScene::~EndScene()
{
}
