#pragma once
#include <d3dx9.h>
#include "../Entity.h"
#include <d3d9.h>
class AppleState
{
public:
	AppleState();
	~AppleState();

	enum StateName
	{
		Flying,
		Breaking,
		NONE
	};
	virtual void Update(float dt);
	D3DXVECTOR3 getPos();
	virtual StateName GetNameState();
protected:
	float posx, posy;
	float acceX, acceY;
	float vX = 0;
	float vY = 0;;
	D3DXVECTOR3 pos;
};

