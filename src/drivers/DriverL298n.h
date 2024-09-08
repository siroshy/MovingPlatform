#ifndef Driver_L256n_H
#define Driver_L256n_H

#include <Interfaces.h>

/**
 * @brief Драйвер для микросхемы L298n
 * @details L298n - маломощный двухканальный драйвер моторов.
 * Класс предоставляет интерфейс к одному каналу.
 * Создайте два экземпляра класса для работы с драйвером
 */
class DriverL298n : public InterDriver
{
public:
	DriverL298n();


	/// @brief Конструктор дравера для микросхемы L298n
	/// @param IN1pin IN1 pin
	/// @param IN2pin IN2 pin
	/// @param ENpin EN pin
	DriverL298n(int IN1pin, int IN2pin, int ENpin);

	~DriverL298n();

	void setDirection(DRIVER_DIR dir) override;

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