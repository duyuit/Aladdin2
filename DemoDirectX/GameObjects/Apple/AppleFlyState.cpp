#include "AppleFlyState.h"



AppleFlyState::AppleFlyState(D3DXVECTOR3 pos,bool reverse)
{
	this->pos = pos;
	acceX =6.0f;
	acceY = 0.05f;
	Reverse = reverse;
}
void AppleFlyState::Update(float dt)
{


	vY += acceY;
	pos.y += vY;
	if(!Reverse)
	pos.x += acceX;
	else pos.x -= acceX;

}

AppleFlyState::~AppleFlyState()
{
}
