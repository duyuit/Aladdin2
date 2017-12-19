#pragma once
#include "AppleObject.h"
class Flame:public SimpleObject
{
public:
	Flame();
	~Flame();

	RECT GetBound();
	vector<RECT> LoadRect();
	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);
};

