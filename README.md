# **Capacitive Soil Moisture Sensing and Automated Watering System**

Welcome to the GitHub repository for my **capacitive soil moisture sensing** and **automated irrigation system**. This project introduces an efficient method for monitoring soil moisture levels using a **capacitive sensing PCB** and automating irrigation using a **relay-controlled water pump**. The system is designed to optimize water usage in **gardening, agriculture, and precision farming**, ensuring plants receive adequate water while preventing overwatering. The system utilizes a Master-Slave communication approach between two Arduino devices, enabling seamless data collection and control.

By integrating **capacitance-based moisture detection** with an Arduino-based control system, this project demonstrates a **low-power, non-invasive**, and **cost-effective** approach to soil monitoring. The **LCD display** provides real-time feedback, while the system autonomously regulates watering cycles based on predefined soil moisture thresholds.

---

##  System Overview

### **Sensor System Image**
*(Insert Image Here)*

The project consists of two main Arduino programs:

**1. Master (Sensor) Arduino**
- Reads data from the capacitive soil moisture sensor.
- Displays soil readings on an LCD screen.
- Sends the moisture level data to the Slave Arduino via I2C communication.

**2. Slave (Watering System) Arduino**
- Receives moisture data from the Master Arduino.
- Controls the water pump and water valve using a relay module.
- Executes automated watering logic based on preset threshold values.


This setup enables **accurate moisture detection** and **automated water regulation** to maintain optimal soil hydration.

---

##  Hardware Requirements

To replicate this project, you will need:

- **Arduino Uno (x2)**
- **Custom PCB capacitive soil moisture sensor**
- **Adafruit MPR121 capacitive sensing IC**
- **16x2 I2C LCD Display**
- **Relay module (2-channel, 5V)**
- **12V DC Water Pump**
- **Whadda Water Valve (12V)**
- **12V Power Supply**
- **Jumper Wires**
- **HC-05 Bluetooth module**

---

##  Software Installation & Setup

### **Prerequisites**
Before getting started, ensure you have:
- **Arduino IDE (latest version)** – [Download Here](https://www.arduino.cc/en/software)
- **Basic knowledge of Arduino programming or C++ programming**

---

### **Installing Required Libraries**

#### **Arduino Libraries**
1. Open **Arduino IDE**
2. Install the following libraries via **Library Manager**:
   ```cpp
   #include <Wire.h>
   #include <Adafruit_MPR121.h>
   #include <rgb_lcd.h>
   ```
3. Connect your Arduino via USB and **upload the code**.

---

##  Setting Up the Hardware

1. **Connect the Capacitive Sensor to the Arduino**
2. **Wire the LCD Display (I2C SDA/SCL)**
3. **Connect the Relay Module to the Water Pump**
4. **Power the system using a 12V battery**
5. **Ensure proper wiring before uploading the code**

---

##  Running the System

### **Uploading Master Code**
1. Open the `Official_Master.ino` file in **Arduino IDE**
2. Select the correct board and port
3. Click **Verify** (✔️) and **Upload** (⏩)

### **Uploading Slave Code**
1. Open the `Official_Slave.ino` file in **Arduino IDE**
2. Select the correct board and port
3. Click **Verify** (✔️) and **Upload** (⏩)

---

##  System Functionality

- **Capacitive Soil Sensing**: Measures soil moisture using **capacitance-based readings**.
- **Moisture Display**: Outputs **real-time percentage** on the LCD screen.
- **Automated Irrigation**:
  - If moisture **drops below 20%**, the **relay activates the water pump**.
  - Once moisture **exceeds 20%**, the **pump shuts off**.
- **Data Averaging for Stability**:
  - **10 readings per second**, averaged every **1 second** for smooth output.
- **Incremental Watering Mechanism**:
  - Water is added in **6mL cycles** to allow gradual absorption.

---

##  Known Issues & Limitations

### **Known Issues**
- **Sensor Noise & False Readings**: Occasionally, sensor readings may fluctuate due to **environmental factors**.
- **Delay in Water Absorption**: Soil moisture changes **gradually**, requiring **incremental watering**.
- **Limited Soil Type Compatibility**: The sensor’s performance varies depending on **soil texture and composition**.

### **Future Improvements**
- **Machine Learning for False Positives**: Train an AI model to filter out **false moisture fluctuations**.
- **Adaptive Watering Algorithm**: Improve efficiency by **adjusting watering frequency** based on historical soil data.
- **Multi-Sensor Integration**: Use multiple **distributed sensors** for **wider soil coverage**.
- **Low-Power Optimization**: Enhance efficiency for **solar-powered or battery-based operation**.

---

##  Contributors

 **[Allyia Loo Binti Zainai](https://github.com/Allyia)**  
 Open to collaborations & feature suggestions!  

If you'd like to **report an issue** or **suggest an improvement**, please open an **issue** in this repository. 

---

##  References

- [Arduino MPR121 Library](https://github.com/adafruit/Adafruit_MPR121)
- [Arduino Capacitive Sensing](https://playground.arduino.cc/Main/CapacitiveSensor/)
