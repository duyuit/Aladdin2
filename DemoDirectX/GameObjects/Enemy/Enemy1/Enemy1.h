#pragma once
#include "../../Entity.h"
#include "../../Player/Player.h"
#include "Enemy1State.h"
#include "Enemy1Data.h"
#include "../../../GameComponents/Animation.h"
#include "Enemy1Running.h"
#include "Enemy1Attacked.h"
#include "Enemy1Fighting.h"
#include "Enemy1Die.h"


class Enemy1:public Entity
{
public:

	Enemy1(Player *player, vector<D3DXVECTOR2> list);
	void Update();

	void Draw( D3DXVECTOR2 transform = D3DXVECTOR2());
	
	void SetState(Enemy1State *newState);


	vector<D3DXVECTOR2> mListPosition;
	vector<int> positionted;
	int CurrentPosIndex = -1;
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
	int Heal = 3;

	Enemy1State::StateName mCurrentState;
	Animation  *mCurrentAnimation;
	void Reset();
private:
	vector<RECT> LoadRECT(Enemy1State::StateName state);
	
	Player* mPlayer;
	Animation  
		*mAnimationRunning,
		*mAnimationFighting,
		*mAnimationAttacked,
		*mAnimationDied;
	Sprite *mSprite;


	void changeAnimation(Enemy1State::StateName state);


};

