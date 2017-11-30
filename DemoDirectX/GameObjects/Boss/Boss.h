#pragma once
#include "../Entity.h"
#include "../Player/Player.h"
#include "../Boss/BossState.h"
#include "BossFightingSnake.h"
#include "BossMagnetState.h"
#include <cstdlib>
#include <ctime>
#include "BossStandHuman.h"
class Boss:public Entity
{
public:
	Boss(Player *player);
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
private:
	vector<RECT> LoadRECT(BossState::StateName state);
	Sprite *star1, *star2, *star3;

	Animation
		*mAnimationStandHuman,
		*mAnimationFightingSnake,
		*mAnimationAttackedSnake,
		*mAnimationStandSnake,
		*mAnimationMagnet;
	Sprite *mSprite;
	void DrawStar(D3DXVECTOR2 transform);

	
	void changeAnimation(BossState::StateName state);


};



