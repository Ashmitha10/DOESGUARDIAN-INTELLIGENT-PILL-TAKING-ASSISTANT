# 💊 DoseGuardian – Intelligent Pill-Taking Assistant

DoesGuardian is an embedded-system-based smart medication reminder designed to help patients take medicines on time. It is built using the LPC2148(ARM7) microcontroller and provides real-time monitoring, alerts,and user acknowledgment to reduce mssed doses.

## 📌 Project
Many patients, especially elderly individuals and those under long-term treatment, often forget or skip their medication. DoseGuardian addresses this issue by integrating a Real-Time Clock (RTC) with visual and audible alert mechanisms to ensure timely medicine intake.

## 🚀 Objectives

- Display RTC (Real Time Clock) date and time on 16x2 LCD
- Allow users to modify RTC settings using 4x4 keypad
- Enable medicine time scheduling
- Trigger alert when current time matches scheduled time
- Detect missed medication using LED indication

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

## 🧩Block Diagram (Logical View)
RTC, Keypad, and Switches provide inputs to the LPC2148 microcontroller. The controller drives the LCD, Buzzer, and LED for output indications.

## 🛠️ Hardware Requirements

- LPC2148
- 16x2 LCD
- 4x4 Matrix Keypad
- RTC Module
- Buzzer
- Switches
- LED
- USB-UART Converter / DB-9 Cable

## 💻 Software Requirements

- Embedded C Programming
- Keil IDE
- Flash Magic



### 4️⃣ Acknowledgment

- User presses Switch2 to confirm intake
- If confirmed → System returns to main display
- If NOT confirmed within time
- Red LED turns ON (Missed Dose Alert)

## ✨ Features

- 🕰️ Real-time clock display  
- ✏️ Time, date, and day editing  
- ⏰ Medicine reminder scheduling  
- 🔔 Audible alerts using buzzer  
- 📺 Visual alerts using LCD and LED  
- ☑️ Confirmation-based medicine intake  
- ⚠️ Missed-dose indication

   ## 📸LCD Display

  ![WhatsApp Image 2026-02-23 at 5 38 52 PM](https://github.com/user-attachments/assets/9541c566-7871-4dfa-bece-1ed33021d8c0)


## 📋 Menu System

1.RTCINFO
2.MEDICINE
3.EXIT


![WhatsApp Image 2026-02-23 at 5 45 26 PM](https://github.com/user-attachments/assets/961f9cad-c1e4-40cf-a9b6-79c24187ea21)


## 🕒 Edit RTC Information

When you press 1 for Editing the RTC Info 
1.HOUR
2.MINUTES
3.SECONDS
4.DAY
5.DATE
6.MONTH
7.YEAR
8.EXIT

![WhatsApp Image 2026-02-23 at 5 51 32 PM](https://github.com/user-attachments/assets/9fda4aa5-69e6-4dc0-9ed5-e79caf99e492)


✏️ Editing HOUR

![WhatsApp Image 2026-02-23 at 5 57 02 PM](https://github.com/user-attachments/assets/7bf1df54-4bce-47d9-877c-8a831a2684f0)

If Invalid range is taken it show invalid for exiting press 3

![WhatsApp Image 2026-02-23 at 6 01 40 PM](https://github.com/user-attachments/assets/1bbb4de7-c4e2-4af0-a1b3-a60952481065)


## 💊 Edit Medicine Time

When you press 2 on main menu it go for Edit medicine time

![WhatsApp Image 2026-02-23 at 6 02 45 PM](https://github.com/user-attachments/assets/538ac652-cd55-4e67-8b55-f41027acb0a8)


 🔹 ON Time Setting

- The LCD prompts the user with:
  
  `ONTIME HHMM:`

- The user enters:
  - 2-digit Hour
  - 2-digit Minute

- The system reads the values using:
  - `read2Digit()` function

- Input validation is performed:
  - Hour must be between 0–23
  - Minute must be between 0–59

- If invalid input is entered:
  - LCD displays: `"Invalid On Time"`
  - System delays for 800 ms
  - Function exits without saving

This ensures only valid 24-hour format time is accepted.

 🔹 OFF Time Setting

- After valid ON time entry, the LCD prompts:

  `OFF TIME HHMM:`

- User enters OFF hour and minute.
- Similar validation is performed to ensure valid time format.
- OFF time is stored for reminder control logic.

![WhatsApp Image 2026-02-23 at 6 09 11 PM](https://github.com/user-attachments/assets/14cbd69d-73b1-4ff7-bf57-f6434c3dab98)


 ⚙️ Purpose in Project

This ON/OFF time scheduling:

- Allows flexible medicine reminder timing
- Prevents invalid time entry
- Improves user safety
- Ensures proper buzzer and LED triggering logic

This module is a critical part of the DoseGuardian medication reminder system.

 🔔 Medicine Alert & Acknowledgment Logic

The system continuously compares the stored medicine ON time with the current RTC time.

 ⏰ Time Match Condition

When:

RTC Time == Stored ON Time

the following sequence is executed:
- Buzzer turns ON.Medicne time
- System waits for a predefined acknowledgment time (`ACKTIMEOUT`).

⌛  Wait for User Confirmation

During the waiting period:

- If **Switch2 is pressed**:
  - Buzzer turns OFF
  - LCD displays: "Medicine Taken"
  - Red LED remains OFF
  - System returns to normal monitoring mode

 ⚠️ Missed Dose Detection

If **Switch2 is NOT pressed** within the timeout period:

- Buzzer turns OFF
- LCD displays: "Fail to medicine taken"
- 🔴 Red LED turns ON
- Indicates missed medicine intake

![WhatsApp Image 2026-02-23 at 6 17 54 PM](https://github.com/user-attachments/assets/3c2dcc20-daae-461a-ad93-638ef438b9dd)

## 🔑Keypad Controls
| Key | Function Name | Description |
|-----|--------------|-------------|
| *   | Delete       | Deletes last entered digit (used for correcting wrong value) |
| D   | Save         | Saves entered value and confirms selection |

## 🔮 Future Enhancements

- Multiple medicine schedules
- GSM or SMS alert system
- Mobile application integration
- Voice reminders
- Low-power sleep mode

## 👩‍💻 Developed By

Korra Ashmitha  
Electronics and Communication Engineering  
Developer of DoseGuardian – Intelligent Pill-Taking Assistant 

## 📜 License

This project is developed for academic and learning purposes. You are free to modify and enhance it with proper credit.

⭐ If you find this project useful, consider giving it a star on GitHub.
