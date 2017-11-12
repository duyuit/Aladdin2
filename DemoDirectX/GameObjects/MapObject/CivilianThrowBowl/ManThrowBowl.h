#pragma once
#include "../../../GameComponents/Animation.h"
#include "../../Entity.h"
#include "../../Apple/Apple.h"
class ManThrowBowl:public Entity
{
public:
	ManThrowBowl(vector<D3DXVECTOR2> listpos);
	~ManThrowBowl();
	Animation* ThrowAnimate;
	Animation* mCurrentAnimate;
	bool AllowThrow = true;
	void Update(Entity* player);
	vector<RECT> LoadRect();
	void CheckSite(Entity* player);
	void Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey);

	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);
	vector<D3DXVECTOR2> mListPosition;
	Apple* mApple;
	Apple* mCurrentApple;
};

