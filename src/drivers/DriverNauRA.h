#ifndef DriverNAURA
#define DriverNAURA

#include <Interfaces.h>

enum NAURA_DRIVER{
	LEFT_MOTOR,
	RIGHT_MOTOR
};

class DriverNauRA : public InterDriver
{
public:

	DriverNauRA(NAURA_DRIVER driver);

	DriverNauRA(int EN, int DIR, int PWM);
	
	~DriverNauRA();

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

	int EN;
    int DIR;
    int PWM;

	void doDir();

	
};

#endif