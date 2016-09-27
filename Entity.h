#pragma once
#include"AnimationManager.h"
#include"Box2D\Box2D.h"

class Entity
{
public:
	Entity();
	~Entity();


	string setName(string value) {
		name = value;
	}

	void setAnimation(string name) {
		animations->set(name);
	}

	void getDamage(float damage) {
		float clear_damage = damage - damage*_def*0.01f;
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

	void Init(string _name, float healht, float attack, float def) {
		name = _name;
		_healht = healht;
		_attack = attack;
		_def = def;
	}
	AnimationManager *animations;
	b2Body *body;
	int _x;
	int _y;
	int _width;
	int _hight;
private:
	string name;
	float _healht;
	float _attack;
	float _def;
};

struct MyStruct
{
	virtual void add() = 0;
};