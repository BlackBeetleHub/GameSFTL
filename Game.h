#pragma once
#include<SFML\Graphics.hpp>
#include"AnimationManager.h"
#include"LvlWorld.h"
#include"Entity.h"
#include<iostream>
#include"Box2D\Box2D.h"
#include"CommandManager.h"
#include"Camera.h"

using namespace sf;



class Game
{
public:
	Game();
	void run();
	~Game();
private:
	RenderWindow window;
	void GetScreenSetting();
	void GameLoop();
};

class ScreenSetting {
public:
	int hight;
	int wigth;
	ScreenSetting(int h, int w) { hight = h; wigth = w; }
}; 