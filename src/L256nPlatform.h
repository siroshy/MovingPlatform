#ifndef L256nPlatform_H
#define L256nPlatform_H

#include <Interfaces.h>
#include <Driver_L256n.h>
#include <NikiRobot.h>


class L256nPlatform : public InterPlatform
{
public:
	L256nPlatform(InterDriver *lDr, InterDriver *rDr);
	
	~L256nPlatform();

	void stop() override;
	void accstop() override;

	void moveFwrd() override;
	void movebwrd() override;

	void turnLft() override;
	void turnRht() override;

	void turnBackLft() override;
	void turnBackRht() override;

	void circleLft() override;
	void circleRht() override;

	void setAccMode(bool mode) override;
	void setAccVal(int acc) override;

	void setSpeed(int speed) override;
	void tickMT() override;
	void setMinSpeed(int speed) override;
	void SetSpeedOT(int speed1, int speed2);
};

#endif
