#ifndef Niki_robot_H_rel
#define Niki_robot_H_rel

#include <NikiRobot.h>

Niki::Niki()
{
	pinIN1 = 0;
	pinEN = 0;

	invDirect = false;
	direction = 0;
	operationPWM = 0;
}

Niki::Niki(int IN1pin, int ENpin)
{
	pinIN1 = IN1pin;
	pinEN = ENpin;

	invDirect = false;
	direction = 0;
	operationPWM = 0;
	pinMode(pinIN1, OUTPUT);
	pinMode(pinEN, OUTPUT);
}

Niki::~Niki()
{
}

void Niki::setDirection(DRIVER_DIR dir)
{

	switch (dir)
	{
	case DRIVER_DIR::IDLE :
		IN1 = 0;
		break;
		
	case DRIVER_DIR::FORWARD :

		if (invDirect)
		{
			IN1 = 0;
		}
		else
		{
			IN1 = 1;
		}
		break;

	case DRIVER_DIR::BACKWARD :

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
	speedOffsetValue = offset;
}

void Niki::setOperationPWM(int duty)
{
	operationPWM = duty + speedOffsetValue;
	if(operationPWM<0) operationPWM = 0;
	if(operationPWM>255) operationPWM = 255;
}

void Niki::startMove()
{
	doDir();
}

void Niki::invDirection(bool inv)
{
	invDirect = inv;
}

void Niki::doDir()
{
	digitalWrite(pinIN1, IN1);
	analogWrite(pinEN, operationPWM);
}

#endif
