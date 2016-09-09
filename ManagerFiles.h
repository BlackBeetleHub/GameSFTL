#pragma once
#include "SFML\Graphics.hpp"
#include "AnimationManager.h"

class ManagerFiles
{
public:
	AnimationManager* LoadAnimatioManager(char *dir);
	
	ManagerFiles();
	~ManagerFiles();
private:
	
};

