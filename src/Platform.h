#ifndef Platform_H
#define Platform_H

#include <Interfaces.h>



class Platform : public InterPlatform
{
public:
	Platform(InterDriver *lDr, InterDriver *rDr);
	
	~Platform();

	void stop() override;
	void accstop() override;

	void moveFwrd() override;
	void moveBwrd() override;

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
