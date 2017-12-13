#include "MenuScene.h"
#include "DemoScene.h"


MenuScene::MenuScene()
{
	screen = new Sprite("Resources/menuscene.png", RECT{ 0,0,1920,1080 });
	screen->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);
	screen->SetScale(D3DXVECTOR2(0.208, 0.209));

	

	knife = new Sprite("Resources/item.png", RECT{ 492,267,163+492,63+267 }, 0, 0, D3DCOLOR_XRGB(248, 0, 248));
	knife->SetPosition(GameGlobal::GetWidth() / 2-70, GameGlobal::GetHeight() / 2+20);
	knife->SetScale(D3DXVECTOR2(0.2, 0.2));

	
	Sound::getInstance()->loadSound("Resources/sound/background_menu.wav", "background_menu");
	Sound::getInstance()->play("background_menu", false,1);
}
void MenuScene::Update(float dt)
{
	int startPos = GameGlobal::GetWidth() / 2 - 85;

	if (knife->GetPosition().x >= startPos +20)
	{
		knife->SetPosition(startPos, knife->GetPosition().y);
	}
	if (knife->GetPosition().x > startPos - 50 && knife->GetPosition().x < startPos + 20)
	{
			knife->SetPosition(knife->GetPosition().x +1.1, knife->GetPosition().y);
	}

		
	

}
void MenuScene::Draw()
{
	screen->Draw();
	knife->Draw();
}

MenuScene::~MenuScene()
{
}

void MenuScene::OnKeyDown(int keyCode)
{
	if ((keyCode == VK_UP || keyCode == VK_DOWN) && !keys[keyCode])
	{
		if (up)
		{
			knife->SetPosition(knife->GetPosition().x, knife->GetPosition().y + 18);
			up = false;
		}
		else
		{
			knife->SetPosition(knife->GetPosition().x, knife->GetPosition().y - 18);
			up = true;
		}
	}
	if (keyCode == VK_SPACE)
	{
		SceneManager::GetInstance()->ReplaceScene(new DemoScene());
	}
	keys[keyCode] = true;


}
void MenuScene::OnKeyUp(int keyCode)
{
	keys[keyCode] = false;
	
}