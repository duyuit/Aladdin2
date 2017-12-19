#include "GameGlobal.h"

HINSTANCE GameGlobal::mHInstance = NULL;
HWND GameGlobal::mHwnd = NULL;
LPD3DXSPRITE GameGlobal::mSpriteHandler = NULL;
int GameGlobal::mWidth = 400; //900 test //400
int GameGlobal::mHeight = 225; //600 test  //250
int GameGlobal::liveCount = 0; 
LPDIRECT3DDEVICE9 GameGlobal::mDevice = nullptr;
bool GameGlobal::isGameRunning = true;
GameGlobal::Song GameGlobal::curSong = GameGlobal::Menu;

IDirect3DSurface9* GameGlobal::backSurface = nullptr;
LPDIRECT3DTEXTURE9 GameGlobal::mAladdintexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mEnemytexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mMaptexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mFlaretexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mCiviliantexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mCameltexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mCayBungtexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mItemtexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mNumbertexture = NULL;
LPDIRECT3DTEXTURE9 GameGlobal::mJafartexture = NULL;
GameGlobal::GameGlobal()
{
	liveCount = 3;
	if (mSpriteHandler)
	{

	
		mSpriteHandler->GetDevice(&GameGlobal::mDevice);

	
		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/Aladdin.png",
			1121,
			2718,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(255, 0, 255),
			NULL,
			NULL,
			&mAladdintexture);

		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/guard.png",
			498,
			1053,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(120, 193, 152),
			NULL,
			NULL,
			&mEnemytexture);

		
		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/67733.png",
			4773,
			1383,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(63, 72, 204),
			NULL,
			NULL,
			&mMaptexture);

		
		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/flare.png",
			658,
			324,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(186, 254, 202),
			NULL,
			NULL,
			&mFlaretexture);

		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/civilian.png",
			1065,
			588,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(120, 193, 152),
			NULL,
			NULL,
			&mCiviliantexture);


		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/camel.png",
			882,
			99,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(248, 0, 248),
			NULL,
			NULL,
			&mCameltexture);

		
		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/cay.png",
			171,
			36,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(255, 0, 255),
			NULL,
			NULL,
			&mCayBungtexture);

	
		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/item.png",
			664,
			474,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(248, 0, 248),
			NULL,
			NULL,
			&mItemtexture);


		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/number.png",
			600,
			515,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(255, 0, 255),
			NULL,
			NULL,
			&mNumbertexture);

	
		D3DXCreateTextureFromFileExA(
			mDevice,
			"Resources/jafar.png",
			863,
			348,
			1,
			D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DCOLOR_XRGB(186, 254, 202),
			NULL,
			NULL,
			&mJafartexture);
	}

	Sound::getInstance()->loadSound("Resources/sound/Aladdin Hurt.wav", "Aladdin Hurt");
	Sound::getInstance()->loadSound("Resources/sound/Apple Collect.wav", "Apple Collect");
	Sound::getInstance()->loadSound("Resources/sound/Apple Splat.wav", "Apple Splat");
	Sound::getInstance()->loadSound("Resources/sound/Camel Spit.wav", "Camel Spit");
	Sound::getInstance()->loadSound("Resources/sound/Canopy Bounce.wav", "Canopy Bounce");
	Sound::getInstance()->loadSound("Resources/sound/Clay Pot.wav", "Clay Pot");
	Sound::getInstance()->loadSound("Resources/sound/Continue Point.wav", "Continue Point");
	Sound::getInstance()->loadSound("Resources/sound/Extra Health.wav", "Extra Health");
	Sound::getInstance()->loadSound("Resources/sound/Guard Hit 1.wav", "Guard Hit 1");
	Sound::getInstance()->loadSound("Resources/sound/Guard Hit 2.wav", "Guard Hit 2");
	Sound::getInstance()->loadSound("Resources/sound/Guard's Pants.wav", "Guard's Pants");
	Sound::getInstance()->loadSound("Resources/sound/Continue Point.wav", "Continue Point");
	Sound::getInstance()->loadSound("Resources/sound/Coming Out.wav", "Coming Out"); 
	Sound::getInstance()->loadSound("Resources/sound/Outta Apples.wav", "Outta Apples");
	Sound::getInstance()->loadSound("Resources/sound/Sword Spinning.wav", "Sword Spinning"); 
	Sound::getInstance()->loadSound("Resources/sound/Fire From Coal.wav", "Fire From Coal");
	Sound::getInstance()->loadSound("Resources/sound/man1.wav", "background_market");
	Sound::getInstance()->loadSound("Resources/sound/chet.wav", "chet");
	Sound::getInstance()->loadSound("Resources/sound/Jafar Laugh.wav", "Jafar Laugh");
	Sound::getInstance()->loadSound("Resources/sound/Aaah.wav", "Aaah");
	Sound::getInstance()->loadSound("Resources/sound/Oooh.wav", "Oooh");
	Sound::getInstance()->loadSound("Resources/sound/Jafar Snake.wav", "Jafar Snake");
	Sound::getInstance()->loadSound("Resources/sound/Jafar Tractor.wav", "Jafar Tractor");
	Sound::getInstance()->loadSound("Resources/sound/bosstheme.wav", "bosstheme");
}


GameGlobal::~GameGlobal()
{
}

void GameGlobal::SetCurrentDevice(LPDIRECT3DDEVICE9 device)
{
    mDevice = device;
}

LPDIRECT3DDEVICE9 GameGlobal::GetCurrentDevice()
{	
   return mDevice;
}


HINSTANCE GameGlobal::GetCurrentHINSTACE()
{
    return mHInstance;
}

HWND GameGlobal::getCurrentHWND()
{
    return mHwnd;
}

void GameGlobal::SetCurrentHINSTACE(HINSTANCE hInstance)
{
    mHInstance = hInstance;
}

void GameGlobal::SetCurrentHWND(HWND hWnd)
{
    mHwnd = hWnd;
}

void GameGlobal::SetCurrentSpriteHandler(LPD3DXSPRITE spriteHandler)
{
    mSpriteHandler = spriteHandler;
}

LPD3DXSPRITE GameGlobal::GetCurrentSpriteHandler()
{
    return mSpriteHandler;
}

void GameGlobal::SetWidth(int width)
{
    mWidth = width;
}

int GameGlobal::GetWidth()
{
    return mWidth;
}

void GameGlobal::SetHeight(int height)
{
    mHeight = height;
}

int GameGlobal::GetHeight()
{
    return mHeight;
}
