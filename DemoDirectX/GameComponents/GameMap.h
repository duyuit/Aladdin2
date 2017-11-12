#pragma once
#ifndef __GAME_MAP__
#define __GAME_MAP__

#include "../GameComponents/Sprite.h"
#include "../MapReader/Tmx.h.in"
#include "Camera.h"
#include "GameGlobal.h"
#include "GameCollision.h"
#include "QuadTree.h"
#include <iostream>
#include <sstream>
#include "../GameObjects/MapObject/Camel.h"
//#include "../AppleObject.h"
using namespace std;
class GameMap
{
public:
    GameMap(char* filePath);

    Tmx::Map* GetMap();
	void Update(float dt);
   
	void SetCamera(Camera *camera);

    void Draw();   

	RECT GetWorldMapBound();
	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();
	std::map<int, Sprite*> getListTileSet();

	bool IsBoundLeft(); //kiem tra luc nay Camera o vi bien ben trai so voi WorldMap
	bool IsBoundRight(); // kiem tra xem co o vi tri bien ben phai worldmap khong
	bool IsBoundTop(); // kiem tra xem co o vi tri bien ben trai worldmap khong
	bool IsBoundBottom(); // kiem tra xem co o vi tri bien ben phai worldmap khong

	QuadTree* GetQuadTree();
    ~GameMap();
	void DrawFront();
	vector<Camel*> listCamel;
	vector<AppleObject*> listAppleObject;
	vector<D3DXVECTOR2> listBowl1;
	vector<D3DXVECTOR2> listBowl2;

private:
    void LoadMap(char* filePath);
	QuadTree                        *mQuadTree;
    bool isContain(RECT rect1, RECT rect2);

    Tmx::Map                        *mMap;
    std::map<int, Sprite*>          mListTileset;
    Camera *mCamera;

};

#endif

