#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT;

Servo escLift;
Servo escThrust;

int liftPin = 18;
int thrustPin = 19;

// Throttle values
int minThrottle = 1000;

// Lift
int liftThrottle = 1650;

// Thrust modes
int thrustLow = 1200;
int thrustMedium = 1400;
int thrustHigh = 1600;

int currentThrust = 1000;
bool thrustActive = false;
bool systemPower = false;   // ✅ NEW

void setup() {
  Serial.begin(115200);
  SerialBT.begin("HOVERCRAFT_PRO");

  escLift.setPeriodHertz(50);
  escThrust.setPeriodHertz(50);

  escLift.attach(liftPin, 1000, 2000);
  escThrust.attach(thrustPin, 1000, 2000);

  escLift.writeMicroseconds(minThrottle);
  escThrust.writeMicroseconds(minThrottle);

  delay(5000);
}

void loop() {

  if (SerialBT.available()) {
    char cmd = SerialBT.read();

    // 🔵 FULL POWER ON
    if (cmd == 'A') {
      systemPower = true;
      escLift.writeMicroseconds(liftThrottle); // auto lift start
    }

    // 🔴 FULL POWER OFF
    if (cmd == 'P') {
      systemPower = false;
      thrustActive = false;
      escLift.writeMicroseconds(minThrottle);
      escThrust.writeMicroseconds(minThrottle);
    }

    // ❗ Agar system OFF hai toh kuch bhi kaam nahi karega
    if (!systemPower) return;

    // 🔵 Lift ON
    if (cmd == 'F') {
      escLift.writeMicroseconds(liftThrottle);
    }

    // 🔵 Lift OFF
    if (cmd == 'B') {
      escLift.writeMicroseconds(minThrottle);
    }

    // 🟢 Thrust ON
    if (cmd == 'L') {
      thrustActive = true;
      currentThrust = thrustMedium;
      escThrust.writeMicroseconds(currentThrust);
    }

    // 🔴 Thrust OFF
    if (cmd == 'R') {
      thrustActive = false;
      escThrust.writeMicroseconds(minThrottle);
    }

    // ⚙️ Speed Modes
    if (thrustActive) {
      if (cmd == 'T') currentThrust = thrustLow;
      if (cmd == 'C') currentThrust = thrustMedium;
      if (cmd == 'X') currentThrust = thrustHigh;

      escThrust.writeMicroseconds(currentThrust);
    }

    // ⚠️ Emergency STOP
    if (cmd == 'S') {
      systemPower = false;
      thrustActive = false;
      escLift.writeMicroseconds(minThrottle);
      escThrust.writeMicroseconds(minThrottle);
    }
  }
}
