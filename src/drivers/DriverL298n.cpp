#ifndef Driver_L256n_rel
#define Driver_L256n_rel

#include "DriverL298n.h"

DriverL298n::DriverL298n()
{
	pinIN1 = 0;
	pinIN2 = 0;
	pinEN = 0;

	invDirect = false;
	operationPWM = 0;

}

DriverL298n::DriverL298n(int IN1pin, int IN2pin, int ENpin )
{
	pinIN1 = IN1pin;
	pinIN2 = IN2pin;
	pinEN = ENpin;

	invDirect = false;
	operationPWM = 0;
	pinMode(pinIN1, OUTPUT);
	pinMode(pinIN2, OUTPUT);
	pinMode(pinEN, OUTPUT);

}


DriverL298n::~DriverL298n()
{

}

void DriverL298n::setDirection(DRIVER_DIR dir)
{


	switch(dir){
	case DRIVER_DIR::IDLE:
		IN1 = 0;
		IN2 = 0;
		break;

	case DRIVER_DIR::ROT_LEFT :

		if(invDirect){
			IN1 = 1;
			IN2 = 0;
		}else{
			IN1 = 0;
			IN2 = 1;
		}
		
		break;

	case DRIVER_DIR::ROT_RIGHT :

		if(invDirect){
			IN1 = 0;
			IN2 = 1;
		}else{
			IN1 = 1;
			IN2 = 0;
		}

		break;

	case DRIVER_DIR::ACTIVE_BREAK :
		IN1 = 1;
		IN2 = 1;
		break;

	}

}

void DriverL298n::setOperationPWM(int duty)
{	
	operationPWM = duty+speedOffsetValue;
	if(operationPWM<0) operationPWM = 0;
	if(operationPWM>255) operationPWM = 255;
	
}

void DriverL298n::startMove()
{
	doDir();
}

void DriverL298n::invDirection(bool inv)
{
	invDirect = inv;
}

void DriverL298n::speedOffset(int offset){
	if(offset>254) offset = 254;
	if (offset<-254) offset = -254;
	speedOffsetValue = offset;	
}

void DriverL298n::doDir()
{
	digitalWrite(pinIN1, IN1);
	digitalWrite(pinIN2,IN2);
	analogWrite(pinEN,operationPWM);
}

#endif