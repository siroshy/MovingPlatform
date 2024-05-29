#ifndef DriverNAURA
#define DriverNAURA

#include <Interfaces.h>



class DriverNauRA : public InterDriver
{
public:

	DriverNauRA();

	DriverNauRA(int EN, int DIR, int PWM);
	
	~DriverNauRA();

	void setDirection(int dir) override; 
	/*
	0 - Отпущено,
	1 - Вперед,
	2 - Назад,
	3 - Активный тормоз
	*/

	void invDir(bool inv) override;

	void speedOffset(int offset) override;

	void setOpPWM(int duty) override;

	void stMove() override;


protected:

	int EN;
    int DIR;
    int PWM;

	void doDir();

	
};

#endif