#pragma once
#include "PlayerData.h"
#include "../Entity.h"
#include <map>

class PlayerState
{
public:
    enum StateName
    {
        Standing,
        Running,
        Falling,
		Throwing,
        Jumping,
		Climbing,
		Fighting,
		Sit,
		SitFight,
		RunFight,
		JumpThrow,
		SitThrow,
        Die,
		Fired
    };

    ~PlayerState();

    virtual void Update(float dt);

    virtual void HandleKeyboard(std::map<int, bool> keys);

	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

    //ham thuan ao bat buoc phai ke thua
    virtual StateName GetState() = 0;
	float GetAcceX();
	float GetAcceY();

protected:
    PlayerState(PlayerData *playerData);
    PlayerState();
	float acceleratorY;
	float acceleratorX;

    PlayerData *mPlayerData;
};

