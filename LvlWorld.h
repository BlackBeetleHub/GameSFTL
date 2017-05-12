#pragma once
#include<vector>
#include"SFML\Graphics.hpp"
#include"Camera.h"
#include"Entity.h"

class LvlWorld
{
public:
	LvlWorld();
	~LvlWorld();
	void bindCamera(Camera *_cam) {
		cam = _cam;
	}
	void draw(sf::RenderWindow &window);
	bool AddObject(Object obj);
private:
	Camera *cam;
	std::vector<Object> terra;
};


