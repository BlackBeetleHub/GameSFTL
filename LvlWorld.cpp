#include "LvlWorld.h"



LvlWorld::LvlWorld()
{
}

void LvlWorld::draw(sf::RenderWindow & window) {
	for (int i = 0; i < terra.size(); i++) {
		window.draw(terra[i].sprite);
	}
}

bool LvlWorld::AddObject(Object obj) {
	terra.push_back(obj);
	return true;
}



LvlWorld::~LvlWorld()
{
}


void Object::create(sf::Texture *text, int x, int y, int w, int h, int dx, int dy) {
	texture = text;
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(x, y, w, h));
	sprite.setPosition(dx, dy);
}