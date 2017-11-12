#include "AppleBreakState.h"



AppleBreakState::AppleBreakState(D3DXVECTOR3 pos)
{
	this->pos = pos;
}
void AppleBreakState::Update(float dt)
{


}

AppleBreakState::~AppleBreakState()
{
}

AppleState::StateName AppleBreakState::GetNameState()
{
	return AppleState::Breaking;
}