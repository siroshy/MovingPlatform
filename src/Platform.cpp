#ifndef Platform_rel
#define Platform_rel

#include <Platform.h>

Platform::Platform(InterDriver *leftDriverRef, InterDriver *rightDriverRef)
{
	leftDriver = leftDriverRef;
	rightDriver = rightDriverRef;
};

Platform::~Platform()
{
}

void Platform::stop()
{
	_stop();
};

void Platform::stop(uint16_t del)
{
	_stop();
	delay(del);
};

void Platform::accstop()
{
	leftDriver->setDirection(3);
	rightDriver->setDirection(3);
	rightDriver->startMove();
	leftDriver->startMove();
};

void Platform::move(DIR dir)
{
	_move(dir);
}

void Platform::move(DIR dir, uint16_t del)
{
	_move(dir);
	delay(del);
}

void Platform::diffSpeed(int L, int R)
{
	if (L > 0)
	{
		leftDriver->setDirection(DRIVER_DIR::FORWARD);
		leftDriver->setOperationPWM(L);
	}
	else
	{
		leftDriver->setDirection(DRIVER_DIR::BACKWARD);
		leftDriver->setOperationPWM(-1 * L);
	}

	if (R > 0)
	{
		rightDriver->setDirection(DRIVER_DIR::FORWARD);
		rightDriver->setOperationPWM(R);
	}
	else
	{
		rightDriver->setDirection(DRIVER_DIR::BACKWARD);
		rightDriver->setOperationPWM(-1 * R);
	}

	rightDriver->startMove();
	leftDriver->startMove();
}

void Platform::_stop()
{
	leftDriver->setDirection(DRIVER_DIR::IDLE);
	rightDriver->setDirection(DRIVER_DIR::IDLE);
	rightDriver->startMove();
	leftDriver->startMove();
};

void Platform::_move(DIR dir)
{
	switch (dir)
	{
	case DIR::FORWARD:
		leftDriver->setDirection(DRIVER_DIR::FORWARD);
		rightDriver->setDirection(DRIVER_DIR::FORWARD);
		break;

	case DIR::BACKWARD:
		leftDriver->setDirection(DRIVER_DIR::BACKWARD);
		rightDriver->setDirection(DRIVER_DIR::BACKWARD);
		break;

	case DIR::FORWARD_LEFT:
		leftDriver->setDirection(DRIVER_DIR::IDLE);
		rightDriver->setDirection(DRIVER_DIR::FORWARD);
		break;

	case DIR::FORWARD_RIGHT:
		leftDriver->setDirection(DRIVER_DIR::FORWARD);
		rightDriver->setDirection(DRIVER_DIR::IDLE);
		break;

	case DIR::BACKWARD_LEFT:
		leftDriver->setDirection(DRIVER_DIR::IDLE);
		rightDriver->setDirection(DRIVER_DIR::BACKWARD);
		break;

	case DIR::BACKWARD_RIGHT:
		leftDriver->setDirection(DRIVER_DIR::BACKWARD);
		rightDriver->setDirection(DRIVER_DIR::IDLE);
		break;

	case DIR::ROTATE_LEFT:
		leftDriver->setDirection(DRIVER_DIR::BACKWARD);
		rightDriver->setDirection(DRIVER_DIR::FORWARD);
		break;

	case DIR::ROTATE_RIGHT:
		leftDriver->setDirection(DRIVER_DIR::FORWARD);
		rightDriver->setDirection(DRIVER_DIR::BACKWARD);
		break;

	default:
		break;
	}

	rightDriver->startMove();
	leftDriver->startMove();
}

void Platform::setAccMode(bool mode)
{
	accMode = mode;
};

void Platform::setAccVal(int acc) {

};

void Platform::setSpeed(int speed)
{
	leftDriver->setOperationPWM(speed);
	rightDriver->setOperationPWM(speed);
};

void Platform::setSpeed(int speed, DRIVER driver)
{
	switch (driver)
	{
	case DRIVER::LEFT:
		leftDriver->setOperationPWM(speed);
		break;

	case DRIVER::RIGHT:
		rightDriver->setOperationPWM(speed);
		break;

	default:
		break;
	}
};

#endif
