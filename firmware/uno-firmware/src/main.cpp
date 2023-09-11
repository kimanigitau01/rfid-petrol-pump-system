#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {0, 2, 7, 13};
byte colPins[COLS] = {3, 4, 6};
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int greenLedPin = 2;
const int redLedPin = 8;
const int buzzerPin = 1;
const int motorRelayPin = 5;

byte authorizedNUID[] = {0x80, 0xB4, 0x4E, 0x12};

bool readRFIDCard();
String readKeypad();
void resetSystem();
bool compareNUID(byte nuid[], byte authorizedNUID[]);
void dispensing_algorithm(float amount);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();

  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorRelayPin, OUTPUT);
  
  lcd.print("RFID Petrol Pump");
  delay(2000);
  lcd.clear();
}

void loop() {
  resetSystem();
  if (readRFIDCard()) {
    if (compareNUID(mfrc522.uid.uidByte, authorizedNUID)) {
      digitalWrite(greenLedPin, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Valid Tag");
      delay(1500);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Amount: ");
      lcd.setCursor(0, 1);
      String amount = readKeypad();
      lcd.setCursor(0, 1);
      lcd.print("Amount: " + amount);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Dispensing Fuel");
      // change the dispensing algorithm
      dispensing_algorithm(amount.toFloat());
      
      lcd.clear();
      float balance = 1000.0 - amount.toFloat();
      lcd.setCursor(0, 0);
      lcd.print("Balance: $" + String(balance));
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      digitalWrite(redLedPin, HIGH);
      lcd.print("Unauthorized ");
      lcd.setCursor(4,1);
      lcd.print("Card");
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
    }

    delay(3000);
    resetSystem();
  } else {
    lcd.clear();
    digitalWrite(redLedPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    resetSystem();
  }
}

bool readRFIDCard() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    return true;
  }
  return false;
}

String readKeypad() {
  String input = "";
  while (true) {
    char key = myKeypad.getKey();
    if (key) {
      if (key == '#') {
        break;
      }
      input += key;
      lcd.print(key);
    }
  }
  return input;
}

void resetSystem() {
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  lcd.clear();
  lcd.print("Provide RFID");
  delay(1000);
}

bool compareNUID(byte nuid[], byte authorizedNUID[]) {
  for (int i = 0; i < 4; i++) {
    if (nuid[i] != authorizedNUID[i]) {
      return false;
    }
  }
  return true;
}

void dispensing_algorithm(float amount)
{
  int delay_time = amount * 15;
    digitalWrite(motorRelayPin, HIGH);
    delay(delay_time);
    digitalWrite(motorRelayPin, LOW);
}