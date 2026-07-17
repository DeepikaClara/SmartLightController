# Smart Light Controller – Arduino Based  

## 📌 Overview  
This project aims to design a **smart backyard lighting system** using Arduino. The system automatically controls a high-brightness LED bulb based on ambient light, time schedules, and human motion detection. It is intended as a beginner-to-intermediate embedded systems project, moving from breadboard prototyping to real-world usage.  

---

## 🎯 Problem Statements  

### **Problem Statement 1: LDR-Based Light Control**  
- **Goal**: Glow the bulb automatically when it is dark.  
- **Inputs**: LDR sensor (light intensity).  
- **Outputs**: LED bulb (via relay).  
- **Logic**: If ambient light < threshold, switch ON bulb; else OFF.  
- **Learning Focus**: Analog sensor reading, voltage divider, relay control for high-voltage bulb.  

---

### **Problem Statement 2: Time-Based Control**  
- **Goal**: Switch OFF the bulb automatically at 7:30 PM IST.  
- **Inputs**: RTC module (DS3231).  
- **Outputs**: LED bulb (via relay).  
- **Logic**: At 7:30 PM, force bulb OFF regardless of LDR reading.  
- **Learning Focus**: RTC integration, scheduled tasks, combining sensor + time logic.  

---

### **Problem Statement 3: Motion-Triggered Lighting**  
- **Goal**: After 7:30 PM, bulb should switch ON automatically if motion is detected.  
- **Inputs**: PIR motion sensor.  
- **Outputs**: LED bulb (via relay).  
- **Logic**: If motion detected after 7:30 PM, turn bulb ON for a fixed duration (e.g., 30 seconds).  
- **Learning Focus**: Digital sensor input, conditional logic, timed events.  

---

### **Problem Statement 4: Real-World Deployment**  
- **Goal**: Move from breadboard prototype to backyard installation.  
- **Inputs/Outputs**: Same as above, but with proper wiring, casing, and safety measures.  
- **Logic**: Integrate all features (LDR + RTC + PIR + relay).  
- **Learning Focus**: System integration, safety with AC voltage, environmental robustness.  

---

## 🛠️ Components Required  
- Arduino Uno  
- LDR sensor + 10kΩ resistor  
- Relay module (optocoupler isolated)  
- RTC DS3231 module  
- PIR motion sensor  
- High-brightness LED bulb (220V AC)  
- Breadboard, jumper wires, casing for deployment  

---
