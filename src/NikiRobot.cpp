#ifndef Niki_robot_H_rel
#define Niki_robot_H_rel

#include <NikiRobot.h>

Niki::Niki()
{
	pinIN1 = 0;
	pinEN = 0;

	invDirect = false;
	direction = 0;
	opPWM = 0;
}

Niki::Niki(int IN1pin, int ENpin)
{
	pinIN1 = IN1pin;
	pinEN = ENpin;

	invDirect = false;
	direction = 0;
	opPWM = 0;
	pinMode(pinIN1, OUTPUT);
	pinMode(pinEN, OUTPUT);
}

Niki::~Niki()
{
}

void Niki::setDirection(int dir)
{

	switch (dir)
	{
	case 0:
		IN1 = 0;
		break;
		
	case 1:

		if (invDirect)
		{
			IN1 = 0;
		}
		else
		{
			IN1 = 1;
		}
		break;

	case 2:

		if (invDirect)
		{
			IN1 = 1;
		}
		else
		{
			IN1 = 0;
		}
		break;
	}
}

void Niki::speedOffset(int offset)
{
	if (offset > 254) offset = 254;
	if (offset < -254) offset = -254;
	spOffset = offset;
}

void Niki::setOpPWM(int duty)
{
	opPWM = duty + spOffset;
	if(opPWM<0) opPWM = 0;
	if(opPWM>255) opPWM = 255;
}

void Niki::stMove()
{
	doDir();
}

void Niki::invDir(bool inv)
{
	invDirect = inv;
}

void Niki::doDir()
{
	digitalWrite(pinIN1, IN1);
	analogWrite(pinEN, opPWM);
}

#endif
