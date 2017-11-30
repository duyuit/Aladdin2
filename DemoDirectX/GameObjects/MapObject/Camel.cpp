#include "Camel.h"

vector<RECT> Camel::LoadRect()
{
	vector<RECT> listSourceRect;
	RECT rect;
	rect.left = 4; rect.top = 21; rect.right = rect.left + 63; rect.bottom = rect.top + 43; listSourceRect.push_back(rect);
	rect.left = 73; rect.top = 11; rect.right = rect.left + 81; rect.bottom = rect.top + 53; listSourceRect.push_back(rect);
	rect.left = 163; rect.top = 9; rect.right = rect.left + 95; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
	rect.left = 268; rect.top = 9; rect.right = rect.left + 112; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
	rect.left = 396; rect.top = 10; rect.right = rect.left + 147; rect.bottom = rect.top + 54; listSourceRect.push_back(rect);
	rect.left = 556; rect.top = 10; rect.right = rect.left + 134; rect.bottom = rect.top + 54; listSourceRect.push_back(rect);
	rect.left = 707; rect.top = 19; rect.right = rect.left + 169; rect.bottom = rect.top + 45; listSourceRect.push_back(rect);
	rect.left = 268; rect.top = 9; rect.right = rect.left + 112; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
	rect.left = 163; rect.top = 9; rect.right = rect.left + 95; rect.bottom = rect.top + 55; listSourceRect.push_back(rect);
	rect.left = 73; rect.top = 11; rect.right = rect.left + 81; rect.bottom = rect.top + 53; listSourceRect.push_back(rect);
	rect.left = 4; rect.top = 21; rect.right = rect.left + 63; rect.bottom = rect.top + 43; listSourceRect.push_back(rect);
	return listSourceRect;
}

Camel::Camel(const char* FilePath,
	float TimePerFrame ,
	D3DXVECTOR2 Center)
{


	this->filePath = FilePath;
	this->source = this->LoadRect();
	this->totalFrame = this->source.size();
	
	this->timePerFrame = TimePerFrame;
	this->center = Center;
	this->colorKey = D3DCOLOR_XRGB(248, 0, 248);
	represent = new Sprite(filePath, RECT(), 0, 0, D3DCOLOR_XRGB(248, 0, 248), center);

	RECT rect = source.at(0);

	represent->SetSourceRect(rect);
	represent->SetWidth(rect.right - rect.left);
	represent->SetHeight(rect.bottom - rect.top);

	mCurrentAnimation = new Animation(filePath, totalFrame, source, timePerFrame, center, D3DCOLOR_XRGB(248, 0, 248));
}

RECT Camel::GetBound()
{
	RECT re;
	re.left = posX - represent->GetWidth() / 2;
	re.right = re.left + represent->GetWidth();
	re.top=posY- represent->GetHeight() / 2;
	re.bottom=re.top+ represent->GetHeight();
	return re;
}
Camel::~Camel()
{
}
void Camel::Update()
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
void Camel::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	
	Actived = true;

}