#pragma once
#include"AnimationManager.h"
#include"Box2D\Box2D.h"

class Entity
{
public:
	Entity();
	~Entity();

	string getName() {
		return name;
	}

	void SomeAction(bool value){
		Action = value;
	}

	virtual void MoveLeftAttack(int value) {
		animations->flip(false);
		setAnimation("Attack");
		body->ApplyLinearImpulseToCenter(b2Vec2(value, 0), true);
	}

	virtual void MoveRightAttack(int value) {
		animations->flip(true);
		setAnimation("Attack");
		body->ApplyLinearImpulseToCenter(b2Vec2(-value, 0), true);
	}

	virtual void MoveLeft(int value) {
		/*
		if (!flip) {
			AllFlip(true);
			flip = true;
		}
		*/
		animations->flip(false);
		setAnimation("Walk");
		body->ApplyLinearImpulse(b2Vec2(value, 0), body->GetWorldCenter(), true);
	}

	virtual void Attack(int value) {
		setAnimation("Attack");
	}

	virtual void MoveRight(int value) {
		//if (flip) {
		//	AllFlip(false);
		//	flip = false;
	//	}
		animations->flip(true);
		setAnimation("Walk");
		body->ApplyLinearImpulse(b2Vec2(-value, 0), body->GetWorldCenter(), true);
	}

	void MoveUp(int value) {
		setAnimation("Walk");
		body->ApplyLinearImpulse(b2Vec2(0, value), body->GetWorldCenter(), true);
	}

	virtual void MoveDown(int value) {
		setAnimation("Walk");
		body->ApplyLinearImpulse(b2Vec2(0, -value), body->GetWorldCenter(), true);
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
		_healht = 0;
		_attack = 0;
		_def = 0;
		w->DestroyBody(body);
		w = NULL;
		animations = NULL;
	}
	void Create(string _name, int x, int y, int width, int hight, float healht, float attack, float def, b2World *world, AnimationManager *anim) {
		animations = anim;
		b2PolygonShape shape;
		shape.SetAsBox(width / 2, hight / 2);
		b2BodyDef bdef;
		bdef.type = b2_dynamicBody;
		bdef.position.Set(static_cast<float32>(x + width / 2), static_cast<float32>(y + hight / 2));
		body = world->CreateBody(&bdef);
		body->CreateFixture(&shape, 1);
		body->SetUserData((void*)_name.c_str());
		w = world;
		name = _name;
		_healht = healht;
		_attack = attack;
		_def = def;
		_width = width;
		_hight = hight;
	}

	virtual void draw(sf::RenderWindow &win) {
		b2Vec2 pos = body->GetPosition();
		b2Vec2 velocity = body->GetLinearVelocity();
		if (velocity.x == 0 && animations->NameCurrentAnimation()=="Walk") {
			stay();
		}
		//win, pos.x - _width / 2, pos.y - _hight / 2
		animations->draw(win, 683 - _width / 2, 384 - _hight / 2);
	}

	b2Vec2 getPosition() {
		b2Vec2 pos = body->GetPosition();
		return pos;
	}

	int getWidth() {
		return _width;
	}

	int getHight() {
		return _hight;
	}

protected:

	virtual void stay() {
		if(!Action){
			if (flip) {
				AllFlip(false);
			}
			setAnimation("Stay");
		}
	}

	AnimationManager *animations;
	b2Body *body;
	b2World *w;
	int _x;
	int _y;
	int _width;
	int _hight;
	string name;
	float _healht;
	float _attack;
	float _def;
	void setAnimation(string name) {
		animations->set(name);
	}
	void Flip(bool value) {
		animations->flip(value);
	}
	void AllFlip(bool value) {
		animations->AllFlip(value);
	}
	bool flip = false;
	bool Action = false;
private:
	
};