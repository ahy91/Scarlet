class FireSensor {
private:
	int fire_pin;
	int thres;

public:
	FireSensor();
	FireSensor(int fire_pin);

	int getValue();
};