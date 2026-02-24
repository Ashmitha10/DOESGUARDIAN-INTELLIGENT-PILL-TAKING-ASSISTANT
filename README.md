## 💊 DoseGuardian – Intelligent Pill-Taking Assistant

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

- LCD displays: "Medicine Time"
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

  ## 📷 LCD Display

<p align="center">
  <img src="https://github.com/user-attachments/assets/b03bf679-caf3-49cd-a0f7-6f2689c5c518" width="500"/>
</p>

## 📋 Menu System

1.RTCINFO
2.MEDICINE
3.EXIT

![WhatsApp Image 2026-02-24 at 10 36 14 PM](https://github.com/user-attachments/assets/c6a5de52-6ffe-4a69-a4a0-f168f77c0e7a)

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

![WhatsApp Image 2026-02-24 at 10 37 20 PM](https://github.com/user-attachments/assets/e5a3ad29-0dd6-4168-a3fd-31898ba87189)

✏️ Editing HOUR

  <p align="center">
  <img src="https://github.com/user-attachments/assets/5b0d9343-c55f-438c-891c-8200e2b7e059" width="500"/>
</p>

## 💊 Edit Medicine Time

When you press 2 on main menu it go for Edit medicine time

![WhatsApp Image 2026-02-24 at 10 41 29 PM](https://github.com/user-attachments/assets/c65d4d9a-4c09-4691-887e-85127657cca4)

 🔹 ON Time Setting

- The LCD prompts the user with:
  
  `ONTIME HHMM:`

  <p align="center">
  <img src="https://github.com/user-attachments/assets/4148639e-db8d-4fd7-a52d-e8e833da716e" width="500"/>
</p>

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

   <p align="center">
  <img src="https://github.com/user-attachments/assets/5006f28f-d625-4050-818e-921e79d95d71" width="500"/>
</p>

- User enters OFF hour and minute.
- Similar validation is performed to ensure valid time format.
- OFF time is stored for reminder control logic.

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

  ![WhatsApp Image 2026-02-24 at 10 49 03 PM](https://github.com/user-attachments/assets/2b1ca35a-a3b2-4b8d-a1d2-1a9362798caf)


⌛  Wait for User Confirmation

During the waiting period:

- If **Switch2 is pressed**:
  - Buzzer turns OFF
  - LCD displays: "Medicine Taken"
  - Red LED remains OFF

  ![WhatsApp Image 2026-02-24 at 10 51 22 PM](https://github.com/user-attachments/assets/f6e70a63-af6d-48be-865c-a880cab23a9f)

 ⚠️ Missed Dose Detection

If **Switch2 is NOT pressed** within the timeout period:

- Buzzer turns OFF
- LCD displays: "Fail to medicine taken"
- 🔴 Red LED turns ON
- Indicates missed medicine intake

![WhatsApp Image 2026-02-24 at 10 52 45 PM](https://github.com/user-attachments/assets/3ea11e4b-289c-4427-afdd-3f07995810d7)


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
