#pragma once

#include"Entity.h"

class Camera
{
public:
	b2Vec2 GetPosition() {
		return _entity->getPosition();
	}
	void init(Entity *entity) {
		_entity = entity;
	}
	Camera();
	~Camera();
private:
	int offX, offY;
	Entity *_entity;
};

