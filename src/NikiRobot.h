#ifndef Niki_robot_H
#define Niki_robot_H

#include <Interfaces.h>



class Niki : public InterDriver
{
public:
	Niki();

	Niki(int IN1pin, int ENpin);

	~Niki();

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
	int pinEN;

	int IN1;
	int EN;
	
	void doDir();


};

#endif
