void initialize()
{
  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);
  pinMode(speedpin1, OUTPUT);
  pinMode(speedpin2, OUTPUT);
  pinMode(encod1_1, INPUT);
  pinMode(encod1_2, INPUT);
  pinMode(encod2_1, INPUT);
  pinMode(encod2_2, INPUT);
  lcd.init();
  lcd.backlight();
}