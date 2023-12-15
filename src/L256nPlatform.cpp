#ifndef L256nPlatform_rel
#define L256nPlatform_rel

#include <L256nPlatform.h>

L256nPlatform::L256nPlatform(InterDriver *lDr, InterDriver *rDr)
{
	leftDr = lDr;
	rightDr = rDr;
};

L256nPlatform::~L256nPlatform()
{

}
void L256nPlatform::stop()
{
	leftDr->setDirection(0);
	rightDr->setDirection(0);
	rightDr->stMove();
	leftDr->stMove();
	
};
void L256nPlatform::accstop()
{
	leftDr->setDirection(3);
	rightDr->setDirection(3);
	rightDr->stMove();
	leftDr->stMove();
	
};

void L256nPlatform::moveFwrd()
{
	leftDr->setDirection(1);
	rightDr->setDirection(1);
	rightDr->stMove();
	leftDr->stMove();
	
};

void L256nPlatform::movebwrd()
{
	leftDr->setDirection(2);
	rightDr->setDirection(2);
	rightDr->stMove();
	leftDr->stMove();
};

void L256nPlatform::turnLft()
{
	leftDr->setDirection(0);
	rightDr->setDirection(1);
	rightDr->stMove();
	leftDr->stMove();
};
void L256nPlatform::turnRht()
{
	leftDr->setDirection(1);
	rightDr->setDirection(0);
	rightDr->stMove();
	leftDr->stMove();
};

void L256nPlatform::turnBackLft()
{
	leftDr->setDirection(0);
	rightDr->setDirection(2);
	rightDr->stMove();
	leftDr->stMove();
};

void L256nPlatform::turnBackRht() 
{
	leftDr->setDirection(2);
	rightDr->setDirection(0);
	rightDr->stMove();
	leftDr->stMove();
};

void L256nPlatform::circleLft()
{
	leftDr->setDirection(2);
	rightDr->setDirection(1);
	rightDr->stMove();
	leftDr->stMove();
};

void L256nPlatform::circleRht()
{
	leftDr->setDirection(1);
	rightDr->setDirection(2);
	rightDr->stMove();
	leftDr->stMove();
};

void L256nPlatform::setAccMode(bool mode)
{
	accMode = mode;
};

void L256nPlatform::setAccVal(int acc)
{

};

void L256nPlatform::setSpeed(int speed)
{
	leftDr->setOpPWM(speed);
	rightDr->setOpPWM(speed);
};
void L256nPlatform::setSpeedOT(int speed1, int speed2)
{
	leftDr->setOpPWM(speed1);
	rightDr->setOpPWM(speed2);
};
void L256nPlatform::setMinSpeed(int speed)
{
	minSpeed = speed;
}
void L256nPlatform::tickMT()
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
