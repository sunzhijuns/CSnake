#ifndef CSNAKE_INPUTHANDLER_H
#define CSNAKE_INPUTHANDLER_H

#include"GameActor.h"
#include<iostream>

class Command {
public:
	virtual ~Command(){}
	virtual void execute(GameActor& actor) = 0;
};

class JumpCommand :public Command {
public:
	virtual void execute(GameActor& actor) override { actor.jump(); }
};

class FireCommand :public Command {
public:
	virtual void execute(GameActor& actor) override { actor.fireGun();  }
	
};

class SwapWeaponCommand :public Command {
public:
	virtual void execute(GameActor& actor) override { actor.swapWeapon(); }
};

class LurchIneffectivelyCommand :public Command {
public:
	virtual void execute(GameActor& actor) override { actor.lurchIneffectively(); }
};

class NullCommand :public Command {
	virtual void execute(GameActor& actor) override { std::cout << "NullCommand\n"; }
};

class InputHandler
{
public:
	enum ButtonType
	{
		kButtonX = 1,
		kButtonY,
		kButtonA,
		kButtonB
	};
public:
	InputHandler();
	~InputHandler();
	Command* handleInput();
	bool isPressed(const ButtonType& type);
public:
	void setButtonType(const ButtonType& type) { type_ = type; }

	void setButtonA(Command* command) { buttonA_ = command; }
	void setButtonB(Command* command) { buttonB_ = command; }
	void setButtonX(Command* command) { buttonX_ = command; }
	void setButtonY(Command* command) { buttonY_ = command; }

private:
	ButtonType type_;
	Command* buttonX_;
	Command* buttonY_;
	Command* buttonA_;
	Command* buttonB_;
	//static Command* null_;

};

#endif // !CSNAKE_INPUTHANDLER_H

