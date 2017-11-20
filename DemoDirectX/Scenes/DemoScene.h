#pragma once

#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../GameComponents/Scene.h"
#include "../GameComponents/Sprite.h"
#include "../GameComponents/Animation.h"
#include "../GameComponents/GameMap.h"
#include "../GameComponents/Camera.h"
#include "../GameObjects/Player/Player.h"
#include "../../GameDefines/GameDefine.h"
//#include "../GameObjects/Apple/Apple.h"
#include "../GameObjects/MapObject/CivilianThrowBowl/ManThrowBowl.h"
#include "../GameObjects/Enemy/Enemy1/Enemy1.h"
#include "../GameObjects/Enemy/Enemy2/Enemy2.h"
#include "../GameObjects/Enemy/Enemy3/Enemy3.h"
#include "../GameObjects/Enemy/Enemy4/Enemy4.h"
#include "../GameObjects/MapObject/CayBung.h"
#include "../GameControllers/SceneManager.h"
#include "DieScene.h"
class DemoScene : public Scene
{
public:
    DemoScene();

    void Update(float dt);
    void LoadContent();
    void Draw();

    void OnKeyDown(int keyCode);
    void OnKeyUp(int keyCode);
    void OnMouseDown(float x, float y);
	DieScene *mDieScene;

protected:

	Animation *EatItem;
    GameMap *mMap;
    Camera *mCamera;
	Player *mPlayer;
    float mTimeCounter;
	void CheckCameraAndWorldMap();

	void checkCollision();

    std::map<int, bool> keys;


};

