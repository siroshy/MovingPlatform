#include <Interfaces.h>
#include <Driver_L256n>
#include <L256nPlatform.h>

int LineL=10;
int LineR=11;

  DriverL256n LMotor(6,7,14);
  DriverL256n RMotor(8,9,16);

  L256nPlatform plat (&LMotor, &RMotor);

int ena = 2;
int enb = 3;
int ena1 = 4;
int enb1 = 5;
uint32_t tmr;

void enc()
{
  if(digitalRead(ena)) fl = true;
 if(!digitalRead(ena)&& fl){
   fl = false;
   cnt++;
 }
// Serial.println(cnt);
 if(millis()- tmr > 1000 ){
  tmr = millis();
  Serial.print(cnt/7*60);
  Serial.print("|");
  Serial.println(cnt/7*60/150);
  cnt = 0;
 }
}
  void setup()
  {
pinMode(ena, INPUT);
pinMode(enb, INPUT);
Serial.begin(9600);
tmr = millis();
pinMode(LineL, INTPUT);
pinMode(LineR, INTPUT);
  }
long int cnt = 0;
bool fl = false;
  void loop()
  {
if (LineL&&LineR)
 {
plat.stop();
  }
 else if(!LineL&&LineR)
 {
 	plat.turnLft();
  enc();
 }
 else if(LineL&&!LineR)
 {
 	plat.turnRht();
  enc();
 }
 else if(!LineL&&!LineR)
 {
 	plat.moveFrwd();
  enc();
 }
}
