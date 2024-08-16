#ifndef Niki_robot_H
#define Niki_robot_H

#include <Interfaces.h>



class Niki : public InterDriver
{
public:
	Niki();

	Niki(int IN1pin, int ENpin);

	~Niki();

	void setDirection(DRIVER_DIR dir) override; 
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

	void invDirection(bool inv) override;

	void setOperationPWM(int duty) override;
	
	void speedOffset(int offset) override;

	void startMove() override;

protected:

	int pinIN1;
	int pinEN;

	int IN1;
	int EN;
	
	void doDir();


};

#endif
