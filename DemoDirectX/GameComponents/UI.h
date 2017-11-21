
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
};

