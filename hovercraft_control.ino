/**
 * 🚀 Smart Hovercraft Control System
 * ----------------------------------
 * Microcontroller : ESP32
 * Communication   : Bluetooth (Serial)
 * Motors          : 2x BLDC (Lift + Thrust via ESC)
 * 
 * Author : Aditya Pandey
 * Project: Flood Rescue Hovercraft
 * 
 * Description:
 * This program controls a hovercraft using Bluetooth commands.
 * It manages lift and thrust motors with multiple speed modes
 * and includes safety features like emergency stop.
 */

#include <BluetoothSerial.h>
#include <ESP32Servo.h>

// ===================== OBJECT INITIALIZATION =====================
BluetoothSerial SerialBT;
Servo escLift;
Servo escThrust;

// ===================== PIN CONFIGURATION =====================
const int LIFT_PIN = 18;
const int THRUST_PIN = 19;

// ===================== THROTTLE SETTINGS =====================
const int MIN_THROTTLE   = 1000;

// Lift motor throttle
const int LIFT_THROTTLE  = 1650;

// Thrust speed levels
const int THRUST_LOW     = 1200;
const int THRUST_MEDIUM  = 1400;
const int THRUST_HIGH    = 1600;

// ===================== SYSTEM STATE VARIABLES =====================
int currentThrust = MIN_THROTTLE;
bool thrustActive = false;
bool systemPower  = false;

// ===================== SETUP FUNCTION =====================
void setup() {
  Serial.begin(115200);
  SerialBT.begin("HOVERCRAFT_PRO");

  // Configure ESC PWM frequency
  escLift.setPeriodHertz(50);
  escThrust.setPeriodHertz(50);

  // Attach ESCs to pins
  escLift.attach(LIFT_PIN, 1000, 2000);
  escThrust.attach(THRUST_PIN, 1000, 2000);

  // Initialize motors to safe state
  escLift.writeMicroseconds(MIN_THROTTLE);
  escThrust.writeMicroseconds(MIN_THROTTLE);

  // ESC arming delay
  delay(5000);

  Serial.println("Hovercraft Ready 🚀");
}

// ===================== MAIN LOOP =====================
void loop() {

  if (SerialBT.available()) {
    char cmd = SerialBT.read();

    // ===================== SYSTEM CONTROL =====================

    // 🔵 System ON
    if (cmd == 'A') {
      systemPower = true;
      escLift.writeMicroseconds(LIFT_THROTTLE); // Auto lift
    }

    // 🔴 System OFF
    if (cmd == 'P') {
      shutdownSystem();
    }

    // If system is OFF, ignore all commands
    if (!systemPower) return;

    // ===================== LIFT CONTROL =====================

    if (cmd == 'F') {
      escLift.writeMicroseconds(LIFT_THROTTLE);
    }

    if (cmd == 'B') {
      escLift.writeMicroseconds(MIN_THROTTLE);
    }

    // ===================== THRUST CONTROL =====================

    if (cmd == 'L') {
      thrustActive = true;
      currentThrust = THRUST_MEDIUM;
      escThrust.writeMicroseconds(currentThrust);
    }

    if (cmd == 'R') {
      thrustActive = false;
      escThrust.writeMicroseconds(MIN_THROTTLE);
    }

    // ===================== SPEED MODES =====================

    if (thrustActive) {
      if (cmd == 'T') currentThrust = THRUST_LOW;
      if (cmd == 'C') currentThrust = THRUST_MEDIUM;
      if (cmd == 'X') currentThrust = THRUST_HIGH;

      escThrust.writeMicroseconds(currentThrust);
    }

    // ===================== EMERGENCY STOP =====================

    if (cmd == 'S') {
      shutdownSystem();
    }
  }
}

// ===================== SAFETY FUNCTION =====================
/**
 * Immediately shuts down all motors and resets system state
 */
void shutdownSystem() {
  systemPower = false;
  thrustActive = false;

  escLift.writeMicroseconds(MIN_THROTTLE);
  escThrust.writeMicroseconds(MIN_THROTTLE);

  Serial.println("⚠️ Emergency Stop Activated");
}
