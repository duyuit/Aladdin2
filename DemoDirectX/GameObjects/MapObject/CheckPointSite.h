#pragma once

#include "AppleObject.h"
class CheckPointSite : public SimpleObject
{
public:
	CheckPointSite();
	~CheckPointSite();
	RECT GetBound();
	vector<RECT> LoadRect();
	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);
	void Update();
};



