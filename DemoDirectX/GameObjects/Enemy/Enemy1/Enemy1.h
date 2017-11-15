#pragma once
#include "../../Entity.h"
#include "../../Player/Player.h"
#include "Enemy1State.h"
#include "Enemy1Data.h"
#include "../../../GameComponents/Animation.h"
#include "Enemy1Running.h"
#include "Enemy1Attacked.h"
#include "Enemy1Fighting.h"



class Enemy1:public Entity
{
public:

	Enemy1(D3DXVECTOR2 Location ,Player *player);
	void Update();

	void Draw( D3DXVECTOR2 transform = D3DXVECTOR2());
	
	void SetState(Enemy1State *newState);



	RECT GetBound();

	Enemy1State::StateName getState();

	void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);
	Enemy1Data *mData;
	bool CheckRunning = false;
	bool CheckFire = false;
	bool Reverse = false;

	Animation* GetCurrentAnimation();
	void CheckAction();
	~Enemy1();
private:
	vector<RECT> LoadRECT(Enemy1State::StateName state);
	
	Player* mPlayer;
	Animation   *mCurrentAnimation,
		*mAnimationRunning,
		*mAnimationFighting,
		*mAnimationAttacked;
	Sprite *mSprite;
	D3DXVECTOR2 startLocation;

	void changeAnimation(Enemy1State::StateName state);

	Enemy1State::StateName mCurrentState;

};

