# Hospital Management System

## Overview
The **Hospital Management System** is a C++ console-based application designed to simulate patient queue management for a hospital with multiple medical specializations. The system supports adding patients to specific specialization queues, prioritizing urgent cases, displaying patient lists, and allowing doctors to retrieve the next patient in line. The implementation uses arrays for data storage and provides a user-friendly interface for hospital staff to manage patient flow efficiently.

## Features
- **Specialization Management**: Supports 20 distinct medical specializations, each with a queue capacity of 5 patients.
- **Patient Addition**: Allows adding patients with a name and status (regular or urgent). Urgent patients are prioritized and placed at the front of the queue.
- **Queue Management**: Enforces a maximum queue length of 5 patients per specialization, rejecting additional patients when the queue is full.
- **Patient List Display**: Prints the list of patients waiting in each specialization, including their names and statuses.
- **Doctor Interaction**: Enables doctors to select a specialization and retrieve the next patient, removing them from the queue.
- **Input Validation**: Ensures robust handling of user inputs, validating specialization IDs and patient statuses.

## Prerequisites
- **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, clang++).
- **Standard C++ Library**: The program uses standard library components (`<iostream>`, `<string>`).

## Installation
1. **Clone or Download the Project**:
   - Copy the source code file (`01_hospitalSystem.cpp`) to your local machine.
2. **Compile the Code**:
   - Use a C++ compiler to compile the program. For example:
     ```bash
     g++ -o hospitalSystem 01_hospitalSystem.cpp
     ```
3. **Run the Program**:
   - Execute the compiled binary:
     ```bash
     ./hospitalSystem
     ```

## Usage
1. Launch the program to access the main menu.
2. Select from the following options:
   - **1) Add new patient**: Enter the specialization ID (1–20), patient name, and status (0 for regular, 1 for urgent).
   - **2) Print all patients**: Displays the list of patients for all specializations with waiting patients.
   - **3) Get next patient**: Enter a specialization ID to retrieve and remove the next patient in the queue.
   - **4) Exit**: Terminates the program.
3. Follow the on-screen prompts to input data. The system validates inputs and provides feedback for invalid entries or full queues.

### Example Interaction
```
***** Welcome To Hospital Management System *******
1) Add new patient
2) Print all patients
3) Get next patient
4) Exit

Enter your choice:
1
Enter specialization (1-20), name, and status (0=regular, 1=urgent): 15 mostafa 0
```

## Code Structure
- **File**: `01_hospitalSystem.cpp`
- **Key Components**:
  - **Global Arrays**:
    - `patientNames[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1]`: Stores patient names for each specialization.
    - `patientStatus[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1]`: Stores patient statuses (0 for regular, 1 for urgent).
    - `queueLength[MAX_SPECIALIZATION + 1]`: Tracks the number of patients in each specialization queue.
  - **Core Functions**:
    - `displayMenu()`: Displays the menu and validates user input.
    - `addPatient()`: Adds a patient to a specialization queue, prioritizing urgent cases.
    - `shiftRight()`: Shifts queue elements to make space for urgent patients.
    - `shiftLeft()`: Removes the front patient by shifting others left.
    - `printPatientList()`: Prints the patient list for a specific specialization.
    - `printAllPatients()`: Displays all non-empty specialization queues.
    - `getNextPatient()`: Retrieves and removes the next patient for a doctor.
    - `hospitalSystem()`: Runs the main program loop.

## Test Cases
The following test inputs can be used to verify the system's functionality:
```
1
15 mostafa 0
1
15 asmaa 0
1
15 belal 1
2
1
15 ziad 1
2
1
15 safaa 0
1
15 ashraf 0
2
3
10
3
15
2
1
7 soha 1
2
1
15 amal 1
3
7
2
```

## Limitations
- **Input Handling**: Assumes valid integer inputs for specialization ID and status. Invalid inputs (e.g., non-numeric) may require additional error handling.
- **Data Persistence**: Patient data is stored in memory and lost when the program exits.
- **Queue Size**: Fixed at 5 patients per specialization, which may not scale for larger hospitals.

## Future Enhancements
- Add data persistence to save patient records to a file.
- Implement advanced input validation for non-numeric or malformed inputs.
- Support dynamic queue sizes or additional patient attributes (e.g., appointment time).
- Introduce a graphical user interface (GUI) for improved usability.

## License
This project is provided for educational purposes and is not licensed for commercial use. Feel free to modify and extend the code for personal or academic projects.