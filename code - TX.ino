#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial uart(10, 11);   // RX, TX

// Buttons
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int quantityButton = 6;

// Buzzer
const int buzzer = 7;

String selectedMedicine = "";
String displayMedicine = "";

int quantity = 0;
bool medicineSelected = false;

void setup() {

  lcd.init();
  lcd.backlight();

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(quantityButton, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  noTone(buzzer);

  uart.begin(9600);
  Serial.begin(9600);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MEDISYNC");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Medicine");
}

void loop() {

  // Medicine 1
  if (digitalRead(button1) == LOW) {

    beep();

    selectedMedicine = "Dextrose Injection";
    displayMedicine = "Dextrose Inj.";
    quantity = 1;
    medicineSelected = true;

    displayOrder();
    sendOrder();

    waitForRelease(button1);
  }


  // Medicine 2
  if (digitalRead(button2) == LOW) {

    beep();

    selectedMedicine = "Adrenaline";
    displayMedicine = "Adrenaline";
    quantity = 1;
    medicineSelected = true;

    displayOrder();
    sendOrder();

    waitForRelease(button2);
  }


  // Medicine 3
  if (digitalRead(button3) == LOW) {

    beep();

    selectedMedicine = "Hydrocortisone Injection";
    displayMedicine = "Hydrocortisone";
    quantity = 1;
    medicineSelected = true;

    displayOrder();
    sendOrder();

    waitForRelease(button3);
  }


  // Medicine 4
  if (digitalRead(button4) == LOW) {

    beep();

    selectedMedicine = "Tranexamic Acid (TXA)";
    displayMedicine = "TXA";
    quantity = 1;
    medicineSelected = true;

    displayOrder();
    sendOrder();

    waitForRelease(button4);
  }


  // Quantity button
  if (digitalRead(quantityButton) == LOW) {

    if (medicineSelected == true) {

      beep();

      quantity++;

      if (quantity > 10) {
        quantity = 1;
      }

      displayOrder();
      sendOrder();
    }

    waitForRelease(quantityButton);
  }
}


// ==============================
// BUZZER
// ==============================

void beep() {

  tone(buzzer, 2000);
  delay(800);
  noTone(buzzer);
}


// ==============================
// DISPLAY
// ==============================

void displayOrder() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(displayMedicine);

  lcd.setCursor(0, 1);
  lcd.print("Qty: ");
  lcd.print(quantity);
}


// ==============================
// SEND UART
// ==============================

void sendOrder() {

  uart.print(selectedMedicine);
  uart.print(",");
  uart.println(quantity);

  Serial.print("Sent: ");
  Serial.print(selectedMedicine);
  Serial.print(",");
  Serial.println(quantity);
}


// ==============================
// WAIT FOR BUTTON RELEASE
// ==============================

void waitForRelease(int buttonPin) {

  while (digitalRead(buttonPin) == LOW) {
    delay(10);
  }
}
