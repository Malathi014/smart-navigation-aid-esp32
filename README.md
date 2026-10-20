# 🦯 Smart Navigation Aid for Visually Impaired (ESP32)

An assistive IoT-enabled embedded device engineered to help visually impaired individuals navigate environments safely. Built on the **ESP32 microcontroller**, the system detects obstacles, monitors hazardous gases, identifies ground terrain variations, and triggers instant audio-haptic feedback.

---

## 🚀 Key Features

- **Multi-Sensor Obstacle Detection:** Ultrasonic and infrared sensors provide obstacle tracking across varying angles and ranges.
- **Hazardous Environment Alert:** Integrated gas sensor detects toxic emissions and smoke spikes.
- **Real-Time Feedback:** Dual signaling mechanism using a high-decibel buzzer and haptic vibration motors.
- **Microcontroller Integration:** Optimized firmware loop executing fast sensor reads and safety interrupts on ESP32.

---

## 🛠️ Hardware Stack & Components

| Component | Pin (ESP32) | Function |
| :--- | :--- | :--- |
| **ESP32 Dev Module** | Core Controller | Central logic, sensor processing & interrupts |
| **HC-SR04 Ultrasonic Sensor** | GPIO 5 (Trig), GPIO 18 (Echo) | Frontal distance & collision warning |
| **IR Sensor Module** | GPIO 19 | Surface elevation / pit detection |
| **MQ-2 / Gas Sensor** | GPIO 34 (Analog) | Smoke & hazardous gas detection |
| **Active Buzzer / Vibration Motor**| GPIO 23 | Immediate user alert signaling |

---

## 📂 Project Architecture

```
├── firmware/
│   └── smart_navigation_aid.ino   # Core ESP32 firmware & sensor loops
├── simulation/
│   └── wokwi_diagram.json         # Wokwi simulation circuit file
├── schematics/
│   └── pin_connections.png       # Circuit diagram
└── README.md                      # Project documentation
```

---

## 💻 Simulation & Running

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/Malathi014/smart-navigation-aid-esp32.git](https://github.com/Malathi014/smart-navigation-aid-esp32.git)
   cd smart-navigation-aid-esp32
   ```

2. **Firmware Upload:**
   - Open `firmware/smart_navigation_aid.ino` in **Arduino IDE**.
   - Select Board: `DOIT ESP32 DEVKIT V1` and appropriate COM Port.
   - Click **Upload**.

---

## 🌐 Live Simulation
Test the circuit prototype online:
[![Simulate on Wokwi](https://img.shields.io/badge/Wokwi-Online_Simulation-00599C?style=flat&logo=espressif&logoColor=white)](https://wokwi.com/makers/skmalathi014)
