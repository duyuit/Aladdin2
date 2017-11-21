#pragma once
#include "../GameComponents/Scene.h"
#include "../GameComponents/Animation.h"
#include "../GameControllers/SceneManager.h"

class DieScene : public Scene
{
public:
	DieScene(Scene *preScene);
	~DieScene();
	void Update(float dt);
	void LoadContent();
	void Draw();
	Animation *die;
	Scene *preScene;
	Sprite* dieText;

	 void OnKeyDown(int keyCode);
	 void OnKeyUp(int keyCode);
};

