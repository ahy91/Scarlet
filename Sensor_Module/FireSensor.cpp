#include <FireSensor.h>
#include <Arduino.h>

FireSensor::FireSensor()
{
	init();
}
FireSensor::FireSensor(int fire_pin)
{
	init();
	this.fire_pin = fire_pin;
}
void FireSensor::init()
{
	pinMode(fire_pin, INPUT);
}
int FireSensor::getValue()
{
	return analogRead(fire_pin);
}