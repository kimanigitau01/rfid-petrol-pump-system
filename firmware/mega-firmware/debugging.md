# RFID Petrol Pump Project - Component Connection Guide

This guide provides step-by-step instructions on how to connect the various hardware components for the RFID Petrol Pump project. Ensure you have the following components ready:

- Arduino Mega
- MFRC522 RFID Module
- 16x2 I2C LCD Display
- 4x3 Keypad
- LEDs (Green and Red)
- Buzzer
- Relay Module
- Jumper wires

## Wiring Diagram

Here's how you should connect the components to your Arduino:

### MFRC522 RFID Module

- Connect **3.3V** on the RFID module to **3.3V** on the Arduino.
- Connect **GND** on the RFID module to **GND** on the Arduino.
- Connect **SDA (Serial Data)** to the appropriate Arduino pin (e.g., **53** on Arduino Mega).
- Connect **SCK (Serial Clock)** to the appropriate Arduino pin (e.g., **52** on Arduino Mega).
- Connect **MOSI (Master Out Slave In)** to the appropriate Arduino pin (e.g., **51** on Arduino Mega).
- Connect **MISO (Master In Slave Out)** to the appropriate Arduino pin (e.g., **50** on Arduino Mega).
- Connect **RST** to an Arduino digital pin (e.g., **5**).
- Connect **SS/SDA** to an Arduino digital pin (e.g., **53**).

### 16x2 I2C LCD Display

- Connect the **VCC** (power) pin to **5V** on the Arduino.
- Connect the **GND** (ground) pin to **GND** on the Arduino.
- Connect the **SDA** (data) pin to the appropriate Arduino pin (e.g., **A4** on Arduino Mega).
- Connect the **SCL** (clock) pin to the appropriate Arduino pin (e.g., **A5** on Arduino Mega).

### 4x3 Keypad

- Connect one end of the keypad rows to Arduino pins **0**, **2**, **7**, and **13**.
- Connect one end of the keypad columns to Arduino pins **3**, **4**, and **6**.

### LEDs (Green and Red)

- Connect the anode (longer lead) of the **Green LED** to a current-limiting resistor (220-470 ohms) and then to an Arduino pin (e.g., **9**).
- Connect the cathode (shorter lead) of the **Green LED** to **GND**.
- Connect the anode of the **Red LED** to a current-limiting resistor and then to an Arduino pin (e.g., **8**).
- Connect the cathode of the **Red LED** to **GND**.

### Buzzer

- Connect one pin of the buzzer to an Arduino pin (e.g., **12**).
- Connect the other pin of the buzzer to **GND**.

### Relay Module

- Connect one end of the relay coil (usually marked **IN** or **Signal**) to an Arduino pin (e.g., **10**).
- Connect the other end of the relay coil to **GND**.
- Connect one of the relay's normally open (NO) terminals to your fuel dispensing motor.
- Connect the other terminal of the motor to **+12V** (or the appropriate motor voltage).
- Connect the motor's ground to the Arduino's **GND**.

## Power Supply

Ensure that the Arduino is powered via USB or an external power source, and that the motor receives the necessary power (usually **+12V**).

## Notes

- Double-check all connections to avoid any shorts or incorrect wiring.
- Make sure the Arduino is grounded with the same ground as the components.
- Adjust pin assignments in your code if you've used different pins than those mentioned in this guide.

With these connections in place, you should be ready to upload the provided Arduino code and test your RFID Petrol Pump project.

