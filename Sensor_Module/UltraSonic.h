public class UltraSonic {
	private int trig_pin;
	private int echo_pin;
	
	private float distance;
	
	public void UltraSonic(int trig_pin, int echo_pin);
	public void InitSensor();
	public float GetDuration();
	public float GetDistance();
}