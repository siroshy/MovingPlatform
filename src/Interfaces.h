#ifndef Iterfaces_H
#define Iterfaces_H

#include <Arduino.h>

/// @brief Направление движения/режим работы
enum DRIVER_DIR{
	IDLE,        // Отпущено
	ROT_LEFT,    // Вращение влево/вперед
	ROT_RIGHT,   // Вращение вправо/назад
	ACTIVE_BREAK // Активный тормоз
};

/// @brief Родительский класс для драйверов
class InterDriver
{
public:
	//InterDriver();
	//virtual ~InterDriver();

//=============================================================================
// Направление

	/// @brief Установка направления
	/// @param dir Направление из списка
	virtual void setDirection(DRIVER_DIR dir) = 0; 
	
	/// @brief Перманентрная инверсия вращения
	/// @param inv true - инверсия, false - прямое
	virtual void invDirection(bool inv);

//=============================================================================
// Скорость


	/// @brief Перманентное смещение значения ШИМ
	/// @param offset Смещение в диапазоне -254 ... 254
	virtual void speedOffset(int offset);
	

	/// @brief Установка текущего значения ШИМ
	/// @param duty Значение ШИМ в диапазоне 0 ... 255
	virtual void setOperationPWM(int duty) = 0;

//=============================================================================
// Выполнение команды


	/// @brief Обновить данные и выполнить команду
	virtual void startMove() = 0;

protected:

	bool invDirect;

	int direction;
	int speed;
	int speedOffsetValue;
	int operationPWM;

};


#endif
