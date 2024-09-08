#ifndef Platform_rel
#define Platform_rel

#include <Platform.h>

Platform::Platform(InterDriver *leftDriverRef, InterDriver *rightDriverRef)
{
	leftDriver = leftDriverRef;
	rightDriver = rightDriverRef;
	setAccelerationParams(250, 64);
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


void Platform::move(MOVE_DIR dir)
{
	_dir(dir);
	_move();
}

void Platform::move(MOVE_DIR dir, uint16_t del, uint16_t targetSpeed, bool accelMove = false)
{
	
	_dir(dir);
	uint16_t speedStep = targetSpeed / accelerationConfig.numSteps;
	if (accelMove)
	{
		for (int i = 0; i < accelerationConfig.numSteps; i++)
		{
			setSpeed(speedStep * i);
			_move();
		}
	}
	setSpeed(targetSpeed);
	_move();
	delay(del - accelerationConfig.speedUpTimer);
}

void Platform::diffSpeed(int L, int R)
{
	if (L > 0)
	{
		leftDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		leftDriver->setOperationPWM(L);
	}
	else
	{
		leftDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		leftDriver->setOperationPWM(-1 * L);
	}

	if (R > 0)
	{
		rightDriver->setDirection(DRIVER_DIR::ROT_RIGHT);
		rightDriver->setOperationPWM(R);
	}
	else
	{
		rightDriver->setDirection(DRIVER_DIR::ROT_RIGHT);
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

void Platform::setAccelerationParams(const uint16_t speedUpTimer, const uint16_t numSteps)
{
	accelerationConfig.numSteps = numSteps;
	accelerationConfig.speedUpTimer = speedUpTimer;
	accelerationConfig.stepDelay = speedUpTimer / numSteps;
}

void Platform::_dir(MOVE_DIR dir)
{
	switch (dir)
	{
	case MOVE_DIR::FORWARD :
		leftDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		rightDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		break;

	case MOVE_DIR::BACKWARD :
		leftDriver->setDirection(DRIVER_DIR::ROT_RIGHT);
		rightDriver->setDirection(DRIVER_DIR::ROT_RIGHT);
		break;

	case MOVE_DIR::FORWARD_LEFT :
		leftDriver->setDirection(DRIVER_DIR::IDLE);
		rightDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		break;

	case MOVE_DIR::FORWARD_RIGHT :
		leftDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		rightDriver->setDirection(DRIVER_DIR::IDLE);
		break;

	case MOVE_DIR::BACKWARD_LEFT :
		leftDriver->setDirection(DRIVER_DIR::IDLE);
		rightDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		break;

	case MOVE_DIR::BACKWARD_RIGHT :
		leftDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		rightDriver->setDirection(DRIVER_DIR::IDLE);
		break;

	case MOVE_DIR::CIRCLE_LEFT :
		leftDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		rightDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		break;

	case MOVE_DIR::CIRCLE_RIGHT :
		leftDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		rightDriver->setDirection(DRIVER_DIR::ROT_LEFT);
		break;

	default:
		break;
	}
}

void Platform::_move()
{
	rightDriver->startMove();
	leftDriver->startMove();
}

void Platform::setSpeed(int speed)
{
	leftDriver->setOperationPWM(speed);
	rightDriver->setOperationPWM(speed);
};

void Platform::setSpeed(int speed, CUR_DRIVER driver)
{
	switch (driver)
	{
	case CUR_DRIVER::LEFT_DRIVER:
		leftDriver->setOperationPWM(speed);
		break;

	case CUR_DRIVER::RIGHT_DRIVER:
		rightDriver->setOperationPWM(speed);
		break;

	default:
		break;
	}
};

#endif
