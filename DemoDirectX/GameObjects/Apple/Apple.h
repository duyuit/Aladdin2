#pragma once
#include "../../GameComponents/Animation.h"

#include "AppleFlyState.h"
#include "AppleBreakState.h"
class Apple: public Entity
{
public:
	Apple(EntityTypes type);
	~Apple();
	void Update(float dt);
	void SetState(AppleState::StateName newState);
	
	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	RECT GetBound();
	void changeAnim(AppleState::StateName state);
	void OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side);
	Animation *mCurrentAnim;
	AppleState* curState;


	vector<RECT> LoadRECT(AppleState::StateName state);
	bool mReverse;

	AppleState::StateName GetCurrentState();
private:
	Animation *FlyingAnim,*BreakingAnim;
	

};

