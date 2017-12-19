#include "Flame.h"


vector<RECT> Flame::LoadRect()
{
	vector<RECT> listSourceRect;
	RECT rect;
	rect.left = 14; rect.top = 193; rect.right = rect.left + 24; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
	rect.left = 46; rect.top = 187; rect.right = rect.left + 21; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
	rect.left = 78; rect.top = 193; rect.right = rect.left + 24; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
	rect.left = 110; rect.top = 190; rect.right = rect.left + 27; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
	rect.left = 150; rect.top = 194; rect.right = rect.left + 35; rect.bottom = rect.top + 45; listSourceRect.push_back(rect);

	rect.left = 150; rect.top = 194; rect.right = rect.left + 35; rect.bottom = rect.top + 45; listSourceRect.push_back(rect);
	rect.left = 110; rect.top = 190; rect.right = rect.left + 27; rect.bottom = rect.top + 49; listSourceRect.push_back(rect);
	rect.left = 78; rect.top = 193; rect.right = rect.left + 24; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
	rect.left = 46; rect.top = 187; rect.right = rect.left + 21; rect.bottom = rect.top + 52; listSourceRect.push_back(rect);
	rect.left = 14; rect.top = 193; rect.right = rect.left + 24; rect.bottom = rect.top + 46; listSourceRect.push_back(rect);
	return listSourceRect;
}
Flame::Flame()
{
	represent = nullptr;
	mCurrentAnimation=new Animation("Resources/jafar.png",10, LoadRect(),(float)1/1,D3DXVECTOR2(0.5,1), D3DCOLOR_XRGB(186, 254, 202), Entity::jafar);
}


Flame::~Flame()
{
}
void Flame::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	if (impactor->Tag == Entity::PlayerOne)
	{
		if (abs(impactor->GetPosition().x - this->GetPosition().x) <= 25)
			Actived = true;
	}
}

RECT Flame::GetBound()
{
	RECT rect;
	rect.top = GetPosition().y - 5;
	rect.bottom = GetPosition().y;
	rect.left = GetPosition().x-14;
	rect.right = GetPosition().x+14;
	return rect;
}