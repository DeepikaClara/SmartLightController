/*Method 3: Intelligent Day-Night Controller 
Problem 3.1 – Adjustable Darkness Threshold- Every installation location has different lighting conditions.
Solution: Allow the user to set the darkness threshold through Serial Monitor.

Expected Output Enter Threshold: 200 | Threshold Updated

C Concepts: User Input, Variables, Validation.
Embedded Concepts: UART Input, Runtime Configuration.
Comments: Not implemented , since using Digital o/p LDR.
----------------------------------------------- 
Problem 3.2 – Stable Decision Making- Sensor readings can fluctuate and cause frequent ON/OFF switching.
Solution:Turn ON only when the sensor remains dark for 5 continuous seconds.

Expected Output Darkness Detected |Waiting...|Light ON

C Concepts: Counters, Time Tracking. 
Embedded Concepts: Debouncing for Sensors, Sampling Logic. 
------------------------------
Problem 3.3 – Intelligent Daylight Shutdown

A temporary flashlight or vehicle light should not switch OFF the system.

What exactly must the system do?

Turn OFF only when brightness remains above threshold for 5 seconds.

Expected Output Brightness Stable

Light OFF

C Concepts Boolean Logic Program Flow Embedded Concepts Sensor Filtering ADC Monitoring Problem 3.4 – Decision Reporting System Why are we building it?

Developers need traceability for automated decisions.

What exactly must the system do?

Display sensor value, threshold, decision, and reason.

Expected Output LDR : 165

Threshold : 200

Decision : ON

Reason : Darkness Detected

C Concepts Functions String Handling Embedded Concepts Serial Reporting Debugging Techniques
*/
uint8_t ldr_pin =4;
uint8_t led_pin= 8;

boolean temp_ldr =LOW;
//boolean initial_ldr=LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr_pin, INPUT);
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);

}
/*
1.get current ldr state
2.test for next 5 seconds each 1 second time gap, whether ldr is giving same output
  a.If yes, fix that output for ldr and control the led.
  b.If No or inbetween 5 seconds ldr output shifts, stop the validation then and there and fix that ldr ouput and repeat the iteration(step 2)
*/
boolean ldr_state()
  {
    boolean initial_ldr = digitalRead(ldr_pin);
    return initial_ldr;
  }
void loop() 
{
  // put your main code here, to run repeatedly:
  uint8_t counters;
  boolean stable = true;
  boolean current_ldr= ldr_state();
  //for(start_time=millis();(millis()-start_time)<=5000;counters++)
  for(counters =1;counters<=5;counters++)
  {
  
    delay(1000);
    temp_ldr = ldr_state();
    if(temp_ldr == current_ldr)
    {
      Serial.println(("Stability Check, please wait..."));
    
    }
    else
    {
      Serial.println("Signal is non stable!");
      stable = false;
      break;
      
    }
  }
  if(stable)
  {
    if(current_ldr == HIGH)
    {
      Serial.println("Stable Darkness.. LED is ON!");
      digitalWrite(led_pin,HIGH);
    }
    else 
    {
      Serial.println("Stable Brightness.. LED is OFF!");
      digitalWrite(led_pin,LOW);
    }
  }


}
