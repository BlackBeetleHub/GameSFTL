#pragma once
#include<SFML\Graphics.hpp>
#include"AnimationManager.h"
#include"LvlWorld.h"
#include"Entity.h"
#include<iostream>
#include"Box2D\Box2D.h"

using namespace sf;

float const SCALE = 30.f;
const float DEG = 57.29577f;

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