#pragma once
#include "../Entity.h"
#include "../Player/Player.h"
#include "../Boss/BossState.h"
#include "BossFightingSnake.h"
#include "BossMagnetState.h"
#include <cstdlib>
#include <ctime>
#include "BossStandHuman.h"
#include "BossStandSnake.h"
#include "BossFightingSnake.h"
#include "FireAmmo.h"
class Boss:public Entity
{
public:
	Boss(Player *player, D3DXVECTOR3 pos);
	~Boss();

	void Update();

	void Draw(D3DXVECTOR2 transform = D3DXVECTOR2());

	void SetState(BossState *newState);
	void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);
	BossState::StateName mCurrentState;
	Animation  *mCurrentAnimation;
	Player* mPlayer;
	BossData *mData;
	Animation* GetCurrentAnimation();
	vector<D3DXVECTOR3> starPos;
	RECT GetBound();
	int HPCount =30;
	int currentAmmo = 0;
	vector<FireAmmo*> listAmmo;
	bool Reverse = false;
private:
	vector<RECT> LoadRECT(BossState::StateName state);
	vector<RECT> LoadRectFire();
	Sprite *star1, *star2, *star3;
	Sprite *hp_green, *hp_yellow, *hp_red,*hp_white;
	Animation
		*mAnimationStandHuman,
		*mAnimationFightingSnake,
		*mAnimationAttackedSnake,
		*mAnimationStandSnake,
		*mAnimationMagnet,
		*mAnimationFire1,
		*mAnimationFire2,
		*mAnimationFire3;
	Sprite *mSprite;
	void DrawStar(D3DXVECTOR2 transform);
	Sprite *arg;
	bool BossAttacked = false;
	float lastTimeBossAttacked = 0;
	
	void changeAnimation(BossState::StateName state);


};



