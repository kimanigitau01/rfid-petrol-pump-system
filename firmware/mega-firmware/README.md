# RFID Petrol Pump Project

This project is an RFID-based petrol pump system that allows authorized users to dispense fuel after verifying their RFID card. Users can also enter the desired fuel amount via a keypad. The system includes the following hardware components:

## Hardware Components

### RFID Module
- **MFRC522 RFID Reader**: This module reads RFID cards and verifies them against authorized card IDs.

### User Interface
- **LiquidCrystal_I2C Display**: A 16x2 character LCD display used to provide information to the user.
- **Keypad**: A 4x3 matrix keypad for users to enter the desired fuel amount.

### Output Indicators
- **Green LED**: Indicates that the RFID card is valid.
- **Red LED**: Indicates that the RFID card is invalid.
- **Buzzer**: Provides audio feedback for card validation and errors.
- **Relay**: Controls the fuel dispensing motor.

## Software

The software for this project is written in Arduino/C++ and utilizes various libraries. Here's an overview of the key functions:

### `setup()`
- Initializes the Serial communication for debugging.
- Initializes SPI communication for the RFID module and LCD display.
- Initializes pins for LEDs, buzzer, and relay.
- Displays the project name on the LCD for 2 seconds.

### `loop()`
- The main loop of the program.
- Calls `resetSystem()` to reset the system's state.
- If a valid RFID card is read:
  - Checks if the card is authorized using `compareNUID()`.
  - If authorized, turns on the green LED, prompts the user to enter the fuel amount via the keypad, and starts the fuel dispensing algorithm.
  - Displays the remaining balance after fueling.
  - If unauthorized, turns on the red LED and buzzes to indicate an invalid card.
- If no RFID card is detected, turns on the red LED and buzzes to indicate a system error.

### `readRFIDCard()`
- Checks if a new RFID card is present and reads the card's serial number.

### `readKeypad()`
- Reads the fuel amount entered by the user on the keypad and displays it on the LCD.

### `resetSystem()`
- Resets the system state by turning off LEDs, clearing the LCD, and displaying a "Provide RFID" message.

### `compareNUID(byte nuid[], byte authorizedNUID[])`
- Compares the UID of the RFID card with authorized card UIDs to validate the card.

### `dispensing_algorithm(float amount)`
- Simulates fuel dispensing by activating the relay for a duration based on the entered fuel amount.

## Usage

1. Power on the system.
2. Hold an authorized RFID card near the RFID reader.
3. If the card is valid, the green LED will light up, and you can enter the desired fuel amount using the keypad.
4. After entering the amount, the system will simulate fuel dispensing.
5. The remaining balance will be displayed on the LCD.

## Modifications

You can modify this project by adjusting the following:

- Change the `authorizedNUID` array to include the UIDs of authorized RFID cards.
- Customize the dispensing algorithm in `dispensing_algorithm()` to control the fuel dispensing motor according to your hardware setup.
- Add additional features such as fuel level monitoring or payment processing.

## Hardware configuration
Struck? Get help from [here](/debugging.md)

Please ensure to follow safety precautions when working with fuel and motors.

