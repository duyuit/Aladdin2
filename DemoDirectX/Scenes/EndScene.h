#pragma once
#include "../GameComponents/Scene.h"
#include "../GameComponents/Animation.h"
#include "../GameControllers/SceneManager.h"
class EndScene:public Scene
{
public:
	EndScene();
	~EndScene();
	void Update(float);
	void Draw();
	Animation* kiss;
	Animation* end;
	vector<RECT> LoadRect(bool);
	Sprite* intro;

};

