# MediSync – Smart Medicine Delivery System

**Project Title:** MediSync – Smart Medicine Delivery System

**Project Type:** Third Year (TY) Mini Project


## 📌 Project Description

**MediSync** is an Arduino-based Smart Medicine Delivery System designed to improve medicine transportation between the Operation Theatre (OT) Unit and the Medical Store Unit in hospitals.

In traditional hospital environments, nurses and medical staff may need to manually travel to the medical store to collect medicines, which can consume valuable time, especially during emergency situations.

MediSync aims to reduce manual effort and improve medicine delivery efficiency through an automated electronic communication system. It uses two Arduino Uno boards connected through UART serial communication to transmit medicine selection and quantity information from the Operation Theatre Unit to the Medical Store Unit.

The system displays the selected medicine and its quantity on LCD displays and provides buzzer alerts for user interaction and acknowledgment.

## 🎯 Objectives

- To reduce manual effort in medicine transportation.
- To improve communication between the Operation Theatre and Medical Store.
- To provide a simple and user-friendly medicine selection system.
- To transmit medicine details using UART communication.
- To display medicine names and quantities on LCD screens.
- To provide buzzer alerts for button operations and acknowledgment.
- To explore automation in smart hospital infrastructure.

## ⚙️ Working Principle

The MediSync system consists of two main units:

### 1. Operation Theatre Unit (Transmitter)

- Uses an Arduino Uno as the transmitter.
- Contains four push buttons for medicine selection.
- Uses an additional push button to select the required quantity (1–10).
- Displays the selected medicine and quantity on an I2C LCD.
- Sends the medicine details to the receiver through UART serial communication.
- A buzzer provides audio feedback when buttons are pressed.

### 2. Medical Store Unit (Receiver)

- Uses a second Arduino Uno as the receiver.
- Receives medicine details through UART communication.
- Displays the requested medicine name and quantity on the second I2C LCD.
- Uses EEPROM for storing relevant data.
- Provides buzzer acknowledgment after receiving the information.

## 🔄 System Workflow

1. The nurse selects the required medicine using the push buttons.
2. The system identifies the selected medicine.
3. The required quantity is selected using the quantity button.
4. The transmitter Arduino displays the medicine details on the LCD.
5. Medicine information is transmitted using UART communication.
6. The receiver Arduino receives the transmitted information.
7. The receiver LCD displays the medicine name and quantity.
8. A buzzer provides audio feedback.

## 💊 Medicines Included

1. Dextrose Injection
2. Adrenaline
3. Hydrocortisone Injection
4. Tranexamic Acid (TXA)

## 🛠️ Hardware Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 2 |
| I2C LCD Display | 2 |
| Push Buttons | 5 |
| Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |
| Power Supply | As required |
| EEPROM | Arduino's internal EEPROM |

## 💻 Software Requirements

- Arduino IDE
- Embedded C / Arduino Programming Language
- LiquidCrystal_I2C Library
- Wire Library
- EEPROM Library
- SoftwareSerial Library (if used for UART communication)

## 📡 Communication Technology

**UART (Universal Asynchronous Receiver-Transmitter)** is used for serial communication between the two Arduino Uno boards.

The transmitter sends medicine selection and quantity information to the receiver. This enables communication between the Operation Theatre Unit and Medical Store Unit.

## 🌟 Key Features

- Dual Arduino-based architecture.
- UART serial communication.
- Four medicine selection options.
- Quantity selection from 1 to 10.
- Dual LCD display system.
- Buzzer-based audio feedback.
- EEPROM data storage.
- Simple and user-friendly operation.

## 🏥 Applications

- Hospital Operation Theatre Units.
- Hospital Medical Stores.
- Emergency Medicine Request Systems.
- Smart Hospital Infrastructure.
- Automated Medicine Transportation Concepts.

## 🚀 Future Scope

- Integration with IoT for remote monitoring.
- Development of a wireless medicine request system.
- Addition of medicine stock management.
- Integration with hospital management software.
- Automated medicine transportation using a motorized mechanism.
- Development of a centralized medicine tracking dashboard
  
## 📌 Conclusion

MediSync demonstrates how embedded systems and communication technologies can be used to improve medicine request and delivery processes in hospitals. By integrating Arduino, UART communication, LCD displays, push buttons, EEPROM, and buzzer alerts, the project provides a simple automated solution that can help reduce manual effort and support faster communication between hospital departments.

**MediSync – Making Hospital Medicine Delivery Smarter!**
