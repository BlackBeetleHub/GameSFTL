#pragma once
#include"Animation.h"

class AnimationManager
{
public:
	
	AnimationManager();

	~AnimationManager();

	void create(string name, Texture &texture, int x, int y, int wight, int higth, int count, int countFrames, int speed);

	void create(string name, Texture &texture, vector<IntRect> rects, float speed);

	void setAnim(string name) { currentAnimation = name; }

	void draw(RenderWindow &win, int x, int y);

	void tick(float time) { 
		animation[currentAnimation].tick(time);
	}

	void set(string nameAnimation) {
		currentAnimation = nameAnimation;
	}

	void flip(bool b) {
		animation[currentAnimation].flip = b;
	}

	void AllFlip(bool value) {
		for (auto & item: animation) {
			item.second.flip = value;
		}
	}

	void play() { isPlay = true; }

	void stop() { isPlay = false; }
private:
	bool isPlay;
	map<string, Animation> animation;
	string currentAnimation;
};

