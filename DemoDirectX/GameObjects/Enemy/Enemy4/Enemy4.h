#pragma once
#include "../../../GameComponents/Animation.h"
#include "../../Entity.h"
#include "../../Apple/Apple.h"
#include "../../Player/Player.h"

class Enemy4 :public Entity
{
public:
	Enemy4(vector<D3DXVECTOR2> listpos);
	Animation* ThrowAnimate,*DieAnimate;
	Animation* mCurrentAnimate;
	~Enemy4();
	bool mReverse;
	bool AllowThrow = true;
	void Update(Entity* player);
	vector<RECT> LoadRect(bool flag);
	void CheckSite(Entity* player);
	void Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey);
	int HP = 2;
	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);
	vector<D3DXVECTOR2> mListPosition;
	Apple* mKnife;
	Apple* mCurrentKnife;
	Player* mPlayer;

	RECT GetBound();

	vector<int> positionted;
	int CurrentPosIndex = -1;
	void Reset();
};




