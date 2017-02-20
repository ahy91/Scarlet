public class Temprature {
	private float temp;
	private int temp_sensor_pin = A0;
	
	public Temprature() {
		analogReference(INTERNAL);
	}
	
	public Temprature(int pin) {
		temp_sensor_pin = pin;	
		analogReference(INTERNAL);
	}
	
	public int GetTemp();
}