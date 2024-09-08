#ifndef DriverNAURA
#define DriverNAURA

#include "Interfaces.h"

/// @brief Список стандартных драйверов с пинами
enum NAURA_DRIVER{
	MOTOR_A, // EN: 48, DIR: 47, PWM: 9
	MOTOR_B // EN: 42, DIR: 43, PWM: 10
};


class DriverNauRA : public InterDriver
{
public:

	/// @brief Конструктор с автоматическим выбором пинов
	/// @param driver Укажите драйвер из списка
	DriverNauRA(NAURA_DRIVER driver);

	/// @brief Конструктор с ручным выбором пинов
	/// @param EN пин EN
	/// @param DIR пин DIR
	/// @param PWM пин PWM
	DriverNauRA(int EN, int DIR, int PWM);
	
	~DriverNauRA();

	void setDirection(DRIVER_DIR dir) override; 

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