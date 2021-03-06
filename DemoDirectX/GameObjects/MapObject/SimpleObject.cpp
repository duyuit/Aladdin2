#include "SimpleObject.h"

SimpleObject::SimpleObject()
{

}
SimpleObject::~SimpleObject()
{

}
void SimpleObject::Update()
{

	if (Actived)
	{

		if (mCurrentAnimation->GetCurrentFrame() == mCurrentAnimation->GetTotalFrame() - 1)
		{
			mCurrentAnimation->Reset();
			Actived = false;
		}else
			mCurrentAnimation->Update(60);
	}
	//else
	//	mCurrentAnimation->Reset();
	
}
void SimpleObject::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform)
{
	
	if (Actived)
	{
		mCurrentAnimation->Draw(GetPosition(),sourceRect, scale,transform);	
	}
	else
	{
		
		if (represent != nullptr)
			represent->Draw(GetPosition(), sourceRect, scale, transform);
	}
}
void SimpleObject::SetPos(float x, float y)
{
	SetPosition(x, y);
	if(represent != nullptr)
	represent->SetPosition(x, y);

	if(mCurrentAnimation!=nullptr)
	mCurrentAnimation->SetPosition(this->GetPosition());
}
void SimpleObject::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{

	
}

vector<RECT> SimpleObject::LoadRect()
{
	return vector<RECT>();
}