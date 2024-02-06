#ifndef Driver_L256n_H
#define Driver_L256n_H

#include <Interfaces.h>



class DriverL298n : public InterDriver
{
public:
	DriverL298n();

	DriverL298n(int IN1pin, int IN2pin, int ENpin );
	
	~DriverL298n();

	void setDirection(int dir) override; 
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

	void invDir(bool inv) override;

	void speedOffset(int offset) override;

	void setTargetSpeed(int duty) override;

	void setAccMode(int duty) override;

	void setAccVal(int duty) override;

	void tick() override;

	void stMove() override;


protected:

	void doDir() override;

	int pinIN1;
	int pinIN2;
	int pinEN;

	int IN1;
	int IN2;
	int EN;

};

#endif