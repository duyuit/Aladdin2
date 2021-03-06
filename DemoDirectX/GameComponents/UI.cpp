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
		rect.left = 313;  rect.top = 374; rect.right = rect.left + 95;  rect.bottom = rect.top + 139;
		break;
	}
	return rect;
}
RECT LoadHP(int i)
{
	RECT rect;
	rect.top = 0;
	rect.bottom =36;
	
	switch (i)
	{
	case 1:
		rect.left = 116;
		rect.right = rect.left + 56;
		break;
	case 2:
		rect.left = 231;
		rect.right = rect.left + 73;
		break;
	case 3:
		rect.left = 345;
		rect.right = rect.left + 84;
		break;
	case 4:
		rect.left = 459;
		rect.right = rect.left + 88;
		break;
	case 5:
		rect.left = 573;
		rect.right = rect.left + 98;
		break;
	case 6:
		rect.left = 688;
		rect.right = rect.left + 105;
	
		break;
	case 7:
		rect.left = 801;
		rect.right = rect.left + 108;
		
		break;
	case 8:
		rect.left = 1026;
		rect.right = rect.left + 114;
		
		break;
	case 9:
		rect.left = 915;
		rect.right = rect.left + 109;	
		break;
	case 10:
		rect.left = 1026;
		rect.right = rect.left + 114;
		break;
	default:
		break;
	}
	return rect;
}
UI::UI(Player* pl)
{
	startTime = GetTickCount();
	mplayer = pl;
	RECT rect;
	rect.left = 14; rect.top = 1; rect.right = rect.left + 97; rect.bottom = rect.top + 146;

	LiveCount = new  Sprite("Resources/item.png", RECT{366,139,366 +26,139 +27}, 0, 0, D3DCOLOR_XRGB(248, 0, 248), D3DXVECTOR2(0.5, 0.5), GameGlobal::mItemtexture);
	LiveCount->SetPosition(15, GameGlobal::GetHeight() - 38);

	apple1 = new Sprite("Resources/number.png", RECT(), 0, 0, D3DCOLOR_XRGB(255, 0, 255),D3DXVECTOR2(0.5,0.5),GameGlobal::mNumbertexture);
	apple1->SetPosition(D3DXVECTOR2(GameGlobal::GetWidth() - 25, GameGlobal::GetHeight() - 15));
	apple1->SetScale(D3DXVECTOR2(0.15, 0.1));
	apple1->SetSourceRect(rect);
	apple1->SetWidth(rect.right - rect.left);
	apple1->SetHeight(rect.bottom - rect.top);

	rect.left = 14; rect.top = 1; rect.right = rect.left + 97; rect.bottom = rect.top + 146;
	apple2 = new Sprite("Resources/number.png", RECT(), 0, 0, D3DCOLOR_XRGB(255, 0, 255), D3DXVECTOR2(0.5, 0.5), GameGlobal::mNumbertexture);

	apple2->SetPosition(D3DXVECTOR2(GameGlobal::GetWidth() - 10, GameGlobal::GetHeight() - 15));
	apple2->SetScale(D3DXVECTOR2(0.15, 0.1));
	apple2->SetSourceRect(rect);
	apple2->SetWidth(rect.right - rect.left);
	apple2->SetHeight(rect.bottom - rect.top);


	rect.left = 370; rect.top = 45; rect.right = rect.left + 14; rect.bottom = rect.top + 14;
	apple = new Sprite("Resources/Aladdin.png", RECT(), 0, 0, D3DCOLOR_XRGB(255, 0, 255), D3DXVECTOR2(0.5, 0.5), GameGlobal::mAladdintexture);
	apple->SetPosition(D3DXVECTOR2(GameGlobal::GetWidth() - 50, GameGlobal::GetHeight() - 15));
	apple->SetScale(D3DXVECTOR2(1.5, 1.5));
	apple->SetSourceRect(rect);
	apple->SetWidth(rect.right - rect.left);
	apple->SetHeight(rect.bottom - rect.top);

	/*rect.left = 1037; rect.top = 75; rect.right = rect.left + 50; rect.bottom = rect.top + 26;
	GoldenLamp = new Sprite("Resources/lamp.png", RECT(), 0, 0, D3DCOLOR_XRGB(255, 0, 255), D3DXVECTOR2(0.5, 0.5));
	GoldenLamp->SetPosition(D3DXVECTOR2(30, 20));
	GoldenLamp->SetScale(D3DXVECTOR2(1, 1));
	GoldenLamp->SetSourceRect(rect);
	GoldenLamp->SetWidth(rect.right - rect.left);
	GoldenLamp->SetHeight(rect.bottom - rect.top);*/


	rect.left = 1026; rect.top = 0; rect.right = rect.left + 114; rect.bottom = rect.top + 36;
	hpBar = new Sprite("Resources/lamp.png", rect, 0, 0, D3DCOLOR_XRGB(255, 255, 255),D3DXVECTOR2(0,0.5));
	hpBar->SetPosition(D3DXVECTOR2(10, 20));
	hpBar->SetScale(D3DXVECTOR2(1, 1));
	//hpBar->SetSourceRect(rect);
	hpBar->SetWidth(rect.right - rect.left);
	hpBar->SetHeight(rect.bottom - rect.top);

	myFont = NULL;

	HRESULT rs = D3DXCreateFont(GameGlobal::GetCurrentDevice(), 30, 10, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, (LPCWSTR) "Arial", &myFont);
	if (!SUCCEEDED(rs))
	{
		return;
	}



}


UI::~UI()
{
}

void UI::Update()
{
	
	mHP = mplayer->HPCount;

	mAppleCount = mplayer->AppleCount;

	int applenum1 = mAppleCount / 10;
	int applenum2 = mAppleCount % 10;

	hpBar->SetSourceRect(LoadHP(mHP));
	apple1->SetSourceRect(LoadNumber(applenum1));
	apple2->SetSourceRect(LoadNumber(applenum2));
	EndTime = GetTickCount();
	CurTime += (float) (EndTime - startTime) / 1000;
	
	message = to_string(CurTime);
	message.replace(message.length()-3,message.length()," s");
	startTime = GetTickCount();
	
}
void UI::Draw()
{
	
	apple->Draw();
	apple1->Draw();
	apple2->Draw();
	//GoldenLamp->Draw();
	hpBar->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), D3DXVECTOR2(), 0, D3DXVECTOR2(0, 0.5));
	LiveCount->Draw();

	myRect.left = 0;
	myRect.top = GameGlobal::GetHeight() - 30;
	myRect.bottom = myRect.top + 200;
	myRect.right = myRect.left + 200;
	if (myFont)
	{
		myFont->DrawTextA(hpBar->GetSpriteHandle(), message.c_str(), -1, &myRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	}
	message = "x " + to_string(mplayer->PlayerLiveCount);


	myRect.left = 30;
	myRect.right = 100;
	myRect.top = GameGlobal::GetHeight() - 50;
	myRect.bottom = GameGlobal::GetHeight();
	if (myFont)
	{
		myFont->DrawTextA(hpBar->GetSpriteHandle(),message.c_str(), -1, &myRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	}
}