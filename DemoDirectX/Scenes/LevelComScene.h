#pragma once
#include "../GameComponents/Scene.h"
#include "../GameComponents/Animation.h"
#include "../GameControllers/SceneManager.h"
#include "BossScene.h"
#include "EndScene.h"
class LevelComScene:public Scene
{
public:
	LevelComScene(Player *player, UI* ui);
	~LevelComScene();
	void LoadContent();
	Sprite* background;
	Animation* aladdin;
	Animation* anbu;
	void Update(float dt);
	vector<RECT> LoadRECT(bool);
	Player *pl;
	UI* ui;
	void Draw();
};

