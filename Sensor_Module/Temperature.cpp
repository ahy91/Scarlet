#include <Arduino.h>
#include <Temprature.h>

Temprature::Temprature() {
	analogReference(INTERNAL);
}
	
Temprature::Temprature(int pin) {
	temp_sensor_pin = pin;	
	analogReference(INTERNAL);
}
	
int Temprature::GetTemp() {
	return analogRead(temp_sensor_pin) / 9.31;
}