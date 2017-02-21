public class FireSensor {
	private int fire_pin;
	private int thres;
	
	public FireSensor();
	public FireSensor(int fire_pin);

	public void init();
	public int getValue();
}