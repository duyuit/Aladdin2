#pragma once
#include "AppleState.h"
class AppleFlyState:public AppleState
{
public:
	AppleFlyState(D3DXVECTOR3 pos,bool Reverse);
	~AppleFlyState();
	void Update(float dt);
	bool Reverse;
};

