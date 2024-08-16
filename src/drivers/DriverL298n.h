#ifndef Driver_L256n_H
#define Driver_L256n_H

#include <Interfaces.h>

class DriverL298n : public InterDriver
{
public:
	DriverL298n();

	DriverL298n(int IN1pin, int IN2pin, int ENpin);

	~DriverL298n();

	void setDirection(DRIVER_DIR dir) override;
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

	void invDirection(bool inv) override;

	void speedOffset(int offset) override;

	void setOperationPWM(int duty) override;

	void startMove() override;

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