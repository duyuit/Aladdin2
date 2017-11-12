#pragma once
#include "AppleState.h"

class AppleFlyState:public AppleState
{
public:
	AppleFlyState(D3DXVECTOR3 pos,bool Reverse, Entity::EntityTypes type);
	~AppleFlyState();
	void Update(float dt);
	AppleState::StateName GetNameState();
	bool Reverse;
};

