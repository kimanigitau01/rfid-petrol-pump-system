## Setting Up the RFID Petrol Pump Project

This guide will walk you through the steps to set up the RFID Petrol Pump project. Ensure you have all the necessary components and follow these instructions carefully.

### Hardware Components Required

- Arduino or compatible microcontroller.
- MFRC522 RFID Module.
- 16x2 I2C LCD Display.
- 4x3 Keypad.
- LEDs (Green and Red).
- Buzzer.
- Relay Module.
- Jumper wires.

### Wiring Connections

#### MFRC522 RFID Module:

- Connect 3.3V on the RFID module to 3.3V on the Arduino.
- Connect GND on the RFID module to GND on the Arduino.
- Connect SDA (Serial Data) to the appropriate Arduino pin (e.g., 10 on Arduino Uno).
- Connect SCK (Serial Clock) to the appropriate Arduino pin (e.g., 13 on Arduino Uno).
- Connect MOSI (Master Out Slave In) to the appropriate Arduino pin (e.g., 11 on Arduino Uno).
- Connect MISO (Master In Slave Out) to the appropriate Arduino pin (e.g., 12 on Arduino Uno).
- Connect RST to an Arduino digital pin (e.g., 9).
- Connect SS/SDA to an Arduino digital pin (e.g., 10).

#### 16x2 I2C LCD Display:

- Connect the VCC (power) pin to 5V on the Arduino.
- Connect the GND (ground) pin to GND on the Arduino.
- Connect the SDA (data) pin to the appropriate Arduino pin (e.g., A4 on Arduino Uno).
- Connect the SCL (clock) pin to the appropriate Arduino pin (e.g., A5 on Arduino Uno).

#### 4x3 Keypad:

- Connect one end of the keypad rows to Arduino pins 0, 2, 7, and 13.
- Connect one end of the keypad columns to Arduino pins 3, 4, and 6.

#### LEDs (Green and Red):

- Connect the anode (longer lead) of the Green LED to a current-limiting resistor (220-470 ohms) and then to an Arduino pin (e.g., 2).
- Connect the cathode (shorter lead) of the Green LED to GND.
- Connect the anode of the Red LED to a current-limiting resistor and then to an Arduino pin (e.g., 8).
- Connect the cathode of the Red LED to GND.

#### Buzzer:

- Connect one pin of the buzzer to an Arduino pin (e.g., 1).
- Connect the other pin of the buzzer to GND.

#### Relay Module:

- Connect one end of the relay coil (usually marked IN or Signal) to an Arduino pin (e.g., 5).
- Connect the other end of the relay coil to GND.
- Connect one of the relay's normally closed (NC) terminals to your fuel dispensing motor.
- Connect the other terminal of the motor to +12V (or the appropriate motor voltage).
- Connect the motor's ground to the Arduino's GND.

### Power Supply

- Ensure that the Arduino is powered via USB or an external power source, and that the motor (if used) receives the necessary power, usually +12V.

### Notes

- Double-check all connections to avoid any shorts or incorrect wiring.
- Make sure the Arduino is grounded with the same ground as the components.
- Adjust pin assignments in your code if you've used different pins than those mentioned in this guide.

With these connections in place, you should be ready to upload the provided Arduino code and test your RFID Petrol Pump project.

