#ifndef Platform_H
#define Platform_H

#include <Interfaces.h>

//=============================================================================
// Перечисления и типы

/// @brief Направление движения
enum MOVE_DIR
{
	FORWARD,       // Движение вперед
	BACKWARD,      // Движение назад

	FORWARD_LEFT,  // Движение вперед с поворотом налево
	FORWARD_RIGHT, // Движение вперед с поворотом направо

	BACKWARD_LEFT,	// Движение назад с поворотом налево
	BACKWARD_RIGHT, // Движение назад с поворотом направо

	CIRCLE_LEFT,    // Поворот на месте против часовой стрелки
	CIRCLE_RIGHT    // Поворот на месте по часовой стрелке

};

/// @brief Выбор драйвера
enum CUR_DRIVER
{
	LEFT_DRIVER, // Драйвер левого мотора
	RIGHT_DRIVER // Драйвер правого мотора
};

/// @brief Кофигурация движения с ускорением
typedef struct{

	uint16_t speedUpTimer; // Время разгона
	uint16_t numSteps; // Кол-во шагов разгона
	uint16_t stepDelay; // Длительность оного шага

}AccelerationConfig;

//=============================================================================
// Класс

/// @brief Двухмоторная колесная платформа
class Platform
{
public:

//=============================================================================
// Конструкторы
	/**
	 * @brief Конструктор объекта платформы
	 * @param leftDriverRef Указатель на драйвер левого мотора
	 * @param rightDriverRef Указатель на драйвер правого мотора
	 */
	Platform(InterDriver *leftDriverRef, InterDriver *rightDriverRef);

	~Platform();

//=============================================================================
// Управление движением

//-----------------------------------------------------------------------------
	/**
	 * @brief Остановиться
	 */
	void stop();

	/**
	 * @brief Остановиться
	 * @param del Задержка для исполнения команды (мс)
	 */
	void stop(uint16_t del);

//-----------------------------------------------------------------------------
	/**
	 * @brief Двигаться
	 * @param dir Направление движения из списка
	 */
	void move(MOVE_DIR dir);

	
	/// @brief Двигаться
	/// @param dir Направление движения из списка
	/// @param del Время движения
	/// @param targetSpeed Целевая скорость
	/// @param accelMove Двигаться с ускорением?
	void move(MOVE_DIR dir, uint16_t del, uint16_t targetSpeed, bool accelMove = false);

//-----------------------------------------------------------------------------
	/**
	 * @brief Движение с независимым управлением моторами
	 * @param L ШИМ для левого мотора от -255 до 255
	 * @param R ШИМ для правого мотора от -255 до 255
	 */
	void diffSpeed(int L, int R);

//=============================================================================
// Установка параметров


	/// @brief Установка скорости движения для обоих драйверов
	/// @param speed ШИМ в диапазоне 0 ... 255
	void setSpeed(int speed);


	/// @brief Установка скорости движения для одного драйвера
	/// @param speed ШИМ в диапазоне 0 ... 255
	/// @param driver Выбор драйвера
	void setSpeed(int speed, CUR_DRIVER driver);

	/** 
	 * @brief Установка параметров движения с ускорением
	 * @param speedUpTimer Время разгона > 50ms
	 * @param numSteps Количество шагов уровней ШИМ.
	 * Время разгона и число 256 должно делиться на это число без остатка
	 */
	void setAccelerationParams(const uint16_t speedUpTimer, const uint16_t numSteps);


protected:

	void _dir(MOVE_DIR dir);
	void _move();
	void _stop();

	/// @brief Указатель на объект левого мотора
	InterDriver *leftDriver;

	/// @brief Указатель на объект правого мотора
	InterDriver *rightDriver;

	/// @brief Настройки движения с ускорением
	AccelerationConfig accelerationConfig;
};

#endif
