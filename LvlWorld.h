#pragma once
#include<vector>
#include"SFML\Graphics.hpp"

class Object {
public:
	int x;
	int y;
	int width;
	int hight;
	sf::Sprite sprite;
	sf::Texture *texture;
	void create(sf::Texture *text, int x, int y, int w, int h, int dx, int dy);
};

class LvlWorld
{
public:
	LvlWorld();
	~LvlWorld();
	void scrool(int x, int y);
	void draw(sf::RenderWindow &window);
	void draw(sf::RenderWindow & window, float offx, float offy);
	bool AddObject(Object obj);
	std::vector<Object> terra;
private:
	
};

