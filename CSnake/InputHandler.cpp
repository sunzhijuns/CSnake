
#include"InputHandler.h"
//Command* InputHandler::null_ = new NullCommand();
InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

bool InputHandler::isPressed(const InputHandler::ButtonType& type) {
	return type_ == type;
}


Command* InputHandler::handleInput() {
	if (isPressed(kButtonX))
		return buttonX_;
	else if (isPressed(kButtonY))
		return buttonY_;
	else if (isPressed(kButtonA))
		return buttonA_;
	else if (isPressed(kButtonB))
		return buttonB_;
	return nullptr;
}

//#define DEBUG_CSNAKE_INPUTHANDLER_H
#ifdef DEBUG_CSNAKE_INPUTHANDLER_H
#include <iostream>

int main() {
	GameActor a;
	InputHandler input;
	SwapWeaponCommand commandA;
	LurchIneffectivelyCommand commandB;
	JumpCommand commandX;
	FireCommand commandY;

	input.setButtonA(&commandA);
	input.setButtonB(&commandB);
	input.setButtonX(&commandX);
	input.setButtonY(&commandY);
	

	input.setButtonType(InputHandler::ButtonType::kButtonB);

	Command* com = input.handleInput();
	if (com != nullptr)
		com->execute(a);
	system("pause");
}
#endif // DEBUG_CSNAKE_INPUTHANDLER_H
