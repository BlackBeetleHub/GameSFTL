#pragma once
#include"Entity.h"

class GameActor: public Entity
{
public:
	void create(int x, int y, int width, int hight, float healht, float attack, float def, b2World *world, AnimationManager *anim) {
		Entity::Create("Player", x, y, width, hight, healht, attack, def, world, anim);
	}
	GameActor();
	~GameActor();
private:
	
};

