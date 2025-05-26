# 🛡️ IoT RC Tank Controlled via Arduino IoT Cloud

This project is an internet-connected RC-style tank that uses the Arduino IoT Cloud for remote control. It features real-time directional control using four virtual buttons: Forward, Backward, Left, and Right.

## 🚀 Features

- Remotely control the tank using Arduino IoT Cloud Dashboard
- Dual 12V DC motors with L298N motor driver
- ESP32 or Arduino Uno R4 WiFi-based connection
- Directional control via four boolean cloud variables
- Full motor stop functionality when idle

## 🧠 Components Used

| Component             | Description                                |
|----------------------|--------------------------------------------|
| Arduino Uno R4 WiFi  | Main microcontroller                       |
| L298N Motor Driver   | Controls the two 12V DC motors             |
| 2 × 12V DC Motors    | Left and right drive motors                |
| 4 × Boolean Variables| forward, backward, left, right (IoT Cloud)|
| EBL 2800mAh Batteries| External motor power supply                |
| Arduino IoT Cloud    | Web dashboard for wireless control         |

---

## 🔌 Wiring Diagram

### 🔧 Motor Pin Connections to Arduino Uno R4 WiFi

| Motor       | L298N Pin | Arduino Pin |
|-------------|-----------|-------------|
| Right Motor | ENA       | 9           |
| Right Motor | IN1       | 10          |
| Right Motor | IN2       | 11          |
| Left Motor  | IN3       | 5           |
| Left Motor  | IN4       | 6           |
| Left Motor  | ENB       | 3           |

Make sure the L298N is powered using an external 12V source (not from the Arduino).

---

## ☁️ Arduino IoT Cloud Variables

| Variable Name | Type | Description              |
|---------------|------|--------------------------|
| `forWard`     | bool | Move both motors forward |
| `backWard`    | bool | Move both motors backward|
| `leFt`        | bool | Turn tank left           |
| `riGht`       | bool | Turn tank right          |

---

## 🧾 How It Works

- When `forWard` is set to `true`, both motors drive forward.
- When `backWard` is `true`, both motors reverse.
- When `leFt` is `true`, the right motor moves forward.
- When `riGht` is `true`, the left motor moves forward.
- All other motors are stopped when a direction is not active.

---

## 🛠️ Setup Instructions

1. **Create a Thing** in [Arduino IoT Cloud](https://create.arduino.cc/iot).
2. Add four boolean variables: `forWard`, `backWard`, `leFt`, `riGht`.
3. Connect your Arduino Uno R4 WiFi or ESP32 board.
4. Upload the provided `.ino` sketch (includes `thingProperties.h`).
5. Open your IoT Cloud Dashboard and toggle the direction buttons.

---


