#pragma once
#include "../GameComponents/Scene.h"
#include "../GameComponents/Animation.h"
#include "../GameControllers/SceneManager.h"
class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	void Update(float dt);
	void Draw();
	Sprite* knife,*screen;
	bool up = true;
	std::map<int, bool> keys;
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};

