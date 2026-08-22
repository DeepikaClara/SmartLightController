/*
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
*/
const uint8_t pir_pin = 7;
const uint8_t led_pin = 8;
const uint8_t ldr_pin = 4;
unsigned long wait_time_off = 5000;
bool previous_pir_state= LOW;
bool led_reset= 0;
unsigned long timer=0;

void setup() {
  // put your setup code here, to run once:
pinMode(pir_pin,INPUT);
pinMode(ldr_pin,INPUT);
pinMode(led_pin,OUTPUT);
uint8_t calibration_time = 3;//time required for the sensor to stabilize after getting power, so that false detections will be avoided.

Serial.begin(9600);
Serial.println("PIR Sensor under calibration...");
delay(calibration_time * 1000);
Serial.println("PIR Sensor is ACTIVE!..");
}

bool ldr_state()
  {
    bool initial_ldr = digitalRead(ldr_pin);
    return initial_ldr;
  }
void loop() {
  // put your main code here, to run repeatedly:

  uint8_t counters;
  bool stable = true;
  bool temp_ldr = LOW;
  bool current_ldr= ldr_state();
  
  //for(start_time=millis();(millis()-start_time)<=5000;counters++)
  for(counters =1;counters<=5;counters++)
  {
  
    delay(1000);
    temp_ldr = ldr_state();
    if(temp_ldr == current_ldr)
    {
      Serial.print("current_ldr:");
      Serial.println(current_ldr);
      Serial.println(("Stability Check, please wait..."));
      Serial.print("counters:");
      Serial.println(counters);
    
    }
    else
    {
      Serial.print("current_ldr:");
      Serial.println(current_ldr);
      Serial.println("Signal is non stable!");
      Serial.print("counters:");
      Serial.println(counters);
      stable = false;
      break;
      
    }
  }
  
  if(stable)
  {
    bool current_pir_state = digitalRead(pir_pin);
    if((previous_pir_state ==LOW ) && (current_pir_state == HIGH))
  {
    Serial.println("Motion Detection");
    Serial.println("Current_ldr:");
    Serial.println(current_ldr);
    if(current_ldr == HIGH)
    {
      Serial.println("Stable Darkness.. LED is ON!");
      digitalWrite(led_pin,HIGH);
    }
      //digitalWrite(led_pin, HIGH);
      //Serial.println("LED is ON...");
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
  if((current_pir_state == LOW ) && ((millis() - timer)> wait_time_off) && (led_reset ==0))
    {
      Serial.println("No Motion Confirmed..");
      Serial.println("Stable Brightness.. LED is OFF!");
      digitalWrite(led_pin,LOW);
      //digitalWrite(led_pin, LOW);
      //Serial.println("LED is OFF...");
      led_reset = 1;
      
    }

}
  
  
//Serial.println(millis());
//delay(1000);

}
