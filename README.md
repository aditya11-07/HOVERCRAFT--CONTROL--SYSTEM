# 🚀 Smart Hovercraft for Flood Rescue  
### ESP32 + Bluetooth Controlled Autonomous Delivery System

A Bluetooth-controlled hovercraft designed for **flood rescue and emergency logistics**, capable of delivering food, medical supplies, and essential items in waterlogged or inaccessible regions.

---

## 📌 Project Overview

This project demonstrates a **low-cost, remotely operated hovercraft system** built using the ESP32 microcontroller. It uses **dual BLDC motors**—one for lift and one for thrust—to enable stable hovering and directional movement over water or uneven terrain.

The system is controlled wirelessly via Bluetooth, making it suitable for **real-time remote operation during disaster scenarios**.

---

## 🎯 Key Objectives

- Provide a **rapid-response delivery solution** during floods  
- Enable **remote-controlled navigation** without human risk  
- Design a **cost-efficient and scalable prototype**  

---

## ⚙️ System Architecture

- **Microcontroller:** ESP32 (Bluetooth-enabled)
- **Lift System:** BLDC motor + ESC (for air cushion generation)
- **Thrust System:** BLDC motor + ESC (for propulsion)
- **Power Source:** 11.1V LiPo Battery
- **Communication:** Bluetooth Serial Interface

---

## 🔥 Features

- 🔵 Centralized System ON/OFF Control  
- 🚁 Automatic Lift Motor Activation  
- 🟢 Multi-Level Thrust Speed Control  
- 📡 Wireless Bluetooth Communication  
- ⚠️ Emergency Stop for Safety  
- 🎮 Real-time Command-Based Navigation  

---

## 🎮 Control Commands

| Command | Function              |
|--------|----------------------|
| A      | System ON             |
| P      | System OFF            |
| L      | Thrust ON             |
| R      | Thrust OFF            |
| T      | Low Speed             |
| C      | Medium Speed          |
| X      | High Speed            |
| S      | Emergency STOP        |

---

## 📦 Components Used

- ESP32 Microcontroller  
- 2 × BLDC Motors (Lift + Thrust)  
- 2 × ESC (Electronic Speed Controllers)  
- LiPo Battery (11.1V, 2200mAh recommended)  
- Propellers (based on thrust requirements)  
- Bluetooth Interface (built-in ESP32)  

---

## 🧠 Working Principle

1. **Lift Generation:**  
   The lift motor creates an air cushion beneath the hovercraft, reducing friction with the surface.

2. **Thrust Control:**  
   The thrust motor propels the craft forward, with adjustable speed levels.

3. **Wireless Control:**  
   Commands are sent via Bluetooth and interpreted by the ESP32 to control ESC signals.

4. **Safety Mechanism:**  
   Emergency STOP instantly cuts off all motors.

---

## 🚀 Applications

- 🌊 Flood Rescue Operations  
- 💊 Medical Supply Delivery  
- 📦 Remote Area Logistics  
- 🛰️ Disaster Management Systems  
- 🧪 Educational & Research Prototypes  

---

## 🛠️ Setup & Installation

1. Install Arduino IDE  
2. Add ESP32 board support  
3. Install required libraries:
   - `BluetoothSerial.h`
   - `ESP32Servo.h`

4. Upload the code to ESP32  
5. Connect ESCs and motors as per circuit  
6. Pair Bluetooth device and start controlling  

---

## ⚠️ Safety Precautions

- Always calibrate ESC before use  
- Do not exceed safe throttle limits  
- Use proper LiPo battery handling practices  
- Test in controlled environments before real deployment  

---

## 📈 Future Improvements

- GPS-based autonomous navigation  
- Obstacle avoidance using sensors  
- Payload optimization system  
- Mobile app-based control interface  
- Camera integration for live monitoring  

---

## 👨‍💻 Author

**Aditya Pandey**  
B.Tech Student | Embedded Systems Enthusiast  

---

## ⭐ Contribution

Contributions, suggestions, and improvements are welcome.  
Feel free to fork the repository and submit a pull request.

---

## 📜 License

This project is open-source and available under the MIT License.
