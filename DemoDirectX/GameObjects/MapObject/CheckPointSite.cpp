#include "CheckPointSite.h"






CheckPointSite::~CheckPointSite()
{
}








vector<RECT> CheckPointSite::LoadRect()
{
	vector<RECT> listSourceRect;
	RECT rect;
	rect.left = 19; rect.top = 424; rect.right = rect.left + 19; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
	rect.left = 49; rect.top = 428; rect.right = rect.left + 23; rect.bottom = rect.top + 28; listSourceRect.push_back(rect);
	rect.left = 78; rect.top = 437; rect.right = rect.left + 34; rect.bottom = rect.top + 19; listSourceRect.push_back(rect);
	rect.left = 119; rect.top = 425; rect.right = rect.left + 19; rect.bottom = rect.top + 33; listSourceRect.push_back(rect);
	rect.left = 145; rect.top = 425; rect.right = rect.left + 22; rect.bottom = rect.top + 33; listSourceRect.push_back(rect);
	rect.left = 174; rect.top = 426; rect.right = rect.left + 25; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
	rect.left = 207; rect.top = 426; rect.right = rect.left + 23; rect.bottom = rect.top + 33; listSourceRect.push_back(rect);
	rect.left = 239; rect.top = 427; rect.right = rect.left + 20; rect.bottom = rect.top + 33; listSourceRect.push_back(rect);
	rect.left = 270; rect.top = 428; rect.right = rect.left + 23; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
	rect.left = 302; rect.top = 429; rect.right = rect.left + 22; rect.bottom = rect.top + 32; listSourceRect.push_back(rect);
	return listSourceRect;
}


RECT CheckPointSite::GetBound()
{
	RECT rect;
	rect.left = this->GetPosition().x;
	rect.right = rect.left + represent->GetWidth();
	rect.top = this->GetPosition().y - represent->GetHeight() / 2;
	rect.bottom = rect.top + represent->GetHeight();
	return rect;
}

CheckPointSite::CheckPointSite()
{
	this->filePath = "Resources/item.png";
	this->source = this->LoadRect();
	this->totalFrame = this->source.size();

	this->timePerFrame = (float)1 /0.5;
	this->center = D3DXVECTOR2(0, 0.5);
	this->colorKey = D3DCOLOR_XRGB(248, 0, 248);
	represent = new Sprite(filePath, RECT(), 0, 0, colorKey, center,GameGlobal::mItemtexture);

	RECT rect = source.at(0);

	represent->SetSourceRect(rect);
	represent->SetWidth(rect.right - rect.left);
	represent->SetHeight(rect.bottom - rect.top);
	Tag = Entity::CheckPoint;
	mCurrentAnimation = new Animation(filePath, totalFrame, source, timePerFrame, center, colorKey,Entity::CheckPoint);
}

void CheckPointSite::Update()
{
	if (Actived)
	{
		if(mCurrentAnimation->GetCurrentFrame()==0)
			Sound::getInstance()->play("Continue Point", false,1);
		if (mCurrentAnimation->GetCurrentFrame() == totalFrame - 1)
		{
			RECT rect = source.at(totalFrame - 1);
			represent->SetSourceRect(rect);

			Actived = false;
			return;
		}
		else SimpleObject::Update();
	}
}
void CheckPointSite::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	if (impactor->Tag == PlayerOne)
	{
		Actived = true;
		
	}

}