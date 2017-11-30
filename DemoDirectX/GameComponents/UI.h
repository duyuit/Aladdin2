
#pragma once

#include "Sprite.h"
#include "../GameObjects/Player/Player.h"
class UI
{
public:
	UI(Player* player);
	void Update();
	void Draw();
	int mHP, mAppleCount;
	Player* mplayer;
	Sprite* apple1,*apple2,*apple;
	Sprite* GoldenLamp;
	Sprite* hpBar;

	~UI();

	ID3DXFont				*myFont;
	RECT myRect;
	LPD3DXSPRITE mSpriteHandler = GameGlobal::GetCurrentSpriteHandler();
	int startTime;
	int EndTime;
	float CurTime=0;
	std::string message;

};

