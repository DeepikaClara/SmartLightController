/*Method 2: Light Sensor Based Automation 
Problem 2.1 – Ambient Light Measurement- The system must understand day and night conditions.
Solution: Read an LDR sensor and display its value.

Expected Output LDR Value : 180

C Concepts: Variables, Arithmetic Operations.
Embedded Concepts: ADC, Analog Input Reading, LDR Interfacing.
*/
uint8_t ldr_pin =4;
uint8_t led_pin = 8;
boolean led_state = LOW;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr_pin,INPUT);
pinMode(led_pin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
boolean val = digitalRead(ldr_pin);

if(val == HIGH)
{
  digitalWrite(led_pin,HIGH);
  Serial.println("Darkness- so turning ON the LED!");
}
else if( val == LOW)
{
  digitalWrite(led_pin,LOW);
  Serial.println("Brightness - so turning OFF the LED!");
}
}
