#define DRIVER_TYPE L298N
#include <MovingPlatform.h>
// using driver L298n
#define IN1 9 // pin for direction motor 1
#define IN2 8 // pin for direction motor 1
#define IN3 4 // pin for direction motor 2
#define IN4 3 // pin for direction motor 2
#define EN1 6 // pin speed for motor 1
#define EN2 5 // pin speed for motor 2

DriverL298n LMotor(IN1, IN2, EN1); // configurating motor 1
DriverL298n RMotor(IN3, IN4, EN2); // configurating motor 2

Platform plat(&LMotor, &RMotor); // configurating platform with motor 1 and motor 2

void setup()
{
  plat.setAccelerationParams(1000, 128);
}

void loop()
{
  //=================================================================
  // move forward for 3 second (↑↑)
  plat.move(MOVE_DIR::FORWARD, 3000, 128, 1);

  //=================================================================
  // move backward for 3 second (↓↓)
  plat.move(MOVE_DIR::BACKWARD, 3000, 128, 1);

  plat.stop(1000);
}
