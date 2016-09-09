#include "Animation.h"



Animation::Animation()
{
}

void Animation::create(Texture &texture, int x, int y, int wight, int higth, int count, int countFrames, int speed)
{
	sprite.setTexture(texture);
	this->speed = speed;
	this->countFrames = countFrames;
	currentFrame = 0;
	flip = false;
	for (int i = 0; i <= countFrames; i++) {
		frames.push_back(IntRect(x + (count + wight)*i, y, wight, higth));
		frames.push_back(IntRect(x + (count + wight)*i, y, -wight, higth));
	}
}

void Animation::create(Texture &texture, vector<IntRect> rects, float speed) {
	sprite.setTexture(texture);
	frames = rects;
	countFrames = rects.size();
	this->speed = speed;
	flip = false;
	for (int i = 0; i <= countFrames; i++) {
		frames_flip.push_back( IntRect(rects[i].left +
			rects[i].width, rects[i].top, -rects[i].width, rects[i].height));
	}
}

Animation::~Animation()
{
}
