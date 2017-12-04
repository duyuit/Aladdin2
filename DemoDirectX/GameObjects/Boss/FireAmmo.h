#pragma once
#include "../Entity.h"
#include "../../GameComponents/Animation.h"
class FireAmmo:public Entity
{
public:
	FireAmmo(D3DXVECTOR2 startPos);
	~FireAmmo();
	Animation *mAni;
	D3DXVECTOR2 startPos;
	bool isActive = false;
	bool isLeftorRight = false; //False is left,true is right
	void Update();
	void Draw(D3DXVECTOR2 trans);
	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);
	vector<RECT> LoadRECT();
};

