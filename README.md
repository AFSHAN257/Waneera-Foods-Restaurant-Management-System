# Waneera Foods  
Console-Based Restaurant Management System in C++

## Overview

Waneera Foods is a role-based Restaurant Management System developed in C++.  
The application simulates core restaurant operations including order processing, billing, sales tracking, table allocation, and employee attendance.

The system uses file-based persistence to store invoices, feedback, attendance records, and customer credentials.

---

## System Modules

### Customer Portal
- File-based authentication and guest access
- Multi-category menu and order placement
- Coupon-based discount logic
- Service selection: Dine-In, Takeaway, Home Delivery
- Dynamic table booking system
- Automated bill generation and payment workflow
- Feedback storage

### Admin Portal
- Product listing retrieval
- Invoice history inspection
- Aggregated sales calculation per item and category

### Employee Portal
- Attendance logging system with persistent storage

---

## Technical Implementation

- C++ Standard Library
- File Handling (`ifstream`, `ofstream`)
- 2D Arrays for structured order management
- Modular function-based design
- ANSI terminal formatting
- Resource state management (table availability tracking)

---

## Data Files

- `customers.txt`
- `invoice.txt`
- `feedback.txt`
- `attendance.txt`
- `Products.txt`

---

## Compilation and Execution

Compile:
```
g++ main.cpp -o restaurant
```

Run:
```
./restaurant
```

Note: Designed for Linux-based terminals due to `unistd.h` and ANSI escape sequences.

---

## Future Improvements

- Refactor into Object-Oriented Programming architecture
- Replace static arrays with STL containers
- Improve input validation
- Enhance portability and modularity

---

## Author

Afshan  
BS Computer Science
