#include "LiquidCrystal_I2C.h"
#include "variables.h"
#include "init.h"
#include "motor_move.h"
void setup() {
  initialize();
  // initializing of interrupts
  int interruptPoint1 = digitalPinToInterrupt(encod1_1);
  attachInterrupt(interruptPoint1, motor1_interrupt, RISING);
  int interruptPoint2 = digitalPinToInterrupt(encod2_1);
  attachInterrupt(interruptPoint2, motor2_interrupt, RISING);
  Serial.begin(9600);
}
void loop() {
  if (start)
  {
    M_move_directed(motor2_1,motor2_2,1);
    M_move_directed(motor1_1,motor1_2,1);
    start = 0;
  }
  float motor1_rate = interruptCounter1/7/14.5*1.15;
  float motor2_rate = interruptCounter2/7/14.5*1.15;
  speed = 100;
  analogWrite(speedpin1, speed);
  analogWrite(speedpin2, speed);
  // if distance is not gone then motor moves
  if (1-isDistanceGone(motor2_rate,18)) {M_move_directed(motor2_1,motor2_2,1);}
  else {M_move_directed(motor2_1,motor2_2,0);}
  if (motor1_rate > 3) {M_move_directed(motor1_1,motor1_2,-1);}
  else if (motor1_rate < 0) {M_move_directed(motor1_1,motor1_2, 1);}
  
  lcd.setCursor(0,0);
  lcd.print(motor1_rate);
  lcd.setCursor(0,1);
  lcd.print(motor2_rate);
}
void motor1_interrupt()
{
  if (digitalRead(encod1_2))
    {interruptCounter1 += 1;}
  else {interruptCounter1-=1;}
}
void motor2_interrupt()
{
  if (digitalRead(encod2_2))
    {interruptCounter2 += 1;}
  else {interruptCounter2-=1;}
}