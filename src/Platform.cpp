#ifndef Platform_rel
#define Platform_rel

#include <Platform.h>

Platform::Platform(InterDriver *lDr, InterDriver *rDr)
{
	leftDr = lDr;
	rightDr = rDr;
};

Platform::~Platform()
{

}
void Platform::stop()
{
	leftDr->setDirection(0);
	rightDr->setDirection(0);
	rightDr->stMove();
	leftDr->stMove();
	
};

void Platform::accstop()
{
	leftDr->setDirection(3);
	rightDr->setDirection(3);
	rightDr->stMove();
	leftDr->stMove();
	
};

void Platform::moveFwrd()
{
	leftDr->setDirection(1);
	rightDr->setDirection(1);
	rightDr->stMove();
	leftDr->stMove();
	
};

void Platform::moveBwrd()
{
	leftDr->setDirection(2);
	rightDr->setDirection(2);
	rightDr->stMove();
	leftDr->stMove();
};

void Platform::turnLft()
{
	leftDr->setDirection(0);
	rightDr->setDirection(1);
	rightDr->stMove();
	leftDr->stMove();
};
void Platform::turnRht()
{
	leftDr->setDirection(1);
	rightDr->setDirection(0);
	rightDr->stMove();
	leftDr->stMove();
};

void Platform::turnBackLft()
{
	leftDr->setDirection(0);
	rightDr->setDirection(2);
	rightDr->stMove();
	leftDr->stMove();
};

void Platform::turnBackRht() 
{
	leftDr->setDirection(2);
	rightDr->setDirection(0);
	rightDr->stMove();
	leftDr->stMove();
};

void Platform::circleLft()
{
	leftDr->setDirection(2);
	rightDr->setDirection(1);
	rightDr->stMove();
	leftDr->stMove();
};

void Platform::circleRht()
{
	leftDr->setDirection(1);
	rightDr->setDirection(2);
	rightDr->stMove();
	leftDr->stMove();
};

void Platform::setAccMode(bool mode)
{
	accMode = mode;
};

void Platform::setAccVal(int acc)
{

};

void Platform::setSpeed(int speed)
{
	leftDr->setOpPWM(speed);
	rightDr->setOpPWM(speed);
};


void Platform::setMinSpeed(int speed)
{
	minSpeed = speed;
}
void Platform::tickMT()
{
	static int count;
	unsigned long int tmr;
	int sp = 0;
	int stp = movingTime / timeInterval;
		if ((count < stp) && mv) {
			if(stp < curSpeed) 
			{
				setSpeed(spm += acc);
			}
		}else {
			setSpeed(curSpeed);
			}
		if (count == stp) {
			mv = false;
			count = 0;
		}
};


#endif
