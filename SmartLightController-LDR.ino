/*Method 2: Light Sensor Based Automation 
Problem 2.1 – Ambient Light Measurement- The system must understand day and night conditions.
Solution: Read an LDR sensor and display its value.

Expected Output LDR Value : 180

C Concepts: Variables, Arithmetic Operations.
Embedded Concepts: ADC, Analog Input Reading, LDR Interfacing.
-------
Problem 2.2 – Darkness Detection - A light should react to environmental conditions.
Solution: Compare LDR value against a threshold and determine: BRIGHT or DARK

Expected Output LDR Value : 150 ; Environment : DARK

C Concepts: Comparison Operators, if-else.
Embedded Concepts: ADC Processing, Sensor Calibration.
-----------------
Problem 2.3 – Automatic Light Control- The owner wants lighting automation without manual intervention.
Solution: If DARK Light ON and If BRIGHT Light OFF

Expected Output Environment : DARK; Light Status : ON

C Concepts: Decision Making, Logical Conditions.
Embedded Concepts: Sensor Driven Control, GPIO Output.
--------- 
Problem 2.4 – Sensor Dashboard-Developers must verify system behavior during testing.
Display: LDR Value Environment; State LED Status 

Expected Output LDR : 210 & Environment : DARK ; LED : ON

C Concepts: Functions, Modular Programming.
Embedded Concepts: Serial Communication, Sensor Monitoring
Since using HW-072- photosensitive Light Detection Resistor which has inbuilt potentiometer and comparator for ADC, no thresold concept required
and so ouput will be 1 for dark and 0 for bright from LDR
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
