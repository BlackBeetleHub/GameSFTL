#pragma once

#include"SFML\Graphics.hpp"
#include<iostream>
using namespace sf;
using namespace std;


class Animation
{
public:
	Animation();
	void create(Texture &texture, int x, int y, int wight, int higth, int count, int countFrames, int speed);
	void create(Texture &texture, vector<IntRect> rects, float speed);
	void tick(float time) {
		currentFrame += speed*time;
		if (currentFrame > countFrames || currentFrame == countFrames || currentFrame < 0) {
			currentFrame = 0;
		}
		int i = static_cast<int>(currentFrame);
		if (flip) {
			sprite.setTextureRect(frames_flip[i]);
		}
		else {
			sprite.setTextureRect(frames[i]);
		}
	}
	~Animation();
	Sprite sprite;
	bool isPlaying, flip;
private:
	int countFrames;
	float speed, currentFrame;
	vector<IntRect> frames, frames_flip;
};

