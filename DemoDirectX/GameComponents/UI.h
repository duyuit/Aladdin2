
#pragma once

#include "Sprite.h"
class UI
{
public:
	UI();
	void Update(int hp,int apple);
	void Draw();
	int mAppleCount = 0;
	int mHP = 0;
	Sprite* apple1,*apple2,*apple;

	Sprite* hp;
	~UI();
};

