# 💊 DoseGuardian – Intelligent Pill-Taking Assistant

DoesGuardian is an embedded-system-based smart medication reminder designed to help patients take medicines on time. It is built using the LPC2148(ARM7) microcontroller and provides real-time monitoring, alerts,and user acknowledgment to reduce mssed doses.

## 📌 Project
Many patients, especially elderly individuals and those under long-term treatment, often forget or skip their medication. DoseGuardian addresses this issue by integrating a Real-Time Clock (RTC) with visual and audible alert mechanisms to ensure timely medicine intake.
---

## 🚀 Objectives

- Display RTC (Real Time Clock) date and time on 16x2 LCD
- Allow users to modify RTC settings using 4x4 keypad
- Enable medicine time scheduling
- Trigger alert when current time matches scheduled time
- Detect missed medication using LED indication

---
## ⚙️ Working Principle

### 1️⃣ Setting Medicine Schedule

- Press Switch1
- Enter medicine time using keypad
- Time stored in microcontroller memory
- LCD displays saved schedule

---

### 2️⃣ Real-Time Monitoring

- Microcontroller continuously reads RTC
- Compares current time with stored medicine time

---

### 3️⃣ Alert Mechanism

When time matches:

- LCD displays: "Take Medicine Now"
- Buzzer turns ON and OFF periodically
- Waits for user acknowledgment

## 🧩 System Components

- LPC2148 Microcontroller
- RTC
- 16x2 LCD
- 4x4 Matrix Keypad
- Buzzer
- Switch1 (Menu/Set)
- Switch2 (Acknowledgment)
- Red LED (Missed Dose Indicator)

---

## 🛠️ Hardware Requirements

- LPC2148
- 16x2 LCD
- 4x4 Matrix Keypad
- RTC Module
- Buzzer
- Switches
- LED
- USB-UART Converter / DB-9 Cable

---

## 💻 Software Requirements

- Embedded C Programming
- Flash Magic

---



---

### 4️⃣ Acknowledgment

- User presses Switch2 to confirm intake
- If confirmed → System returns to main display
- If NOT confirmed within time:
  - Red LED turns ON (Missed Dose Alert)

---

## 📋 Menu System

```
1. E.RTCINFO
2. E.MEDICINE TIME
3. EXIT
```

---

## 🕒 Edit RTC Information

Editable Fields:

- Hour
- Minute
- Second
- Day
- Date
- Month
- Year

All input values are range validated before updating RTC.

---

## 💊 Edit Medicine Time

- Set ON time
- Set OFF time
- Save schedule
- Exit to main logic

All test cases are validated.

---

## 🔄 Software Flow

1. Initialize RTC, LCD, Keypad, Buzzer
2. Display current date & time
3. Wait for Switch1 press
4. Allow editing (RTC or Medicine Time)
5. Continuously compare RTC with stored schedule
6. Trigger alert if match found
7. Wait for acknowledgment
8. If missed → Turn ON Red LED
9. Return to main loop

---

## 📂 Suggested Project Structure

```
DoseGuardian/
│
├── main.c
├── lcd.c
├── keypad.c
├── rtc.c
├── buzzer.c
├── README.md
└── documentation/
```

---

## 🔮 Future Enhancements

- EEPROM storage for permanent schedule saving
- GSM module for SMS alerts
- IoT cloud integration
- Mobile app integration
- Multiple medicine reminders
- Battery backup support

---

## 👩‍💻 Author

Korra Asmitha  
Embedded Systems Developer  
Vector Institute, Hyderabad  

---

## 📜 License

This project is for academic and educational purposes.
