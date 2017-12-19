#include "AppleObject.h"




vector<RECT> AppleObject::LoadRect()
{
	vector<RECT> listSourceRect;
	RECT rect;
	rect.left = 758; rect.top = 31; rect.right = rect.left +15; rect.bottom = rect.top + 10; listSourceRect.push_back(rect);
	rect.left = 756; rect.top =32; rect.right = rect.left + 24; rect.bottom = rect.top + 18; listSourceRect.push_back(rect);
	rect.left = 731; rect.top = 25; rect.right = rect.left + 22; rect.bottom = rect.top + 23; listSourceRect.push_back(rect);
	rect.left = 794; rect.top = 23; rect.right = rect.left + 32; rect.bottom = rect.top + 21; listSourceRect.push_back(rect);
	
	
	return listSourceRect;
}

void AppleObject::Update()
{
	
}
void AppleObject::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform)
{
	if (Actived) return;
	SimpleObject::Draw(position, sourceRect, scale, transform);

}
AppleObject::AppleObject(const char* FilePath,
	float TimePerFrame,
	D3DXVECTOR2 Center)
{
	
	
	this->filePath = FilePath;
	//this->source = this->LoadRect();


	this->totalFrame = this->source.size();

	this->timePerFrame = TimePerFrame;
	this->center = Center;
	this->colorKey = D3DCOLOR_XRGB(255, 0, 255);
	represent = new Sprite(filePath, RECT(), 0, 0, colorKey, center);

	RECT rect;
	rect.left = 370; rect.top = 45; rect.right = rect.left + 14; rect.bottom = rect.top + 14;
	represent->SetSourceRect(rect);
	represent->SetWidth(rect.right - rect.left);
	represent->SetHeight(rect.bottom - rect.top);
}


AppleObject::~AppleObject()
{
}
AppleObject::AppleObject(Sprite *sprite)
{
	represent = sprite;

}
void AppleObject::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	
	Sound::getInstance()->play("Apple Collect", false, 1);
	SetPos(0, 0);
}