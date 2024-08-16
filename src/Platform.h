#ifndef Platform_H
#define Platform_H

#include <Interfaces.h>

typedef enum
{
	FORWARD,  // Движение вперед
	BACKWARD, // Движение назад

	FORWARD_LEFT,  // Движение вперед с поворотом налево
	FORWARD_RIGHT, // Движение вперед с поворотом направо

	BACKWARD_LEFT,	// Движение назад с поворотом налево
	BACKWARD_RIGHT, // Движение назад с поворотом направо

	ROTATE_LEFT, // Поворот на месте против часовой стрелки
	ROTATE_RIGHT // Поворот на месте по часовой стрелке

}DIR;

typedef enum 
{
	LEFT,
	RIGHT
}DRIVER;

class Platform
{
public:
	Platform(InterDriver *leftDriverRef, InterDriver *rightDriverRef);

	~Platform();

	void stop();
	void stop(uint16_t del);

	void accstop();

	void diffSpeed(int L, int R);

	void move(DIR dir);
	void move(DIR dir, uint16_t del);

	void setAccMode(bool mode);
	void setAccVal(int acc);

	void setSpeed(int speed);
	void setSpeed(int speed, DRIVER driver);


protected:
	void _move(DIR dir);
	void _stop();

	bool accMode;
	int accVal;
	int curSpeed;
	int acc;

	int movingTime;
	int timeInterval;
	bool mv; // need moving?
	int minSpeed = 0;
	int spm;

	InterDriver *leftDriver;
	InterDriver *rightDriver;
};

#endif
