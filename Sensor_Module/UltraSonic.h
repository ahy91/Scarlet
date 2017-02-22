class UltraSonic {
private:
	bool is_available;
	int trig_pin;
	int echo_pin;
	
	float distance;
	
public:
	UltraSonic(int trig_pin, int echo_pin);
	void InitSensor();
	float GetDuration();
	float GetDistance();
	bool IsAvailable();
};