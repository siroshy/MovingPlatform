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

	virtual void invDir(bool inv) = 0;

	virtual void speedOffset(int offset) = 0;

	virtual void setTargetSpeed(int duty) = 0;

	virtual void setAccMode(int duty) = 0;

	virtual void setAccVal(int duty) = 0;

	virtual void stMove() = 0;

	virtual void tick() = 0;



protected:

	virtual void doDir() = 0;

	bool invDirect;
	bool accMode;

	int direction;
	int targetSpeed;
	int spOffset;
	int opPWM;
	int acc;

};


class InterPlatform
{
public:
	InterPlatform() {};
	virtual ~InterPlatform() {};

	virtual void stop() = 0;
	virtual void accstop() = 0;

	virtual void diffSpeed(int L, int R) = 0;
	
	virtual void moveFwrd() = 0;
	virtual void moveBwrd() = 0;

	virtual void turnLft() = 0;
	virtual void turnRht() = 0;

	virtual void turnBackLft() = 0;
	virtual void turnBackRht() = 0;

	virtual void circleLft() = 0;
	virtual void circleRht() = 0;

	virtual void setSpeed(int speed) = 0;
	virtual void setAccMode(bool mode) = 0;
	virtual void setAccVal(int acc) = 0;
	virtual void tick() = 0;


protected:

	bool accMode;
	int accVal;
	int targetSpeed;

	InterDriver *leftDr;
	InterDriver *rightDr;

};



#endif
