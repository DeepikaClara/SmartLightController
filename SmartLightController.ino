//Smart Light Controller
/* Method 1: Basic Automatic Lighting Using Program Logic 
Problem 1.1 – Manual Light Control Why are we building it?

Before automating a house light, the developer must understand how to control an output device from Arduino.

When a push button is pressed, turn ON an LED. When the button is released, turn OFF the LED.

Expected Output Button Pressed

Light Status : ON

C Concepts: Variables, Data Types, if statements, Digital state handling 
Embedded Concepts: GPIO Input, GPIO Output, Push Button Interfacing, LED Control
-------------------------------------------------------
Problem 1.2 – Toggle Lighting Mode (skipped toggle setup, since planned to use latching switch, incase planning to use digital switch then toggle setup is required) Why are we building it?

Home owners normally expect a switch-like behavior instead of holding a button continuously.

What exactly must the system do?

Each button press should change the light state.

Press 1 → ON Press 2 → OFF Press 3 → ON

Expected Output Button Pressed

Light Status : ON

C Concepts Variables State Management Conditional Logic Embedded Concepts Button Debouncing Digital Inputs LED Output Control
-------------------------------------------------------------------------------------
Problem 1.3 – Lighting Status Monitor Why are we building it?

Users need visibility into the operation of the controller.

What exactly must the system do?

Display:Button State Light State over Serial Monitor.
Expected Output: Button -PRESSED & Light : ON

C Concepts: Functions, Formatted Printing Program Structure
Embedded Concepts: UART Communication, Serial Monitor
-----------------------------------------------------------------
Problem 1.4 – Configurable Auto OFF Timer Why are we building it?
Outdoor lights are often forgotten after switching ON.
Solution: After turning ON, keep the light active for 30 seconds and then automatically switch OFF.
Expected Output:  Light ON , Timer Running... ,Light OFF
C Concepts: Timers, Variables, Functions.
Embedded Concepts: millis(). Software Timing, Non-Blocking Design. 
*/
uint8_t button = 4;
uint8_t LED =8;
boolean last_led_state = LOW;
boolean led_state = LOW;
unsigned long start_time = 0;
void setup() 
{
  // put your setup code here, to run once:
pinMode(button,INPUT);
pinMode(LED,OUTPUT);
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:

/* Toggle LED-for push button or digital buttons using remote control types*/
boolean current_led_state = digitalRead(button);

if(current_led_state == HIGH && last_led_state == LOW)
{
 led_state = !led_state;
 digitalWrite(LED,led_state);
 start_time = millis();//fetches current time in milli second


}


if(led_state == HIGH)
{
  Serial.println("LED is ON");

}
else
{
Serial.println("LED is OFF");

}
 last_led_state = current_led_state;
  /*if time at which led started ON minus current millis()after sometime is greater than 30 seconds, LED will OFF automatically
    Before this 30 seconds if inbetween button is pressed, no issues, LED will off, because this if checks only if both led state and millis()-start time>=30000 both are true.*/ 
{
if((led_state== HIGH) && (millis()- start_time >= 30000) )
  led_state = LOW;
  digitalWrite(LED,led_state);
}


/* for latching switch

boolean val;
val = digitalRead(button);
if(val == HIGH)
{
  digitalWrite(LED,HIGH);
  Serial.println("LED is ON!");
}
else
{
  digitalWrite(LED,LOW);
  Serial.println("LED is OFF!");
}
*/

}
