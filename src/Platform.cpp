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

void Platform::diffSpeed(int L, int R)
{
	if(L>0){
		leftDr->setDirection(1);
		leftDr->setOpPWM(L);
	}else{
		leftDr->setDirection(2);
		leftDr->setOpPWM(-1*L);
	}
	
	if(R>0){
		rightDr->setDirection(1);
		rightDr->setOpPWM(R);
	}else{
		rightDr->setDirection(2);
		rightDr->setOpPWM(-1*R);
	}

	rightDr->stMove();
	leftDr->stMove();

}

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
	leftDr->setAccMode(mode);
	rightDr->setAccMode(mode);
};

void Platform::setAccVal(int acc)
{
	leftDr->setAccVal(1);
	rightDr->setAccVal(2);
};

void tick(){
	leftDr->tick();
	rightDr->tick();
};

void Platform::setSpeed(int speed)
{
	leftDr->setTargetSpeed(speed);
	rightDr->setDirection(speed);
};



#endif
