#include "LvlWorld.h"



LvlWorld::LvlWorld()
{
}

void LvlWorld::scrool(int x, int y) {
	for (int i = 0; i < terra.size(); i++) {
		terra[i].sprite.setPosition(terra[i].sprite.getPosition().x + x, terra[i].sprite.getPosition().y + y);
	}
}

void LvlWorld::draw(sf::RenderWindow & window) {
	for (int i = 0; i < terra.size(); i++) {
		b2Vec2 pos = cam->GetPosition();
		terra[i].sprite.setPosition(terra[i]._x - pos.x + 683 - terra[i]._width/2, terra[i]._y - pos.y - terra[i]._hight/2 + 384);
		window.draw(terra[i].sprite);
	}
}

void LvlWorld::draw(sf::RenderWindow & window,float offx,float offy) {
	for (int i = 0; i < terra.size(); i++) {
		terra[i].sprite.setPosition(terra[i]._x - offx , terra[i]._y - offy );
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
	_x = dx;
	_y = dy;
	_width = w;
	_hight = h;
}