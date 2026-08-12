/*
Method 4: Motion-Aware Energy Saving
Problem 4.1 – Motion Detection-Lights should operate only when people are present.
Solution: Read motion status from a PIR sensor.

Expected Output: Motion Detected

C Concepts: Variables, State Tracking.
Embedded Concepts: PIR Sensor, Interface, Digital Inputs. 
-----------------------------
Problem 4.2 – Motion Controlled Lighting - Nobody wants lights ON in an empty area.
Solution: Dark + No Motion = OFF

Expected Output Environment : DARK | Motion : YES | Light : ON

C Concepts: Nested Conditions, Boolean Logic. 
Embedded Concepts: Sensor Fusion, Multi-Input Decisions. 
-----------------------------
Problem 4.3 – Delayed Shutdown - Lights should remain ON briefly after someone leaves.
Solution: Switch OFF 30 seconds after the last detected motion.

Expected Output No Motion | Shutdown In Progress... | Light OFF

C Concepts: Timers, Counters. 
Embedded Concepts: millis(), Embedded Timing. 
--------------------------------
Problem 4.4 – Energy Saving Statistics - Users want proof that automation reduces energy consumption.
Solution:
Display: Motion Count, Light ON Duration, Estimated Energy Saved. 

Expected Output Motion Events : 25 | ON Duration : 72 Minutes | Energy Saved : 18%

C Concepts: Calculations, Accumulators, Counters. 
Embedded Concepts: Runtime, Logging Data Collection.
*/
const uint8_t pir_pin = 8;
const uint8_t led_pin = 4;
unsigned long wait_time_off = 5000;
bool previous_pir_state= LOW;
bool led_reset= 0;
unsigned long timer=0;

void setup() {
  // put your setup code here, to run once:
pinMode(pir_pin,INPUT);
pinMode(led_pin,OUTPUT);
uint8_t calibration_time = 3;//time required for the sensor to stabilize after getting power, so that false detections will be avoided.

Serial.begin(9600);
Serial.println("PIR Sensor under calibration...");
delay(calibration_time * 1000);
Serial.println("PIR Sensor is ACTIVE!..");
}

void loop() {
  // put your main code here, to run repeatedly:
  bool current_pir_state = digitalRead(pir_pin);
  

  if((previous_pir_state ==LOW ) && (current_pir_state == HIGH))
  {
    Serial.println("Motion Detection");
      digitalWrite(led_pin, HIGH);
      Serial.println("LED is ON...");
      //led_reset = 1;
      previous_pir_state = HIGH;
  
  }
  else if((previous_pir_state == HIGH ) && (current_pir_state == LOW ) )
  {
   Serial.println("Motion Ended");
   timer = millis();
   Serial.print("Timer Started at:");
   Serial.println(timer);
   previous_pir_state = LOW;
   led_reset=0;
  }
//Serial.println(millis());
//delay(1000);
if((current_pir_state == LOW ) && ((millis() - timer)> wait_time_off) && (led_reset ==0))
    {
       Serial.println("No Motion Confirmed..");
      digitalWrite(led_pin, LOW);
      Serial.println("LED is OFF...");
      led_reset = 1;
      
    }

}

/*
Reregister H:
    When pir detected movement, it will be high all the time.
Non-Reregister L:
    Eventhough pir detected continous movement, it will turn low after sometime, depending on the potentiometer adjustment. 
    potentiometer rotated to clkwise, to inc the time delay in tuning off pir state to low.

*/
