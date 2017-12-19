#pragma once
#include "../GameComponents/Scene.h"
#include "../GameComponents/Animation.h"
#include "../GameControllers/SceneManager.h"
#include "DemoScene.h"
class ContinueScene :public Scene
{
public:
	ContinueScene(Scene* preSce);
	~ContinueScene();
	Sprite* background;
	Animation* ald,*run;
	void Update(float dt);
	void Draw();
	void OnKeyDown(int keyCode);
	bool isLeft = true;
	bool active = false;
	Scene* preScene;
	//BossScene* boss;
	//DemoScene* dm;
};

