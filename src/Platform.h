#ifndef Platform_H
#define Platform_H

#include <Interfaces.h>

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

enum CUR_DRIVER
{
	LEFT_DRIVER,
	RIGHT_DRIVER
};

class Platform
{
public:
	Platform(InterDriver *leftDriverRef, InterDriver *rightDriverRef);

	~Platform();

	void stop();
	void stop(uint16_t del);

	void accstop();

	void diffSpeed(int L, int R);

	void move(MOVE_DIR dir);
	void move(MOVE_DIR dir, uint16_t del);

	void setAccMode(bool mode);
	void setAccVal(int acc);

	void setSpeed(int speed);
	void setSpeed(int speed, CUR_DRIVER driver);


protected:
	void _move(MOVE_DIR dir);
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
