#ifndef Iterfaces_H
#define Iterfaces_H

#include <Arduino.h>

enum DRIVER_DIR{
	IDLE,
	ROT_LEFT,
	ROT_RIGHT,
	ACTIVE_BREAK
};


class InterDriver
{
public:
	InterDriver();
	virtual ~InterDriver();

	virtual void setDirection(DRIVER_DIR dir) = 0; 
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

	virtual void invDirection(bool inv);

	virtual void speedOffset(int offset);
	
	virtual void setOperationPWM(int duty) = 0;

	virtual void startMove() = 0;

protected:

	bool invDirect;

	int direction;
	int speed;
	int speedOffsetValue;
	int operationPWM;

};


#endif
