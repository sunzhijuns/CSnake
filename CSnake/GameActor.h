#ifndef CSNAKE_GAMEACTOR_H
#include<iostream>
class GameActor {
public:
	void jump() { std::cout << "jump\n"; }
	void fireGun() { std::cout << "fireGun\n"; }
	void swapWeapon() { std::cout << "swapWeapon\n"; }
	void lurchIneffectively() { std::cout << "lurchIneffectively\n"; }
};
#endif // !CSNAKE_GAMEACTOR_H
