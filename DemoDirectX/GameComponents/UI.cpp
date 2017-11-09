#include "UI.h"

RECT LoadNumber(int i)
{
	RECT rect;
	switch (i)
	{
	case 0:
		rect.left = 14; rect.top =5; rect.right = rect.left + 96; rect.bottom = rect.top + 140;
		break;
	case 1:
		rect.left = 174; rect.top = 6; rect.right = rect.left + 55;  rect.bottom = rect.top + 139;
		break;
	case 2:
		rect.left = 315; rect.top = 6; rect.right = rect.left + 95; rect.bottom = rect.top + 139;
		break;
	case 3:
		rect.left = 489; rect.top = 6; rect.right = rect.left + 96; rect.bottom = rect.top + 139;
		break;
	case 4:
		rect.left = 8; rect.top = 194; rect.right = rect.left + 101; rect.bottom = rect.top + 138;
		break;
	case 5:
		rect.left = 157; rect.top = 194; rect.right = rect.left + 99; rect.bottom = rect.top + 139;
		break;
	case 6:
		rect.left = 313; rect.top = 193; rect.right = rect.left + 95; rect.bottom = rect.top + 139;
		break;
	case 7:
		rect.left = 494; rect.top = 194;  rect.right = rect.left + 98; rect.bottom = rect.top + 139;
		break;
	case 8:
		rect.left = 155; rect.top = 375; rect.right = rect.left + 95;  rect.bottom = rect.top + 139;
		break;
	case 9:
		rect.left = 313;  rect.top = 374; rect.right = rect.left + 95;  rect.bottom = rect.top + 139;
		break;
	default:
		break;
	}
	return rect;
}

UI::UI()
{
	

	RECT rect;
	rect.left = 14; rect.top = 1; rect.right = rect.left + 97; rect.bottom = rect.top + 146;

	apple1 = new Sprite("Resources/number.png", RECT(), 0, 0, D3DCOLOR_XRGB(255, 0, 255));
	apple1->SetPosition(D3DXVECTOR2(540, 580));
	apple1->SetScale(D3DXVECTOR2(0.2, 0.15));
	apple1->SetSourceRect(rect);
	apple1->SetWidth(rect.right - rect.left);
	apple1->SetHeight(rect.bottom - rect.top);

	rect.left = 14; rect.top = 1; rect.right = rect.left + 97; rect.bottom = rect.top + 146;
	apple2 = new Sprite("Resources/number.png", RECT(), 0, 0, D3DCOLOR_XRGB(255, 0, 255));
	apple2->SetPosition(D3DXVECTOR2(560, 580));
	apple2->SetScale(D3DXVECTOR2(0.2, 0.15));
	apple2->SetSourceRect(rect);
	apple2->SetWidth(rect.right - rect.left);
	apple2->SetHeight(rect.bottom - rect.top);


	rect.left = 370; rect.top = 45; rect.right = rect.left + 14; rect.bottom = rect.top + 14;
	apple = new Sprite("Resources/Aladdin.png", RECT(), 0, 0, D3DCOLOR_XRGB(255, 0, 255));
	apple->SetPosition(D3DXVECTOR2(510, 580));
	apple->SetScale(D3DXVECTOR2(2, 2));
	apple->SetSourceRect(rect);
	apple->SetWidth(rect.right - rect.left);
	apple->SetHeight(rect.bottom - rect.top);

}


UI::~UI()
{
}

void UI::Update(int hp, int apple)
{
	mHP = hp;

	mAppleCount = apple;

	int applenum1 = mAppleCount / 10;
	int applenum2 = mAppleCount % 10;
	
	apple1->SetSourceRect(LoadNumber(applenum1));
	apple2->SetSourceRect(LoadNumber(applenum2));
}
void UI::Draw()
{
	apple->Draw();
	apple1->Draw();
	apple2->Draw();
}