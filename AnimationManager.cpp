#include "AnimationManager.h"

void AnimationManager::create(string name, Texture &texture, int x, int y, int wight, int higth, int count, int countFrames,int speed) {
	animation[name].create(texture, x, y, wight, higth, count, countFrames, speed);
}

void AnimationManager::create(string name, Texture &texture, vector<IntRect> rects, float speed) {
	animation[name].create(texture, rects, speed);
}

AnimationManager::AnimationManager()
{
}


AnimationManager::~AnimationManager()
{
}

void AnimationManager::draw(RenderWindow &win, int x, int y) {
	if (!isPlay) return;
	animation[currentAnimation].sprite.setPosition(x, y);
	win.draw(animation[currentAnimation].sprite);
}