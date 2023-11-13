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

void L256nPlatform::moveFwrd()
{

};

void L256nPlatform::movebwrd()
{

};

void L256nPlatform::turnLft()
{

};
void L256nPlatform::turnRht()
{

};

void L256nPlatform::turnBackLft()
{

};

void L256nPlatform::turnBackRht() 
{

};

void L256nPlatform::circleLft()
{

};

void L256nPlatform::circleRht()
{

};

void L256nPlatform::setAccMode(int mode)
{

};

void L256nPlatform::setAccVal(int acc)
{

};

void L256nPlatform::setSpeed(int speed)
{

};

#endif