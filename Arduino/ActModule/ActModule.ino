int motor_direction = 2;
int motor_pwm = 4;

void setup()
{
  pinMode(motor_direction, OUTPUT);
  pinMode(motor_pwm, OUTPUT);

  digitalWrite(motor_direction, HIGH);
}
 
void loop()
{
  digitalWrite(motor_pwm, HIGH);
}
