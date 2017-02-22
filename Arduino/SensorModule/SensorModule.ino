#include <Bluetooth.h>
#include <FireSensor.h>
#include <Temperature.h>
#include <UltraSonic.h>

//#include <SoftwareSerial.h>

void setup()
{
  int temp_pin = -1;    // 설정해야 함
  Temperature temp_sensor = Temperature(temp_pin);    // 온도 센서

  int us_trig_pin = -1;   // 설정해야 함
  int us_echo_pin = -1;   // 설정해야 함
  UltraSonic us_sensor = UltraSonic(us_trig_pin, us_echo_pin);    // 초음파 센서

  int fire_pin = -1;    // 설정해야 함
  int thresh = -1;    // 설정해야 함
  FireSensor fire_sensor = FireSensor(fire_pin);    // 화재 센서
  fire_sensor.SetThresh(thresh);
}
 
void loop()
{
  // 온도 출력
  Serial.print("온도: ");
  int temp = temp_sensor.GetTemp();
  Serial.println(temp);

  // 화재 감지
  if (fire_sensor.DetectFire()) {
    Serial.println("FIRE!!");
  }

  // 초음파 센서
  float dist = us_sensor.GetDistance();
  Serial.print("거리는: ");
  Serial.println(dist);

  // 수집한 정보를 블루투스로 전송한다.
  // ...
}
