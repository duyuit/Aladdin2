#pragma once
#include "PlayerState.h"
#include "Player.h"
class PlayerFiredState : public PlayerState
{
public:
	PlayerFiredState(PlayerData *playerData);
	~PlayerFiredState();
	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

