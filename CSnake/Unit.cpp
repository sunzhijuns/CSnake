#include "Unit.h"

//#define DEBUG_CSNAKE_UNIT_H
#ifdef DEBUG_CSNAKE_UNIT_H
int main(){
	Unit u(1, 1);
	MoveUnitCommand moveCommand1(&u, 2, 2);
	MoveUnitCommand moveCommand2(&u, 3, 3);
	moveCommand1.execute();
	moveCommand2.execute();
	moveCommand2.undo();
	moveCommand1.undo();
	system("pause");
}
#endif // DEBUG_CSNAKE_UNIT_H
