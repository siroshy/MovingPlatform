float setpoint = 3000;
float kp = 0;
float ki = 0;
float kd = 0;
float dt = 0;
int minOut = 0;
int maxOut = 0;

int computePID(float input, float setpoint, float kp, float ki, float kd, float dt, int minOut, int maxOut) {
  float err = setpoint - input;
  static float integral = 0, prevErr = 0;
  integral = constrain(integral + (float)err * dt * ki, minOut, maxOut);
  float D = (err - prevErr) / dt;
  prevErr = err;
  return constrain(err * kp + integral + D * kd, minOut, maxOut);
}

//если мотор с энкодером
//чтение показаний энкодера
void en_counter() {
if(digitalRead(enc2)) fl = true;
 if(!digitalRead(enc1)&& fl){
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
void setup() {
  // put your setup code here, to run once:
  pinMode(enc1, INPUT);
  pinMode(enc2, INPUT);


 Serial.begin(9600);
tmr = millis();
}
void loop() {
  // put your main code here, to run repeatedly:
en_counter();
plat.setSpeed(255);
plat.moveFwrd();
en_counter();
delay(1000);
plat.movebwrd();
en_counter();
delay(1000);
}
