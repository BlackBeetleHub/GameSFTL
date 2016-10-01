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

	void bindTargetEntity(Entity *entity) {
		_entity = entity;
		//eWidht = entity->
	}

	void bindSizeWindow(int w, int h){
		WinWidht = w;
		WinHight = h;
	}

	// It's try: terra[i]._x - pos.x + 683 + 20, terra[i]._y - pos.y  + 384 + 30;
	
	Vector2f TarGetCenter(int x, int y) {
		b2Vec2 pos = this->GetPosition();
		return Vector2f(x - pos.x + WinWidht/2, y - pos.y + WinHight/2 );
	}

	Camera();
	~Camera();
private:
	int eWidht,eHight;
	int WinWidht, WinHight;
	int getW() {
		return _entity->getWidth();
	}
	int getH() {
		return _entity->getHight();
	}
	Entity *_entity;
};

