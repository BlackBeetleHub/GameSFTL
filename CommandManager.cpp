#include "CommandManager.h"



CommandManager::CommandManager()
{
}


CommandManager::~CommandManager()
{
}

InputHandler::InputHandler(Command* W, Command* D, Command* A, Command* S, Command* E, Command* F) {
	buttonA_ = A;
	buttonW_ = W;
	buttonD_ = D;
	buttonS_ = S;
	buttonE_ = E;
	buttonF_ = F;
}

InputHandler::InputHandler() {

}

Command::~Command()
{
}
