#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/Camera.h"
#include "../Entity.h"
#include "PlayerData.h"
#include "PlayerState.h"
#include "PlayerRunningState.h"
#include "PlayerThrowAppleState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerFiredState.h"

#include "PLayerThrowClimb.h"
#include "PlayerBung.h"
#include "PlayerClimHori.h"
#include "PLayerRevive.h"
class Player : public Entity
{
public:
    Player();
    ~Player();

    enum MoveDirection
    {
        MoveToLeft, //chay tu phai sang trai
        MoveToRight, //chay tu trai sang phai
        None //dung im
    };

    void Update(float dt);

    void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

    void SetState(PlayerState *newState);

    MoveDirection getMoveDirection();

    RECT GetBound();     

    PlayerState::StateName Player::getState();

    //xu ly input
    //gom 256 key tuong ung true = dang dc nhan, false = khong dc nhan
    void HandleKeyboard(std::map<int, bool> keys);

    void OnKeyPressed(int key);

    void OnKeyUp(int key);

    //true thi se lat nguoc anh theo truc y
    void SetReverse(bool flag); 
	bool GetReverse();
	PlayerData*		GetCurrentPlayerData();
	void SetCamera(Camera *camera);
	Animation* GetCurrentAnimation();
	bool GetallowThrow();
	void SetallowThrow(bool flag);


	void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);

	void OnNoCollisionWithBottom();
	bool allowMoveLeft;
	bool allowMoveRight;
	Apple* a;
	vector<Apple*> listApple;
	int AppleCount = 10;
	int HPCount = 900;

	bool allowJump, allowThrow, mCurrentReverse,isAttacked=false;
	int Count_temp = 0;
	PlayerData *mPlayerData;
	int PlayerLiveCount = 3;
	PlayerState::StateName mCurrentState;
	Animation *mAnimationThrowClimb;
	D3DXVECTOR2 CheckPoint;
protected:

	Camera      *mCamera;

    
	Animation   *mCurrentAnimation,
		*mAnimationStanding,
		*mAnimationRunning,
		*mAnimationJumping,
		*mAnimationThrowing,
		*mAnimationClimbing,
		*mAnimationSiting,
		*mAnimationFighting,
		*mAnimationSitFight,
		*mAnimationJumpThrow,
		*mAnimationSitThrow,
		*mAnimationFired,
		
		*mAnimationBung,
		*mAnimationClimbHori,
		*mAnimationRevive;
	
	
    void changeAnimation(PlayerState::StateName state);
	
  
    //chi cho phep jump khi nhan nhim space, muon nhay lai phai tha phim space roi nhan lai
   
};

