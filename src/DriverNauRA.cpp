#ifndef DriverNauRA_rel
#define DriverNauRA_rel

#include <DriverNauRA.h>

DriverNauRA::DriverNauRA()
{
	this->EN = 0;
    this->DIR = 0;
    this->PWM = 0;

	invDirect = false;
	direction = 0;
	opPWM = 0;

}

DriverNauRA::DriverNauRA(int EN, int DIR, int PWM )
{
	this->EN = EN;
    this->DIR = DIR;
    this->PWM = PWM;

	invDirect = false;
	direction = 0;
	opPWM = 0;
	pinMode(this->EN, OUTPUT);
	pinMode(this->DIR, OUTPUT);
	pinMode(this->PWM, OUTPUT);

}


DriverNauRA::~DriverNauRA()
{

}

void DriverNauRA::setDirection(int dir)
{


	switch(dir){
	case 0:
		direction = 0;
		break;

	case 1:

		if(invDirect){
			direction = 1;
		}else{
			direction = 0;
		}
		
		break;

	case 2:

		if(invDirect){
			direction = 0;
		}else{
			direction = 1;
		}

		break;

	case 3:
		direction = 0;
		break;

	}

}

void DriverNauRA::setOpPWM(int duty)
{	
	opPWM = duty+spOffset;
	if(opPWM<0) opPWM = 0;
	if(opPWM>255) opPWM = 255;
	
}

void DriverNauRA::stMove()
{
	doDir();
}

void DriverNauRA::invDir(bool inv)
{
	invDirect = inv;
}

void DriverNauRA::speedOffset(int offset){
	if(offset>254) offset = 254;
	if (offset<-254) offset = -254;
	spOffset = offset;	
}

void DriverNauRA::doDir()
{
	digitalWrite(EN, 1);
	digitalWrite(DIR, direction);
	analogWrite(PWM, opPWM);
}

#endif