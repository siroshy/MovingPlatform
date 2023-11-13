#ifndef Driver_L256n_H
#define Driver_L256n_H

#include <Interfaces.h>



class DriverL256n : public InterDriver
{
public:
	DriverL256n();

	DriverL256n(int IN1pin, int IN2pin, int ENpin );
	
	~DriverL256n();

	void setDirection(int dir) override; 
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

	void invDir(bool inv) override;

	void setOpPWM(int duty) override;

	void stMove() override;


protected:

	int pinIN1;
	int pinIN2;
	int pinEN;

	int IN1;
	int IN2;
	int EN;

	void doDir();

	
};

#endif