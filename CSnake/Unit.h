#ifndef CSNAKE_UNIT_H
#define CSNAKE_UNIT_H
#include<iostream>
class Unit {
private:
	int x_, y_;
public:
	Unit(int x,int y):x_(x),y_(y){}
	int x() { return x_; }
	int y() { return y_; }
	void moveTo(int x, int y) {
		x_ = x;
		y_ = y;
		std::cout << "move to:" << x << "," << y << "\n"; 
	}
};

class UnitCommand {
public:
	virtual ~UnitCommand() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class MoveUnitCommand :public UnitCommand {
public:
	MoveUnitCommand(Unit* unit, int x, int y)
		:unit_(unit),x_(x),y_(y),
		xBefore_(0),yBefore_(0)
	{}
	virtual void execute() override { 
		xBefore_ = unit_->x();
		yBefore_ = unit_->y();
		unit_->moveTo(x_, y_); 
	}
	virtual void undo() {
		unit_->moveTo(xBefore_, yBefore_);
	}
private:
	Unit* unit_;
	int x_, y_;
	int xBefore_,yBefore_;
};
#endif // !CSNAKE_UNIT_H
