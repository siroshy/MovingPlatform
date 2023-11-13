#ifndef Iterfaces_H
#define Iterfaces_H

#include <Arduino.h>

class InterDriver
{
public:
	InterDriver() {};
	virtual ~InterDriver() { };

	virtual void setDirection(int dir) = 0; 
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

	virtual void invDir(bool inv);
	
	virtual void setOpPWM(int duty) = 0;

	virtual void stMove() = 0;

protected:

	bool invDirect;
	int direction;
	int speed;

	int opPWM;

};


class InterPlatform
{
public:
	InterPlatform() {};
	virtual ~InterPlatform() {};
	
	virtual void moveFwrd() = 0;
	virtual void movebwrd() = 0;

	virtual void turnLft() = 0;
	virtual void turnRht() = 0;

	virtual void turnBackLft() = 0;
	virtual void turnBackRht() = 0;

	virtual void circleLft() = 0;
	virtual void circleRht() = 0;

	virtual void setAccMode(int mode) = 0;
	virtual void setAccVal(int acc) = 0;

	virtual void setSpeed(int speed) = 0;

protected:

	int accMode;
	int accVal;

	int movingTime;

	InterDriver *leftDr;
	InterDriver *rightDr;

};



#endif