#include <FireSensor.h>
#include <Arduino.h>

FireSensor::FireSensor()
{
	pinMode(fire_pin, INPUT);
}
FireSensor::FireSensor(int fire_pin)
{
	FireSensor();
	this->fire_pin = fire_pin;
}
int FireSensor::getValue()
{
	return analogRead(fire_pin);
}