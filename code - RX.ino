#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// =====================================
// LCD 2
// =====================================

LiquidCrystal_I2C lcd(0x27, 16, 2);

// =====================================
// UART
// D10 = RX
// D11 = TX
// =====================================

SoftwareSerial uart(10, 11);

// =====================================
// VARIABLES
// =====================================

String receivedData = "";
String medicine = "";
String quantity = "";

// =====================================
// SETUP
// =====================================

void setup() {

  lcd.init();
  lcd.backlight();

  // UART
  uart.begin(9600);

  // Serial Monitor
  Serial.begin(9600);

  // Starting message
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("MEDISYNC STORE");

  lcd.setCursor(0, 1);
  lcd.print("Waiting Order");

  delay(2000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Waiting Order");
}

// =====================================
// MAIN LOOP
// =====================================

void loop() {

  if (uart.available()) {

    // Receive complete order
    receivedData = uart.readStringUntil('\n');

    receivedData.trim();

    // Serial Monitor
    Serial.print("Received: ");
    Serial.println(receivedData);

    // Find comma
    int commaIndex = receivedData.indexOf(',');

    if (commaIndex > 0) {

      // Extract medicine
      medicine = receivedData.substring(0, commaIndex);

      // Extract quantity
      quantity = receivedData.substring(commaIndex + 1);

      // Display received order
      displayOrder();
    }
  }
}

// =====================================
// DISPLAY ORDER ON LCD 2
// =====================================

void displayOrder() {

  lcd.clear();

  // Display medicine
  lcd.setCursor(0, 0);

  // LCD can display only 16 characters
  if (medicine == "Dextrose Injection") {

    lcd.print("Dextrose Inj.");

  }
  else if (medicine == "Hydrocortisone Injection") {

    lcd.print("Hydrocortisone");

  }
  else if (medicine == "Tranexamic Acid (TXA)") {

    lcd.print("TXA");

  }
  else {

    lcd.print(medicine);
  }

  // Display quantity
  lcd.setCursor(0, 1);
  lcd.print("Qty: ");
  lcd.print(quantity);
}
