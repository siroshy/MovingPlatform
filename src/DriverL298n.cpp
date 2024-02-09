#ifndef Driver_L256n_rel
#define Driver_L256n_rel

#include <DriverL298n.h>

DriverL298n::DriverL298n()
{
	pinIN1 = 0;
	pinIN2 = 0;
	pinEN = 0;

	invDirect = false;
	direction = 0;
	opPWM = 0;

}

DriverL298n::DriverL298n(int IN1pin, int IN2pin, int ENpin )
{
	pinIN1 = IN1pin;
	pinIN2 = IN2pin;
	pinEN = ENpin;

	invDirect = false;
	direction = 0;
	opPWM = 0;
	pinMode(pinIN1, OUTPUT);
	pinMode(pinIN2, OUTPUT);
	pinMode(pinEN, OUTPUT);

}


DriverL298n::~DriverL298n()
{

}

void DriverL298n::setDirection(int dir)
{


	switch(dir){
	case 0:
		IN1 = 0;
		IN2 = 0;
		break;

	case 1:

		if(invDirect){
			IN1 = 1;
			IN2 = 0;
		}else{
			IN1 = 0;
			IN2 = 1;
		}
		
		break;

	case 2:

		if(invDirect){
			IN1 = 0;
			IN2 = 1;
		}else{
			IN1 = 1;
			IN2 = 0;
		}

		break;

	case 3:
		IN1 = 1;
		IN2 = 1;
		break;

	}

}

void DriverL298n::setOpPWM(int duty)
{	
	opPWM = duty+spOffset;
	if(opPWM<0) opPWM = 0;
	if(opPWM>255) opPWM = 255;
	
}

void DriverL298n::stMove()
{
	doDir();
}

void DriverL298n::invDir(bool inv)
{
	invDirect = inv;
}

void DriverL298n::speedOffset(int offset){
	if(offset>254) offset = 254;
	if (offset<-254) offset = -254;
	spOffset = offset;	
}

void DriverL298n::doDir()
{
	digitalWrite(pinIN1, IN1);
	digitalWrite(pinIN2,IN2);
	analogWrite(pinEN,opPWM);
}

#endif