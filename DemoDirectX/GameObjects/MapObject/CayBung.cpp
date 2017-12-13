#include "CayBung.h"





CayBung::~CayBung()
{
}





vector<RECT> CayBung::LoadRect()
{
	vector<RECT> listSourceRect;
	RECT rect;
	rect.left =0; rect.top = 0; rect.right = rect.left + 46; rect.bottom =36; listSourceRect.push_back(rect); //1
	rect.left =66; rect.top = 0; rect.right = rect.left + 45; rect.bottom = 36; listSourceRect.push_back(rect);//2
	rect.left = 133; rect.top = 0; rect.right = rect.left + 38; rect.bottom = 36; listSourceRect.push_back(rect); //3
	rect.left = 0; rect.top = 0; rect.right = rect.left + 46; rect.bottom = 36; listSourceRect.push_back(rect); //1
	rect.left = 66; rect.top = 0; rect.right = rect.left + 45; rect.bottom = 36; listSourceRect.push_back(rect); //2

	rect.left = 0; rect.top = 0; rect.right = rect.left + 46; rect.bottom = 36; listSourceRect.push_back(rect);//1
	rect.left = 133; rect.top = 0; rect.right = rect.left + 38; rect.bottom = 36; listSourceRect.push_back(rect); //3
	rect.left = 0; rect.top = 0; rect.right = rect.left + 46; rect.bottom = 36; listSourceRect.push_back(rect);//1
	return listSourceRect;
}


RECT CayBung::GetBound()
{
	RECT rect;
	rect.left = this->GetPosition().x;
	rect.right =rect.left+represent->GetWidth();
	rect.top = this->GetPosition().y - represent->GetHeight() / 2;
	rect.bottom = rect.top + represent->GetHeight();
	return rect;
}

CayBung::CayBung()
{
	this->filePath = "Resources/cay.png";
	this->source = this->LoadRect();
	this->totalFrame = this->source.size();

	this->timePerFrame = (float)1 / 20;
	this->center = D3DXVECTOR2(0, 0.5);
	this->colorKey = D3DCOLOR_XRGB(255, 0, 255);
	represent = new Sprite(filePath, RECT(), 0, 0, colorKey, center,GameGlobal::mCayBungtexture);

	RECT rect = source.at(0);

	represent->SetSourceRect(rect);
	represent->SetWidth(rect.right - rect.left);
	represent->SetHeight(rect.bottom - rect.top);
	Tag = Entity::Bung;
	mCurrentAnimation = new Animation(filePath, totalFrame, source, timePerFrame, center, colorKey,Entity::Bung);
}

void CayBung::Update()
{
	if (Actived)
	{
		if (mCurrentAnimation->GetCurrentFrame() == totalFrame - 1)
		{
			Actived = false;
			mCurrentAnimation->Reset();
		}
		else SimpleObject::Update();
	}
}
void CayBung::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	Actived = true;

}