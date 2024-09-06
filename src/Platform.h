#ifndef Platform_H
#define Platform_H

#include <Interfaces.h>

/// @brief Направление движения
enum MOVE_DIR
{
	FORWARD,  // Движение вперед
	BACKWARD, // Движение назад

	FORWARD_LEFT,  // Движение вперед с поворотом налево
	FORWARD_RIGHT, // Движение вперед с поворотом направо

	BACKWARD_LEFT,	// Движение назад с поворотом налево
	BACKWARD_RIGHT, // Движение назад с поворотом направо

	CIRCLE_LEFT, // Поворот на месте против часовой стрелки
	CIRCLE_RIGHT // Поворот на месте по часовой стрелке

};

/// @brief Выбор драйвера
enum CUR_DRIVER
{
	LEFT_DRIVER,
	RIGHT_DRIVER
};


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
	 * @param del Задержка для исполнения команды
	 */
	void stop(uint16_t del);

//-----------------------------------------------------------------------------
	/**
	 * @brief Двигаться
	 * @param dir Направление движения из списка
	 */
	void move(MOVE_DIR dir);

	/**
	 * @brief Двигаться
	 * @param dir Направление движения из списка
	 * @param del Задержка для исполнения команды
	 */
	void move(MOVE_DIR dir, uint16_t del);

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


protected:
	void _move(MOVE_DIR dir);
	void _stop();

	InterDriver *leftDriver;
	InterDriver *rightDriver;
};

#endif
