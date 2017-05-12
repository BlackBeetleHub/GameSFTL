#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Object::Create(sf::Texture *text,string name, int x, int y, int w, int h, int dx, int dy, b2BodyType type, b2World *world) {
	b2PolygonShape shape;
	shape.SetAsBox(w / 2, h / 2);
	b2BodyDef bdef;
	bdef.type = type;
	bdef.position.Set(static_cast<float32>(dx + w / 2), static_cast<float32>(dy + h / 2));
	body = world->CreateBody(&bdef);
	body->CreateFixture(&shape, 1);
	texture = text;
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(x, y, w, h));
	sprite.setPosition(dx, dy);
	_x = dx;
	_y = dy;
	_width = w;
	_hight = h;
	_name = name;
}

