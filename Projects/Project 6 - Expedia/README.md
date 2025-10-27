---


# **Project: Expedia.com**  
> **A Console-Based Travel Booking System in Modern C++**

---

### **Instructor**

**Mostafa S. Ibrahim**  
_Teaching, Training and Coaching since more than a decade!_

**Artificial Intelligence & Computer Vision Researcher**  
**PhD from Simon Fraser University – Canada**  
**Bachelor / MSc from Cairo University – Egypt**  
**Ex-Software Engineer / ICPC World Finalist**

---

### **Student**

**Ualiur Rahman Rahat**  
_Full Rewrite with Modern C++, Doxygen, RAII, and Design Patterns_  
[GitHub Profile](https://github.com/ualiurrahat)

---

## Project Overview

This project simulates **Expedia.ca** — a **full travel booking platform** in **C++ console**, implementing:

- User Authentication (Login / Signup)
- Flight & Hotel Search
- Itinerary Builder
- Secure Payment Processing
- Reservation Management with Rollback
- Polymorphic Design using **Factory, Adapter, Composite**

---

## Functional Requirements

| Feature            | Description                                      |
| ------------------ | ------------------------------------------------ |
| **User System**    | Two user types: `Admin` and `Customer`           |
| **Login / Signup** | Customer can register; Admin pre-loaded          |
| **Flight Search**  | Search by origin, destination, dates, passengers |
| **Hotel Search**   | Search by city, dates, room types                |
| **Itinerary**      | Combine flight + hotel                           |
| **Payment**        | PayPal, Stripe, Square (via JSON)                |
| **Reservation**    | Atomic commit with rollback on failure           |
| **History**        | View past bookings                               |

> **No parallel sessions** — one user at a time.

---

## Non-Functional Requirements [FYI]

| Quality             | Achieved                      |
| ------------------- | ----------------------------- |
| **Usability**       | Clear menus, input validation |
| **Security**        | CCV never printed             |
| **Reliability**     | RAII, exception-safe          |
| **Performance**     | O(1) lookups via `map`        |
| **Maintainability** | Doxygen, modular design       |
| **Scalability**     | Easily extendable APIs        |

---

## Dummy Login Credentials

| Type         | Username | Password |
| ------------ | -------- | -------- |
| **Customer** | `asmaa`  | `222`    |
| **Admin**    | `rahat`  | `111`    |

---

## Project Structure

Project 06 - Expedia/
├── API to use/
│ ├── expedia_flights_api.h
│ ├── expedia_hotels_api.h
│ ├── expedia_payments_api.h
│ └── json.hpp
├── code/
│ ├── expedia_main.cpp
│ ├── expedia_backend.h
│ ├── expedia_user.h
│ ├── expedia_user_mgr.h
│ ├── expedia_customer.h
│ ├── expedia_customer_mgr.h
│ ├── expedia_customer_view.h
│ ├── expedia_payment_card.h
│ ├── expedia_common_reservation.h
│ └── expedia_utils.h
├── assets/
│ └── expedia_banner.jpg
├── sample_input.txt
├── README.md
└── CMakeLists.txt
text---

## How to Compile & Run

### 1. Compile (Linux/macOS/WSL)

```bash
cd "Project 06 - Expedia"
g++ -std=c++17 -Wall -Wextra -O2 code/*.cpp -o expedia
2. Run with Sample Input
bash./expedia < sample_input.txt

Windows (MinGW/MSYS2):
cmdg++ -std=c++17 -o expedia.exe code\*.cpp
expedia.exe < sample_input.txt


Sample Input Flow (sample_input.txt)
txt1
asmaa
222

2
1 Cairo 10-05-20 Vancouver 13-06-20 3 2 1
3
2 10-05-20 13-06-20 Canada Vancouver 3 2
4
3 1

2
1 10-05-20 13-06-20 Canada California 3 2 1
1
3 1

2
1 Giza 10-05-20 Toronto 13-06-20 3 2 1
4
2 10-05-20 2-06-20 Giza Vancouver 3 2
5
2 3-06-20 13-06-20 Giza Vancouver 3 2
1
3 2

4

Design Patterns Used

PatternPurposeFactoryCreate payment/flight/hotel providersAdapterIntegrate PayPal, Stripe, Square APIsCompositeBuild itineraries from componentsCloneDeep copy reservationsRAIIAutomatic memory cleanupDependency InversionHigh-level modules depend on abstractions

Sample Output
txt=========================================
     EXPEDIA.COM - C++ CONSOLE SYSTEM
     Author: Ualiur Rahman Rahat
=========================================

Enter username & password: asmaa 222
Login successful! Welcome, Asmaa Saad Ibrahim

[Customer Menu]
1: Search Flights
2: Search Hotels
3: Build Itinerary
4: View History
5: Logout

> 2
Enter origin: Cairo
Enter destination: Vancouver
Enter departure: 10-05-20
Enter return: 13-06-20
Enter adults: 3 children: 2 infants: 1

[1] AirCanada: $450.00
[2] Turkish: $480.00
Select flight: 1

[1] Hilton: $840.00
[2] Marriott: $920.00
Select hotel: 1

Payment: SquarePayment - SUCCESS
Total: $1290.00
Reservation confirmed!


License
MIT License – Free to use, modify, and distribute.


```
