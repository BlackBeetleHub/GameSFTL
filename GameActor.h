#pragma once
#include"Entity.h"

class GameActor: public Entity
{
public:
	void create(int x, int y, int width, int hight, float healht, float attack, float def, b2World *world, AnimationManager *anim) {
		Entity::Create("Player", x, y, width, hight, healht, attack, def, world, anim);
	}
	void draw(sf::RenderWindow &win) {
		b2Vec2 pos = body->GetPosition();
		animations->draw(win, pos.x + 600, pos.y + 300);
	}
	GameActor();
	~GameActor();
private:
	
};

