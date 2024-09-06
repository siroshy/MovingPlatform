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
  plat.setSpeed(130);        // set speed for both motors
  LMotor.speedOffset(-10);   // offset left motor speed -10
  LMotor.invDirection(true); // inversion of direction for left motor
}

void loop()
{
  //=================================================================
  // move forward for 1 second (↑↑)
  plat.move(MOVE_DIR::FORWARD, 1000);

  //=================================================================
  // move backward for 1 second (↓↓)
  plat.move(MOVE_DIR::BACKWARD, 1000);

  //=================================================================
  // left motor stopped, right goes forward (.↑) for 1 secomd
  plat.move(MOVE_DIR::FORWARD_LEFT, 1000);

  //=================================================================
  // left motor goes forward, right stopped (↑.) for 1 second
  plat.move(MOVE_DIR::FORWARD_RIGHT, 1000);

  //=================================================================
  // left motor goes backward, right stopped (↓.) for 1 second
  plat.move(MOVE_DIR::BACKWARD_RIGHT, 1000);

  //=================================================================
  // left motor stopped, right goes backward (.↓) for 1 second
  plat.move(MOVE_DIR::BACKWARD_LEFT, 1000);

  //=================================================================
  // left motor goes backward, right goes forward (↓↑) for 1 second
  plat.move(MOVE_DIR::CIRCLE_LEFT, 1000);

  //=================================================================
  // left motor goes forward, right goes backward (↑↓) for 1 second
  plat.move(MOVE_DIR::CIRCLE_RIGHT, 1000);

  //=================================================================
  // both motors stopped (..) for 1 second
  plat.stop(1000);
}
