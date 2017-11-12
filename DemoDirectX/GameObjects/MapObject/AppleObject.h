#pragma once
#include "SimpleObject.h"
class AppleObject:public SimpleObject
{
public:
	AppleObject(const char* filePath,
		float timePerFrame = 1 / 20,
		D3DXVECTOR2 center = D3DXVECTOR2(0.5, 0.5));
	AppleObject(Sprite *sprite);
	
	void Update();
	void Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform);
	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);

	static vector<RECT> LoadRect();
	
	 

	~AppleObject();
};



