#include "ManThrowBowl.h"

vector<RECT> ManThrowBowl::LoadRect()
{
	vector<RECT> listSourceRect;
	RECT rect;
	rect.left = 11; rect.top = 35; rect.right = rect.left + 11; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);
	rect.left = 42; rect.top = 32; rect.right = rect.left + 17; rect.bottom = rect.top + 24; listSourceRect.push_back(rect);
	rect.left = 73; rect.top = 29; rect.right = rect.left + 22; rect.bottom = rect.top + 31; listSourceRect.push_back(rect);
	rect.left = 107; rect.top = 29; rect.right = rect.left + 29; rect.bottom = rect.top + 30; listSourceRect.push_back(rect);
	rect.left = 145; rect.top = 26; rect.right = rect.left + 41; rect.bottom = rect.top + 35; listSourceRect.push_back(rect);
	rect.left = 194; rect.top = 26; rect.right = rect.left + 41; rect.bottom = rect.top + 40; listSourceRect.push_back(rect);
	rect.left = 251; rect.top = 27; rect.right = rect.left + 43; rect.bottom = rect.top + 40; listSourceRect.push_back(rect);
	rect.left = 306; rect.top = 31; rect.right = rect.left + 25; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);
	rect.left = 345; rect.top = 36; rect.right = rect.left + 18; rect.bottom = rect.top + 12; listSourceRect.push_back(rect);
	rect.left = 382; rect.top = 37; rect.right = rect.left + 8; rect.bottom = rect.top + 5; listSourceRect.push_back(rect);
	return listSourceRect;
}

ManThrowBowl::ManThrowBowl(vector<D3DXVECTOR2> listpos)
{
	mListPosition = listpos;
	SetPosition(listpos.at(0));
	ThrowAnimate = new Animation("Resources/civilian.png", 10, LoadRect(),(float)1/0.3,D3DXVECTOR2(0,0.5),D3DCOLOR_XRGB(120, 193, 152));
	ThrowAnimate->SetScale(D3DXVECTOR2(1,1));

	mApple = new Apple(Entity::Bowl);
	
	Tag = Entity::None;

	//mCurrentAnimate = ThrowAnimate;
	
	

	mCurrentApple = mApple;
	mCurrentApple->SetPosition(GetPosition());



}


ManThrowBowl::~ManThrowBowl()
{
}
void ManThrowBowl::Update(Entity* player)
{
	CheckSite(player);
	if (AllowThrow)
	{

		//if(mCurrentApple->GetCurrentState() == AppleState::NONE ) //Check Bowl phai dang o trang thai None, Flying or Breaking thi ko nem
			mCurrentAnimate = ThrowAnimate;
		/*else
		{
				mCurrentAnimate = nullptr;
		}*/



		if (mCurrentAnimate != nullptr) //Khac null moi update
		{
			mCurrentAnimate->SetPosition(GetPosition());
			mCurrentAnimate->Update(1);
			if (mCurrentAnimate->GetCurrentFrame() == 9) //Nem xong thi thoi ko nem nua,cho khi nao bowl None moi nem tiep
				mCurrentAnimate = nullptr;

		}

		
		if (mCurrentApple->GetCurrentState() == AppleState::NONE) //NONE FIRST, None thi flying
		{
			if (mCurrentAnimate != nullptr && mCurrentAnimate->GetCurrentFrame() == 7)
			{
				mCurrentApple->SetPosition(GetPosition().x + 25, GetPosition().y + 10);
				mCurrentApple->SetState(AppleState::Flying);
			}
		}
		
		

	}
	else
	{
		if (mCurrentAnimate != nullptr )
		{
			if(mCurrentAnimate->GetCurrentFrame()<9)
			mCurrentAnimate->Update(1);
			else
			mCurrentAnimate = nullptr;
			
		}
		
		
	}
	mCurrentApple->Update(1);
}

void ManThrowBowl::CheckSite(Entity* player)
{
	for (int i = 0; i < mListPosition.size(); i++)
	{
		if (player->GetPosition().y < mListPosition.at(i).y) continue;
		int deltay =player->GetPosition().y - mListPosition.at(i).y;
		int deltax = abs(player->GetPosition().x - mListPosition.at(i).x);
		if (deltax<=100  && deltay <=150)
		{
			SetPosition(mListPosition.at(i));
			break;
		}
	}
	if (abs(GetPosition().x - player->GetPosition().x) <= 100 && player->GetPosition().y>GetPosition().y)
		AllowThrow = true;
	else AllowThrow = false;
	

}
void ManThrowBowl::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{


	if(mCurrentAnimate!=nullptr)
		mCurrentAnimate->Draw(GetPosition(),sourceRect,scale,transform,angle,rotationCenter,colorKey);
	if(mCurrentApple->GetCurrentState() != AppleState::NONE)
		mCurrentApple->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);

}
void ManThrowBowl::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
//	if(impactor->Tag==Entity::Land)
	mCurrentApple->SetState(AppleState::Breaking);

}