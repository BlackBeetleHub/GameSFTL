#pragma once
#include"AnimationManager.h"

class Entity
{
public:
	Entity();
	~Entity();
	int _x;
	int _y;
	int _width;
	int _hight;

	string setName(string value) {
		name = value;
	}

	void setAnimation(string name) {
		animations->set(name);
	}

	void getDamage(float damage) {
		float clear_damage = damage - damage*_def*0.01;
		_healht = _healht - (clear_damage);
	}

	void bindAnimation(AnimationManager *anim) {
		animations = anim;
		animations->set("Walk");
		animations->play();
	}

	void setDef(float value) {
		_def = value;
	}

	void kill() {
		animations = NULL;
		_healht = 0;
		_attack = 0;
		_def = 0;
	}
private:
	AnimationManager *animations;
	string name;
	float _healht;
	float _attack;
	float _def;
};

