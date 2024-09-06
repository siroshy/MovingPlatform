#ifndef DriverNauRA_rel
#define DriverNauRA_rel

#include "DriverNauRA.h"

DriverNauRA::DriverNauRA(NAURA_DRIVER driver)
{
	switch (driver)
	{
	case NAURA_DRIVER::MOTOR_A :
	{
		this->EN = 48;
		this->DIR = 47;
		this->PWM = 9;
	}
	break;

	case NAURA_DRIVER::MOTOR_B :
	{
		this->EN = 42;
		this->DIR = 43;
		this->PWM = 10;
	}
	break;

	default:
	{
		this->EN = 0;
		this->DIR = 0;
		this->PWM = 0;
	}
	break;
	}

	invDirect = false;
	direction = 0;
	operationPWM = 0;
	pinMode(this->EN, OUTPUT);
	pinMode(this->DIR, OUTPUT);
	pinMode(this->PWM, OUTPUT);
}

DriverNauRA::DriverNauRA(int EN, int DIR, int PWM)
{
	this->EN = EN;
	this->DIR = DIR;
	this->PWM = PWM;

	invDirect = false;
	direction = 0;
	operationPWM = 0;
	pinMode(this->EN, OUTPUT);
	pinMode(this->DIR, OUTPUT);
	pinMode(this->PWM, OUTPUT);
}

DriverNauRA::~DriverNauRA()
{
}

void DriverNauRA::setDirection(DRIVER_DIR dir)
{

	switch (dir)
	{
	case DRIVER_DIR::IDLE:
		direction = 0;
		digitalWrite(EN, 0);
		break;

	case DRIVER_DIR::ROT_LEFT :
		digitalWrite(EN, 1);
		if (invDirect)
		{
			direction = 1;
		}
		else
		{
			direction = 0;
		}

		break;

	case DRIVER_DIR::ROT_RIGHT :
		digitalWrite(EN, 1);
		if (invDirect)
		{
			direction = 0;
		}
		else
		{
			direction = 1;
		}

		break;

	case DRIVER_DIR::ACTIVE_BREAK:
		digitalWrite(EN, 1);
		direction = 0;
		break;
	}
}

void DriverNauRA::setOperationPWM(int duty)
{
	operationPWM = duty + speedOffsetValue;
	if (operationPWM < 0)
		operationPWM = 0;
	if (operationPWM > 255)
		operationPWM = 255;
}

void DriverNauRA::startMove()
{
	doDir();
}

void DriverNauRA::invDirection(bool inv)
{
	invDirect = inv;
}

void DriverNauRA::speedOffset(int offset)
{
	if (offset > 254)
		offset = 254;
	if (offset < -254)
		offset = -254;
	speedOffsetValue = offset;
}

void DriverNauRA::doDir()
{
	digitalWrite(DIR, direction);
	analogWrite(PWM, operationPWM);
}

#endif