#pragma once
#include"Entity.h"

class GameActor: public Entity
{
public:
	virtual void Create(int x, int y, int width, int hight, float healht, float attack, float def, b2World *world, AnimationManager *anim) {
		Entity::Create("Player", x, y, width, hight, healht, attack, def, world, anim);
	}

	virtual void draw(sf::RenderWindow &win) {
		b2Vec2 pos = body->GetPosition();
		b2Vec2 velocity = body->GetLinearVelocity();
		if (velocity.x == 0 && animations->NameCurrentAnimation() == "Walk") {
			stay();
		}
		//win, pos.x - _width / 2, pos.y - _hight / 2
		animations->draw(win, 683 - _width / 2, 384 - _hight / 2);
	}
	GameActor();
	~GameActor();
private:
	
};

