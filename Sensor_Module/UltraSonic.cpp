#include <Arduino.h>
#include <UltraSonic.h>

UltraSonic::UltraSonic(int trig_pin, int echo_pin) {
	this->trig_pin = trig_pin;
	this->echo_pin = echo_pin;
}
	
void UltraSonic::InitSensor() {
	digitalWrite(trig_pin, HIGH);
	delay(10);
	digitalWrite(trig_pin, LOW);
}

float UltraSonic::GetDuration() {
	return pulseIn(echo_pin, HIGH);
}

float UltraSonic::GetDistance() {
	InitSensor();
	float result = ((float)(340 * GetDuration()) / 10000) / 2;
	delay(500);
	return result;
}