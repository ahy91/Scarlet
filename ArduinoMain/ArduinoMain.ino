#include <Bluetooth.h>
#include <FireSensor.h>
#include <Temperature.h>
#include <UltraSonic.h>

#include <SoftwareSerial.h>

void setup()
{
  int temp_pin = -1;    // 설정해야 함
  Temperature temp_sensor = Temperature(temp_pin);    // 온도 센서

  int us_trig_pin = -1;   // 설정해야 함
  int us_echo_pin = -1;   // 설정해야 함
  UltraSonic us_sensor = UltraSonic(us_trig_pin, us_echo_pin);    // 초음파 센서

  int fire_pin = -1;    // 설정해야 함
  FireSensor fire_sensor = FireSensor(fire_pin);    // 화재 센서
}
 
void loop()
{
    
}
