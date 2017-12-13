#include "DropBrick.h"



DropBrick::DropBrick(D3DXVECTOR2 startPOS)
{
	SetPosition(startPOS);
	mStartPOS = startPOS;
	RECT rect = { 1050,171,1083,188};
	Brick = new Sprite("Resources/Aladdin.png", rect, 33, 17, D3DCOLOR_XRGB(255, 0, 255),D3DXVECTOR2(0.5,0.5),GameGlobal::mAladdintexture);
	Brick->SetPosition(startPOS);
	Tag = Entity::BrickDrop;
}


DropBrick::~DropBrick()
{
}
void DropBrick::Draw(D3DXVECTOR2 tran, D3DXVECTOR2 Scale)
{
	Brick->Draw(D3DXVECTOR3(),RECT(),Scale,tran);
}

void DropBrick::Update()
{
	if (FlagActive)
	{
		mDelay++;
		if (mDelay < 10) return;
		Entity::AddPosition(0,5);
		Brick->SetPosition(GetPosition());
		if (GetPosition().y - mStartPOS.y >= 200)
		{
			FlagActive = false;
			SetPosition(mStartPOS);
		}
		
	}
	else
	{
		SetPosition(mStartPOS);
		Brick->SetPosition(GetPosition());
		mDelay = 0;
	}
	
}
void DropBrick::OnCollision(Entity *impactor, CollisionReturn data, SideCollisions side)
{
	FlagActive = true;
}
