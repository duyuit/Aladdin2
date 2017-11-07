#pragma once
//pre define
#include "../Apple/Apple.h"
class PlayerState;
class Player;

class PlayerData
{
public:
    PlayerData();
    ~PlayerData();

    Player      *player=nullptr;
    PlayerState *state= nullptr;
	void Update(float dt);
protected:
    
};

