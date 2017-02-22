#include <Arduino.h>
#include <Temperature.h>

Temperature::Temperature() {
	analogReference(INTERNAL);
}
	
Temperature::Temperature(int pin) {
	temp_sensor_pin = pin;	
	analogReference(INTERNAL);
}
	
int Temperature::GetTemp() {
	return analogRead(temp_sensor_pin) / 9.31;
}