#include "LvlWorld.h"



LvlWorld::LvlWorld()
{
}

void LvlWorld::draw(sf::RenderWindow & window) {
	for (int i = 0; i < terra.size(); i++) {
		b2Vec2 pos = terra[i].getPosition();
		Vector2f res = cam->TarGetCenter(pos.x, pos.y);
		// It's try: terra[i]._x - pos.x + 683, terra[i]._y - pos.y  + 384;
		terra[i].draw(window, res.x, res.y);
	}
}

bool LvlWorld::AddObject(Object obj) {
	terra.push_back(obj);
	return true;
}

LvlWorld::~LvlWorld()
{
}


