#pragma once
#include "AppleObject.h"
class CayBung: public SimpleObject
{
public:
	CayBung();
	~CayBung();

	RECT GetBound();
	vector<RECT> LoadRect();
	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);
	void Update();
};



