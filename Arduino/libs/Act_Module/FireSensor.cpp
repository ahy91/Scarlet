#include <FireSensor.h>
#include <Arduino.h>

FireSensor::FireSensor()
{
	pinMode(fire_pin, INPUT);
	thresh = 50;
}
FireSensor::FireSensor(int fire_pin)
{
	FireSensor();
	this->fire_pin = fire_pin;
}
int FireSensor::GetValue()
{
	return analogRead(fire_pin);
}
void FireSensor::SetThresh(int v)
{
	thresh = v;
}
bool FireSensor::DetectFire()
{
	if (thresh < GetValue()) {
		return true;
	}
	
	return false;
}