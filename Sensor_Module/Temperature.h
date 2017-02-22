class Temperature {
private:
	float temp;
	int temp_sensor_pin;
	
public:
	Temperature();
	Temperature(int pin);
	
	int GetTemp();
};