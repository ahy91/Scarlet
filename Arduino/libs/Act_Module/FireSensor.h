class FireSensor {
private:
	int fire_pin;
	int thres;
	int thresh;

public:
	FireSensor();
	FireSensor(int fire_pin);

	int GetValue();
	void SetThresh(int v);
	bool DetectFire();
};