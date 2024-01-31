#define L256N
#include <MovingPlatform.h>
//using driver L298n
#define IN1 9 //pin for direction motor 1
#define IN2 8 //pin for direction motor 1
#define IN3 4 //pin for direction motor 2
#define IN4 3 //pin for direction motor 2
#define EN1 6 //pin speed for motor 1
#define EN2 5 //pin speed for motor 2

  DriverL256n LMotor(IN1,IN2,EN1); //configurating motor 1
  DriverL256n RMotor(IN3,IN4,EN2); //configurating motor 2

  Platform plat (&LMotor, &RMotor); //configurating platform with motor 1 and motor 2

void setup() {
  plat.setSpeed(130); //set speed for both motors
  LMotor.speedOffset(-10); //offset left motor speed -10
  LMotor.invDir(true); // inversion of direction for left motor 
}

void loop() {
  plat.moveFwrd(); //move forward for 1 second (↑↑)
  delay(1000);
  plat.moveBwrd(); //move backward for 1 second (↓↓)
  delay(1000);
  plat.turnLft(); //left motor stopped, right goes forward (.↑) for 1 secomd
  delay(1000);
  plat.turnRht(); //left motor goes forward, right stopped (↑.) for 1 second
  delay(1000);
  plat.turnBackLft(); //left motor stopped, right goes backward (.↓) for 1 second
  delay(1000);
  plat.turnBackRht(); //left motor goes backward, right stopped (↓.) for 1 second
  delay(1000);
  plat.circleLft(); //left motor goes backward, right goes forward (↓↑) for 1 second
  delay(1000);
  plat.circleRht(); //left motor goes forward, right goes backward (↑↓) for 1 second
  delay(1000);
  plat.stop(); //both motors stopped (..) for 1 second
  delay(1000);
}
