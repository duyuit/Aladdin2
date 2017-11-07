#include "SimpleObject.h"

SimpleObject::SimpleObject()
{

}
void SimpleObject::LoadAnimation()
{
	FlagAnimate = true;
}
void SimpleObject::Update()
{

	if (FlagAnimate)
	{
		if (mCurrentAnimation->GetCurrentFrame() == mCurrentAnimation->mSourRect.size() - 1)
		{
			mCurrentAnimation->Reset();
			FlagAnimate = false; 
			return;
		}
		mCurrentAnimation->Update(60);
	}
	
}
void SimpleObject::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform)
{
	
	if (FlagAnimate)
	{
	
		mCurrentAnimation->SetPosition(this->GetPosition());

		mCurrentAnimation->Draw(position,sourceRect, scale,transform);
		
	}
	else
	{
		if (represent != nullptr)
			represent->Draw(position, sourceRect, scale, transform);
	}
}
void SimpleObject::SetPos(float x, float y)
{
	SetPosition(x, y);
	represent->SetPosition(x, y);
}
void SimpleObject::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	//if (Actived) return;
	
}

vector<RECT> SimpleObject::LoadRect()
{
	return vector<RECT>();
}