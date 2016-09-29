#pragma once
#include"SFML\Graphics.hpp"
#include"GameActor.h"

class CommandManager
{
public:
	CommandManager();
	~CommandManager();
};


class Command{
public:
	virtual ~Command();
	virtual void execute(GameActor &actor) = 0;
};

class JumpCommand : public Command {
public:
	virtual void execute(GameActor &actor) {
		printf("Execute jump\n");
	}
	virtual ~JumpCommand() {
	}
};

class FireCommand : public Command {
public:
	virtual void execute(GameActor &actor){
		//fire();
	}
	virtual ~FireCommand() {
	}
};

class MoveLeft : public Command {
public:
	virtual void execute(GameActor &actor) {
		actor.MoveLeft(500);
	}
	virtual ~MoveLeft() {
	}
};

class MoveRight : public Command {
public:
	virtual void execute(GameActor &actor) {
		actor.MoveRight(500);
	}
	virtual ~MoveRight() {
	}
};

class MoveUp : public Command {
public:
	virtual void execute(GameActor &actor) {
		actor.MoveUp(-1000);
	}
	virtual ~MoveUp() {
	}
};

class MoveDown : public Command {
public:
	virtual void execute(GameActor &actor) {
		actor.MoveDown(-500);
	}
	virtual ~MoveDown() {
	}
};


class InputHandler {
public:
	Command* handleInput() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) return buttonW_;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return buttonD_;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return buttonA_;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) return buttonS_;
		return NULL;
	}

	void bindButtonA(Command *com) {
		buttonA_ = com;
	}
	void bindButtonW(Command *com) {
		buttonW_ = com;
	}
	void bindButtonD(Command *com) {
		buttonD_ = com;
	}
	void bindButtonS(Command *com) {
		buttonS_ = com;
	}
	void bindButtonE(Command *com) {
		buttonE_ = com;
	}
	void bindButtonR(Command *com) {
		buttonR_ = com;
	}
	void bindButtonF(Command *com) {
		buttonF_ = com;
	}
    InputHandler(Command* W, Command* D, Command* A, Command* S, Command* E, Command* F);
	InputHandler();
private:
	Command* buttonW_;
	Command* buttonD_;
	Command* buttonA_;
	Command* buttonS_;
	Command* buttonF_;
	Command* buttonE_;
	Command* buttonR_;
};

//Command* InputHandler::handleInputssssss()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) return buttonW_;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return buttonD_;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return buttonA_;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) return buttonS_;
//	return NULL;
//}