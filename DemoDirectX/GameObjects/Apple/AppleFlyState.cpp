#include "AppleFlyState.h"



AppleFlyState::AppleFlyState(D3DXVECTOR3 pos,bool reverse, Entity::EntityTypes type)
{
	this->pos = pos;
	if (type == Entity::AppleThrow || type == Entity::KnifeEnemy3)
	{
		acceX = 3.2f;
		acceY = 0.025f;
	}
	else if(type=Entity::Bowl)
	{
		acceX = 0.0f;
		acceY = 0.4f;
	}
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

AppleState::StateName AppleFlyState::GetNameState()
{
	return AppleState::Flying;
}